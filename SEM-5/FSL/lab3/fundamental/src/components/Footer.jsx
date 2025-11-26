export default function Footer({ year }) {
  return (
    <footer className="bg-dark text-light text-center py-3 mt-auto">
      <div className="container">
        &copy; {year} Built with React + Bootstrap. All rights reserved.
      </div>
    </footer>
  );
}
