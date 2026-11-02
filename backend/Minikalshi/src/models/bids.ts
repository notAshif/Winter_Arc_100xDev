import mongoose from "mongoose";

const BidSchema = new mongoose.Schema(
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

BidSchema.index({ orderbookId: 1, price: -1, createdAt: 1 });

export const BidModel = mongoose.model("Bid", BidSchema);
export const Bid = BidModel;
