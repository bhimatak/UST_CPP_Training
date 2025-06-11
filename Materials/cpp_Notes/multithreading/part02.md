
---

## 🔐 Why We Need Locks / Mutexes

### 📌 Problem: **Race Condition**

A *race condition* occurs when two or more threads access shared data at the same time and try to modify it. This leads to **unexpected or incorrect results**, especially when operations are not atomic.

---

### ❌ Without Lock — Race Condition Example

```cpp
#include <iostream>
#include <thread>
#include <vector>

int counter = 0; // Shared resource

void increment(int times) {
    for (int i = 0; i < times; ++i) {
        ++counter;
    }
}

int main() {
    std::thread t1(increment, 100000);
    std::thread t2(increment, 100000);

    t1.join();
    t2.join();

    std::cout << "Final counter (without mutex): " << counter << std::endl;
    return 0;
}
```

### 🧪 Input/Test:

Two threads increment the counter 100,000 times each.

### 🚨 Expected Output:

```
Final counter (without mutex): 200000
```

### ⚠️ Actual Output (may vary each run):

```
Final counter (without mutex): 173456
```

### 💥 Explanation:

Even though `++counter` looks atomic, it’s actually **read-modify-write**, which is **not thread-safe**. Threads interrupt each other during this sequence, causing loss of increments.

---

### ✅ With Lock — Fix Using `std::mutex`

```cpp
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

int counter = 0; // Shared resource
std::mutex mtx;

void increment(int times) {
    for (int i = 0; i < times; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++counter;
    }
}

int main() {
    std::thread t1(increment, 100000);
    std::thread t2(increment, 100000);

    t1.join();
    t2.join();

    std::cout << "Final counter (with mutex): " << counter << std::endl;
    return 0;
}
```

### 🧪 Input/Test:

Same as before — two threads increment 100,000 times each.

### ✅ Output:

```
Final counter (with mutex): 200000
```

---

## 🧠 What’s the Impact?

| Aspect             | Without Mutex     | With Mutex        |
| ------------------ | ----------------- | ----------------- |
| Correctness        | ❌ Race condition  | ✅ Safe access     |
| Output Consistency | ❌ Varies per run  | ✅ Always correct  |
| Performance        | ✅ Slightly faster | ❌ Slightly slower |
| Thread Safety      | ❌ Not safe        | ✅ Safe            |

---

## 📚 Summary for Participants

* **Race conditions** are common in multithreaded code when shared variables are modified without protection.
* **Mutexes (locks)** ensure only one thread accesses the critical section at a time.
* Use `std::lock_guard` for automatic locking and unlocking.
* You trade a bit of performance for **correctness and safety**, which is essential for production code.

---
