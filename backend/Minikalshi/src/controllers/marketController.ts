import type { Request, Response } from "express";
import { createMarketSchema } from "../zods/market";
import { Market } from "../models/market";
import { Orderbook } from "../models/orderBook";

export const marketController = {
    async create(req: Request, res: Response) {
        const parsed = createMarketSchema.safeParse(req.body);

        if (!parsed.success) {
            return res.status(400).json({
                error: "Market title is required"
            });
        }

        try {
            const market = await Market.create({
                creatorId: req.userId,
                title: parsed.data.title,
                totalIssued: 0,
                resolution: null
            });

            await Orderbook.create([
                {
                    marketId: market._id,
                    type: "YES"
                },
                {
                    marketId: market._id,
                    type: "NO"
                }
            ]);

            return res.status(201).json({
                message: "Market created",
                market: {
                    id: market._id,
                    creatorId: market.creatorId,
                    title: market.title,
                    totalIssued: market.totalIssued,
                    resolution: market.resolution
                }
            });
        } catch (error: unknown) {
            console.error("createMarket error:", error);
            return res.status(500).json({
                error: "Could not create market"
            });
        }
    },

    async getMarkets(req: Request, res: Response) {
        try {
            const markets = await Market.find().populate("creatorId", "username");
            return res.status(200).json(markets);
        } catch (error: unknown) {
            console.error("Get markets error:", error);
            return res.status(500).json({
                error: "Could not get markets"
            });
        }
    }
};
