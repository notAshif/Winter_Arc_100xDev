import { NavLink } from "react-router";

export default function Navbar() {
  return (
    <nav style={{ display: "flex", gap: "20px", padding: "20px" }}>
      <NavLink to="/" end>
        All Courses
      </NavLink>
      <NavLink to="/purchases">My Courses</NavLink>
      <NavLink to="/login">Login</NavLink>
    </nav>
  );
}
