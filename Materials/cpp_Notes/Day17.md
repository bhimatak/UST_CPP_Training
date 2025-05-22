

---

## 🔐 **Day 17: Smart Pointers in C++14/17 – `unique_ptr`, `shared_ptr`, `weak_ptr`**

---

### 🔷 1. The Problem with Raw Pointers

Consider this:

```cpp
int* ptr = new int(10);
// do something...
delete ptr;  // Did we forget this?
```

Problems:
- ❌ Memory leaks if `delete` is forgotten
- ❌ Double deletes
- ❌ Exception safety issues

---

### 💡 Enter Smart Pointers

Smart pointers **automatically deallocate memory** when not needed. Think of them like a `RAII` wrapper around a raw pointer.

Header:  
```cpp
#include <memory>
```

---

### ✅ 2. `std::unique_ptr` – Exclusive Ownership

- Only one owner at a time
- Auto-deletes the object when out of scope

#### 📦 Example:

```cpp
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> p1 = make_unique<int>(42);
    cout << *p1 << endl;

    // unique_ptr<int> p2 = p1; ❌ ERROR: copy not allowed
    unique_ptr<int> p2 = move(p1); // ✅ Move ownership
}
```

---

#### 🧠 Real-World Analogy:

`unique_ptr` is like **owning a car**. Only one person can own it at a time. If you give it away, you lose access.

---

### 🧩 Custom Deleter

You can even provide a custom function to clean up resources:

```cpp
auto deleter = [](int* ptr) {
    cout << "Deleting...\n";
    delete ptr;
};

unique_ptr<int, decltype(deleter)> p(new int(10), deleter);
```

---

### ✅ 3. `std::shared_ptr` – Shared Ownership

- Reference-counted ownership
- Deletes object only when the **last owner** is gone

#### 📦 Example:

```cpp
shared_ptr<int> p1 = make_shared<int>(100);
shared_ptr<int> p2 = p1;

cout << "Count: " << p1.use_count() << endl; // Output: 2
```

#### 🔁 use_count()

This tracks how many `shared_ptr`s point to the same object.

---

#### 🧠 Real-World Analogy:

`shared_ptr` is like **co-owning a document** in the cloud — multiple users can access and modify it. The file is deleted when **all users** disconnect.

---

### ⚠️ Circular References (The Weakness of Shared Pointers)

```cpp
struct B;
struct A {
    shared_ptr<B> b_ptr;
};
struct B {
    shared_ptr<A> a_ptr;  // ❌ Creates circular reference
};
```

These will never get deleted because their use_count never drops to zero.

---

### ✅ 4. `std::weak_ptr` – Breaking the Cycle

- Non-owning reference to `shared_ptr`
- Doesn’t increase the reference count

#### 📦 Example:

```cpp
shared_ptr<int> sp = make_shared<int>(50);
weak_ptr<int> wp = sp; // doesn't increase count

cout << "Count: " << sp.use_count(); // 1

if (auto spt = wp.lock()) {
    cout << "Value: " << *spt;
}
```

---

### 🧠 Real-World Analogy:

`weak_ptr` is like **borrowing a book** from someone. You don’t own it, and if they throw it away, it's gone—you can't stop it.

---

### 🔄 Summary Table

| Smart Pointer   | Ownership     | Ref Counting | Moveable | Copyable |
|----------------|---------------|--------------|----------|----------|
| `unique_ptr`   | Exclusive     | ❌            | ✅       | ❌       |
| `shared_ptr`   | Shared        | ✅            | ✅       | ✅       |
| `weak_ptr`     | Non-owning    | ✅ (no inc)   | ✅       | ✅       |

---

### 🧪 Smart Pointer + Class Example

```cpp
class File {
public:
    File() { cout << "Opened file\n"; }
    ~File() { cout << "Closed file\n"; }
};

int main() {
    {
        unique_ptr<File> f = make_unique<File>();
    } // File is automatically closed here
}
```

Output:
```
Opened file
Closed file
```

---

### 🔧 C++17 Bonus: `std::make_unique<T>`

C++14 introduced `make_unique<T>`, a safer and more efficient way to create `unique_ptr`s.

```cpp
auto ptr = make_unique<int>(99);
```

Why use it?
- Cleaner syntax
- Exception-safe
- Prevents redundant `new`

---

### 📚 Exercises

1. Implement a `Book` class. Use:
   - `unique_ptr` for managing content memory
   - `shared_ptr` to simulate library sharing
2. Show how `weak_ptr` helps avoid cyclic references between `Node` objects in a doubly-linked list
3. Replace raw pointers in a previous project with smart pointers

---

### 🧠 Diagram: Smart Pointer Relationships

```
[unique_ptr] --> [Object] (1 owner)

[shared_ptr1] --> [Object] <-- [shared_ptr2]
    ↑
 [weak_ptr] (non-owning)
```

---

### 🛡️ Homework

- Create a `DocumentEditor` class that holds:
   - `unique_ptr<TextBuffer>` – for private text memory
   - `shared_ptr<User>` – for shared collaboration
   - `weak_ptr<Session>` – for temporary session linking

---
