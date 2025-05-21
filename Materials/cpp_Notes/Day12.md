

---

## 🚀 **Day 12: Copy Constructor, Copy Assignment & Move Semantics (C++14/17 Deep Dive)**

---

### 🔷 1. Why Do We Need to Care About Copying and Moving?

In C++, when you copy or assign an object, you're potentially copying **resources** like memory, file handles, or network sockets. If not done correctly, you can get:

- **Double deletions**
- **Memory leaks**
- **Shallow copies**
- **Performance issues**

So, C++ gives you tools to **customize** how objects are copied or moved.

---

### 📘 Let’s Start Simple: The Big Three (Copy Constructor, Copy Assignment, Destructor)

```cpp
class MyClass {
    int* data;
public:
    MyClass(int val) {
        data = new int(val);
        cout << "Constructor\n";
    }

    ~MyClass() {
        delete data;
        cout << "Destructor\n";
    }

    // Copy Constructor
    MyClass(const MyClass& other) {
        data = new int(*other.data);
        cout << "Copy Constructor\n";
    }

    // Copy Assignment
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        cout << "Copy Assignment\n";
        return *this;
    }
};
```

---

### 📊 Diagram: Deep Copy vs Shallow Copy

```
Shallow Copy:
-------------
obj1: [data] → 100
obj2: [data] → 100  (points to same memory!)
--> Double deletion risk!

Deep Copy:
----------
obj1: [data] → 100
obj2: [data] → 100  (different memory, same value)
```

---

### 🔷 2. Rule of Three

If your class manually defines:

- a destructor
- a copy constructor
- or a copy assignment operator

➡️ then you **must define all three**. Otherwise, the compiler-generated versions may break your logic.

---

### 🔷 3. Enter Move Semantics – C++11/14/17 Style

Copying is expensive. What if you **just want to transfer ownership**?

That’s where **move constructors** and **move assignment operators** come in.

---

### ✨ Move Constructor and Move Assignment

```cpp
MyClass(MyClass&& other) noexcept {
    data = other.data;
    other.data = nullptr;
    cout << "Move Constructor\n";
}

MyClass& operator=(MyClass&& other) noexcept {
    if (this != &other) {
        delete data;
        data = other.data;
        other.data = nullptr;
    }
    cout << "Move Assignment\n";
    return *this;
}
```

Now you have **Rule of Five**:

- Destructor
- Copy constructor
- Copy assignment
- Move constructor
- Move assignment

---

### 🔥 Real World Analogy: File Transfer

Copy: You're making a **duplicate of a file**  
Move: You're **cutting and pasting** a file — no copy is left behind

---

### 🔷 4. Using `std::move`

```cpp
MyClass a(10);
MyClass b = std::move(a); // Calls move constructor
```

> ⚠️ After a move, the source (`a`) is in a **valid but unspecified state**

---

### 🔷 5. Rule of Zero (Modern Best Practice)

In modern C++, try not to manage resources directly — use **smart pointers**, containers, etc. Let the compiler do the heavy lifting.

Example using `std::unique_ptr`:

```cpp
class SafeClass {
    std::unique_ptr<int> data;
public:
    SafeClass(int val) : data(std::make_unique<int>(val)) {}
    // No need to write destructor, copy/move constructors!
};
```

---

### 🔷 6. C++17 Enhancements

- `std::optional`, `std::variant` — simplify value management
- Guaranteed copy elision: `return MyClass();` may **not** invoke move or copy at all
- Structured bindings to unpack returns

---

### 🔷 7. Visual Summary of Special Functions

| Function               | Trigger                            |
|------------------------|-------------------------------------|
| Copy Constructor       | `MyClass b = a;`                    |
| Copy Assignment        | `b = a;`                            |
| Move Constructor       | `MyClass b = std::move(a);`        |
| Move Assignment        | `b = std::move(a);`                |
| Destructor             | `delete`, scope exit, etc.         |

---

### 🔶 8. Hands-On Exercise

Create a class `Buffer` with a `char*` buffer:

- Write constructor, destructor
- Implement deep copy constructor
- Add move constructor and move assignment
- Show what happens when you use `std::move`

---

### 📘 9. Real-World Example: Custom String Class

```cpp
class MyString {
    char* str;
public:
    MyString(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    ~MyString() {
        delete[] str;
    }

    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    MyString(MyString&& other) noexcept {
        str = other.str;
        other.str = nullptr;
    }

    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] str;
            str = other.str;
            other.str = nullptr;
        }
        return *this;
    }
};
```

---

### 📚 Homework

1. Implement a class `Document` with file name and content as `char*`
2. Add copy and move constructors
3. Track memory usage before and after moving large objects
4. Explore the difference between shallow copy vs deep copy

---

### 💡 Summary Table

| Concept             | Best Practice                           |
|---------------------|------------------------------------------|
| Rule of 3           | Needed when managing resources manually  |
| Rule of 5           | Add move semantics for performance       |
| Rule of 0           | Use smart pointers, RAII-style classes   |
| `std::move`         | Transfers ownership                      |
| `unique_ptr`        | Avoids manual resource management        |

---

