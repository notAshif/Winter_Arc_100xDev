import mongoose from "mongoose";

const userSchema = new mongoose.Schema(
    {
        username: {
            type: String,
            required: true,
            unique: true,
            trim: true,
        },
        password: {
            type: String,
            required: true, 
        },
        usdBalance: {
            type: Number,
            default: 0,
            min: 0,
        },
        lockedUsdBalance: {
            type: Number,
            default: 0,
            min: 0,
        },
        role: {
            type: String,
            enum: ["admin", "user", "oracle"],
            default: "user",
            required: true,
        },
    },
    { timestamps: true }
); 

export const User = mongoose.model("User", userSchema);
