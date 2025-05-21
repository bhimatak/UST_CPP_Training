

---

## 🚀 **Day 7: Constructors & Destructors in C++14/17 – Lifecycle Management**

---

### 1. Introduction

Every object in C++ has a **lifecycle**: it's **created**, used, and eventually **destroyed**.  
Constructors and destructors are special functions that **automate this process**.

---

### 2. Constructors: The Beginning

A **constructor** is a special function that **initializes an object** when it's created.

#### Syntax:
```cpp
class Car {
public:
    Car() { cout << "Car constructed\n"; }
};
```

---

### 3. Types of Constructors

| Type                    | Purpose                                           |
|-------------------------|---------------------------------------------------|
| **Default Constructor** | No parameters                                     |
| **Parameterized**       | Accepts arguments                                 |
| **Copy Constructor**    | Creates copy from another object                  |
| **Move Constructor**    | Transfers resources (C++11+)                      |
| **`constexpr` Constructor** | Compile-time instantiation (C++14+)             |

---

### 4. Examples of Constructors

```cpp
class Student {
    string name;
    int age;

public:
    Student() : name("Unknown"), age(0) {}                      // Default
    Student(string n, int a) : name(n), age(a) {}              // Parameterized
    Student(const Student& s) = default;                       // Copy
};
```

---

### 5. Destructors: The End

A **destructor** is called automatically when an object goes out of scope or is deleted.

#### Syntax:
```cpp
~Student() {
    cout << "Destructor called\n";
}
```

> Only **one destructor** per class and it **cannot be overloaded**.

---

### 6. Modern Enhancements in C++14/17

#### ✅ `constexpr` Constructor
```cpp
class Point {
    int x, y;
public:
    constexpr Point(int a, int b) : x(a), y(b) {}
};
```

> Enables constant expression objects at compile-time.

#### ✅ `= default` & `= delete`

```cpp
class A {
public:
    A() = default;              // Keep default behavior
    A(const A&) = delete;       // Prevent copying
};
```

---

### 7. Rule of 3/5/0 (Modern C++ Design Principles)

- If you define **any** of:
  - Destructor
  - Copy Constructor
  - Copy Assignment Operator  
  → You should define all three (Rule of 3)

- With **move semantics**: Rule of **5**

- If no resource management: Rule of **0**

---

### 8. Real-World Use Case: File Handler

```cpp
class File {
    FILE* f;
public:
    File(const char* name) { f = fopen(name, "r"); }
    ~File() { fclose(f); }
};
```

> Constructor opens file, destructor closes it – neat & safe!

---

### 9. Best Practices

✅ Use initializer lists for constructors  
✅ Mark trivial constructors/destructors as `= default`  
✅ Use `= delete` to disable unwanted operations  
✅ Avoid logic inside destructors unless absolutely necessary  
✅ Prefer `constexpr` constructors when possible

---

### 10. Hands-On Lab

**Task:**  
Create a class `Employee` with:
- `name`, `salary` as private members
- Default and parameterized constructors
- Destructor that logs object destruction
- `= default` for copy constructor
- `= delete` for assignment

Add a `display()` method to show employee details

---

### 11. Quiz

**Q1:** How many destructors can a class have?  
> **A:** One

**Q2:** Which C++ keyword prevents object copying?  
> **A:** `= delete`

**Q3:** True or False: A `constexpr` constructor can be evaluated at runtime  
> **A:** False (Only compile-time)

**Q4:** What happens if no constructor is defined?  
> **A:** Compiler provides a default one

---

### 12. Daily Challenge / Mini Project

**Project:**  
Build a **Vehicle Inventory System**:
- Class `Vehicle` with name, price
- Multiple constructors for input flexibility
- Destructor that logs vehicle removal
- Add logic to track number of active vehicles using a `static` member

---

### 13. Summary

- **Constructor**: Initializes objects (default, parameterized, copy, move)
- **Destructor**: Cleans up on object deletion
- **C++14/17** adds power via `constexpr`, `= default`, `= delete`
- Follow **Rule of 3/5/0** for clean class design

---

### 14. Homework

- Create a `Book` class with default and parameterized constructors  
- Implement a destructor that displays a message  
- Add a static member `bookCount` to track number of books

---

### 15. Resources

- [C++ Constructors](https://www.geeksforgeeks.org/constructors-cpp/)
- [Destructors Guide](https://cplusplus.com/doc/tutorial/classes2/)
- [Modern C++ Constructor Practices](https://en.cppreference.com/w/cpp/language/constructor)

---

