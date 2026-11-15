import React from "react";

export default function ImagePreview({
  PreviewUrl,
}: {
  PreviewUrl: string | null;
}) {
  if (!PreviewUrl) return null;
  return <PreviewCard key={PreviewUrl} url={PreviewUrl} />;
}


function PreviewCard({ url }: { url: string }) {
  const [size, setSize] = React.useState<{ width: number; height: number } | null>(null);
  const [failed, setFailed] = React.useState(false);

  const handleLoad = (event: React.SyntheticEvent<HTMLImageElement>) => {
    const { naturalWidth, naturalHeight } = event.currentTarget;
    setSize({ width: naturalWidth, height: naturalHeight });
  };

  return (
    <section aria-labelledby="preview-title" className="surface">
      <div className="bg-checker grid min-h-56 place-items-center overflow-hidden rounded-xl">
        {failed ? (
          <p className="px-6 text-center text-sm text-pretty text-neutral-500">
            This file can't be shown as an image.
          </p>
        ) : (
          <img
            src={url}
            alt="Uploaded image"
            onLoad={handleLoad}
            onError={() => setFailed(true)}
            className={`max-h-[60vh] w-auto max-w-full object-contain outline-1 -outline-offset-1 outline-black/10 transition-opacity duration-200 ease-out motion-reduce:transition-none ${
              size ? "opacity-100" : "opacity-0"
            }`}
          />
        )}
      </div>

      <div className="flex items-center justify-between gap-4 py-1.5 pr-1.5 pl-3">
        <div className="min-w-0">
          <h2 id="preview-title" className="text-sm font-medium text-neutral-900">
            Uploaded image
          </h2>
          <p className="text-[0.8125rem] text-neutral-500 tabular-nums">
            {failed ? "Preview unavailable" : size ? `${size.width} × ${size.height} px` : "Loading preview…"}
          </p>
        </div>

        {!failed && (
          <a
            href={url}
            target="_blank"
            rel="noreferrer"
            className="inline-flex h-10 shrink-0 items-center gap-1.5 rounded-lg px-3 text-sm font-medium text-[#0051C3] transition-colors duration-150 hover:bg-[#0051C3]/6 focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-[#0051C3]"
          >
            Open full size
            <svg aria-hidden="true" viewBox="0 0 16 16" fill="none" stroke="currentColor" strokeWidth="1.5" strokeLinecap="round" strokeLinejoin="round" className="size-3.5">
              <path d="M9.5 2.5h4v4M13.5 2.5 7.5 8.5M11.5 9.5v3a1 1 0 0 1-1 1h-7a1 1 0 0 1-1-1v-7a1 1 0 0 1 1-1h3" />
            </svg>
          </a>
        )}
      </div>
    </section>
  );
}
