
---

## 🔁 **Upcasting vs Downcasting in C++**

---

### 🔼 **Upcasting** (Safe and Implicit)

**Definition**: Converting a derived class pointer/reference **to a base class** pointer/reference.

* ✅ Always safe.
* ✅ Happens implicitly.
* ❌ You lose access to derived-specific members.

#### Example:

```cpp
class Base {
public:
    void baseFunc() { std::cout << "Base function\n"; }
};

class Derived : public Base {
public:
    void derivedFunc() { std::cout << "Derived function\n"; }
};

int main() {
    Derived d;
    Base* bptr = &d;  // 🔼 Upcasting

    bptr->baseFunc();     // ✅ OK
    // bptr->derivedFunc(); // ❌ Error: Base doesn't know about this
}
```

---

### 🔽 **Downcasting** (Unsafe unless checked)

**Definition**: Converting a base class pointer/reference **to a derived class** pointer/reference.

* ⚠️ Dangerous unless done with care (can cause undefined behavior).
* ❌ Not implicit — must be explicit (e.g., `dynamic_cast`, `static_cast`).
* ✅ Best done with `dynamic_cast` when RTTI (Run-Time Type Information) is enabled and base class has at least one `virtual` function.

#### Example (Safe way using `dynamic_cast`):

```cpp
class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void derivedFunc() { std::cout << "Derived function\n"; }
};

int main() {
    Base* bptr = new Derived();   // Upcast

    // 🔽 Downcast safely
    Derived* dptr = dynamic_cast<Derived*>(bptr);
    if (dptr) {
        dptr->derivedFunc();  // ✅ OK
    } else {
        std::cout << "Invalid cast\n";
    }
}
```

#### ⚠️ Example (Risky way using `static_cast`):

```cpp
Derived* dptr = static_cast<Derived*>(bptr);  // ⚠️ Unsafe if bptr is not really pointing to Derived
dptr->derivedFunc();  // ✅ Works only if the object is really a Derived
```

---

### 🔁 Summary Table

| Operation   | Type           | Safe?         | Implicit? | Cast Used                                      | Access to Derived Members |
| ----------- | -------------- | ------------- | --------- | ---------------------------------------------- | ------------------------- |
| Upcasting   | Derived → Base | ✅ Yes         | ✅ Yes     | None needed                                    | ❌ No                      |
| Downcasting | Base → Derived | ⚠️ Not always | ❌ No      | `dynamic_cast` (safe) / `static_cast` (unsafe) | ✅ Yes (if valid)          |

---
