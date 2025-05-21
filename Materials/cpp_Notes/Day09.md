

---

## 🚀 **Day 9: Inheritance & Polymorphism in C++14/17 – Powering Reusability and Dynamic Behavior**

---

### 🔷 1. What is Inheritance?

Inheritance allows one class (**derived class**) to **reuse** and **extend** the features of another class (**base class**).

> 📌 **Real-world analogy:** A `Car` is a type of `Vehicle`. All cars have wheels (from `Vehicle`), but each car can have its own model and brand.

---

### 🔷 2. Types of Inheritance

| Type            | Syntax                        | Example                      |
|-----------------|-------------------------------|------------------------------|
| **Single**      | `class B : public A`          | `class Car : public Vehicle` |
| **Multilevel**  | `C → B → A`                   | `class SportsCar : public Car` |
| **Multiple**    | `class D : public B, public A`| Complex scenarios (handled carefully) |
| **Hierarchical**| Multiple classes from one base| `Truck`, `Bike` → `Vehicle`  |

> 🚨 Multiple inheritance should be used wisely to avoid the **Diamond Problem** (we’ll cover that too!).

---

### 🔷 3. Basic Syntax of Inheritance

```cpp
class Vehicle {
public:
    void start() {
        cout << "Vehicle started\n";
    }
};

class Car : public Vehicle {
public:
    void honk() {
        cout << "Car honks\n";
    }
};
```

Usage:
```cpp
Car myCar;
myCar.start(); // from Vehicle
myCar.honk();  // from Car
```

---

### 🔷 4. Access Specifiers in Inheritance

| Base Class Member | `public` Inheritance | `protected` Inheritance | `private` Inheritance |
|-------------------|----------------------|--------------------------|------------------------|
| `public`          | `public`             | `protected`              | `private`              |
| `protected`       | `protected`          | `protected`              | `private`              |
| `private`         | Not Inherited        | Not Inherited            | Not Inherited          |

---

### 🔷 5. Real-World Example – Employee Management

```cpp
class Employee {
protected:
    string name;
    int id;
public:
    Employee(string n, int i) : name(n), id(i) {}
    void display() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};

class Manager : public Employee {
    int teamSize;
public:
    Manager(string n, int i, int t) : Employee(n, i), teamSize(t) {}
    void showTeam() {
        cout << name << " manages " << teamSize << " people.\n";
    }
};
```

Usage:
```cpp
Manager m("Alice", 101, 5);
m.display();   // From Employee
m.showTeam();  // From Manager
```

---

## 🌀 Polymorphism – Same Interface, Different Behavior

---

### 🔷 6. What is Polymorphism?

**Polymorphism** means "many forms." In C++, this allows functions and methods to behave differently depending on the object or data they’re working on.

Two types:

1. **Compile-time Polymorphism (Static)** → *Function overloading, Operator overloading*  
2. **Run-time Polymorphism (Dynamic)** → *Virtual functions*

---

### 🔷 7. Compile-time Polymorphism: Function Overloading

```cpp
class Print {
public:
    void show(int a) { cout << "Int: " << a << endl; }
    void show(double d) { cout << "Double: " << d << endl; }
};
```

> 📌 Functions with the **same name** but **different signatures**.

---

### 🔷 8. Operator Overloading Example

```cpp
class Point {
    int x;
public:
    Point(int x) : x(x) {}
    Point operator+(const Point& p) {
        return Point(x + p.x);
    }
    void display() { cout << "Point: " << x << endl; }
};
```

---

### 🔷 9. Run-time Polymorphism: Virtual Functions

Allows **dynamic dispatch** — the function that runs is determined at **runtime**, not compile time.

```cpp
class Animal {
public:
    virtual void speak() {
        cout << "Animal sound\n";
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof!\n";
    }
};
```

Usage:
```cpp
Animal* a = new Dog();
a->speak(); // Outputs: Woof!
```

> Without `virtual`, it would have called `Animal::speak()`.

---

### 🔷 10. Real-World Analogy: Payment System

```cpp
class Payment {
public:
    virtual void pay() {
        cout << "Generic payment\n";
    }
};

class CreditCard : public Payment {
public:
    void pay() override {
        cout << "Paid using Credit Card\n";
    }
};

class PayPal : public Payment {
public:
    void pay() override {
        cout << "Paid using PayPal\n";
    }
};

void processPayment(Payment* p) {
    p->pay();
}
```

Usage:
```cpp
Payment* p1 = new CreditCard();
Payment* p2 = new PayPal();
processPayment(p1);  // Credit Card
processPayment(p2);  // PayPal
```

---

### 🔷 11. Virtual Destructors – A Must-Have

If a base class has virtual functions, always provide a **virtual destructor** to ensure proper cleanup.

```cpp
class Base {
public:
    virtual ~Base() {
        cout << "Base destroyed\n";
    }
};
```

---

### 🔷 12. Best Practices for Inheritance and Polymorphism

✅ Use `override` to avoid surprises  
✅ Always use `virtual` destructor in polymorphic base classes  
✅ Use `final` if a class/function shouldn't be overridden (C++11+)  
✅ Prefer composition over inheritance when unsure

---

### 🔷 13. Hands-On Lab

- Create base class `Shape` with `draw()` as a virtual method  
- Derive `Circle`, `Rectangle`, and `Triangle` classes from `Shape`  
- Override `draw()` in each derived class  
- Create a function `render(Shape*)` that calls `draw()`

---

### 🔷 14. Quiz

**Q1:** What is dynamic polymorphism implemented through in C++?  
> **A:** Virtual functions

**Q2:** Which inheritance type leads to Diamond Problem?  
> **A:** Multiple inheritance

**Q3:** What does `override` keyword ensure?  
> **A:** That a function is correctly overriding a virtual base class function

**Q4:** Should base class destructor be virtual when using polymorphism?  
> **A:** Yes

---

### 🔷 15. Mini Project

**Project:**  
Build an **E-commerce Order System**:

- Base class `Order` with virtual method `calculateTotal()`
- Derived classes: `NormalOrder`, `BulkOrder`, `SubscriptionOrder`
- Override pricing logic in each
- Use polymorphism to process multiple orders in a loop

---

### 🔷 16. Summary

| Concept           | Purpose                                   |
|------------------|--------------------------------------------|
| Inheritance       | Reuse and extend existing classes          |
| Polymorphism      | Different behavior for same interface      |
| Virtual Functions | Enable runtime binding of method calls     |
| Virtual Destructors | Ensure proper cleanup                    |

---

### 🔷 17. Homework

- Build a class hierarchy for `Appliance → WashingMachine`, `Refrigerator`  
- Implement `start()` as virtual in base, override in derived  
- Create a list of `Appliance*` and call `start()` for each

---

### 🔷 18. Resources

- [Virtual Functions – CPP Reference](https://en.cppreference.com/w/cpp/language/virtual)
- [Inheritance in C++ – GeeksforGeeks](https://www.geeksforgeeks.org/inheritance-in-c/)
- [Polymorphism Deep Dive](https://cplusplus.com/doc/tutorial/polymorphism/)

---

