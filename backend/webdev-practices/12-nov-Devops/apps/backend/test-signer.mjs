import { S3Client, PutObjectCommand } from "@aws-sdk/client-s3";
import { getSignedUrl } from "@aws-sdk/s3-request-presigner";

const client = new S3Client({
  region: "auto",
  endpoint: "https://test.r2.cloudflarestorage.com",
  credentials: { accessKeyId: "test", secretAccessKey: "test" },
  requestChecksumCalculation: "WHEN_REQUIRED",
  responseChecksumValidation: "WHEN_REQUIRED"
});

async function run() {
  const cmd = new PutObjectCommand({ Bucket: "test", Key: "test.png", ContentType: "image/png" });
  const url1 = await getSignedUrl(client, cmd, { expiresIn: 60 });
  console.log("url1 signed headers:", new URL(url1).searchParams.get("X-Amz-SignedHeaders"));

  const url2 = await getSignedUrl(client, cmd, { expiresIn: 60, signableHeaders: new Set(["content-type"]) });
  console.log("url2 signed headers:", new URL(url2).searchParams.get("X-Amz-SignedHeaders"));
}
run();
