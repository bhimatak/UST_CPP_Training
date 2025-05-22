
---

## 🧠 **Day 19: Templates in Modern C++ – Functions, Classes, Variadic Templates, and Type Traits**

---

### 🧩 1. What Are Templates?

Templates let you **write code once** and use it with **any data type**. This supports **generic programming**.

#### 📦 Function Template

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

#### Usage:

```cpp
cout << add<int>(3, 4);       // 7
cout << add<string>("A", "B"); // AB
```

You can omit `<int>` — the compiler will deduce it.

---

### 🧱 2. Class Templates

You can define **generic data structures**, like a custom vector or stack:

```cpp
template <typename T>
class MyStack {
    vector<T> data;
public:
    void push(T value) { data.push_back(value); }
    T pop() {
        T temp = data.back();
        data.pop_back();
        return temp;
    }
};
```

#### Usage:

```cpp
MyStack<int> intStack;
intStack.push(10);
cout << intStack.pop(); // 10

MyStack<string> strStack;
strStack.push("Hello");
cout << strStack.pop(); // Hello
```

---

### 🛠 Real-World Use Case: Type-Independent Logger

```cpp
template <typename T>
void log(const T& msg) {
    cout << "[LOG] " << msg << endl;
}
```

Use it for strings, numbers, or custom types with `operator<<`.

---

### 🔀 3. Template Specialization

Customize behavior for specific types.

```cpp
template <typename T>
class Printer {
public:
    void print(T val) { cout << val << endl; }
};

// Specialization for bool
template <>
class Printer<bool> {
public:
    void print(bool val) {
        cout << (val ? "true" : "false") << endl;
    }
};
```

#### Usage:

```cpp
Printer<int>().print(5);       // 5
Printer<bool>().print(true);   // true
```

---

### 🎯 4. Variadic Templates – Accept Multiple Types

Handle **arbitrary number of arguments** (like `printf` in C):

```cpp
template <typename T>
void printAll(const T& t) {
    cout << t << endl;
}

template <typename T, typename... Args>
void printAll(const T& first, const Args&... rest) {
    cout << first << " ";
    printAll(rest...); // recursive unpack
}
```

#### Usage:

```cpp
printAll(1, 2.5, "Hello", true);
```

**Output**: `1 2.5 Hello 1`

---

### 🧠 Real-World Use Case: Logger Utility

```cpp
template <typename... Args>
void logAll(const Args&... args) {
    (cout << ... << args) << endl; // C++17 fold expression
}
```

#### Usage:

```cpp
logAll("[INFO] ", "User ID: ", 1024, ", Status: ", true);
```

---

### 🔬 5. Template Metaprogramming + Type Traits

C++ templates are **Turing-complete**, and with `type_traits`, you can create code that behaves differently at compile-time.

#### 📦 `std::is_integral`

```cpp
template <typename T>
void checkType(const T& val) {
    if constexpr (is_integral<T>::value) {
        cout << "Integral type\n";
    } else {
        cout << "Not integral\n";
    }
}
```

#### Usage:

```cpp
checkType(5);       // Integral type
checkType(3.14);    // Not integral
```

---

### 🧩 Template with Multiple Parameters

```cpp
template <typename T, typename U>
class Pair {
    T first;
    U second;
public:
    Pair(T a, U b): first(a), second(b) {}
    void print() {
        cout << first << ", " << second << endl;
    }
};
```

#### Usage:

```cpp
Pair<string, int> p("Alice", 30);
p.print(); // Alice, 30
```

---

### 💡 Use Case: Type-Safe Configuration Wrapper

```cpp
template <typename T>
class ConfigValue {
    T value;
public:
    ConfigValue(T v): value(v) {}
    T get() const { return value; }
};

ConfigValue<int> timeout(30);
ConfigValue<string> host("localhost");
```

---

### 🔥 Type Traits in Action – Enable Function Only for Integers

```cpp
template <typename T>
typename enable_if<is_integral<T>::value, T>::type
increment(T x) {
    return x + 1;
}
```

---

### 🛡️ Error: SFINAE – Substitution Failure Is Not An Error

This allows template overloads to fail **gracefully** when they don't match.

---

### 🧪 Exercises

1. Create a function template `minOfTwo()` that works for any type.
2. Build a `Matrix<T>` class that supports addition.
3. Write a variadic `debug()` function that prints all values.
4. Use `enable_if` to create a function only available for floating-point numbers.

---

### 📘 Homework Challenge

Build a **Generic Cache** class using class templates:

- Stores data in `unordered_map<Key, Value>`
- Supports `get(key)`, `put(key, value)`
- Works for any type of `Key` and `Value`

---

### 📌 Summary Table

| Feature                | Description                               |
|------------------------|-------------------------------------------|
| Function Templates     | Generic functions for any type            |
| Class Templates        | Generic classes                           |
| Specialization         | Custom behavior for specific types        |
| Variadic Templates     | Functions/classes with multiple arguments |
| Type Traits            | Inspect/limit types at compile time       |
| `enable_if`, `if constexpr` | Conditional compilation              |

---

---

