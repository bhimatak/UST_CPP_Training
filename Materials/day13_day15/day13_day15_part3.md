#  Part 3  
---

# Part 2: Moving into Advanced C++ Building Blocks

---

# 15. Functions in C++ (Pass by Value vs Pass by Reference)

## Theory/Concept
Functions allow you to **reuse code**.  
You can pass arguments *by value* (copy) or *by reference* (no copy, direct access).

- **Pass by Value**: Copies data. Safe but slower for large objects.
- **Pass by Reference**: No copy. Fast, but needs careful handling to avoid side effects.

## Syntax
```cpp
// Pass by value
void foo(int x);

// Pass by reference
void fooRef(int& x);
```

## Example Code
```cpp
#include<iostream>
using namespace std;

void byValue(int n) {
    n++;
}

void byReference(int& n) {
    n++;
}

int main() {
    int a = 5, b = 5;

    byValue(a);
    byReference(b);

    cout << "By Value (a): " << a << endl;      // Still 5
    cout << "By Reference (b): " << b << endl;  // Now 6
}
```

## Explanation
- `byValue` copies `a` — original not changed.
- `byReference` modifies `b` directly.

## Useful Notes
- Prefer `const &` if you just want to **read** large objects without copying.

Example:
```cpp
void print(const string& name);
```

## Common Pitfalls
- Forgetting `const` can accidentally modify data.
- Returning references to local variables = **undefined behavior** (danger!).

## Real-world Use Case
Optimizing large data handling (like processing a huge list of users).

## More Details
- C++17: `[[nodiscard]]` attribute can force users to handle function return values.

```cpp
[[nodiscard]] int compute();
```

---

# 16. Introduction to Object-Oriented Programming (OOP) in C++

## Theory/Concept
OOP is about modeling real-world **entities** using:
- **Classes** (blueprints)
- **Objects** (instances)
- **Encapsulation**, **Inheritance**, **Polymorphism**

C++ is a *multi-paradigm* language but **OOP is core**.

## Syntax
```cpp
class ClassName {
  private:
    int data;
  public:
    void setData(int d);
    int getData();
};
```

## Example Code
```cpp
#include<iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    void setDetails(string n, int a) {
        name = n;
        age = a;
    }

    void showDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s;
    s.setDetails("Alice", 20);
    s.showDetails();
}
```

## Explanation
Class `Student` has private data. Public methods allow controlled access.

## Useful Notes
- Always keep data private, expose through getters/setters (best practice).
- Constructors can automate object creation.

## Common Pitfalls
- Forgetting to initialize objects leads to garbage/default values.

## Real-world Use Case
Bank account management system — Customer class, Account class.

## More Details
- C++11/14 introduced *default* and *delete* functions.

Example:
```cpp
Student() = default; 
Student(const Student&) = delete;
```
(prevents copying)

---

# 17. Constructors and Destructors

## Theory/Concept
- **Constructor**: Special function to initialize an object.
- **Destructor**: Special function to clean up.

Automatically called when object **created** or **destroyed**.

## Syntax
```cpp
class ClassName {
public:
    ClassName();  // Constructor
    ~ClassName(); // Destructor
};
```

## Example Code
```cpp
#include<iostream>
using namespace std;

class Car {
public:
    Car() {
        cout << "Car created!" << endl;
    }
    ~Car() {
        cout << "Car destroyed!" << endl;
    }
};

int main() {
    Car c;
}
```

## Explanation
`Car` constructor and destructor get automatically called.

## Useful Notes
- Always manage dynamic memory cleanly inside destructors.

## Common Pitfalls
- Forgetting to `delete` dynamically allocated memory (`new`) causes memory leaks.

## Real-world Use Case
Managing network connections (open in constructor, close in destructor).

## More Details
- C++17 allows `constexpr` constructors for compile-time object creation.

Example:
```cpp
struct Point {
    int x, y;
    constexpr Point(int x, int y) : x(x), y(y) {}
};
```

---

# 18. Modern C++17 Features You Should Know

✅ **Structured Bindings**
```cpp
#include<iostream>
#include<tuple>
using namespace std;

tuple<int, string> getInfo() {
    return {1, "GenZ"};
}

int main() {
    auto [id, name] = getInfo(); // 🎯 split tuple into two vars
    cout << id << " " << name;
}
```

✅ **`if constexpr`**
```cpp
template<typename T>
void display(T t) {
    if constexpr (is_integral<T>::value) {
        cout << "Integer" << endl;
    } else {
        cout << "Something else" << endl;
    }
}
```

✅ **Filesystem Library**
```cpp
#include<filesystem>
namespace fs = std::filesystem;

int main() {
    for (auto& entry : fs::directory_iterator(".")) {
        cout << entry.path() << endl;
    }
}
```
(Real-world file and directory handling without external libraries!)

---

# 📚 Quick Recap Table

| Concept             | Key Takeaways |
|---------------------|---------------|
| Functions           | Master pass by value vs reference. |
| Classes & Objects   | Encapsulate data properly. |
| Constructors        | Automate setup of objects. |
| C++17 Modernizations| Cleaner syntax, better optimizations. |
| Filesystem Access   | Easier and more portable file operations. |

---
