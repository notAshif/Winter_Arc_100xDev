interface PropsCard{
    name: string,
    price: number,
}

function CourseCard(props: PropsCard) {
  return (
    <div
      style={{
        border: "1px solid #ccc",
        padding: "16px",
        marginBottom: "12px",
        borderRadius: "8px",
      }}
    >
      <h3>Full Stack Cohort: Winter Arc</h3>
          <p>Instructor: {props.name}</p>
      <p>Price: ₹{props.price}</p>
    </div>
  );
}

export default CourseCard;