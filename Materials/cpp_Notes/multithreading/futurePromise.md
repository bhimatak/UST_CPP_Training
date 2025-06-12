
---

# 🔮 `std::future` and `std::promise` in C++

---

## 🧠 Step-by-Step Conceptual Explanation

### 🎯 Goal:

Communicate between **two threads** where:

* One **produces a result** (`promise`)
* The other **waits for the result** (`future`)

---

## 👨‍🏫 Real-Life Analogy

Imagine you're a **manager** waiting for a **report** from an employee.

* The employee **promises** to give the report (`std::promise`)
* You don’t do anything until the report is ready — you wait (`std::future`)

So:

* `std::promise` → employee commits to deliver a result.
* `std::future` → manager is waiting for that result.

---

## 💡 Why Use This?

* Synchronize **asynchronous tasks**
* Transfer result or error from one thread to another
* Useful in **thread pool**, **task queues**, **event pipelines**

---

## 📦 Library Headers:

```cpp
#include <iostream>
#include <thread>
#include <future>
```

---

## 🧪 Simple Code Example

### ✅ Step 1: Create `promise` and get `future`

### ✅ Step 2: Launch a thread that sets the value

### ✅ Step 3: In main thread, wait and get the result

```cpp
#include <iostream>
#include <thread>
#include <future>

void worker(std::promise<int>&& prom) {
    std::this_thread::sleep_for(std::chrono::seconds(2));  // simulate work
    prom.set_value(42);  // set the result
}

int main() {
    std::promise<int> prom;           // Step 1: Create a promise
    std::future<int> fut = prom.get_future();  // Step 2: Get associated future

    std::thread t(worker, std::move(prom));    // Step 3: Launch worker thread

    std::cout << "Waiting for result...\n";
    int result = fut.get();   // Step 4: Waits until value is ready

    std::cout << "Result received: " << result << "\n";

    t.join();
    return 0;
}
```

---

## 🧵 What’s Happening Under the Hood

| Thread 1 (Main)     | Thread 2 (Worker)                  |
| ------------------- | ---------------------------------- |
| Creates promise     | Receives promise object            |
| Gets future from it | Sets the value using `set_value()` |
| Calls `get()`       | Once set, value is delivered       |
| Waits (blocks)      | Completes and returns              |

---

## 📍 Output:

```
Waiting for result...
Result received: 42
```

---

## 🛠 Real Use Case: Download Manager

### Problem:

You start downloading a file in one thread. The main thread wants to wait until the download finishes and get its size.

### Solution:

* Download thread sets the file size using `std::promise`
* Main thread waits for the result using `std::future`

```cpp
void downloadFile(std::promise<int>&& sizePromise) {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Download complete!\n";
    sizePromise.set_value(1024);  // Size in KB
}

int main() {
    std::promise<int> p;
    std::future<int> f = p.get_future();

    std::thread downloader(downloadFile, std::move(p));
    std::cout << "Waiting for download...\n";
    
    int fileSize = f.get();
    std::cout << "Downloaded file size: " << fileSize << " KB\n";

    downloader.join();
    return 0;
}
```

---

## ❗ Important Notes

* Once a `promise` sets the value, it **can’t be changed again**.
* `future.get()` **blocks** until the value is available.
* Use `promise.set_exception()` to transfer errors.
* `promise` should be **moved** into thread (`std::move`).

---

## 🆚 Difference Between `std::async` and `promise`+`future`

| Feature                        | `std::async`             | `promise` + `future`         |
| ------------------------------ | ------------------------ | ---------------------------- |
| Simplified launch              | Yes                      | No                           |
| Control over when value is set | No                       | Yes — manually `set_value()` |
| Use in thread pool             | Limited                  | Great flexibility            |
| Exception transfer             | Automatically via future | You can manually pass it     |

---

## 🧪 Advanced: Passing Exceptions

```cpp
void worker(std::promise<int>&& p) {
    try {
        throw std::runtime_error("Something went wrong!");
    } catch (...) {
        p.set_exception(std::current_exception());
    }
}

int main() {
    std::promise<int> p;
    std::future<int> f = p.get_future();

    std::thread t(worker, std::move(p));

    try {
        int val = f.get();  // Will rethrow exception
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << '\n';
    }

    t.join();
}
```

---

## 📚 Summary 

* **`promise`** = Send value from thread
* **`future`** = Receive value in thread
* Used for **asynchronous communication**
* Use **`.get()`** to wait and retrieve
* Perfect for **beginner-friendly thread communication**

---
