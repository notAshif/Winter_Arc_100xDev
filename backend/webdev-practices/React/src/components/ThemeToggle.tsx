import React, { useState } from "react";

const ThemeToggle = () => {
  const [theme, setTheme] = useState("light");
  return (
    <div
      data-theme={theme}
      className="mx-4 my-3 inline-flex rounded-full bg-neutral-100 p-1 antialiased ring-1 ring-black/6 transition-colors duration-150 ease-out motion-reduce:transition-none data-[theme=dark]:bg-[#27272a] data-[theme=dark]:ring-white/10"
    >
      <button
        data-theme={theme}
        className="relative inline-flex h-8 min-w-24 cursor-pointer items-center justify-center gap-2 rounded-full bg-white px-3.5 text-[0.8125rem] leading-none font-medium text-[#202020] capitalize shadow-[0_0_0_1px_rgba(0,0,0,0.09),0_1px_2px_rgba(0,0,0,0.06)] outline-none select-none before:size-2 before:rounded-full before:bg-amber-400 before:shadow-[0_0_6px_rgba(251,191,36,0.7)] after:absolute after:inset-x-0 after:-inset-y-1.5 transition-[transform,background-color,color,box-shadow] duration-150 ease-out motion-reduce:transition-none focus-visible:ring-3 focus-visible:ring-[#3074fe]/40 active:scale-[0.96] data-[theme=dark]:bg-[#1b1b1e] data-[theme=dark]:text-[#fafafa] data-[theme=dark]:shadow-[0_0_0_1px_#29292d,0_2px_6px_0_rgba(0,0,0,0.45)] data-[theme=dark]:before:bg-[#3a7bff] data-[theme=dark]:before:shadow-[0_0_8px_rgba(58,123,255,0.75)] [@media(hover:hover)]:hover:bg-neutral-50 data-[theme=dark]:[@media(hover:hover)]:hover:bg-[#222226]"
        onClick={() =>
          setTheme((prevTheme) => (prevTheme == "light" ? "dark" : "light"))
        }
      >
        {theme}
      </button>
    </div>
  );
};

export default ThemeToggle;
