import { Route, Routes } from "react-router";
import Home from "./pages/Home";
import CourseDetail from "./pages/CourseDetail";
import Login from "./pages/Login";
import Purchases from "./pages/Purchases";

function App() {
  return (
    <Routes>
      <Route path="/" element={<Home />} />
      <Route path="/courses" element={<CourseDetail />} />
      <Route path="/courses/:courseId" element={<CourseDetail />} />
      <Route path="/login" element={<Login />} />
      <Route path="/purchases" element={<Purchases />} />
    </Routes>
  );
}

export default App;
