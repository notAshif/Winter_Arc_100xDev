import React, { useState } from "react";

export default function UploadImage({
  onUploadSuccess,
}: {
  onUploadSuccess: (url: string) => void;
}) {
  const [selectFile, setSelectFile] = useState<File | null>(null);
  const [isUpload, setIsUpload] = useState(false);
  const [message, setMessage] = useState<string | " ">(" ");
  const [isDragging, setIsDragging] = useState(false);
  const [localPreview, setLocalPreview] = useState<string | null>(null);

  const isBusy = isUpload && message.trim() === "";
  const isDone = message === "Upload Successfully.";
  const isError = !isBusy && !isDone && message.trim() !== "";
  const isImage = selectFile?.type.startsWith("image/") ?? false;

  const handleUpload = async () => {
    if (!selectFile) {
      setMessage("Please choose an file.");
      return;
    }

    setIsUpload(true);

    try {
      const preSignedRes = await fetch("http://localhost:3000/presign", {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({
          filename: selectFile.name,
          filetype: selectFile.type,
        }),
      });

      if (!preSignedRes.ok) {
        setMessage("Failed to upload file.");
      }

      const { signedUrl, key, publicUrl } = await preSignedRes.json();

      //store in R2.
      const UploadRes = await fetch(signedUrl, {
        method: "PUT",
        headers: {
          "Content-Type": selectFile.type,
        },
        body: selectFile,
      });

      if (!UploadRes.ok) {
        const errorText = await UploadRes.text();
        throw new Error(`R2 upload failed: ${UploadRes.status} ${errorText}`);
      }

      console.log({
        key,
        publicUrl,
      });

      if (!UploadRes.ok) {
        setMessage("Failed to store in R2.");
      }

      onUploadSuccess(URL.createObjectURL(selectFile));
      setIsUpload(true);
      setMessage("Upload Successfully.");
    } catch (error) {
      console.log(error);
      setMessage("Failed to upload.");
    }
  };

  const resetStatus = () => {
    setIsUpload(false);
    setMessage(" ");
  };

  const pickFile = (file?: File) => {
    if (!file) return;
    if (localPreview) URL.revokeObjectURL(localPreview);
    setLocalPreview(
      file.type.startsWith("image/") ? URL.createObjectURL(file) : null,
    );
    setSelectFile(file);
    resetStatus();
  };

  const removeFile = () => {
    if (localPreview) URL.revokeObjectURL(localPreview);
    setLocalPreview(null);
    setSelectFile(null);
    resetStatus();
  };

  const startUpload = () => {
    setMessage(" ");
    void handleUpload();
  };

  const handleDragOver = (event: React.DragEvent<HTMLLabelElement>) => {
    event.preventDefault();
    event.dataTransfer.dropEffect = isBusy ? "none" : "copy";
    if (!isBusy) setIsDragging(true);
  };

  const handleDragLeave = (event: React.DragEvent<HTMLLabelElement>) => {
    if (!event.currentTarget.contains(event.relatedTarget as Node | null)) {
      setIsDragging(false);
    }
  };

  const handleDrop = (event: React.DragEvent<HTMLLabelElement>) => {
    event.preventDefault();
    setIsDragging(false);
    if (!isBusy) pickFile(event.dataTransfer.files[0]);
  };

  const handleInputChange = (event: React.ChangeEvent<HTMLInputElement>) => {
    pickFile(event.target.files?.[0]);
    event.target.value = "";
  };

  return (
    <section aria-labelledby="upload-title" className="flex flex-col gap-8">
      <header className="flex flex-col gap-5">
        <div className="flex items-center gap-2.5">
          <span className="grid size-8 place-items-center rounded-lg bg-[#F6821F] text-white shadow-[inset_0_-1px_0_rgb(0_0_0/0.15)]">
            <svg
              aria-hidden="true"
              viewBox="0 0 20 20"
              fill="currentColor"
              className="size-4.5"
            >
              <path d="M14.5 15.5h-9a3.5 3.5 0 0 1-.6-6.95 5 5 0 0 1 9.55-1.3A4.13 4.13 0 0 1 14.5 15.5Z" />
            </svg>
          </span>
          <span className="text-sm font-medium text-neutral-700">
            R2 Uploads
          </span>
        </div>

        <div className="flex flex-col gap-2">
          <h1
            id="upload-title"
            className="text-[1.75rem] leading-tight font-semibold tracking-[-0.02em] text-balance text-neutral-950"
          >
            Upload an image
          </h1>
          <p className="max-w-[46ch] text-[0.9375rem] leading-relaxed text-pretty text-neutral-600">
            Your file goes straight from the browser to Cloudflare R2 through a
            short-lived presigned URL. Images get a preview once the upload
            finishes.
          </p>
        </div>
      </header>

      <div className="surface flex flex-col gap-2">
        <label
          onDragEnter={handleDragOver}
          onDragOver={handleDragOver}
          onDragLeave={handleDragLeave}
          onDrop={handleDrop}
          className={`group flex flex-col items-center gap-3 rounded-xl border border-dashed px-6 py-10 text-center transition-colors duration-150 ease-out has-focus-visible:outline-2 has-focus-visible:outline-offset-2 has-focus-visible:outline-[#0051C3] ${
            isDragging
              ? "border-[#F6821F] bg-[#FFF5EC]"
              : "border-neutral-300 bg-neutral-50 hover:border-neutral-400 hover:bg-neutral-100/70"
          } ${isBusy ? "cursor-not-allowed opacity-60" : "cursor-pointer"}`}
        >
          <input
            type="file"
            className="sr-only"
            disabled={isBusy}
            onChange={handleInputChange}
          />

          <span
            className={`grid size-11 place-items-center rounded-full bg-white shadow-[0_0_0_1px_rgb(0_0_0/0.08),0_1px_2px_rgb(0_0_0/0.06)] transition-colors duration-150 ${
              isDragging ? "text-[#F6821F]" : "text-neutral-500"
            }`}
          >
            <svg
              aria-hidden="true"
              viewBox="0 0 20 20"
              fill="none"
              stroke="currentColor"
              strokeWidth="1.5"
              strokeLinecap="round"
              strokeLinejoin="round"
              className="size-5"
            >
              <path d="M10 13V3.5M6.25 7.25 10 3.5l3.75 3.75M3.5 12.5v2.25c0 .97.78 1.75 1.75 1.75h9.5c.97 0 1.75-.78 1.75-1.75V12.5" />
            </svg>
          </span>

          <span className="flex flex-col gap-1">
            <span className="text-sm font-medium text-neutral-900">
              {isDragging ? (
                "Drop to select this file"
              ) : (
                <>
                  Drag a file here, or{" "}
                  <span className="text-[#0051C3] underline decoration-[#0051C3]/30 underline-offset-2 transition-colors duration-150 group-hover:decoration-[#0051C3]">
                    browse
                  </span>
                </>
              )}
            </span>
            <span className="text-[0.8125rem] text-neutral-500">
              Previews are shown for image files only
            </span>
          </span>
        </label>

        {selectFile && (
          <div className="flex items-center gap-3 rounded-xl bg-neutral-50 p-2 pr-1 ring-1 ring-black/5 ring-inset">
            {localPreview ? (
              <img
                src={localPreview}
                alt=""
                className="size-11 shrink-0 rounded-sm object-cover outline-1 -outline-offset-1 outline-black/10"
              />
            ) : (
              <span className="grid size-11 shrink-0 place-items-center rounded-sm bg-white text-neutral-500 ring-1 ring-black/10 ring-inset">
                <svg
                  aria-hidden="true"
                  viewBox="0 0 20 20"
                  fill="none"
                  stroke="currentColor"
                  strokeWidth="1.5"
                  strokeLinejoin="round"
                  className="size-5"
                >
                  <path d="M11.5 2.75H6A1.75 1.75 0 0 0 4.25 4.5v11c0 .97.78 1.75 1.75 1.75h8c.97 0 1.75-.78 1.75-1.75V7l-4.25-4.25Z" />
                  <path d="M11.5 2.75V7h4.25" />
                </svg>
              </span>
            )}

            <div className="min-w-0 flex-1">
              <p
                className="truncate text-sm font-medium text-neutral-900"
                title={selectFile.name}
              >
                {selectFile.name}
              </p>
              <p className="flex gap-3 text-[0.8125rem] text-neutral-500">
                <span className="shrink-0 tabular-nums">
                  {formatBytes(selectFile.size)}
                </span>
                <span className="truncate">
                  {isImage ? selectFile.type : "No preview for this file type"}
                </span>
              </p>
            </div>

            <button
              type="button"
              onClick={removeFile}
              disabled={isBusy}
              aria-label={`Remove ${selectFile.name}`}
              className="grid size-10 shrink-0 place-items-center rounded-lg text-neutral-500 transition-colors duration-150 hover:bg-neutral-200/70 hover:text-neutral-900 focus-visible:outline-2 focus-visible:outline-[#0051C3] disabled:pointer-events-none disabled:opacity-40"
            >
              <svg
                aria-hidden="true"
                viewBox="0 0 16 16"
                fill="none"
                stroke="currentColor"
                strokeWidth="1.5"
                strokeLinecap="round"
                className="size-4"
              >
                <path d="m4 4 8 8M12 4l-8 8" />
              </svg>
            </button>
          </div>
        )}

        <div className="flex min-h-13 items-center justify-between gap-4 py-1.5 pr-1.5 pl-3">
          <p
            role="status"
            className={`flex min-w-0 items-center gap-2 text-sm ${
              isError
                ? "text-[#B42318]"
                : isDone
                  ? "text-[#067647]"
                  : "text-neutral-500"
            }`}
          >
            {isBusy && (
              <svg
                aria-hidden="true"
                viewBox="0 0 16 16"
                fill="none"
                className="size-4 shrink-0 animate-spin text-[#F6821F] motion-reduce:animate-[spin_6s_linear_infinite]"
              >
                <circle
                  cx="8"
                  cy="8"
                  r="6.25"
                  stroke="currentColor"
                  strokeOpacity="0.25"
                  strokeWidth="1.5"
                />
                <path
                  d="M14.25 8A6.25 6.25 0 0 0 8 1.75"
                  stroke="currentColor"
                  strokeWidth="1.5"
                  strokeLinecap="round"
                />
              </svg>
            )}
            {isDone && (
              <svg
                aria-hidden="true"
                viewBox="0 0 16 16"
                fill="none"
                stroke="currentColor"
                strokeWidth="1.5"
                strokeLinecap="round"
                strokeLinejoin="round"
                className="size-4 shrink-0"
              >
                <circle cx="8" cy="8" r="6.25" />
                <path d="m5.5 8.25 1.75 1.75L10.75 6.5" />
              </svg>
            )}
            {isError && (
              <svg
                aria-hidden="true"
                viewBox="0 0 16 16"
                fill="none"
                stroke="currentColor"
                strokeWidth="1.5"
                strokeLinecap="round"
                className="size-4 shrink-0"
              >
                <circle cx="8" cy="8" r="6.25" />
                <path d="M8 4.75v3.75M8 11.25v.01" />
              </svg>
            )}
            <span className="truncate">
              {isBusy
                ? "Uploading to R2…"
                : isDone || isError
                  ? message
                  : selectFile
                    ? "Ready to upload"
                    : "No file selected"}
            </span>
          </p>

          <button
            type="button"
            onClick={startUpload}
            disabled={!selectFile || isBusy || isDone}
            className="inline-flex h-10 shrink-0 items-center rounded-lg bg-[#0051C3] px-4 text-sm font-semibold text-white shadow-[inset_0_1px_0_rgb(255_255_255/0.12),0_1px_2px_rgb(0_0_0/0.12)] transition-[background-color,scale] duration-150 ease-out hover:bg-[#003F9E] focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-[#0051C3] active:scale-[0.96] disabled:cursor-not-allowed disabled:bg-neutral-200 disabled:text-neutral-500 disabled:shadow-none disabled:active:scale-100"
          >
            {isBusy
              ? "Uploading…"
              : isError
                ? "Try again"
                : isDone
                  ? "Uploaded"
                  : "Upload"}
          </button>
        </div>
      </div>
    </section>
  );
}

function formatBytes(bytes: number) {
  if (bytes < 1024) return `${bytes} B`;
  const units = ["KB", "MB", "GB"];
  let value = bytes / 1024;
  let unit = 0;
  while (value >= 1024 && unit < units.length - 1) {
    value /= 1024;
    unit += 1;
  }
  return `${value.toFixed(value < 10 ? 1 : 0)} ${units[unit]}`;
}
