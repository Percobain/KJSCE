// script.js

// 1. Variables and Data Types
let num1 = 42, num2 = 3.14
let str1 = "Hello", str2 = 'World'
let bool1 = true, bool2 = false
console.log(num1, typeof num1)
console.log(num2, typeof num2)
console.log(str1, typeof str1)
console.log(str2, typeof str2)
console.log(bool1, typeof bool1)
console.log(bool2, typeof bool2)

function calculate(a, b) {
  a = Number(a)
  b = Number(b)
  console.log("Add:", a + b)
  console.log("Subtract:", a - b)
  console.log("Multiply:", a * b)
  console.log("Divide:", b !== 0 ? a / b : "Cannot divide by 0")
}
document.getElementById("calculateBtn").addEventListener("click", () => {
    const numA = document.getElementById("numA").value;
    const numB = document.getElementById("numB").value;
    calculate(numA, numB);
});

// 3. Grade Classification
function classifyGrade(marks) {
  const resultElement = document.getElementById("gradeResult");
  if (marks < 0 || marks > 100) {
      resultElement.textContent = "Invalid marks";
  } else if (marks >= 90) {
      resultElement.textContent = "Excellent";
  } else if (marks >= 75) {
      resultElement.textContent = "Good";
  } else if (marks >= 50) {
      resultElement.textContent = "Average";
  } else {
      resultElement.textContent = "Fail";
  }
}
document.getElementById("classifyBtn").addEventListener("click", () => {
    const marks = Number(document.getElementById("marksInput").value);
    classifyGrade(marks);
});

// 4. Loop Comparison
for (let i = 1; i <= 10; i++) if (i !== 5) console.log("for", i)
let j = 1
while (j <= 10) {
  if (j !== 5) console.log("while", j)
  j++
}
let k = 1
do {
  if (k !== 5) console.log("do-while", k)
  k++
} while (k <= 10)

// 5. Sum of Even Numbers
let sum = 0
for (let i = 1; i <= 100; i++) if (i % 2 === 0) sum += i
console.log("Sum of evens:", sum)

// 6. Fibonacci Sequence
function fib(n) {
  let a = 0, b = 1
  while (a <= n) {
    console.log(a)
    let temp = a + b
    a = b
    b = temp
  }
}
fib(50)

// 7. Array of Students
let students = [
  { name: "A", age: 20, marks: 85 },
  { name: "B", age: 22, marks: 92 },
  { name: "C", age: 19, marks: 75 }
]
students.sort((a, b) => b.marks - a.marks)
console.log(students)
console.log("Top scorer:", students[0])

// 8. Binary Search
function binarySearch(arr, target) {
  let low = 0, high = arr.length - 1
  while (low <= high) {
    let mid = Math.floor((low + high) / 2)
    if (arr[mid] === target) return mid
    else if (arr[mid] < target) low = mid + 1
    else high = mid - 1
  }
  return -1
}
console.log(binarySearch([1, 3, 5, 7, 9], 5))

// 9. Array Analysis
function analyzeArray(arr) {
  let min = Math.min(...arr)
  let max = Math.max(...arr)
  return { min, max }
}
console.log(analyzeArray([4, 2, 7, 1]))

// 10. Recursion for Factorial
function factorial(n) {
  if (n < 0) return "Factorial not defined for negative numbers";
  if (n <= 1) return 1
  return n * factorial(n - 1)
}
console.log(factorial(5))

// 11. Object with Methods
let Book = {
  title: "JS Basics",
  author: "John",
  price: 500,
  getDiscountedPrice(rate) {
    return this.price * (1 - rate)
  },
  summary() {
    return `${this.title} by ${this.author} costs ₹${this.price}`
  }
}
console.log(Book.getDiscountedPrice(0.1))
console.log(Book.summary())

// 12. DOM Text Manipulation
function changeText() {
  let p = document.getElementById("text")
  p.textContent = "Text Changed"
  p.style.color = "green"
  p.style.fontWeight = "bold"
}
document.getElementById("changeTextBtn").addEventListener("click", changeText);

// 13. Dynamic List Update
function addItem() {
  let input = document.getElementById("listInput")
  if (input.value.trim() === "") return
  let li = document.createElement("li")
  li.textContent = input.value
  document.getElementById("list").appendChild(li)
  input.value = ""
}
document.getElementById("addItemBtn").addEventListener("click", addItem);

// 14. Event-Based Visibility Toggle
let box = document.getElementById("toggleBox")
let btn = document.getElementById("toggleBtn")
btn.addEventListener("click", () => {
  if (box.style.display === "none") {
    box.style.display = "block"
    btn.textContent = "Hide"
  } else {
    box.style.display = "none"
    btn.textContent = "Show"
  }
})

// 15. Real-Time Form Validation
let emailInput = document.getElementById("emailInput")
let error = document.getElementById("emailError")
emailInput.addEventListener("keyup", () => {
  let valid = /^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(emailInput.value)
  if (valid) {
    error.textContent = ""
    emailInput.style.borderColor = "green"
  } else {
    error.textContent = "Invalid Email"
    emailInput.style.borderColor = "red"
  }
})
