import { useState } from "react";
import CourseCard from "./CourseCard"

function App() {

  // let count = 0;
  const [count, setCount] = useState(0);
  const [theme, setTheme] = useState("light");

  function handleIncrement() {
    // setCount(count + 1);
    setCount((prevCount) => prevCount + 1);
    // setCount((prevCount) => prevCount + 1);
    // setCount((prevCount) => prevCount + 1);
    // setCount(count + 1);
    // setCount(count + 1);
    console.log("count in memory is now:", count);
  }


  return (
    <>
      <h1>hello</h1>
      <div>
        <h2>Count: {count}</h2>
        <button
          className="bg-red-500 border p-2 rounded-md"
          onClick={handleIncrement}
        >
          Increment
        </button>
        <button
          className="bg-sky-700 border p-2 rounded-md"
          onClick={() =>
            setTheme((prevTheme) => (prevTheme == "light" ? "dark" : "light"))
          }
        >
          {theme}
        </button>
      </div>
      <CourseCard name="Rahul" price={4990} />
      <CourseCard name="Harkirat" price={2990} />
      <CourseCard name="Dhruv" price={3990} />
    </>
  );
}

export default App
