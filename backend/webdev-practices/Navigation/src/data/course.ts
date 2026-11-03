export interface Course{
    id: string;
    title: string;
    price: number;
};

export const courses: Course[] = [
    { id: "1", title: "Full Stack Cohort", price: 4999 },
    { id: "2", title: "React Fundamentals", price: 1999 },
    { id: "3", title: "Node.js, Express & Zod", price: 2999 },
];