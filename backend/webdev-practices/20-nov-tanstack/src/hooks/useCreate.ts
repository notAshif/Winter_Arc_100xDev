import { useMutation, useQueryClient } from "@tanstack/react-query";
import { todos } from "../libs/api";

interface CreateTodoInput {
  id?: number | Date | string;
  todo: string;
  completed?: boolean;
  userId?: number | string;
}

interface CreateTodoResponse {
  id: number;
  todo: string;
  completed: boolean;
  userId: number;
}

const createTodo = async (newTodo: CreateTodoInput): Promise<CreateTodoResponse> => {
  const res = await todos.post("/todos/add", {
    todo: newTodo.todo,
    completed: newTodo.completed ?? false,
    userId: Number(newTodo.userId) || 1,
  });
  return res.data;
};

export const useCreateTodo = () => {
  const queryClient = useQueryClient();

  return useMutation({
    mutationKey: ["todos"],
    mutationFn: createTodo,
    onSuccess: () => {
      queryClient.invalidateQueries({ queryKey: ["todos"] });
    },
  });
};
