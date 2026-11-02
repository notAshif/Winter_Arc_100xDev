import mongoose from "mongoose";

const FillSchema = new mongoose.Schema(
    {
        orderbookId: {
            type: mongoose.Schema.Types.ObjectId,
            ref: "OrderBook",
            required: true,
        },
        userId: {
            type: mongoose.Schema.Types.ObjectId,
            ref: "User",
            required: true,
        },
        price: {
            type: Number,
            required: true,
        },
        qty: {
            type: Number,
            required: true,
        },
        type: {
            type: String,
            enum: ["buy", "sell"],
            required: true,
        },
        isMaker: {
            type: Boolean,
            required: true,
        },
    },
    { timestamps: true }
);

export const FillModel = mongoose.model("Fill", FillSchema);
export const Fill = FillModel;
