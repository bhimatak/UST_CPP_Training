<h1 align="center"> Virtual Base Class in C++ </h1>

A **virtual base class** in C++ is used to prevent **multiple copies** of a base class when using **multiple inheritance**, especially in a **diamond inheritance** scenario. It ensures that **only one instance** of the base class is inherited, even if multiple paths exist.

---

## 🔷 Problem: The Diamond Problem

### Inheritance Diagram

```
        A
       / \
      B   C
       \ /
        D
```

Here:

* `B` and `C` both inherit from `A`.
* `D` inherits from both `B` and `C`.

➡️ This causes **two copies of `A`** to be present in `D`.

---

## 🔷 Without Virtual Base Class

```cpp
#include <iostream>
using namespace std;

class A {
public:
    int val = 10;
};

class B : public A {};
class C : public A {};
class D : public B, public C {};

int main() {
    D obj;
    // cout << obj.val;  // ❌ Error: Ambiguous — which A::val to use?
    cout << obj.B::val << endl;  // ✅ Okay
    cout << obj.C::val << endl;  // ✅ Okay
    return 0;
}
```

### ❌ Issue:

* Two separate `A` subobjects exist in `D`.
* Leads to **ambiguity**.

---

## ✅ With Virtual Base Class

```cpp
#include <iostream>
using namespace std;

class A {
public:
    int val = 20;
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main() {
    D obj;
    cout << obj.val << endl;  // ✅ No ambiguity
    return 0;
}
```

### ✅ Output:

```
20
```

Only **one shared copy** of `A` exists in `D`.

---

## 🔷 Key Points

| Feature                    | Description                                                               |
| -------------------------- | ------------------------------------------------------------------------- |
| `virtual` keyword          | Applied during inheritance (e.g., `class B : virtual public A`)           |
| Use case                   | Resolves diamond problem                                                  |
| Object layout              | Only one `A` subobject is present, shared by all intermediate classes     |
| Constructor responsibility | The **most derived class** (e.g., `D`) initializes the virtual base class |

---

## 🔷 Constructor Call Order

```cpp
#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A()\n"; }
};

class B : virtual public A {
public:
    B() { cout << "B()\n"; }
};

class C : virtual public A {
public:
    C() { cout << "C()\n"; }
};

class D : public B, public C {
public:
    D() { cout << "D()\n"; }
};

int main() {
    D obj;
    return 0;
}
```

### 🧾 Output:

```
A()
B()
C()
D()
```

* `A()` is called **once** — by the most derived class `D`.
* This shows **single instance** of virtual base class.

---

## 🔷 Summary

| Term               | Meaning                                                |
| ------------------ | ------------------------------------------------------ |
| Virtual function   | Enables **runtime polymorphism**                       |
| Virtual base class | Solves **diamond problem** in **multiple inheritance** |

---

