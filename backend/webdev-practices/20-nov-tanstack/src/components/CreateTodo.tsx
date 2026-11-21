import { useCreateTodo } from "../hooks/useCreate";

export default function CreateTodo() {
  const mutation = useCreateTodo();

  return (
    <>
      <div className="rounded-xl border border-black/8 bg-white p-5 shadow-xs shadow-black/5 ring-1 ring-black/5 flex flex-wrap items-center justify-between gap-4 transition-all duration-200">
        {mutation.isPending ? (
          <div className="inline-flex items-center gap-2 text-[13px] font-medium text-neutral-600">
            <span className="size-2 rounded-full bg-[#3074FE] animate-pulse" />
            Adding todo...
          </div>
        ) : (
          <>
            {mutation.isError ? (
              <div className="inline-flex items-center gap-1.5 rounded-lg border border-red-200/80 bg-red-50 px-3 py-1.5 text-xs font-medium text-red-700">
                An error occurred: {mutation.error.message}
              </div>
            ) : null}

            {mutation.isSuccess ? (
              <div className="inline-flex items-center gap-1.5 rounded-full border border-emerald-200/80 bg-emerald-50 px-3 py-1 text-xs font-medium text-emerald-700">
                <span className="size-1.5 rounded-full bg-emerald-500" />
                Todo added!
              </div>
            ) : null}

            <button
              type="button"
              onClick={() => {
                mutation.mutate({ id: new Date(), todo: "Do Laundry" });
              }}
              className="group/button relative inline-flex shrink-0 cursor-pointer items-center justify-center gap-2 rounded-lg bg-[#3074FE] px-4 py-2 text-[13px] font-semibold text-white shadow-xs transition-all duration-150 ease-out hover:bg-[#2563eb] active:scale-[0.98] focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-[#3074FE]/40 ml-auto"
            >
              Create Todo
            </button>
          </>
        )}
      </div>
    </>
  );
}
