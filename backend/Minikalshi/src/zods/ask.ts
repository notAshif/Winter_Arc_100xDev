import z from "zod";

export const AskSchema = z.object({
    price: z.number(),
    qty: z.number(),
    stockType: z.enum(["yes", "no"]),
    remainingQty: z.number(),
});

export const BidSchema = z.object({
    price: z.number(),
    qty: z.number(),
    stockType: z.enum(["yes", "no"]),
    remainingQty: z.number(),
});
