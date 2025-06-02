

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
---
<p>
The constexpr keyword in C++ is used to indicate that a variable or function can be evaluated at compile time. This enables the compiler to perform computations during the compilation process rather than at runtime, which can lead to improved performance and efficiency.  
Key uses of constexpr: 
<ul>
    
<li>
Compile-time Constants: constexpr can be used to declare variables that are known at compile time. 
</li>
<li>
Compile-time Functions: constexpr functions can be evaluated at compile time if their arguments are also compile-time constants. 
</li>
<li>
Template Arguments: constexpr values can be used as template arguments, enabling more flexible and efficient generic programming.
</li>
<li>
Array Sizes: constexpr values can be used to define the size of arrays, ensuring that the size is known at compile time.

</li>
<li>
Performance Optimization: By performing computations at compile time, constexpr can reduce the runtime overhead of programs.

</li>
</ul>

Benefits of using constexpr: 
<ul>
<li>Improved Performance: Computations performed at compile time avoid runtime overhead. 
</li><li>Increased Code Safety: constexpr enforces compile-time checks, preventing errors that might occur during runtime. </li><li>Better Code Readability: constexpr can make code more explicit and easier to understand, by clearly indicating which values and computations are known at compile time. 
</ul>
Limitations of constexpr: 
<ul>
<li>
</li><li>constexpr functions must adhere to certain restrictions, such as having a single return statement and only using other constexpr functions. 
</li><li>Not all computations can be performed at compile time, limiting the use of constexpr in some cases. 
</li></ul>
    
</p>

---

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

