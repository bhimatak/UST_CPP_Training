

---

## 🚀 **Day 5: Function Overloading and Recursion in C++14/17**

---

### 1. Introduction to Function Overloading

**Function Overloading** allows multiple functions to share the same name but with **different parameter lists** (type or count). It boosts **code clarity** and **flexibility**.

> **Real-World Analogy:** Think of “print” in an office – you can print a doc, image, or PDF, but the machine adapts based on input.

---

### 2. Syntax and Examples

```cpp
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}
```

#### Output:
```cpp
cout << add(2, 3);        // Calls int version
cout << add(2.5, 3.1);    // Calls double version
```

✅ **Modern C++ Tip:** Use `auto` or `decltype(auto)` in generic function overloads

---

### 3. Default Arguments + Overloading

⚠️ **Avoid combining default arguments with overloading in ambiguous cases**

```cpp
void greet(string name, string prefix = "Mr.") {}
void greet(string name) {}  // ❌ Ambiguous with default argument
```

---

### 4. Recursion: The Concept

**Recursion** is when a function **calls itself**, directly or indirectly.

> **Real-World Analogy:** Think of nested Russian dolls – each contains a smaller one until it can't anymore.

---

### 5. Syntax: Basic Recursion

```cpp
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

---

### 6. C++14/17 Recursive Enhancements

#### `constexpr` Recursive Function (C++14/17)

```cpp
constexpr int fib(int n) {
    return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
}
```

> This enables compile-time Fibonacci calculation!

#### Using `auto` for cleaner code

```cpp
auto square(int x) {
    return x * x;
}
```

---

### 7. Tail Recursion (Optimization Concept)

Tail recursion occurs when the recursive call is the **last thing** in the function. Some compilers optimize it (though C++ doesn't **guarantee** this).

```cpp
int tailSum(int n, int acc = 0) {
    return (n == 0) ? acc : tailSum(n - 1, acc + n);
}
```

> For large `n`, use iteration instead to avoid stack overflow.

---

### 8. Real-World Use Case: Order Processing System

| Task                       | Function Type         | Example                     |
|---------------------------|------------------------|-----------------------------|
| Calculate total price     | Overloaded             | `calcPrice(int qty)` vs. `calcPrice(int qty, double discount)` |
| Compute nested tax levels | Recursive              | `applyTax()` calls itself for tiers |
| Display info in stages    | Recursive or iterative | `displayStage(int stage)` |

---

### 9. Best Practices

✅ Keep recursion base cases clear and tight  
✅ Avoid overloading with conflicting default values  
✅ Use recursion only when natural — prefer iteration for efficiency  
✅ Leverage `auto` and `constexpr` in overloads and recursion  
✅ Avoid deep recursion in production (consider stack limits)

---

### 10. Hands-On Lab

**Task:**  
1. Write an overloaded function `area()` for:
   - Circle (`radius`)
   - Rectangle (`length`, `breadth`)
   - Square (`side`)

2. Write a recursive function to:
   - Calculate factorial
   - Print a countdown

---

### 11. Quiz

**Q1:** Can two overloaded functions differ only by return type?  
> **A:** No

**Q2:** What's the key risk with recursion?  
> **A:** Stack overflow if not properly terminated

**Q3:** Which C++ keyword supports compile-time recursion?  
> **A:** `constexpr`

**Q4:** What’s the last thing a tail-recursive function does?  
> **A:** Makes the recursive call

---

### 12. Daily Challenge / Mini Project

**Project:**  
Build a **Math Helper Utility**:
- Overloaded `calculate()` function for:
  - Square root, power, factorial
- Use recursion for factorial
- Use `auto` and `constexpr` where appropriate

**Bonus:** Add a menu using `switch` and loop to make it interactive

---

### 13. Summary

- **Overloading** enhances reusability and clarity  
- **Recursion** is powerful but needs careful control  
- Use **modern syntax**: `auto`, `constexpr`, and function templates  
- Understand when to **choose recursion vs. iteration**

---

### 14. Homework

- Create an overloaded function for salary calculation (basic, with bonus, with tax)
- Write a recursive function to compute the **nth Fibonacci number**
- Implement factorial using **both** iteration and recursion — compare results

---

### 15. Resources

- [Function Overloading](https://www.geeksforgeeks.org/function-overloading-c/)
- [Recursion in C++](https://cplusplus.com/doc/tutorial/functions2/)
- [Tail Recursion & Optimization](https://en.wikipedia.org/wiki/Tail_call)

---
