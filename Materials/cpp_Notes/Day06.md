Perfect — we’re now entering the heart of **Object-Oriented Programming** with **Encapsulation** and **Abstraction**, aligned with **C++14/17**. Let's make **Day 6** a powerful launchpad for understanding classes, data hiding, and design clarity.

---

## 🚀 **Day 6: Encapsulation & Abstraction in C++14/17 – Mastering Class Design**

---

### 1. Introduction to Encapsulation

**Encapsulation** means **binding data and functions** that operate on the data into a single unit – the **class**. It restricts direct access to internal data for better **security** and **maintainability**.

> **Analogy:** Think of a capsule – it hides the medicine (data) inside a shell (class) and controls how it’s released (methods).

---

### 2. Introduction to Abstraction

**Abstraction** is about **hiding internal implementation** details and **exposing only what’s necessary**. It allows us to work at a high level without worrying about low-level logic.

> **Analogy:** You drive a car using the steering wheel and pedals, not by tweaking engine pistons.

---

### 3. Basic Class Structure

```cpp
class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount(string name, double bal) : owner(name), balance(bal) {}

    void deposit(double amount);
    double getBalance() const;
};
```

### 4. Access Specifiers

| Specifier | Meaning                        | Use Case                             |
|----------|----------------------------------|--------------------------------------|
| `private`| Accessible only within class     | Data hiding                          |
| `public` | Accessible anywhere              | Interface to the world               |
| `protected`| Accessible in derived classes | Used in inheritance scenarios        |

---

### 5. Inline Member Functions

You can define small methods inside the class definition:

```cpp
class User {
private:
    string name;
public:
    void setName(const string& n) { name = n; }
};
```

> These are **implicitly inline**.

---

### 6. Modern C++ Enhancements

#### ✅ In-class Member Initialization (C++11+)
```cpp
class Product {
    int id = 100;
    string name = "Unknown";
};
```

#### 🧠 `constexpr` Constructors (C++14+)
```cpp
class Point {
    int x, y;
public:
    constexpr Point(int x, int y) : x(x), y(y) {}
};
```

#### 🔒 `= delete` and `= default` (C++11+)
```cpp
class NoCopy {
public:
    NoCopy() = default;
    NoCopy(const NoCopy&) = delete;
};
```

> These give precise control over how objects are copied or default-constructed.

---

### 7. Real-World Use Case: Student Management

| Feature         | Encapsulation | Abstraction             |
|----------------|---------------|--------------------------|
| Name, marks     | `private`      | Hidden from direct access |
| `setMarks()`    | `public`       | Controlled modification   |
| `getGrade()`    | `public`       | Abstracts grading logic   |

---

### 8. Best Practices

✅ Always keep data members `private`  
✅ Only expose necessary functions (`public`)  
✅ Use inline for short methods, separate for long ones  
✅ Prefer `const` member functions for getters  
✅ Use `= default`, `= delete`, and in-class initializations for safety

---

### 9. Hands-On Lab

**Task:**  
Create a class `Employee` with:
- `private` members: name, salary
- Public methods: `setSalary()`, `getSalary()`, `display()`

Add:
- Inline methods for `getSalary()`
- `constexpr` constructor
- In-class initialization of `salary` to 0.0

---

### 10. Quiz

**Q1:** Which access specifier promotes encapsulation the most?  
> **A:** `private`

**Q2:** What keyword defines compile-time constants in constructors?  
> **A:** `constexpr`

**Q3:** True or False: Public data members violate encapsulation  
> **A:** True

**Q4:** What specifier prevents copy construction?  
> **A:** `= delete`

---

### 11. Daily Challenge / Mini Project

**Project:**  
Build a **Library Book Management System** with:
- Class `Book` (title, author, pages – private)
- Constructor with `in-class initialization`
- Member functions: `displayInfo()`, `borrowBook()`, `returnBook()`
- Bonus: Use a `vector<Book>` to store collection and access using methods only (no public data!)

---

### 12. Summary

- **Encapsulation**: Data hiding using `private` and `public`
- **Abstraction**: Simplifying interface, hiding logic
- C++14/17 empowers this with **`constexpr`, `= default`, in-class init**
- Design clean classes with public interfaces and hidden data

---

### 13. Homework

- Convert Day 3 Banking System to use `BankAccount` class  
- Implement `deposit()`, `withdraw()`, and `showBalance()` as encapsulated methods  
- Use `in-class initialization` for balance = 0  
- Add a `display()` method using `inline` syntax

---

### 14. Resources

- [Encapsulation & Abstraction](https://www.geeksforgeeks.org/abstraction-encapsulation-oops/)
- [C++ Classes and Objects](https://cplusplus.com/doc/tutorial/classes/)
- [Modern C++ OOP Best Practices](https://en.cppreference.com/)

---
