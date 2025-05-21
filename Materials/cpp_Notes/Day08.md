

---

## 🚀 **Day 8: Static Members, Friend Functions & Namespaces in C++14/17 – Enhancing Class Utility & Code Organization**

---

### 1. Static Members – One Instance for All

**Static members** belong to the **class**, not to any individual object. They're shared across all objects.

#### 🔹 Static Data Members:
- Defined inside the class.
- Declared `static`, but must be **defined outside** the class.

```cpp
class Account {
private:
    static int accountCount;

public:
    Account() { ++accountCount; }
    static int getAccountCount(); // static member function
};

int Account::accountCount = 0;

int Account::getAccountCount() {
    return accountCount;
}
```

> Useful for counting objects, maintaining global settings, or constants.

---

### 2. Static Member Functions

- Can only access other **static members**
- Can be called **without an object**

```cpp
Account::getAccountCount(); // ✅ No object needed
```

---

### 3. Constexpr with Static (C++14/17)

```cpp
class Config {
public:
    static constexpr int maxUsers = 100;
};
```

> `constexpr` static members can be initialized **in-class** (from C++14 onwards)!

---

### 4. Friend Functions – Controlled Access

**Friend functions** can access `private` and `protected` members of a class.

#### Syntax:
```cpp
class Box {
private:
    int width;
public:
    Box(int w) : width(w) {}
    friend void showWidth(Box b); // declaration
};

void showWidth(Box b) {
    cout << "Width: " << b.width << endl;
}
```

> Useful when you need close cooperation between two classes or functions without breaking encapsulation.

---

### 5. Friend Class

Allows one class to access another’s private/protected members.

```cpp
class Engine;

class Car {
    friend class Engine; // full access to Car's internals
private:
    int speed;
};
```

---

### 6. Namespaces – Avoid Name Collisions

A **namespace** allows grouping of identifiers (classes, functions, variables) under a **unique scope**.

```cpp
namespace Geometry {
    const double PI = 3.14;
    double area(double r) { return PI * r * r; }
}
```

Usage:
```cpp
double a = Geometry::area(5);
```

#### 🔹 `using` Directive:
```cpp
using namespace Geometry;
cout << area(5);
```

> Avoid in **headers** to prevent name clashes!

---

### 7. Nested Namespaces (C++17)

```cpp
namespace School::Department::Physics {
    void teach() { cout << "Quantum Mechanics\n"; }
}
```

> Cleaner and easier than traditional nested namespace syntax.

---

### 8. Anonymous Namespaces (Internal Linkage)

```cpp
namespace {
    int secretCode = 1234;
}
```

> Accessible only within the file – similar to `static` in C.

---

### 9. Real-World Example – Logger Utility

```cpp
namespace Logger {
    void log(const string& msg) {
        cout << "[LOG]: " << msg << endl;
    }
}
```

Used throughout project:
```cpp
Logger::log("App started.");
```

---

### 10. Best Practices

✅ Use static members for **shared resources**  
✅ Use friend functions **judiciously** – don’t overuse  
✅ Use namespaces for **logical grouping**  
✅ Prefer `constexpr` static members for **compile-time constants**  
✅ Avoid `using namespace` in global scope of headers

---

### 11. Hands-On Lab

**Task:**  
- Create a class `Counter` with:
  - Static int `count`
  - Constructor increments `count`
  - Static function `getCount()`

- Add a friend function `resetCounter(Counter&)` to reset the counter value

- Wrap the entire code in a `namespace app`

---

### 12. Quiz

**Q1:** Can a static function access non-static data?  
> **A:** No

**Q2:** Are friend functions members of a class?  
> **A:** No

**Q3:** What does `namespace` do?  
> **A:** Groups related code and avoids name clashes

**Q4:** True/False: Friend functions break encapsulation  
> **A:** False – they allow **controlled access**

---

### 13. Mini Project

**Project:**  
Build a **Temperature Tracker** system with:

- Class `Temperature` with static member for unit (Celsius/Fahrenheit)
- Static function `setUnit()`
- Friend function `convertToFahrenheit(Temperature)`
- Encapsulate the whole module under `namespace Weather`

---

### 14. Summary

- **Static** members are shared across all objects  
- **Friend functions/classes** help build trusted components  
- **Namespaces** prevent collisions and organize code  
- C++14/17 gives `constexpr` static members and clean nested namespaces

---

### 15. Homework

- Build a `MathLib` namespace with static functions: `add()`, `subtract()`, `square()`
- Create a class `Vector2D` with static count of instances
- Implement friend function to compare two vectors

---

### 16. Resources

- [Static Members – GeeksforGeeks](https://www.geeksforgeeks.org/static-keyword-cpp/)
- [Friend Functions](https://cplusplus.com/doc/tutorial/inheritance/)
- [Namespaces Reference](https://en.cppreference.com/w/cpp/language/namespace)

---

