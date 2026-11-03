import React from 'react';

const courses = [
  { id: "c1", title: "Node.js & Express", price: 2999 },
  { id: "c2", title: "MongoDB & Prisma", price: 3499 },
  { id: "c3", title: "System Design", price: 4999 },
];

const CourseList = () => {
    return (
      <div className="mx-4 my-5 max-w-md overflow-hidden rounded-xl bg-neutral-100 p-1 antialiased shadow-[0_1px_3px_rgba(0,0,0,0.04)] ring-1 ring-black/6">
        <h1 className="px-3 pt-2 pb-1.5 text-sm leading-normal font-semibold tracking-[-0.015em] text-balance text-[#202020] tabular-nums">
          All courses ({courses.length})
        </h1>
        <div className="mx-1 mb-1.5 rounded-md bg-neutral-200/65 px-2.5 py-1.5 font-mono text-xs leading-relaxed wrap-anywhere text-[#71717a]">
          {JSON.stringify(courses)}
        </div>
        {courses.map((courses) => (
          <div
            key={courses.id}
            className="not-last:mb-1 rounded-lg bg-white px-3.5 py-3 shadow-[0_1px_2px_rgba(0,0,0,0.05)] ring-1 ring-black/8 transition-[background-color,box-shadow] duration-150 ease-out motion-reduce:transition-none [@media(hover:hover)]:hover:bg-neutral-50/70 [@media(hover:hover)]:hover:ring-black/14"
          >
            <strong className="flex items-center justify-between gap-3 font-normal">
              <h1 className="min-w-0 truncate text-sm leading-snug font-medium tracking-[-0.01em] text-[#202020]">
                {courses.title}
              </h1>
              <p className="shrink-0 rounded-full bg-neutral-100 px-2.5 py-0.5 text-xs leading-snug font-semibold text-[#202020] tabular-nums ring-1 ring-black/8 ring-inset">
                {courses.price}
              </p>
            </strong>
          </div>
        ))}
      </div>
    );
}

export default CourseList;
