
---

## 🚀 **Day 4: Functions in C++14/17 – Basics, Default Arguments, and Inline Functions**

---

### 1. Introduction to Functions

A **function** is a reusable block of code that performs a specific task. Functions improve code readability, reduce redundancy, and support modular design.

> **Real-World Analogy:** Think of functions like coffee machines – you give input (beans, water), and it performs a task (brewing), then gives you output (coffee)!

---

### 2. Function Syntax

```cpp
return_type function_name(parameters) {
    // body
    return value;
}
```

#### Example:
```cpp
int add(int a, int b) {
    return a + b;
}
```

---

### 3. Function Declaration vs. Definition

- **Declaration (Prototype):** Tells the compiler about the function's signature.
- **Definition:** Provides the actual implementation.

```cpp
int add(int, int);  // Declaration

int main() {
    cout << add(3, 4);
}

int add(int x, int y) {  // Definition
    return x + y;
}
```

---

### 4. Default Arguments

C++ allows parameters to have **default values**.

```cpp
void greet(string name = "Guest") {
    cout << "Hello, " << name << "!\n";
}

greet();          // Hello, Guest!
greet("Alice");   // Hello, Alice!
```

> Default arguments must be specified **from right to left**.

---

### 5. Inline Functions

Used for **small, frequently-used functions** to reduce function call overhead.

```cpp
inline int square(int x) {
    return x * x;
}
```

> The compiler *may* ignore the `inline` keyword — it's just a suggestion.

---

### 6. C++14/17 Function Enhancements

#### 🧠 **Return Type Deduction (C++14)**

```cpp
auto multiply(int x, int y) {
    return x * y;
}
```

> Use `auto` to reduce boilerplate in function declarations.

#### ✅ **`constexpr` Functions (C++14/17)**  
Enable compile-time evaluation for performance.

```cpp
constexpr int cube(int x) {
    return x * x * x;
}
```

---

### 7. Real-World Use Case: Tax Calculator

| Task                 | Function                | Description                     |
|----------------------|-------------------------|---------------------------------|
| Input user salary    | `getSalary()`           | Takes user input                |
| Calculate tax        | `calculateTax()`        | Uses conditional logic          |
| Display result       | `displayTaxInfo()`      | Modular output formatting       |

---

### 8. Best Practices

✅ Keep functions short and single-purpose  
✅ Use `auto` for inferred return types (C++14)  
✅ Prefer `constexpr` when the logic is pure and constant  
✅ Avoid default arguments in function definitions (keep them in declarations)  
✅ Use `inline` only for tiny logic (≤ 1–2 lines)

---

### 9. Hands-On Lab

**Task:**  
Create a function-based program that:
- Takes marks in 3 subjects
- Calculates total, average, and grade
- Uses `auto` for return types
- `displayResult()` should be an `inline` function

---

### 10. Quiz

**Q1:** What is the correct syntax for a function with default args?  
> **A:** `void func(int x, int y = 10);`

**Q2:** True or False: `inline` guarantees inlining at compile-time  
> **A:** False

**Q3:** What keyword enables compile-time function evaluation?  
> **A:** `constexpr`

**Q4:** Which feature allows C++14 to infer function return types?  
> **A:** `auto`

---

### 11. Daily Challenge / Mini Project

**Project:**  
Build a **Mini-Grade Processing System**:
- Functions: `getMarks()`, `calcGrade()`, `displayReport()`
- Use default parameters for elective subjects
- Use `constexpr` to define grade boundaries

**Bonus:** Add `inline` and `auto` in appropriate places.

---

### 12. Summary

- Functions are building blocks of clean code  
- Use default args, `inline`, and `constexpr` to optimize usage  
- C++14/17 offers `auto` and compile-time function power  
- Modularizing with functions improves maintainability and reuse

---

### 13. Homework

- Rewrite Day 3’s Banking System using separate functions  
- Add logging via a `logTransaction(string msg)` function  
- Try combining `auto`, `inline`, and `constexpr` in small helper functions

---

### 14. Resources

- [Functions in C++](https://www.geeksforgeeks.org/functions-in-cpp/)
- [C++14 `auto` in functions](https://en.cppreference.com/w/cpp/language/function)
- [Default Parameters Guide](https://cplusplus.com/doc/tutorial/functions2/)

---

