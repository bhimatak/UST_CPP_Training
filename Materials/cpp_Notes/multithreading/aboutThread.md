
---

## 🧵 "Threads have their own stack and registers" — What It Means

### 💡 1. **Shared Memory, Separate Execution Contexts**

In a multithreaded process:

* **All threads share** the *code*, *global variables*, *heap*, and *file descriptors*.
* But each thread has **its own:**

  * **Stack**
  * **Registers**
  * **Program Counter (Instruction Pointer)**

---

### 📦 What Is a Thread’s Stack?

Each thread gets its own **stack memory** for:

* Local variables
* Function calls (frames)
* Return addresses

#### 🎯 Why?

So that one thread's function calls and local variables **don’t interfere** with another thread's execution.

#### 🧠 Example:

```cpp
void task() {
    int x = 10;  // Local variable - goes into this thread's stack
}
```

Even if two threads call `task()`, each gets its **own `x`** in its **own stack**.

---

### 🧮 What Are Thread Registers?

Registers are part of the CPU and hold:

* Current values of variables
* Instruction pointer (which line is being executed)
* Stack pointer (top of the stack)
* Frame pointer, etc.

Each thread:

* Has its own **copy** of these registers
* Maintains its **own execution flow**

#### 📌 That’s how two threads can execute *different* code paths at the same time — they keep track of where they are via their own registers.

---

### 🔄 Analogy: Office Workers in Shared Workspace

| Concept          | Analogy                     |
| ---------------- | --------------------------- |
| Process memory   | Shared office space         |
| Threads          | Individual employees        |
| Thread stack     | Each worker’s personal desk |
| Thread registers | Their notebook + to-do list |

They all work in the same office (shared memory), but don’t mess with each other’s desks or notes (stack/registers).

---

### 🧪 Quick Visual Example

```cpp
#include <iostream>
#include <thread>

void task(const std::string& name) {
    int local_value = 0;
    for (int i = 0; i < 3; ++i) {
        ++local_value;
        std::cout << name << ": " << local_value << std::endl;
    }
}

int main() {
    std::thread t1(task, "Thread 1");
    std::thread t2(task, "Thread 2");

    t1.join();
    t2.join();
    return 0;
}
```

### 🧾 Output (varies):

```
Thread 1: 1
Thread 2: 1
Thread 1: 2
Thread 2: 2
Thread 1: 3
Thread 2: 3
```

Despite calling the same function, `local_value` remains independent per thread — stored in **each thread’s stack**.

---
