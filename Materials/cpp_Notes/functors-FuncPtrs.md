
---

### 🔹 Function Pointer

A **function pointer** is a pointer that points to a function. You can use it to call the function indirectly.

#### ✅ Syntax Example:

```cpp
#include <iostream>
using namespace std;

void greet() {
    cout << "Hello from function pointer!" << endl;
}

int main() {
    void (*funcPtr)() = greet; // function pointer
    funcPtr(); // calling function through pointer
    return 0;
}
```

#### 📌 Key Points:

* Only stores the address of a free function (not a class member function).
* Cannot maintain any state.
* Simple and efficient, but not flexible.

---

### 🔹 Functor (Function Object)

A **functor** is an object of a class or struct that overloads the `operator()`.

#### ✅ Syntax Example:

```cpp
#include <iostream>
using namespace std;

class Greet {
public:
    void operator()() {
        cout << "Hello from functor!" << endl;
    }
};

int main() {
    Greet greetObj;
    greetObj(); // looks like a function call
    return 0;
}
```

#### 📌 Key Points:

* It's an object that behaves like a function.
* Can **maintain state** (store values in data members).
* More flexible than function pointers.
* Frequently used with STL algorithms.

---

### 🔁 Quick Comparison Table

| Feature         | Function Pointer              | Functor (Function Object)           |
| --------------- | ----------------------------- | ----------------------------------- |
| Type            | Pointer to a function         | Object of a class with `operator()` |
| Maintains State | ❌ No                          | ✅ Yes                               |
| Object-Oriented | ❌ Not really                  | ✅ Fully supports OOP                |
| Performance     | ✅ Slightly better (no object) | 🔄 Slight overhead (object call)    |
| Use with STL    | 🔄 Limited                    | ✅ Commonly used                     |

---

### 🧠 Summary

| If you need                                                         | Use              |
| ------------------------------------------------------------------- | ---------------- |
| Simple function calling                                             | Function pointer |
| Stateful or parameterized behavior                                  | Functor          |
| Compatibility with STL algorithms like `std::sort`, `std::for_each` | Functor          |
| Closures and inline logic (in modern C++)                           | Lambda functions |

---

