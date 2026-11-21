/*
  A query is a declarative dependency on an asynchronous source of data that is tied to a 
  unique keyA query is a declarative dependency on an asynchronous source of data that is tied to a unique key. 

  We can use query for these method get data from server (GET, POST) if method are modifies data so use mutation.

  To subscribe to a query in your components or custom hooks, call the useQuery hook with at least:

  - A unique key for the query

  - A function that returns a promise that:
      Resolves the data, or
      Throws an error

  `
  import { useQuery } from '@tanstack/react-query'

  function App() {
    const info = useQuery({ queryKey: ['todos'], queryFn: fetchTodoList })
  }
  `

  Also query provide us bunch of function like isPending, isError, data, isLoading, so on...
  
  Now comes on mutation
  - is use to Unlike queries, mutations are typically used to create/update/delete data or perform server side-effects. 
  For this purpose, TanStack Query exports a useMutation hook.

  syntax: 
  function App() {
  const mutation = useMutation({
    mutationFn: (newTodo) => {
      return axios.post('/todos', newTodo)
    },
  })

  return (
    <div>
      {mutation.isPending ? (
        'Adding todo...'
      ) : (
        <>
          {mutation.isError ? (
            <div>An error occurred: {mutation.error.message}</div>
          ) : null}

          {mutation.isSuccess ? <div>Todo added!</div> : null}

          <button
            onClick={() => {
              mutation.mutate({ id: new Date(), title: 'Do Laundry' })
            }}
          >
            Create Todo
          </button>
        </>
      )}
    </div>
  )
}`
*/

import CreateTodo from "./components/CreateTodo";
import { useFetchTodo } from "./hooks/useFetchTodos"

function App() {

  const { data, isError, isPending, error } = useFetchTodo();

  if (isPending) {
    return <span>Loading...</span>
  }

  if (isError) {
    return <span>Something went wrong { error.message }.</span>
  }

  return (
    <>
      <div className="min-h-screen bg-[#f7f7f7] p-4 sm:p-6 lg:p-8 grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 xl:grid-cols-4 gap-4 max-w-7xl mx-auto items-start">
        <CreateTodo/>
        {data.map((td) => (
          <div
            key={td.id}
            className="group relative grid grid-cols-2 items-start gap-y-3 rounded-xl border border-black/8 bg-white p-5 shadow-xs shadow-black/5 ring-1 ring-black/5 transition-all duration-200 hover:-translate-y-0.5 hover:border-black/15 hover:shadow-md hover:ring-black/10"
          >
            <p className="col-start-1 row-start-1 w-fit rounded-md border border-[#3074FE]/20 bg-[#3074FE]/10 px-2 py-0.5 font-mono text-xs font-semibold text-[#3074FE] before:content-['#']">
              {td.id}
            </p>
            <p className="col-span-2 row-start-2 text-[15px] font-semibold leading-snug tracking-[-0.01em] text-neutral-900 group-hover:text-black">
              {td.todo}
            </p>
            <p
              className={`col-start-2 row-start-1 justify-self-end inline-flex items-center rounded-full px-2.5 py-0.5 text-xs font-medium border ${
                td.completed
                  ? "bg-emerald-50 text-emerald-700 border-emerald-200/80 before:content-['Completed']"
                  : "bg-amber-50 text-amber-700 border-amber-200/80 before:content-['Pending']"
              }`}
            >
              {td.completed}
            </p>
            <p className="col-span-2 row-start-3 mt-1 flex items-center border-t border-neutral-100 pt-3 text-xs font-medium text-neutral-400 before:content-['User_#']">
              {td.userId}
            </p>
          </div>
        ))}
      </div>
    </>
  );
}

export default App
