import z from "zod";

export const fillSchema = z.object({
    price: z.number(),
    qty: z.number(),
    isMaker: z.boolean().default(true),
});

