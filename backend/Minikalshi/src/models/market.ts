import mongoose from "mongoose";

const marketSchema = new mongoose.Schema(
    {
        title: {
            type: String,
            required: true,
            trim: true,
        },
        creatorId: {
            type: mongoose.Schema.Types.ObjectId,
            ref: "User",
            required: true,
        },
        totalIssued: {
            type: Number,
            default: 0,
        },
        resolution: {
            type: String,
            enum: ["YES", "NO", "yes", "no", null],
            default: null,
        },
        status: {
            type: String,
            enum: ["open", "closed", "resolved", "cancelled"],
            default: "open",
        },
        initialWager: {
            type: Number,
            default: 0,
        },
        side: {
            type: String,
            enum: ["YES", "NO", "yes", "no", null],
            default: null,
        },
        expiry: {
            type: Date,
        },
    },
    { timestamps: true }
);

export const Market = mongoose.model("Market", marketSchema);
