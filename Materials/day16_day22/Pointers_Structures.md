**Structures** and **Pointers** in C++  
---

# 📘 **C++ Structures and Pointers**

---

## 🧱 Part 1: Structures in C++

### 🔹 1. What is a Structure?

A structure (`struct`) in C++ is a user-defined data type that groups related variables (of potentially different types) under one name.

```cpp
struct Employee {
    int id;
    std::string name;
    float salary;
};
```

This helps model real-world entities in code, aligning with the principles of object-oriented and modular design.

---

### 🔹 2. Memory Layout of a Structure

Each member is stored in contiguous memory blocks with possible padding for alignment.

**Example:**

```cpp
struct A {
    char c;
    int i;
    double d;
};
```

On a 64-bit system, due to padding:

* `char c` (1 byte) → +3 bytes padding
* `int i` (4 bytes)
* `double d` (8 bytes)

Total size = 4 (char + padding) + 4 (int) + 8 (double) = **16 bytes**

Use `sizeof()` to find structure size.

---

### 🔹 3. Declaration & Initialization

```cpp
Employee e1 = {101, "John", 50000.0};
Employee e2;
e2.id = 102;
e2.name = "Alice";
e2.salary = 65000.5;
```

---

### 🔹 4. Accessing Members

```cpp
std::cout << e1.name;
```

---

### 🔹 5. Nested Structures

```cpp
struct Date {
    int day, month, year;
};

struct Employee {
    int id;
    std::string name;
    Date joiningDate;
};
```

Access:

```cpp
Employee emp;
emp.joiningDate.day = 15;
```

---

### 🔹 6. Array of Structures

```cpp
Employee employees[3] = {
    {1, "Alex", 30000},
    {2, "Bob", 40000},
    {3, "Carol", 50000}
};
```

---

### 🔹 7. Pointer to Structure

```cpp
Employee *ptr = &e1;
std::cout << ptr->name;
```

Use `->` for member access through pointer.

---

### 🔹 8. Passing Structures to Functions

#### By Value (costly for large structs)

```cpp
void display(Employee e) { ... }
```

#### By Pointer

```cpp
void display(const Employee* e) {
    std::cout << e->name;
}
```

#### By Reference (Preferred)

```cpp
void display(const Employee& e) {
    std::cout << e.name;
}
```

---

### 🔹 9. Structure and Dynamic Memory Allocation

```cpp
Employee* e = new Employee;
e->id = 1;
e->name = "Raj";
delete e;
```

Use `new` and `delete` for dynamic memory handling.

---

### 🔹 10. Structures vs Classes

| Aspect         | struct        | class           |
| -------------- | ------------- | --------------- |
| Default access | public        | private         |
| Inheritance    | Yes           | Yes             |
| Use-case       | Data grouping | Data + behavior |

---

## 🧠 Advanced Use-Cases of Structures

### 🔹 Using Structure in File Handling

```cpp
#include <fstream>
std::ofstream fout("emp.dat", std::ios::binary);
fout.write(reinterpret_cast<char*>(&e1), sizeof(e1));
```

---

### 🔹 Structure as Function Return Type

```cpp
Employee createEmployee() {
    return {104, "Shyam", 60000};
}
```

---

### 🔹 Bit Fields in Structures

```cpp
struct Flags {
    unsigned int isVisible : 1;
    unsigned int isLocked  : 1;
};
```

Used to save memory with small boolean flags.

---

## 💡 Tips

* Always pass large structures by reference.
* Be mindful of structure padding and alignment.
* Prefer `class` if behavior (methods) are associated.

---

# 🔗 Part 2: Pointers in C++

### 🔹 1. What is a Pointer?

A pointer is a variable that stores the **memory address** of another variable.

```cpp
int a = 5;
int* p = &a;
```

---

### 🔹 2. Pointer Syntax & Dereferencing

```cpp
std::cout << *p;  // Outputs 5
```

---

### 🔹 3. Pointer Types

| Pointer Type     | Example             | Use                 |
| ---------------- | ------------------- | ------------------- |
| Null Pointer     | `int* p = nullptr;` | Safe initialization |
| Void Pointer     | `void* vp = &a;`    | Generic pointer     |
| Wild Pointer     | Uninitialized       | Unsafe              |
| Dangling Pointer | After deletion      | Bug-prone           |

---

### 🔹 4. Pointers and Arrays

```cpp
int arr[] = {10, 20, 30};
int* p = arr;
std::cout << *(p + 2); // 30
```

---

### 🔹 5. Pointer to Pointer

```cpp
int a = 10;
int* p = &a;
int** pp = &p;
std::cout << **pp;
```

---

### 🔹 6. Pointer Arithmetic

Valid operations: increment/decrement, subtraction (between pointers of same array)

```cpp
p++;  // Moves to next int (i.e., +4 bytes)
```

---

### 🔹 7. Function Pointers

```cpp
int add(int a, int b) { return a + b; }
int (*fptr)(int, int) = add;
std::cout << fptr(3, 4);
```

---

### 🔹 8. Pointers and Structures

```cpp
Employee e = {1, "Ron", 45000};
Employee* eptr = &e;
std::cout << eptr->name;
```

---

### 🔹 9. Dynamic Memory Allocation

#### Single Variable

```cpp
int* p = new int(10);
delete p;
```

#### Array

```cpp
int* arr = new int[5];
delete[] arr;
```

---

### 🔹 10. Smart Pointers (C++11+)

Smart pointers help manage dynamic memory automatically.

```cpp
#include <memory>

std::unique_ptr<int> up(new int(5));
std::shared_ptr<int> sp = std::make_shared<int>(10);
```

---

### 🔹 11. Common Mistakes to Avoid

* Dereferencing null/wild/dangling pointers.
* Not freeing dynamically allocated memory.
* Memory leaks due to forgotten `delete`.

---

## 🧠 Advanced Use-Cases of Pointers

### 🔹 Pointer to Function for Callbacks

```cpp
void greet() { std::cout << "Hello!\n"; }
void callFunc(void (*func)()) { func(); }
callFunc(greet);
```

---

### 🔹 Pointers to Members

```cpp
struct A {
    int x;
    void display() { std::cout << "x = " << x; }
};

int A::* ptr = &A::x;
void (A::*fptr)() = &A::display;

A obj;
obj.*ptr = 10;
(obj.*fptr)();
```

---

### 🔹 Using `const` with Pointers

```cpp
const int* p1;      // Pointer to const int
int* const p2;      // Const pointer to int
const int* const p3; // Const pointer to const int
```

---

## ✅ Summary Chart

| Concept  | Structure                         | Pointer                               |
| -------- | --------------------------------- | ------------------------------------- |
| Purpose  | Group multiple variables          | Store address of variable             |
| Memory   | Contiguous layout                 | Stores address                        |
| Usage    | Real-world modeling               | Dynamic data structures, optimization |
| Advanced | Nested, function return, file I/O | Function pointers, smart pointers     |

---
