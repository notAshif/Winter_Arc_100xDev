import "dotenv/config";

import express, { type NextFunction, type Request, type Response } from "express";
import cors from "cors";
import { S3Client, PutObjectCommand } from "@aws-sdk/client-s3";
import { getSignedUrl } from "@aws-sdk/s3-request-presigner"

const app = express();
app.use(cors());
app.use(express.json());

app.use((req: Request, res: Response, next: NextFunction) => {
    res.header("Access-Control-Allow-Origin", "*");
    res.header("Access-Control-Allow-Headers", "Content-Type");
    res.header("Access-Control-Allow-Methods", "GET,POST,OPTIONS");
    
    if (req.method === "OPTION") {
        return res.status(204);
    }
    next();
});

const R2_ACCESS_KEY_ID = process.env.R2_ACCESS_KEY_ID;
const R2_ACCESS_SECRET_KEY = process.env.R2_ACCESS_SECRET_KEY;
const R2_ENDPOINT = process.env.R2_ENDPOINT;
const R2_BUCKET = process.env.R2_BUCKET;
const R2_PUBLIC_URL = process.env.R2_PUBLIC_URL;

if (!R2_ACCESS_KEY_ID || !R2_ACCESS_SECRET_KEY || !R2_ENDPOINT || !R2_BUCKET) {
    throw new Error("Missing required R2 env vars");
}

const s3Client = new S3Client({
    region: "auto",
    endpoint: R2_ENDPOINT,
    credentials: {
        accessKeyId: R2_ACCESS_KEY_ID,
        secretAccessKey: R2_ACCESS_SECRET_KEY
    },
    requestChecksumCalculation: "WHEN_REQUIRED",
    responseChecksumValidation: "WHEN_REQUIRED",
});

const getFileExtension = (filename: string) => {
    const parts = filename.split(".");
    const extension = parts[parts.length - 1];
    return extension && extension !== filename ? extension : "bin";
}

app.post("/presign", async (req: Request, res: Response) => {
    const { filetype, filename } = req.body ?? {};

    if (!filetype || !filename) {
        return res.status(401).json({ message: "Invalid input format. " });
    }

    if (!filetype.startsWith("image/"))
        return res.status(400).json({ error: "Only image uploads allowed" });

    const extension = getFileExtension(filename);
    const key = `uploads/${Date.now()}-${crypto.randomUUID()}.${extension}`;

    try {

        const command = new PutObjectCommand({
            Bucket: R2_BUCKET,
            Key: key,
            ContentType: filetype
        });

        const signedUrl = await getSignedUrl(s3Client, command, {
            expiresIn: 60,
        });
        console.log(signedUrl);

        const publicUrl = R2_PUBLIC_URL ? `${R2_PUBLIC_URL.replace(/\/&/, " ")}/${key}` : null;

        return res.status(200).json({ signedUrl, key, publicUrl })
        
    } catch (error) {
        return res.status(500).json({ message: "Internal server error" });
    }
});

app.listen(3000, () => {
    console.log("Server running at http://localhost:3000");
});