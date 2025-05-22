**C++ OOP Concepts Using Employee Class**

---

### Title Slide

**C++ OOPS Using Employee Class**


---

### Table of Contents

1. Class & Object
2. Encapsulation
3. Inheritance (UML Included)
4. Polymorphism (Flowchart Included)
5. Abstraction
6. Constructor & Destructor
7. Constructor Overloading
8. Static Members
9. this Pointer
10. Friend Functions
11. Namespaces
12. Operator Overloading
13. Exception Handling
14. Exercises & Problem Statements

---

### Class & Object

**Concept:** Blueprint to create objects (real-world entities).

```cpp
class Employee {
public:
    int id;
    std::string name;
    void display() {
        std::cout << id << ", " << name << std::endl;
    }
};
```

**Object Example:**

```cpp
Employee e1;
e1.id = 1;
e1.name = "Alice";
e1.display();
```

---

### Encapsulation

**Concept:** Wrapping data and methods into a single unit.

```cpp
class Employee {
private:
    int id;
    std::string name;
public:
    void setData(int i, std::string n) {
        id = i; name = n;
    }
    void display() {
        std::cout << id << ", " << name << std::endl;
    }
};
```

**Benefits:** Data hiding, control over data

---

### Slide 5: Inheritance

**Concept:** Reusing features from base class

```cpp
class Employee {
protected:
    int id;
    std::string name;
public:
    void setData(int i, std::string n) {
        id = i; name = n;
    }
};

class Manager : public Employee {
public:
    void display() {
        std::cout << id << ", " << name << std::endl;
    }
};
```

---

### UML Diagram

**Employee UML**

* Employee (Base)

  * id: int
  * name: string
  * setData(), display()
* Developer, Manager (Derived)

  * work() override

---

### Polymorphism

**Concept:** Many forms

* Compile-Time: Function Overloading
* Run-Time: Virtual Functions

```cpp
class Employee {
public:
    virtual void work() {
        std::cout << "Employee working";
    }
};

class Developer : public Employee {
public:
    void work() override {
        std::cout << "Developer coding";
    }
};
```

---

### Flowchart

**Runtime Polymorphism Flow:**

1. Base class pointer
2. Derived object
3. Call virtual function
4. Resolved at runtime

(Insert flowchart image here)

---

### Abstraction

**Concept:** Show only essential details

* Abstract class or Interface in C++
* Example:

```cpp
class Employee {
public:
    virtual void work() = 0; // Pure virtual
};
```

---

### Constructor & Destructor

```cpp
class Employee {
public:
    Employee() { std::cout << "Constructor called"; }
    ~Employee() { std::cout << "Destructor called"; }
};
```

---

### Constructor Overloading

```cpp
class Employee {
public:
    Employee() {}
    Employee(int id) { this->id = id; }
};
```

---

### Static Members

```cpp
class Employee {
public:
    static int count;
    Employee() { count++; }
};
int Employee::count = 0;
```

---

### this Pointer

```cpp
class Employee {
private:
    int id;
public:
    Employee setID(int id) {
        this->id = id;
        return *this;
    }
};
```

---

### Friend Functions

```cpp
class Employee {
    friend void show(Employee);
};
```

---

### Namespaces

```cpp
namespace Company {
    class Employee {
        // ...
    };
}
```

---

### Operator Overloading

```cpp
Employee operator+(const Employee& e1, const Employee& e2);
```

---

### Exception Handling

```cpp
try {
    throw "Error!";
} catch (const char* msg) {
    std::cout << msg;
}
```

---

### Exercises

1. Create a class with constructor, destructor, and display method.
2. Demonstrate inheritance using Employee and Manager.
3. Write a virtual function in base and override in derived.
4. Use friend function to modify private members.

---

### Advanced Challenges

1. Create an abstract class and implement it in 2+ derived classes.
2. Overload operators to compare Employee objects.
3. Create a static member to track number of objects.
4. Demonstrate exception safety in a function.

---

### Summary Table

| Concept           | Feature Used              |
| ----------------- | ------------------------- |
| Encapsulation     | private + public methods  |
| Inheritance       | Manager : public Employee |
| Polymorphism      | virtual + override        |
| Abstraction       | pure virtual function     |
| Operator Overload | operator+                 |
| Exception         | try-catch                 |
