

---

## 🚀 **Day 14: Templates – Generic Programming in C++14/17**

---

### 🔷 1. What Are Templates?

Templates allow you to **write code once** and use it with **any data type**.

You’ve seen this in STL: `std::vector<int>`, `std::vector<string>`, etc. That’s templates in action.

Templates reduce **code duplication** and increase **type safety**, all while preserving **performance**.

---

### 📘 2. Function Templates

Instead of writing:

```cpp
int max(int a, int b) { return a > b ? a : b; }
float max(float a, float b) { return a > b ? a : b; }
```

You write:

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

**Usage:**

```cpp
cout << max(3, 5);       // int
cout << max(3.1, 2.8);   // double
cout << max('a', 'z');   // char
```

🔹 `typename` and `class` are interchangeable in templates.

---

### 🔧 3. Class Templates

```cpp
template <class T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    T get() const { return value; }
};
```

**Usage:**

```cpp
Box<int> intBox(10);
Box<string> strBox("Hello");

cout << intBox.get();    // 10
cout << strBox.get();    // Hello
```

---

### 📊 Diagram: Templates Conceptual View

```
Template Box<T>:
----------------
Box<int>       → T = int       → value = 10
Box<string>    → T = string    → value = "Hi"
Box<double>    → T = double    → value = 3.14
```

Compiler creates a **separate class** for each type used.

---

### 🔷 4. Default Template Arguments (C++14/17)

```cpp
template <typename T = int>
class DefaultBox {
    T value;
public:
    DefaultBox(T v) : value(v) {}
    T get() const { return value; }
};
```

**Usage:**

```cpp
DefaultBox<> defBox(42);     // T is int
DefaultBox<double> dBox(3.14);
```

---

### 🔷 5. Function Template Overloading

You can combine normal and template versions:

```cpp
void print(int x) {
    cout << "int: " << x << endl;
}

template <typename T>
void print(T x) {
    cout << "template: " << x << endl;
}
```

**Call:**

```cpp
print(10);       // int version
print(3.14);     // template version
```

---

### 🔶 6. Template Specialization

Sometimes generic logic won’t work for all types. That’s when you **specialize**:

```cpp
template <typename T>
class Printer {
public:
    void print(T value) {
        cout << "Generic: " << value << endl;
    }
};

// Specialization for char*
template <>
class Printer<char*> {
public:
    void print(char* value) {
        cout << "Char*: " << value << endl;
    }
};
```

---

### 🔶 7. Template Recursion (Intro to Metaprogramming)

Example: **Factorial at compile time**

```cpp
template<int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0> {
    static const int value = 1;
};

cout << Factorial<5>::value;  // 120
```

---

### 💥 Real World: Generic Stack

```cpp
template <typename T>
class Stack {
    vector<T> elements;
public:
    void push(T val) { elements.push_back(val); }
    void pop() {
        if (!elements.empty()) elements.pop_back();
    }
    T top() const { return elements.back(); }
    bool empty() const { return elements.empty(); }
};
```

**Usage:**

```cpp
Stack<int> intStack;
intStack.push(10);
intStack.push(20);
cout << intStack.top();  // 20
```

---

### ✨ C++17 Goodies: `auto` & Deduction Guides

```cpp
template <typename T1, typename T2>
auto add(T1 a, T2 b) {
    return a + b;
}

auto result = add(10, 3.14);  // deduces double
```

➡️ Also supports **template argument deduction** for constructors (CTAD):

```cpp
template<typename T>
class Wrapper {
public:
    Wrapper(T) {}
};

Wrapper w(42); // deduces Wrapper<int>
```

---

### 🛠️ Hands-On Tasks

1. Write a class template `Pair<T1, T2>` that holds two types and prints them.
2. Implement a `Matrix<T>` template class with:
   - Dynamic 2D array
   - Overload `+`, `*`
   - Output operator

3. Create a `Sorter<T>` class template that:
   - Sorts array using Bubble Sort or STL sort
   - Allows functor comparison

---

### 🧠 Design Patterns with Templates

- **Policy-Based Design**
- **CRTP (Curiously Recurring Template Pattern)**
- **Traits Classes**

> We’ll explore these in advanced days (Day 25+)

---

### 📚 Homework

- Implement a `SmartArray<T>` template class with:
  - Bounds checking
  - `[]` operator
  - Dynamic resizing

- Write a compile-time power function: `Power<N, E>` using template recursion

---

### 💡 Summary Table

| Concept                  | Description                           |
|--------------------------|----------------------------------------|
| Function Templates       | Generic functions                      |
| Class Templates          | Generic classes                        |
| Specialization           | Customize for specific types           |
| CTAD (C++17)             | Deduce template type from constructor  |
| Template Metaprogramming| Compile-time logic (like recursion)    |

---

