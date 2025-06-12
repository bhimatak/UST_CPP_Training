
---

## 🧩 What is `std::unique_lock`?

`std::unique_lock` is a C++ Standard Library class template used to manage a **mutex**. It is part of the `<mutex>` header and provides **flexible, controllable** locking mechanisms.

### ✅ Key Features of `std::unique_lock`:

* Can **lock and unlock** manually.
* Supports **deferred locking** (construct without locking immediately).
* Can **transfer ownership** of the lock.
* Works well with **condition variables**.
* Slightly **larger and slower** than `lock_guard` due to its flexibility.

---

### 🔧 Syntax:

```cpp
std::unique_lock<std::mutex> lock(mutex);
```

---

## 🔍 Example: Using `std::unique_lock`

```cpp
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

void print_safe(const std::string& msg) {
    std::unique_lock<std::mutex> lock(mtx);  // Acquires lock
    std::cout << msg << std::endl;
    // lock is automatically released when it goes out of scope
}

int main() {
    std::thread t1(print_safe, "Hello from t1");
    std::thread t2(print_safe, "Hello from t2");

    t1.join();
    t2.join();
    return 0;
}
```

---

### 🧰 Manual Control Example

```cpp
std::unique_lock<std::mutex> lock(mtx, std::defer_lock); // No lock yet
// some logic
lock.lock();    // Lock later
// critical section
lock.unlock();  // Manually unlock
```

This is **not possible** with `std::lock_guard`.

---

## 🔐 What is `std::lock_guard`?

`std::lock_guard` is a **lightweight RAII** wrapper around a mutex. It **locks the mutex** as soon as it’s created and **automatically unlocks** it when destroyed (goes out of scope).

### ✅ Features:

* Simple and fast.
* Cannot be unlocked manually.
* Cannot be moved or copied.
* Ideal for **basic critical section protection**.

---

### 🔍 Example: Using `std::lock_guard`

```cpp
void print_safe(const std::string& msg) {
    std::lock_guard<std::mutex> lock(mtx);  // Acquires and releases automatically
    std::cout << msg << std::endl;
}
```

---

## 🆚 Difference: `lock_guard` vs `unique_lock`

| Feature                 | `std::lock_guard`           | `std::unique_lock`                           |
| ----------------------- | --------------------------- | -------------------------------------------- |
| Flexibility             | Low — no manual lock/unlock | High — can lock/unlock manually              |
| Manual lock/unlock      | ❌ Not possible              | ✅ Possible                                   |
| Defer locking           | ❌ No                        | ✅ Yes (`std::defer_lock`)                    |
| Moveable                | ❌ No                        | ✅ Yes (can be transferred between scopes)    |
| Use with condition vars | ❌ Not allowed               | ✅ Required (`std::condition_variable::wait`) |
| Overhead                | Minimal                     | Slightly higher due to internal logic        |
| Best for                | Simple locking scenarios    | Complex locking scenarios                    |

---

### 📌 When to Use Which?

| Scenario                            | Preferred Lock Type |
| ----------------------------------- | ------------------- |
| Simple function needing basic lock  | `std::lock_guard`   |
| You need to unlock and relock later | `std::unique_lock`  |
| You're using condition variables    | `std::unique_lock`  |
| You want to transfer lock ownership | `std::unique_lock`  |

---

## 📚 Practical Use Case Example: Condition Variable

```cpp
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });  // uses unique_lock only
    std::cout << "Worker thread starts work.\n";
}

void starter() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();
}

int main() {
    std::thread t1(worker);
    std::thread t2(starter);
    t1.join();
    t2.join();
}
```

📝 Note: `cv.wait()` **requires** `std::unique_lock`, not `std::lock_guard`.

---

## 🧠 Summary

* Use `std::lock_guard` for simplicity, low-overhead, and automatic RAII behavior.
* Use `std::unique_lock` when you need more **control**, like deferred locking, unlocking, re-locking, or condition variables.

---

