import mongoose from "mongoose";

const StockBalanceSchema = new mongoose.Schema(
    {
        userId: {
            type: mongoose.Schema.Types.ObjectId,
            ref: "User",
            required: true,
        },
        marketId: {
            type: mongoose.Schema.Types.ObjectId,
            ref: "Market",
            required: true,
        },
        type: {
            type: String,
            enum: ["YES", "NO"],
            required: true,
        },
        qty: {
            type: Number,
            default: 0,
            min: 0,
        },
        locked: {
            type: Number,
            default: 0,
            min: 0,
        },
    },
    { timestamps: true }
);

StockBalanceSchema.index({ userId: 1, marketId: 1, type: 1 }, { unique: true });

export const StockBalanceModel = mongoose.model("StockBalance", StockBalanceSchema);
export const StockBalance = StockBalanceModel;
