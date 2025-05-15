## C++ Advanced Concepts: Functions, References, Exceptions, Strings, and Namespaces (with C++14/17 Enhancements)

---

### 1. FUNCTIONS IN C++

Functions are blocks of code designed to perform specific tasks. In C++, functions allow modular, reusable code, improving maintainability and readability.

#### 1.1 Function Types

* **Value-returning functions**: Return a result after processing.
* **Void functions**: Execute code without returning a value.

#### 1.2 Function Declaration and Definition

```cpp
int add(int a, int b); // Declaration
int add(int a, int b) { return a + b; } // Definition
```

#### 1.3 Default Arguments

Default values for parameters.

```cpp
void display(int a, int b = 10); // b has default value
```

#### 1.4 Function Overloading

Same function name with different parameter lists.

```cpp
int add(int a, int b);
double add(double a, double b);
```

#### 1.5 Inline Functions

Improves performance by substituting function code at call site.

```cpp
inline int square(int x) { return x * x; }
```

#### 1.6 Recursive Functions

A function calling itself to solve subproblems.

```cpp
int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}
```

#### 1.7 Variadic Templates (C++11+)

Allows functions to accept variable number of parameters.

```cpp
template<typename T, typename... Args>
void log(T first, Args... args) {
    std::cout << first << " ";
    log(args...);
}
```

---

### 2. REFERENCES

References are aliases for variables. They are crucial for modifying values without copying them.

#### 2.1 Lvalue References

```cpp
int a = 5;
int& ref = a;  // ref is an alias to a
```

#### 2.2 Const Lvalue References

```cpp
const int& cref = a;  // read-only alias
```

#### 2.3 Rvalue References (C++11+)

Used for move semantics, allowing resource transfer without copying.

```cpp
int&& rref = 10; // binds to rvalue
```

#### 2.4 Reference Collapsing (C++11+)

Occurs during template instantiation. Universal references are formed.

```cpp
template<typename T>
void forwarder(T&& arg) {
    process(std::forward<T>(arg));
}
```

---

### 3. EXCEPTIONS AND ERROR HANDLING

Exception handling separates error-handling logic from main logic.

#### 3.1 Try-Catch-Throw

```cpp
try {
    throw std::runtime_error("Failure");
} catch (const std::exception& e) {
    std::cerr << e.what();
}
```

#### 3.2 Custom Exception Classes

```cpp
class MyError : public std::exception {
    const char* what() const noexcept override {
        return "My custom error";
    }
};
```

#### 3.3 noexcept (C++11+)

Marks functions that do not throw exceptions.

```cpp
void myFunc() noexcept { }
```

---

### 4. STRINGS

#### 4.1 std::string

`std::string` is a dynamic string class handling memory automatically.

```cpp
std::string s = "Hello";
s += " World";  // Concatenation
```

#### 4.2 Useful Methods

* `length()`, `size()` – Get length
* `substr(pos, len)` – Get substring
* `find(str)` – Search string
* `c_str()` – Convert to C-string

#### 4.3 Iterating

```cpp
for (char c : s) std::cout << c;
```

#### 4.4 string\_view (C++17)

A non-owning view into a string.

```cpp
void greet(std::string_view name) {
    std::cout << "Hello " << name;
}
```

---

### 5. NAMESPACES

Namespaces help organize code and prevent name conflicts.

#### 5.1 Creating Namespaces

```cpp
namespace Geometry {
    double area(double r) { return 3.14 * r * r; }
}
```

#### 5.2 Using Namespace

```cpp
using namespace Geometry;
```

#### 5.3 Nested Namespaces (C++17)

```cpp
namespace Company::Department::Team {
    void report() {}
}
```

#### 5.4 Namespace Alias

```cpp
namespace geo = Geometry;
geo::area(5);
```

---

---

### Conclusion

These topics—functions, references, exception handling, strings, and namespaces—form the foundation of robust C++ development. With C++14 and C++17, the language introduces more efficient, expressive, and safer mechanisms, enhancing productivity and code quality.

