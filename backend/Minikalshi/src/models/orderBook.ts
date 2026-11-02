import mongoose from "mongoose";

const OrderBookSchema = new mongoose.Schema(
    {
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
    },
    { timestamps: true }
);

export const OrderBookModel = mongoose.model("OrderBook", OrderBookSchema);
export const Orderbook = OrderBookModel;
