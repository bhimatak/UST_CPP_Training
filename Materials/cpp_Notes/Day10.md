

---

## 🚀 **Day 10: Abstract Classes, Interfaces & RTTI in C++14/17 – Building for Flexibility and Safety**

---

### 🔷 1. What Is an Abstract Class?

An **abstract class** is a class that **cannot be instantiated**. It's meant to provide a **base interface** for derived classes. It contains **at least one pure virtual function**.

```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};
```

> 📌 Think of it as a **template** or **blueprint**: You can’t create a generic "Shape", but you can have specific shapes like `Circle`, `Rectangle`, etc.

---

### 🔷 2. Pure Virtual Functions

A **pure virtual function** forces derived classes to implement it.

```cpp
virtual void draw() = 0;
```

This makes `Shape` an **interface-like class** — a contract every subclass must follow.

---

### 🔷 3. Real-World Analogy: UI Components

Imagine building a GUI framework:

```cpp
class UIComponent {
public:
    virtual void render() = 0;
};

class Button : public UIComponent {
public:
    void render() override {
        cout << "Rendering Button\n";
    }
};

class TextBox : public UIComponent {
public:
    void render() override {
        cout << "Rendering TextBox\n";
    }
};
```

Usage:
```cpp
vector<UIComponent*> elements = { new Button(), new TextBox() };

for (UIComponent* e : elements) {
    e->render();  // Polymorphic call
}
```

---

### 🔷 4. Abstract Classes vs. Interfaces (C++ Style)

- **C++ doesn’t have a separate interface keyword** like Java.
- But you can **simulate interfaces** using abstract classes with **only pure virtual functions**.

```cpp
class Printable {
public:
    virtual void print() = 0;
    virtual ~Printable() = default;
};
```

---

### 🔷 5. Multiple Interfaces

C++ supports multiple interface inheritance (carefully!):

```cpp
class Savable {
public:
    virtual void save() = 0;
};

class Printable {
public:
    virtual void print() = 0;
};

class Report : public Savable, public Printable {
public:
    void save() override { cout << "Saved!\n"; }
    void print() override { cout << "Printed!\n"; }
};
```

---

### 🔷 6. Abstract Base Class with Implementation

Abstract classes can contain **non-abstract** (implemented) methods too:

```cpp
class Shape {
public:
    virtual void draw() = 0; // Must override
    void moveTo(int x, int y) { cout << "Move to " << x << "," << y << endl; }
};
```

> 📌 Great for sharing common code between all derived classes.

---

### 🔷 7. Runtime Type Information (RTTI)

RTTI allows you to inspect an object’s type at runtime. It’s often used with **polymorphic base classes**.

---

### ✅ Conditions for RTTI:

- At least one **virtual function** in the class hierarchy
- Use `typeid` or `dynamic_cast`

---

### 🔷 8. `typeid` Operator

```cpp
#include <typeinfo>

void identify(UIComponent* comp) {
    cout << typeid(*comp).name() << endl;
}
```

> Use this to **get the type** of the object (returns a `type_info` object). On most compilers, this prints a mangled name unless demangled (platform-specific).

---

### 🔷 9. `dynamic_cast` – Safe Downcasting

```cpp
UIComponent* comp = new Button();

if (Button* b = dynamic_cast<Button*>(comp)) {
    b->render(); // Safe cast!
}
```

- Returns `nullptr` if cast fails — safe and clean
- Only works with polymorphic types (must have at least one virtual function)

---

### 🔷 10. Real-World Example: File Processor System

```cpp
class FileProcessor {
public:
    virtual void process() = 0;
};

class PDFProcessor : public FileProcessor {
public:
    void process() override {
        cout << "Processing PDF file\n";
    }
};

class WordProcessor : public FileProcessor {
public:
    void process() override {
        cout << "Processing Word document\n";
    }
};

void handleFile(FileProcessor* fp) {
    if (dynamic_cast<PDFProcessor*>(fp)) {
        cout << "It's a PDF\n";
    }
    fp->process();
}
```

---

### 🔷 11. Abstract Class in Template Design

Abstract classes + templates = **powerful design tools** in modern C++.

```cpp
template <typename T>
class Serializer {
public:
    virtual void serialize(const T&) = 0;
};
```

> Combine generic programming with OOP flexibility.

---

### 🔷 12. Best Practices

✅ Always declare a **virtual destructor** in base abstract classes  
✅ Use `override` and `final` to ensure clarity  
✅ Use abstract classes to enforce design contracts  
✅ Avoid casting unless necessary — **prefer virtual methods over RTTI**

---

### 🔷 13. Hands-On Lab

Build an abstract class `Device` with:

- Pure virtual `void operate()`
- Concrete function `void shutdown()`

Create two derived classes `Printer`, `Scanner`  
Override `operate()` in both  
Use RTTI to print device type before operating

---

### 🔷 14. Quiz Time

**Q1:** What makes a class abstract?  
> **A:** At least one pure virtual function

**Q2:** What is the use of `dynamic_cast`?  
> **A:** Safe downcasting of polymorphic types

**Q3:** Can abstract class have implemented methods?  
> **A:** Yes

**Q4:** Does `typeid` require virtual functions?  
> **A:** Only if you're using `typeid(*object)` for polymorphic behavior

---

### 🔷 15. Mini Project

**Smart Home Control System**

- Abstract base class `SmartDevice`
  - Pure virtual `control()`
  - Non-virtual `connectWiFi()`
- Derived classes: `Light`, `Thermostat`, `DoorLock`
- Use `dynamic_cast` to apply device-specific logic like `adjustTemperature()`, `unlock()`

---

### 🔷 16. Summary Table

| Feature          | Purpose                                  |
|------------------|------------------------------------------|
| Abstract Class   | Provides a base for related classes      |
| Interface Class  | Enforces a contract (pure virtuals)      |
| RTTI             | Safe type checking and casting at runtime |
| `typeid`         | Returns actual object type               |
| `dynamic_cast`   | Safe polymorphic downcast                |

---

### 🔷 17. Homework

- Create an interface `Drawable` with `draw()`  
- Derive `Circle`, `Square`, `Line` classes  
- Add a virtual base class `CanvasObject` with shared logic  
- Use RTTI to detect which shape is being drawn and print custom messages

---

### 🔷 18. Resources

- [RTTI in C++ – cppreference](https://en.cppreference.com/w/cpp/language/typeid)
- [Abstract Class Design Patterns – GfG](https://www.geeksforgeeks.org/abstract-classes-in-c/)
- [Virtual Destructors Explained](https://www.learncpp.com/cpp-tutorial/destructors-virtual-destructors/)

---

