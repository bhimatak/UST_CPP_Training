<h1 align="center"> CPP Templates</h1>
<p>
What templates are and why they are used

Syntax of function and class templates

In-depth theory and explanations

Practical code examples

Real-time use cases

Benefits and limitations
</p>
---

# 🧠 C++ Templates: A Comprehensive Tutorial

---

## 📌 1. What Are Templates?

**Templates** in C++ allow us to **write generic and reusable code**. Instead of writing multiple versions of a function or class to handle different data types (like `int`, `float`, `double`, etc.), we can write a **template** that works with any data type.

Think of templates as **"type-independent blueprints"** for functions or classes.

---

## 🎯 2. Why Use Templates?

### 🔧 Without Templates:

You'd have to write multiple versions of the same function:

```cpp
int max(int a, int b) { return (a > b) ? a : b; }
float max(float a, float b) { return (a > b) ? a : b; }
double max(double a, double b) { return (a > b) ? a : b; }
```

### ✅ With Templates:

You write it **once**, and it works for all types:

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

---

## 🧬 3. Function Templates

### 📘 Syntax:

```cpp
template <typename T>
T function_name(T arg1, T arg2) {
    // function logic
}
```

**Alternative keyword:** `class` can be used instead of `typename` (they're interchangeable in this context).

### ✅ Example:

```cpp
#include <iostream>
using namespace std;

template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max of 10 and 20: " << maxValue(10, 20) << endl;
    cout << "Max of 4.5 and 3.3: " << maxValue(4.5, 3.3) << endl;
    cout << "Max of 'a' and 'z': " << maxValue('a', 'z') << endl;
    return 0;
}
```

---

## 🧱 4. Class Templates

### 📘 Syntax:

```cpp
template <typename T>
class ClassName {
private:
    T data;
public:
    ClassName(T val) : data(val) {}
    void display() {
        cout << "Data: " << data << endl;
    }
};
```

### ✅ Example:

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Box {
    T value;
public:
    Box(T val) : value(val) {}
    void show() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Box<int> intBox(10);
    Box<string> strBox("Hello Template");

    intBox.show();
    strBox.show();

    return 0;
}
```

---

## 🧪 5. Real-Time Use Case: Template Stack Class

### 🔄 Problem:

You want to implement a **stack** that works with any type: `int`, `float`, `string`, etc.

### ✅ Solution: Use a class template

```cpp
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> elements;
public:
    void push(T elem) {
        elements.push_back(elem);
    }

    void pop() {
        if (!elements.empty())
            elements.pop_back();
    }

    T top() {
        return elements.back();
    }

    bool isEmpty() {
        return elements.empty();
    }
};

int main() {
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    cout << "Top of intStack: " << intStack.top() << endl;

    Stack<string> strStack;
    strStack.push("C++");
    strStack.push("Templates");
    cout << "Top of strStack: " << strStack.top() << endl;

    return 0;
}
```

---

## 🧩 6. Template Specialization

Sometimes you want a custom behavior for a **specific data type**.

### ✅ Example:

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Printer {
public:
    void print(T val) {
        cout << "Value: " << val << endl;
    }
};

// Specialization for char*
template <>
class Printer<char*> {
public:
    void print(char* val) {
        cout << "String: " << val << endl;
    }
};

int main() {
    Printer<int> p1;
    p1.print(100);

    Printer<char*> p2;
    p2.print((char*)"Hello");

    return 0;
}
```

---

## 🧠 7. Theory Behind Templates

### ✔ Compile-Time Polymorphism:

Templates are a form of **compile-time polymorphism** (unlike virtual functions which are runtime).

### ✔ Type Safety:

Templates provide **type safety** because the compiler checks type usage during compilation.

### ✔ Code Reusability:

Write once — use for many types.

### ✔ Performance:

Since template code is generated at compile-time, there is **no runtime overhead**.

---

## ⚠️ 8. Limitations of Templates

* **Code Bloat**: The compiler generates code for every type used, which can increase binary size.
* **Harder Debugging**: Compiler errors with templates can be long and difficult to interpret.
* **Not Runtime-Friendly**: You can't create templates with types decided at runtime.

---

## 🚀 9. Summary Table

| Feature                 | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| Function Template       | A generic function for multiple types                        |
| Class Template          | A generic class for different data types                     |
| Template Specialization | Custom behavior for specific type(s)                         |
| Compile-Time Benefit    | Type-checked and efficient                                   |
| Real-Time Use           | Generic containers (e.g., `Stack<T>`, `List<T>`)             |
| Language Standard       | Templates exist since **C++98**, enhanced in later standards |

---

## 📂 10. Real-Time Applications

| Domain                          | Use Case                                                   |
| ------------------------------- | ---------------------------------------------------------- |
| STL (Standard Template Library) | All containers like `vector`, `map`, `queue` use templates |
| Game Dev                        | Generic math libraries (Vector2D<T>, Matrix<T>)            |
| Networking                      | Packet serialization templates for all types               |
| GUI Libraries                   | Widget classes templated for data types                    |

---

## 📘 Homework / Practice

1. Create a function template `minValue(T a, T b)` that returns the smaller value.
2. Create a `Pair<T1, T2>` class template that stores two values of different types.
3. Implement a templated `Queue` using `std::list`.

---
