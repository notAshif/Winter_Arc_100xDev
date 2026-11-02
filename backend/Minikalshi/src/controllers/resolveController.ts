import type { Request, Response } from "express";
import { resolveMarketSchema } from "../zods/resolve";
import { Market } from "../models/market";
import { Bet } from "../models/bet";
import { User } from "../models/user";
import { WalletEvent } from "../models/walletEvent";

const PLATFORM_FEE_RATE = 0.02;

export const resolveController = {
    async resolve(req: Request, res: Response) {
        try {
            const parsed = resolveMarketSchema.safeParse(req.body);

            if (!parsed.success) {
                return res.status(400).json({ message: "Invalid resolve payload." });
            }

            const { marketId, resolution } = parsed.data;

            const market = await Market.findById(marketId);

            if (!market) {
                return res.status(404).json({
                    message: "Market not found."
                });
            }

            if (market.expiry && new Date() < market.expiry) {
                return res.status(400).json({
                    error: "Cannot resolve market before its expiry time."
                });
            }

            if (market.resolution !== null || market.status === "resolved") {
                return res.status(400).json({
                    message: "Market is already resolved."
                });
            }

            const bets = await Bet.find({ marketId });
            const totalBet = bets.reduce((acc, curr) => acc + curr.betAmount, 0);

            if (market.side === resolution) {
                const grossWinnings = totalBet;
                const fee = Math.round(grossWinnings * PLATFORM_FEE_RATE * 100) / 100;
                const netWinnings = grossWinnings - fee;
                const payout = (market.initialWager || 0) + netWinnings;

                await User.updateOne(
                    { _id: market.creatorId },
                    { $inc: { usdBalance: payout } }
                );

                await WalletEvent.create({
                    userId: market.creatorId,
                    tx_type: "payout",
                    externalId: { marketId },
                    amount: payout
                });

                if (fee > 0) {
                    await WalletEvent.create({
                        userId: market.creatorId,
                        tx_type: "fee",
                        externalId: { marketId },
                        amount: -fee
                    });
                }

            } else {
                for (const bet of bets) {
                    const grossWinnings = bet.betAmount;
                    const fee = Math.round(grossWinnings * PLATFORM_FEE_RATE * 100) / 100;
                    const payout = (bet.betAmount * 2) - fee;

                    await User.updateOne(
                        { _id: bet.userId },
                        { $inc: { usdBalance: payout } }
                    );

                    await WalletEvent.create({
                        userId: bet.userId,
                        tx_type: "payout",
                        externalId: { marketId, betId: bet._id },
                        amount: payout
                    });

                    if (fee > 0) {
                        await WalletEvent.create({
                            userId: bet.userId,
                            tx_type: "fee",
                            externalId: { marketId, betId: bet._id },
                            amount: -fee
                        });
                    }
                }

                const refund = (market.initialWager || 0) - totalBet;

                if (refund > 0) {
                    await User.updateOne(
                        { _id: market.creatorId },
                        { $inc: { usdBalance: refund } }
                    );

                    await WalletEvent.create({
                        userId: market.creatorId,
                        tx_type: "refund",
                        externalId: { marketId },
                        amount: refund
                    });
                }
            }

            market.resolution = resolution;
            market.status = "resolved";
            await market.save();

            return res.status(200).json({
                message: "Market resolved successfully",
                resolution,
                totalBet,
                winner: market.side === resolution ? "creator" : "bettors",
            });

        } catch (error: unknown) {
            console.error("Resolve error:", error);
            return res.status(500).json({ message: "Internal server error" });
        }
    }
};
