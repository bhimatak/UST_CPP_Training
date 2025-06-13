
# C++11, C++14, and C++17 Features Tutorial



---

## Table of Contents

1. Key Terms You Should Know First
2. C++11 Features\
   2.1 Auto Keyword\
   2.2 Range-Based For Loop\
   2.3 nullptr\
   2.4 Lambda Expressions\
   2.5 Smart Pointers\
   2.6 Move Semantics\
   2.7 Uniform Initialization\
   2.8 Strongly-Typed Enums\
   2.9 Static Assert
3. C++14 Features\
   3.1 Binary Literals\
   3.2 Digit Separators\
   3.3 Generic Lambdas\
   3.4 Return Type Deduction\
   3.5 std::make\_unique\
   3.6 Deprecated Attribute\
   3.7 Variable Templates
4. C++17 Features\
   4.1 Structured Bindings\
   4.2 if constexpr\
   4.3 Inline Variables\
   4.4 std::optional\
   4.5 std::variant\
   4.6 std::any\
   4.7 Nested Namespaces\
   4.8 Fold Expressions\
   4.9 std::filesystem

---

## 1. Key Terms You Should Know First

### Deduce

**Meaning:** To determine the type of a variable based on its initializer expression.

**Example:**

```cpp
auto x = 5; // Compiler deduces x to be int
auto y = 3.14; // Compiler deduces y to be double
```

**Why use it?**

- Reduces redundancy
- Improves readability
- Enables generic programming

---

## 2. C++11 Features

### 2.1 Auto Keyword

```cpp
auto x = 10;  // deduced as int
auto y = 3.14; // deduced as double
```

**Why use it?**

- Reduces code verbosity.

### 2.2 Range-Based For Loop

```cpp
for (auto x : {1, 2, 3}) {
    std::cout << x << " ";
}
```

**Use Case:** Iterating over STL containers.

### 2.3 nullptr

```cpp
int* p = nullptr; // Replaces NULL
```

**Why?** Type-safe null pointer.

### 2.4 Lambda Expressions

```cpp
auto add = [](int a, int b) { return a + b; };
std::cout << add(3, 4); // 7
```

**Use Case:** Anonymous functions, callbacks.

### 2.5 Smart Pointers

```cpp
std::unique_ptr<int> p1 = std::make_unique<int>(10);
```

**Why?** Automatic memory management.

### 2.6 Move Semantics

```cpp
std::string s = "hello";
std::string t = std::move(s); // Transfers ownership
```

### 2.7 Uniform Initialization

```cpp
int arr[] {1, 2, 3};
std::vector<int> v {4, 5, 6};
```

### 2.8 Strongly-Typed Enums

```cpp
enum class Color { Red, Green, Blue };
Color c = Color::Red;
```

### 2.9 Static Assert

```cpp
static_assert(sizeof(int) == 4, "Expected int size of 4");
```

---

## 3. C++14 Features

### 3.1 Binary Literals

```cpp
int mask = 0b1010;
```

### 3.2 Digit Separators

```cpp
int val = 1'000'000;
```

### 3.3 Generic Lambdas

```cpp
auto lambda = [](auto x, auto y) { return x + y; };
lambda(1, 2);
```

### 3.4 Return Type Deduction

```cpp
auto multiply(int x, int y) { return x * y; }
```

### 3.5 std::make\_unique

```cpp
auto ptr = std::make_unique<int>(42);
```

### 3.6 Deprecated Attribute

```cpp
[[deprecated]] void oldFunc();
```

### 3.7 Variable Templates

```cpp
template<typename T>
constexpr T pi = T(3.1415);
```

---

## 4. C++17 Features

### 4.1 Structured Bindings

**Description:** Decomposes tuples, pairs, or struct-like objects into individual variables.

**Syntax:**

```cpp
auto [x, y] = std::make_pair(1, 2);
```

**Example:**

```cpp
#include <iostream>
#include <tuple>
int main() {
    std::tuple<int, std::string> t(1, "apple");
    auto [id, name] = t;
    std::cout << id << " " << name << std::endl;
    return 0;
}
```

