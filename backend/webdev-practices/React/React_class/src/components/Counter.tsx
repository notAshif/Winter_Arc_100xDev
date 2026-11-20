import { useState } from "react";

function Counter() {
  // count: current state value (starts at 0)
  // setCount: setter function to update count and trigger a re-render
  const [count, setCount] = useState(0);

  function handleIncrement() {
    //Bad
    setCount(count + 1);
    //Good
    setCount((preCount) => preCount + 1);
  }

  function handleDecrement() {
    //Bad
    setCount(count - 1);

    //Good
    setCount((preCount) => preCount - 1);
  }

  function handleReset() {
    setCount(0);
  }

  return (
    <div className="mx-4 my-3 max-w-md rounded-xl border-4 border-neutral-100 bg-white bg-clip-padding p-4 antialiased shadow-[inset_0_0_0_1px_rgba(0,0,0,0.08),0_0_0_1px_rgba(0,0,0,0.05),0_2px_6px_-1px_rgba(0,0,0,0.06)]">
      <h2 className="mb-3.5 text-lg leading-tight font-semibold tracking-[-0.015em] text-[#202020] tabular-nums">
        Count: {count}
      </h2>
      <button
        className="relative mr-2 mb-1.5 inline-flex h-9 cursor-pointer items-center justify-center rounded-full bg-linear-to-b from-[#3f80ff] to-[#2867f2] px-4 text-sm leading-none font-medium text-white shadow-[0_0_0_1px_#1a4bc2,inset_0_1px_0_0_rgba(255,255,255,0.22),0_1px_2px_0_rgba(16,54,160,0.2)] outline-none select-none before:absolute before:inset-x-0 before:-inset-y-1 transition-[transform,box-shadow,filter] duration-150 ease-out motion-reduce:transition-none focus-visible:ring-3 focus-visible:ring-[#3074fe]/40 active:scale-[0.96] [@media(hover:hover)]:hover:brightness-105"
        onClick={handleIncrement}
      >
        + Increment
      </button>{" "}
      <button
        className="relative mr-2 mb-1.5 inline-flex h-9 cursor-pointer items-center justify-center rounded-full bg-linear-to-b from-white to-[#f7f7f8] px-4 text-sm leading-none font-medium text-[#202020] shadow-[0_0_0_1px_rgba(0,0,0,0.1),0_1px_2px_0_rgba(0,0,0,0.05),inset_0_-1px_0_0_rgba(0,0,0,0.04)] outline-none select-none before:absolute before:inset-x-0 before:-inset-y-1 transition-[transform,background-color,box-shadow] duration-150 ease-out motion-reduce:transition-none focus-visible:ring-3 focus-visible:ring-neutral-400/40 active:scale-[0.96] [@media(hover:hover)]:hover:from-[#fafafa] [@media(hover:hover)]:hover:to-[#f0f0f2]"
        onClick={handleDecrement}
      >
        - Decrement
      </button>{" "}
      <button
        className="relative mb-1.5 inline-flex h-9 cursor-pointer items-center justify-center rounded-full bg-neutral-100 px-3.5 text-sm leading-none font-medium text-[#71717a] ring-1 ring-black/6 outline-none select-none ring-inset before:absolute before:inset-x-0 before:-inset-y-1 transition-[transform,background-color,color] duration-150 ease-out motion-reduce:transition-none focus-visible:ring-3 focus-visible:ring-neutral-400/40 active:scale-[0.96] [@media(hover:hover)]:hover:bg-neutral-200/80 [@media(hover:hover)]:hover:text-[#202020]"
        onClick={handleReset}
      >
        Reset
      </button>
    </div>
  );
}

export default Counter;
