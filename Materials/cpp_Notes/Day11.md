

---

## 🚀 **Day 11: Constructors, Destructors & Virtual Destructors in Inheritance**

---

### 🔷 1. The Object Lifecycle – Constructors and Destructors

In C++, when an object is created and destroyed, **constructors and destructors** are called in a **specific order**, especially in **inheritance hierarchies**.

---

### 📘 Basic Rule

- **Constructor** calls happen from **base to derived**
- **Destructor** calls happen from **derived to base**

Let’s visualize:

```cpp
class Base {
public:
    Base() { cout << "Base constructor\n"; }
    ~Base() { cout << "Base destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived constructor\n"; }
    ~Derived() { cout << "Derived destructor\n"; }
};
```

```cpp
int main() {
    Derived d;
}
```

**Output:**
```
Base constructor
Derived constructor
Derived destructor
Base destructor
```

---

### 📊 Diagram: Object Construction/Destruction Flow

```
Object Creation:
----------------
      +----------------+
      | Base Constructor|
      +----------------+
                ↓
      +------------------+
      | Derived Constructor|
      +------------------+

Object Destruction:
-------------------
      +------------------+
      | Derived Destructor|
      +------------------+
                ↓
      +----------------+
      | Base Destructor |
      +----------------+
```

---

### 🔷 2. What Happens with Pointers?

Here’s where things get **risky**.

```cpp
Base* b = new Derived();
delete b; // Uh-oh!
```

If `Base`'s destructor is **not virtual**, this leads to **undefined behavior** — only `Base`'s destructor will run!

---

### 🔥 Solution: Use Virtual Destructors in Polymorphic Classes

```cpp
class Base {
public:
    virtual ~Base() {
        cout << "Base virtual destructor\n";
    }
};
```

Now when you `delete` a derived object through a base pointer, both destructors will be called:

```cpp
class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived destructor\n";
    }
};

int main() {
    Base* b = new Derived();
    delete b; // Safe!
}
```

**Output:**
```
Derived destructor
Base virtual destructor
```

---

### 📘 Rule of Thumb

> If a class has **any virtual functions**, make its destructor **virtual**.

---

### 🔷 3. Constructor Overriding? Nope ❌

C++ does **not** allow **virtual constructors**. Instead, you can use **factory patterns** if you need dynamic construction.

---

### 🔷 4. Constructor Initialization Order

Initialization of members occurs in this order:

1. Base class constructor
2. Member initializers (in order of declaration, not order in initializer list)
3. Derived class constructor body

Example:

```cpp
class Base {
public:
    Base(int x) { cout << "Base with x = " << x << endl; }
};

class Derived : public Base {
    int a;
public:
    Derived(int x, int y) : Base(x), a(y) {
        cout << "Derived with y = " << y << endl;
    }
};
```

---

### 🧠 Key Concept: Destruction is always **safe** when destructors are virtual, especially in inheritance hierarchies.

---

### 🔷 5. Real-World Example: Plugin System

```cpp
class Plugin {
public:
    virtual void run() = 0;
    virtual ~Plugin() {
        cout << "Plugin destroyed\n";
    }
};

class ImagePlugin : public Plugin {
public:
    void run() override { cout << "Image plugin running\n"; }
    ~ImagePlugin() { cout << "ImagePlugin destroyed\n"; }
};
```

```cpp
Plugin* p = new ImagePlugin();
p->run();
delete p; // Clean and safe
```

---

### 🛠️ Hands-On Exercise

Create a base class `Logger` with:

- Constructor and destructor that print messages
- Make the destructor virtual

Create `FileLogger`, `ConsoleLogger` derived classes  
Use a `Logger*` to create and delete derived class objects  
Observe and explain the destruction sequence

---

### 🔶 6. What If Destructor Isn’t Virtual?

```cpp
class Animal {
public:
    ~Animal() {
        cout << "Animal destroyed\n";
    }
};

class Dog : public Animal {
public:
    ~Dog() {
        cout << "Dog destroyed\n";
    }
};

int main() {
    Animal* a = new Dog();
    delete a; // Only Animal destructor runs! Memory leak possible
}
```

**Fix:** Make `Animal::~Animal()` virtual.

---

### 🧠 Common Mistakes

❌ Forgetting virtual destructors  
❌ Relying on base class pointer deletion without virtual destructor  
✅ Always test your polymorphic deletions

---

### 🔷 7. Summary Table

| Concept                  | Behavior                             |
|--------------------------|---------------------------------------|
| Constructor Order        | Base → Derived                        |
| Destructor Order         | Derived → Base                        |
| Virtual Destructor       | Ensures proper cleanup                |
| No Virtual Constructor   | Use factory functions instead         |
| Member Init Order        | Order of declaration, not init list   |

---

### 📚 Homework

1. Implement a `Shape` hierarchy (`Shape`, `Circle`, `Square`)
2. Add constructors and destructors with logs
3. Use pointers and test deleting via `Shape*`
4. Add `virtual` keyword and observe difference

---

