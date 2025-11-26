import Navbar from "./components/Navbar";
import Footer from "./components/Footer";
import './App.css';

function App() {
  return (
    <div className="d-flex flex-column min-vh-100">
      <Navbar brand="ZyberThreads" />

      <main className="flex-grow-1 d-flex align-items-center bg-light text-dark">
        <div className="container text-center">
          <h1 className="display-4 fw-bold">Welcome to Our Landing Page</h1>
          <p className="lead mb-4">
            A beautifully simple React + Bootstrap layout with clean design and great UX.
          </p>
          <a href="#learn-more" className="btn btn-primary btn-lg">
            Get Started
          </a>
        </div>
      </main>

      <Footer year={new Date().getFullYear()} />
    </div>
  );
}

export default App;