**Why use it?**

- Improves code readability by eliminating manual unpacking.

### 4.2 if constexpr

**Description:** Enables compile-time branching inside templates.

**Syntax:**

```cpp
if constexpr (condition) {
    // compile-time branch
}
```

**Example:**

```cpp
#include <iostream>
#include <type_traits>
template<typename T>
void print_type(const T& value) {
    if constexpr (std::is_integral<T>::value) {
        std::cout << "Integral: " << value << std::endl;
    } else {
        std::cout << "Other: " << value << std::endl;
    }
}
int main() {
    print_type(42);
    print_type(3.14);
    return 0;
}
```

**Why use it?**

- Enables more efficient and safer compile-time decisions.

### 4.3 Inline Variables

**Description:** Allows variables defined in header files to be shared across translation units without linker errors.

**Syntax:**

```cpp
inline int myVar = 10;
```

**Example:**

```cpp
// header.h
inline int count = 0;
```

**Why use it?**

- Solves the One Definition Rule (ODR) issue for global constants.

### 4.4 std::optional

**Description:** Represents a value that might be absent.

**Syntax:**

```cpp
std::optional<int> val = 42;
```

**Example:**

```cpp
#include <iostream>
#include <optional>
std::optional<int> getValue(bool valid) {
    if (valid) return 10;
    return std::nullopt;
}
int main() {
    auto value = getValue(true);
    if (value)
        std::cout << "Value: " << *value << std::endl;
    else
        std::cout << "No value" << std::endl;
    return 0;
}
```

**Why use it?**

- Replaces raw pointers or sentinel values when a value may be absent.

### 4.5 std::variant

**Description:** Type-safe union that can hold one of many specified types.

**Syntax:**

```cpp
std::variant<int, std::string> data;
```

**Example:**

```cpp
#include <iostream>
#include <variant>
int main() {
    std::variant<int, std::string> var;
    var = "Hello";
    std::cout << std::get<std::string>(var) << std::endl;
    var = 100;
    std::cout << std::get<int>(var) << std::endl;
    return 0;
}
```

**Why use it?**

- Useful in scenarios requiring dynamic type handling.

### 4.6 std::any

**Description:** Can store any type of value.

**Syntax:**

```cpp
std::any a = 5;
```

**Example:**

```cpp
#include <iostream>
#include <any>
int main() {
    std::any value = 42;
    std::cout << std::any_cast<int>(value) << std::endl;
    value = std::string("Hello");
    std::cout << std::any_cast<std::string>(value) << std::endl;
    return 0;
}
```

**Why use it?**

- Stores heterogeneous types, similar to Python’s dynamic typing.

### 4.7 Nested Namespaces

**Description:** Concise syntax for nested namespaces.

**Syntax:**

```cpp
namespace A::B::C {
    void func();
}
```

**Example:**

```cpp
namespace project::module::utils {
    void greet() {
        std::cout << "Hello from utils!" << std::endl;
    }
}
int main() {
    project::module::utils::greet();
    return 0;
}
```

**Why use it?**

- Reduces redundancy in deeply nested codebases.

### 4.8 Fold Expressions

**Description:** Simplifies operations over parameter packs.

**Syntax:**

```cpp
template<typename... Args>
auto sum(Args... args) {
    return (args + ...);
}
```

**Example:**

```cpp
#include <iostream>
template<typename... Args>
auto sum(Args... args) {
    return (args + ...);
}
int main() {
    std::cout << sum(1, 2, 3, 4) << std::endl; // 10
    return 0;
}
```

**Why use it?**

- Provides elegant syntax for variadic templates.

### 4.9 std::filesystem

**Description:** Provides facilities for performing operations on file systems.

**Syntax:**

```cpp
#include <filesystem>
namespace fs = std::filesystem;
```

**Example:**

```cpp
#include <iostream>
#include <filesystem>
int main() {
    std::filesystem::create_directory("my_folder");
    std::cout << "Directory created." << std::endl;
    return 0;
}
```

**Why use it?**

- Makes file and directory manipulation standardized and portable.


