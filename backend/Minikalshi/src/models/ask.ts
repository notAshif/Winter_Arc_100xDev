import mongoose from "mongoose";

const AskSchema = new mongoose.Schema(
    {
        orderbookId: {
            type: mongoose.Schema.Types.ObjectId,
            ref: "OrderBook",
            required: true,
        },
        price: {
            type: Number,
            required: true,
            min: 1,
            max: 99,
        },
        qty: {
            type: Number,
            required: true,
            min: 0,
        },
        userId: {
            type: mongoose.Schema.Types.ObjectId,
            ref: "User",
            required: true,
        },
        stockType: {
            type: String,
            enum: ["YES", "NO"],
            required: true,
        },
    },
    { timestamps: true }
);

AskSchema.index({ orderbookId: 1, price: 1, createdAt: 1 });

export const AskModel = mongoose.model("Ask", AskSchema);
export const Ask = AskModel;
