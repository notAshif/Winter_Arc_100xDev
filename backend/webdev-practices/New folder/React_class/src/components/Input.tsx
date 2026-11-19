import React, { useState } from "react";

const Input = () => {
  const [title, setTitle] = useState("");
  const [price, setPrices] = useState("");

  const handleSubmit = (e: React.ChangeEvent<HTMLElement>) => {
    e.preventDefault();

    if (!title.trim()) return;

    console.log("Submitting new course:", {
      title: title.trim(),
      price: Number(price),
    });

    setTitle("");
    setPrices("");
  };

  return (
    <>
      <form
        onSubmit={handleSubmit}
        className="mx-4 my-5 flex max-w-md flex-col gap-3 rounded-xl border-4 border-neutral-100 bg-white bg-clip-padding p-4 antialiased shadow-[inset_0_0_0_1px_rgba(0,0,0,0.08),0_0_0_1px_rgba(0,0,0,0.05),0_2px_6px_-1px_rgba(0,0,0,0.06)]"
      >
        <input
          type="text"
          placeholder="Course Title"
          value={title}
          onChange={(e) => setTitle(e.target.value)}
          className="min-h-12 w-full rounded-lg bg-neutral-50/80 px-3.5 text-base leading-normal text-[#202020] placeholder:text-[#71717a] shadow-[inset_0_0_0_1px_#d4d4d8,0_1px_2px_rgba(0,0,0,0.03)] outline-none transition-[background-color,box-shadow] duration-150 ease-out sm:text-sm pointer-coarse:min-h-13 motion-reduce:transition-none focus:bg-white focus:shadow-[inset_0_0_0_1px_#3074fe] focus:ring-3 focus:ring-[#3074fe]/25 user-invalid:shadow-[inset_0_0_0_1px_#dc2626] user-invalid:focus:ring-red-500/25 [@media(hover:hover)]:hover:bg-neutral-50 [@media(hover:hover)]:hover:shadow-[inset_0_0_0_1px_#a1a1aa]"
        />

        <input
          type="number"
          placeholder="Course Price"
          value={price}
          onChange={(e) => setPrices(e.target.value)}
          className="min-h-12 w-full rounded-lg bg-neutral-50/80 px-3.5 text-base leading-normal text-[#202020] tabular-nums placeholder:text-[#71717a] shadow-[inset_0_0_0_1px_#d4d4d8,0_1px_2px_rgba(0,0,0,0.03)] outline-none transition-[background-color,box-shadow] duration-150 ease-out sm:text-sm pointer-coarse:min-h-13 motion-reduce:transition-none focus:bg-white focus:shadow-[inset_0_0_0_1px_#3074fe] focus:ring-3 focus:ring-[#3074fe]/25 user-invalid:shadow-[inset_0_0_0_1px_#dc2626] user-invalid:focus:ring-red-500/25 [@media(hover:hover)]:hover:bg-neutral-50 [@media(hover:hover)]:hover:shadow-[inset_0_0_0_1px_#a1a1aa]"
        />
        <button
          type="submit"
          className="mt-1 inline-flex min-h-12 w-full cursor-pointer items-center justify-center rounded-lg bg-linear-to-b from-[#3f80ff] to-[#2867f2] px-4 text-sm leading-none font-medium text-white shadow-[0_0_0_1px_#1a4bc2,inset_0_1px_0_0_rgba(255,255,255,0.22),0_1px_2px_0_rgba(16,54,160,0.2),0_4px_10px_-2px_rgba(48,116,254,0.28)] outline-none select-none pointer-coarse:min-h-13 transition-[transform,box-shadow,filter] duration-150 ease-out motion-reduce:transition-none focus-visible:ring-3 focus-visible:ring-[#3074fe]/40 active:scale-[0.96] [@media(hover:hover)]:hover:brightness-105"
        >
          Create Course
        </button>
      </form>
    </>
  );
};

export default Input;
