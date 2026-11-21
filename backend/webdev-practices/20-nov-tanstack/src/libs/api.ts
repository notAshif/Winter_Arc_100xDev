import axios from "axios";

export const todos = await axios.create({
    baseURL: 'https://dummyjson.com',
});

todos.interceptors.response.use(
    function (response) {
        return Promise.resolve(response);
    },

    function (error) {
        if (axios.isAxiosError(error)) {
            error.message = error.response?.data.message || "Could not reach the server"
        }

        return Promise.reject(error);
    }
);