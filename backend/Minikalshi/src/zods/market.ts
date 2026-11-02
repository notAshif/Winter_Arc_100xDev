import z from "zod";

export const createMarketSchema = z.object({
    title: z.string().trim().min(1),
    initialWager: z.number().optional(),
    side: z.enum(["yes", "no", "YES", "NO"]).optional(),
    expiry: z.coerce.date().optional(),
    totalIssued: z.number().optional(),
});

export const placeBetSchema = z.object({
    marketId: z.string().regex(/^[a-f\d]{24}$/i),
    side: z.enum(["yes", "no", "YES", "NO"]),
    amount: z.number().int().positive(),
});

export const createOrderSchema = z.object({
    marketId: z.string().regex(/^[a-f\d]{24}$/i),
    type: z.enum(["buy", "sell"]),
    side: z.enum(["YES", "NO"]),
    price: z.number().int().min(1).max(99),
    qty: z.number().int().positive(),
});
