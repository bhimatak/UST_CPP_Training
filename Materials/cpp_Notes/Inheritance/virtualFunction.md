<h1 align="center">Virtual Functions</h1>
---

## 🔹 Syntax of a Virtual Function

```cpp
class Base {
public:
    virtual void show() {
        std::cout << "Base class show()" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {  // override is optional but good practice
        std::cout << "Derived class show()" << std::endl;
    }
};
```

---

## 🔹 Key Concepts

| Feature                    | Description                                                                                              |
| -------------------------- | -------------------------------------------------------------------------------------------------------- |
| **virtual** keyword        | Tells the compiler to support dynamic binding.                                                           |
| **vtable (Virtual Table)** | Behind the scenes, the compiler creates a table of function pointers for classes with virtual functions. |
| **Polymorphism**           | With base class pointer/reference, you can call derived class methods.                                   |

---

## 🔹 Example: Runtime Polymorphism

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Animal* a;
    Dog d;
    a = &d;

    a->sound();  // Output: Dog barks (calls derived class method)
    return 0;
}
```

---

## 🔹 Why Use Virtual Functions?

1. To implement **runtime polymorphism**.
2. When you want a base class pointer/reference to call the appropriate method in derived classes.
3. To follow **Open/Closed Principle**: open for extension, closed for modification.

---

## 🔹 Notes

* Virtual functions **must be members** of a class.
* Constructors **cannot be virtual**, but destructors **should be virtual** in polymorphic base classes to avoid memory leaks.
* If a class has at least one virtual function, it should have a **virtual destructor**.

---

## 🔹 Pure Virtual Function (Abstract Classes)

If you want to make a function **mandatory** to override, use a **pure virtual function**:

```cpp
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual
};
```

This makes `Shape` an **abstract class** — it cannot be instantiated.

---
