import { useQuery } from "@tanstack/react-query";
import { todos } from "../libs/api"

interface Todos {
    id: number,
    todo: string | " ",
    completed: boolean,
    userId: string,
}


const fetchTodos = async (): Promise<Todos[]> => {
    const res = await todos.get("/todos");
    return res.data.todos;
}

export const useFetchTodo = () => {
    return useQuery({
        queryKey: ["todos"],
        queryFn: fetchTodos,
        // staleTime: 5*10,
        // refetchInterval: 5 * 10
    });
}