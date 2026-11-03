import { useState } from "react";
import CourseCard from "./components/CourseCard"
import Counter from "./components/Counter";
import ThemeToggle from "./components/ThemeToggle";
import CourseList from "./components/CourseList";
import Input from "./components/Input";

function App() {

  return (
    <>
      <h1>hello</h1>
      <div>
        <Counter />
        <ThemeToggle />

        <CourseCard name="Rahul" price={4990} />
        <CourseCard name="Harkirat" price={2990} />
        <CourseCard name="Dhruv" price={3990} />

        <CourseList />
        <Input/>
      </div>
    </>
  );
}

export default App
