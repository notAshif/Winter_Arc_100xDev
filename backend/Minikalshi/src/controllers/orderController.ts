import type { Request, Response } from "express";
import mongoose from "mongoose";
import { createOrderSchema } from "../zods/market";
import { User } from "../models/user";
import { Market } from "../models/market";
import { Orderbook } from "../models/orderBook";
import { Bid } from "../models/bids";
import { Ask } from "../models/ask";
import { Fill } from "../models/fill";
import { StockBalance } from "../models/stockBalance";

async function addToStockBalance(
    userId: mongoose.Types.ObjectId | string,
    marketId: mongoose.Types.ObjectId | string,
    side: "YES" | "NO",
    qty: number
) {
    await StockBalance.findOneAndUpdate(
        {
            userId,
            marketId,
            type: side
        },
        {
            $inc: { qty },
            $setOnInsert: { locked: 0 }
        },
        {
            upsert: true
        }
    );
}

export const OrderController = {
    async create(req: Request, res: Response) {
        const parsed = createOrderSchema.safeParse(req.body);

        if (!parsed.success) {
            return res.status(400).json({
                error: "Invalid order request"
            });
        }

        const { marketId, type, side, price, qty } = parsed.data;

        if (!mongoose.isValidObjectId(marketId)) {
            return res.status(400).json({
                error: "Invalid market ID"
            });
        }

        const maxCost = price * qty;

        if (!Number.isSafeInteger(maxCost)) {
            return res.status(400).json({
                error: "Order amount is too large"
            });
        }

        try {
            const market = await Market.findOne({
                _id: marketId,
                resolution: null
            });

            if (!market) {
                return res.status(404).json({
                    error: "Unresolved market not found"
                });
            }

            const orderbook = await Orderbook.findOne({
                marketId,
                type: side
            });

            if (!orderbook) {
                return res.status(404).json({
                    error: "Order book not found"
                });
            }

            const user = await User.findById(req.userId);

            if (!user) {
                return res.status(404).json({
                    error: "User not found"
                });
            }

            let remainingQty = qty;
            let filledQty = 0;
            let pendingOrder = null;

            if (type === "buy") {
                if (user.usdBalance < maxCost) {
                    return res.status(400).json({
                        error: "Insufficient available USD"
                    });
                }

                user.usdBalance -= maxCost;
                user.lockedUsdBalance += maxCost;
                await user.save();

                const matchingAsks = await Ask.find({
                    orderbookId: orderbook._id,
                    stockType: side,
                    price: { $lte: price },
                    qty: { $gt: 0 },
                    userId: { $ne: user._id }
                }).sort({
                    price: 1,
                    createdAt: 1,
                    _id: 1
                });

                for (const ask of matchingAsks) {
                    if (remainingQty === 0) break;

                    const matchedQty = Math.min(remainingQty, ask.qty);
                    const executionPrice = ask.price;
                    const actualCost = executionPrice * matchedQty;
                    const reservedForMatch = price * matchedQty;
                    const refund = reservedForMatch - actualCost;

                    const seller = await User.findById(ask.userId);
                    const sellerStock = await StockBalance.findOne({
                        userId: ask.userId,
                        marketId,
                        type: side
                    });

                    if (
                        !seller ||
                        !sellerStock ||
                        sellerStock.locked < matchedQty ||
                        sellerStock.qty < matchedQty
                    ) {
                        throw new Error("Seller balance is inconsistent");
                    }

                    user.lockedUsdBalance -= reservedForMatch;
                    user.usdBalance += refund;

                    seller.usdBalance += actualCost;

                    sellerStock.qty -= matchedQty;
                    sellerStock.locked -= matchedQty;

                    await user.save();
                    await seller.save();
                    await sellerStock.save();

                    await addToStockBalance(user._id, marketId, side, matchedQty);

                    await Fill.create([
                        {
                            orderbookId: orderbook._id,
                            userId: seller._id,
                            price: executionPrice,
                            qty: matchedQty,
                            type: "sell",
                            isMaker: true
                        },
                        {
                            orderbookId: orderbook._id,
                            userId: user._id,
                            price: executionPrice,
                            qty: matchedQty,
                            type: "buy",
                            isMaker: false
                        }
                    ]);

                    ask.qty -= matchedQty;

                    if (ask.qty === 0) {
                        await Ask.deleteOne({ _id: ask._id });
                    } else {
                        await ask.save();
                    }

                    remainingQty -= matchedQty;
                    filledQty += matchedQty;
                }

                if (remainingQty > 0) {
                    pendingOrder = await Bid.create({
                        orderbookId: orderbook._id,
                        userId: user._id,
                        stockType: side,
                        price,
                        qty: remainingQty
                    });
                }
            } else {
                const sellerStock = await StockBalance.findOne({
                    userId: user._id,
                    marketId,
                    type: side
                });

                if (!sellerStock || sellerStock.qty - sellerStock.locked < qty) {
                    return res.status(400).json({
                        error: "Insufficient unlocked contracts"
                    });
                }

                sellerStock.locked += qty;
                await sellerStock.save();

                const matchingBids = await Bid.find({
                    orderbookId: orderbook._id,
                    stockType: side,
                    price: { $gte: price },
                    qty: { $gt: 0 },
                    userId: { $ne: user._id }
                }).sort({
                    price: -1,
                    createdAt: 1,
                    _id: 1
                });

                for (const bid of matchingBids) {
                    if (remainingQty === 0) break;

                    const matchedQty = Math.min(remainingQty, bid.qty);
                    const executionPrice = bid.price;
                    const actualCost = executionPrice * matchedQty;

                    const buyer = await User.findById(bid.userId);

                    if (!buyer || buyer.lockedUsdBalance < actualCost) {
                        throw new Error("Buyer balance is inconsistent");
                    }

                    buyer.lockedUsdBalance -= actualCost;
                    user.usdBalance += actualCost;

                    sellerStock.qty -= matchedQty;
                    sellerStock.locked -= matchedQty;

                    await buyer.save();
                    await user.save();
                    await sellerStock.save();

                    await addToStockBalance(buyer._id, marketId, side, matchedQty);

                    await Fill.create([
                        {
                            orderbookId: orderbook._id,
                            userId: buyer._id,
                            price: executionPrice,
                            qty: matchedQty,
                            type: "buy",
                            isMaker: true
                        },
                        {
                            orderbookId: orderbook._id,
                            userId: user._id,
                            price: executionPrice,
                            qty: matchedQty,
                            type: "sell",
                            isMaker: false
                        }
                    ]);

                    bid.qty -= matchedQty;

                    if (bid.qty === 0) {
                        await Bid.deleteOne({ _id: bid._id });
                    } else {
                        await bid.save();
                    }

                    remainingQty -= matchedQty;
                    filledQty += matchedQty;
                }

                if (remainingQty > 0) {
                    pendingOrder = await Ask.create({
                        orderbookId: orderbook._id,
                        userId: user._id,
                        stockType: side,
                        price,
                        qty: remainingQty
                    });
                }
            }

            const status =
                remainingQty === 0
                    ? "FILLED"
                    : filledQty === 0
                    ? "OPEN"
                    : "PARTIALLY_FILLED";

            return res.status(201).json({
                message: "Order processed",
                orderId: pendingOrder?._id ?? null,
                marketId,
                type,
                side,
                price,
                requestedQty: qty,
                filledQty,
                remainingQty,
                status
            });
        } catch (error) {
            console.error("createOrder error:", error);
            return res.status(500).json({
                error: "Could not process order"
            });
        }
    },

    async getOrderbook(req: Request, res: Response) {
        const { marketId } = req.params;

        if (!mongoose.isValidObjectId(marketId)) {
            return res.status(400).json({
                error: "Invalid market ID"
            });
        }

        try {
            const orderbooks = await Orderbook.find({ marketId });

            if (!orderbooks.length) {
                return res.status(404).json({
                    error: "Order book not found"
                });
            }

            const result: Record<string, { bids: unknown[]; asks: unknown[] }> = {};

            for (const book of orderbooks) {
                const bids = await Bid.find({ orderbookId: book._id, qty: { $gt: 0 } })
                    .select("price qty createdAt")
                    .sort({ price: -1, createdAt: 1 });

                const asks = await Ask.find({ orderbookId: book._id, qty: { $gt: 0 } })
                    .select("price qty createdAt")
                    .sort({ price: 1, createdAt: 1 });

                result[book.type] = { bids, asks };
            }

            return res.status(200).json({
                marketId,
                orderbooks: result
            });
        } catch (error) {
            console.error("getOrderbook error:", error);
            return res.status(500).json({
                error: "Could not fetch order book"
            });
        }
    }
};

export const createOrder = OrderController.create;
