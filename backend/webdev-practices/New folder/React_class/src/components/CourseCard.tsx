interface PropsCard{
    name: string,
    price: number,
}

function CourseCard(props: PropsCard) {
  return (
    <article className="@container mx-4 mb-3 max-w-md rounded-xl border-4 border-neutral-100 bg-white bg-clip-padding p-4 antialiased shadow-[inset_0_0_0_1px_rgba(0,0,0,0.08),0_0_0_1px_rgba(0,0,0,0.05),0_2px_6px_-1px_rgba(0,0,0,0.06)] transition-[box-shadow,transform] duration-150 ease-out motion-reduce:transition-none [@media(hover:hover)]:hover:-translate-y-0.5 [@media(hover:hover)]:hover:shadow-[inset_0_0_0_1px_rgba(0,0,0,0.14),0_0_0_1px_rgba(0,0,0,0.07),0_8px_20px_-6px_rgba(0,0,0,0.1)]">
      <h3 className="text-[1.0625rem] leading-snug font-semibold tracking-[-0.015em] text-balance text-[#202020]">
        Full Stack Cohort: Winter Arc
      </h3>
      <p className="mt-1.5 text-sm leading-normal text-[#71717a]">
        Instructor:{" "}
        <span className="font-medium text-[#202020]">{props.name}</span>
      </p>
      <p className="mt-3.5 flex flex-col gap-1.5 border-t border-black/6 pt-3 text-xs leading-normal font-medium text-[#71717a] @xs:flex-row @xs:items-center @xs:justify-between">
        Price:{" "}
        <span className="inline-flex w-fit items-center rounded-full bg-[#ebf1ff] px-2.5 py-0.5 text-[0.8125rem] leading-snug font-semibold text-[#1e4fd6] tabular-nums ring-1 ring-[#2563eb]/20 ring-inset">
          ₹{props.price}
        </span>
      </p>
    </article>
  );
}

export default CourseCard;
