const express = require("express");
const path = require("path");
const cors = require("cors");
const { v4: uuidv4 } = require("uuid");

const app = express();
const PORT = process.env.PORT || 8080;

app.use(cors());
app.use(express.json());

const captchas = new Map();
const puzzles = new Map();

function generateCaptchaText(length = 6) {
  const chars = "ABCDEFGHJKLMNPQRSTUVWXYZ23456789";
  let text = "";
  for (let i = 0; i < length; i += 1) {
    text += chars.charAt(Math.floor(Math.random() * chars.length));
  }
  return text;
}

function pickRandom(arr) {
  return arr[Math.floor(Math.random() * arr.length)];
}

function randInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

function generatePuzzle() {
  const generators = [
    // 1) Math addition
    () => {
      const a = randInt(2, 50);
      const b = randInt(2, 50);
      return { question: `What is ${a} + ${b}?`, answer: String(a + b), type: "math" };
    },
    // 2) Math subtraction
    () => {
      const a = randInt(20, 99);
      const b = randInt(1, a - 1);
      return { question: `What is ${a} - ${b}?`, answer: String(a - b), type: "math" };
    },
    // 3) Math multiplication
    () => {
      const a = randInt(2, 12);
      const b = randInt(2, 12);
      return { question: `What is ${a} × ${b}?`, answer: String(a * b), type: "math" };
    },
    // 4) Count vowels
    () => {
      const words = ["ELEPHANT", "UMBRELLA", "KEYBOARD", "ORANGE", "UNIVERSE", "COMPUTER", "DINOSAUR", "BEAUTIFUL", "ALGORITHM", "MOLECULE"];
      const word = pickRandom(words);
      const vowels = word.split("").filter((c) => "AEIOU".includes(c)).length;
      return { question: `How many vowels in "${word}"?`, answer: String(vowels), type: "count" };
    },
    // 5) Sequence (add constant)
    () => {
      const start = randInt(1, 10);
      const step = randInt(2, 7);
      const seq = [start, start + step, start + 2 * step];
      const ans = start + 3 * step;
      return { question: `What comes next: ${seq.join(", ")}, ?`, answer: String(ans), type: "sequence" };
    },
    // 6) Word length
    () => {
      const words = ["PYTHON", "CASTLE", "GARDEN", "BRIDGE", "PLANET", "ROCKET", "FOREST", "WINDOW", "SUNSET", "PIRATE"];
      const word = pickRandom(words);
      return { question: `How many letters in "${word}"?`, answer: String(word.length), type: "count" };
    },
    // 7) Largest number
    () => {
      const nums = [randInt(10, 99), randInt(10, 99), randInt(10, 99)];
      return { question: `Which is the largest: ${nums.join(", ")}?`, answer: String(Math.max(...nums)), type: "logic" };
    },
    // 8) Reverse word
    () => {
      const words = ["CAT", "DOG", "SUN", "MAP", "CUP", "PEN", "NET", "TOP", "JAR", "BUS"];
      const word = pickRandom(words);
      const reversed = word.split("").reverse().join("");
      return { question: `Spell "${word}" backwards:`, answer: reversed.toLowerCase(), type: "word" };
    },
    // 9) Missing letter
    () => {
      const words = ["APPLE", "MANGO", "GRAPE", "LEMON", "MELON", "PEACH", "BERRY", "GUAVA", "PLUMB", "OLIVE"];
      const word = pickRandom(words);
      const idx = randInt(1, word.length - 2);
      const display = word.substring(0, idx) + "_" + word.substring(idx + 1);
      return { question: `Fill the blank: ${display}`, answer: word[idx].toLowerCase(), type: "word" };
    },
    // 10) Odd one out (numbers)
    () => {
      const even = randInt(1, 20) * 2;
      const options = [even, even + 2, even + 4, even + 5];
      // shuffle
      for (let i = options.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [options[i], options[j]] = [options[j], options[i]];
      }
      return { question: `Which is the odd one out: ${options.join(", ")}?`, answer: String(even + 5), type: "logic" };
    },
  ];

  return pickRandom(generators)();
}

app.get("/health", (req, res) => {
  res.json({ status: "ok" });
});

app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "index.html"));
});

app.post("/captcha", (req, res) => {
  const id = uuidv4();
  const text = generateCaptchaText();

  captchas.set(id, text.toLowerCase());

  console.log(`[TEXT CAPTCHA] Generated | ID: ${id} | Text: ${text}`);

  res.json({
    id,
    captcha: text,
    message: "Please type the text exactly as shown.",
  });
});

// ─── Puzzle CAPTCHA ───
app.post("/puzzle", (req, res) => {
  const id = uuidv4();
  const puzzle = generatePuzzle();

  puzzles.set(id, puzzle.answer.toLowerCase());

  console.log(`[PUZZLE CAPTCHA] Generated | ID: ${id} | Type: ${puzzle.type} | Q: ${puzzle.question} | A: ${puzzle.answer}`);

  res.json({
    id,
    question: puzzle.question,
    type: puzzle.type,
  });
});

app.post("/puzzle/validate", (req, res) => {
  const { id, answer } = req.body || {};

  if (!id || typeof answer !== "string") {
    return res.status(400).json({
      success: false,
      error: "Missing 'id' or 'answer' in request body.",
    });
  }

  const expected = puzzles.get(id);

  if (!expected) {
    return res.status(400).json({
      success: false,
      error: "Puzzle not found or already used.",
    });
  }

  puzzles.delete(id);

  const ok = expected === answer.trim().toLowerCase();

  if (!ok) {
    console.log(`[PUZZLE CAPTCHA] FAILED | ID: ${id} | Expected: ${expected} | Got: ${answer}`);
    return res.json({
      success: false,
      message: "Wrong answer! Try again.",
    });
  }

  console.log(`[PUZZLE CAPTCHA] PASSED | ID: ${id}`);
  return res.json({
    success: true,
    message: "Puzzle solved correctly!",
  });
});

app.post("/captcha/validate", (req, res) => {
  const { id, answer } = req.body || {};

  if (!id || typeof answer !== "string") {
    return res.status(400).json({
      success: false,
      error: "Missing 'id' or 'answer' in request body.",
    });
  }

  const expected = captchas.get(id);

  if (!expected) {
    return res.status(400).json({
      success: false,
      error: "CAPTCHA not found or already used.",
    });
  }

  captchas.delete(id);

  const ok = expected === answer.toLowerCase();

  if (!ok) {
    console.log(`[TEXT CAPTCHA] FAILED | ID: ${id} | Expected: ${expected} | Got: ${answer}`);
    return res.json({
      success: false,
      message: "CAPTCHA validation failed.",
    });
  }

  console.log(`[TEXT CAPTCHA] PASSED | ID: ${id}`);
  return res.json({
    success: true,
    message: "CAPTCHA validation succeeded.",
  });
});

app.listen(PORT, () => {
  // eslint-disable-next-line no-console
  console.log(`CAPTCHA server listening on http://localhost:${PORT}`);
});
