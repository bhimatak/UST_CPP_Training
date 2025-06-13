# C++ Multithreading Tutorial

## Table of Contents

1. Introduction to Multithreading in C++
2. Why Multithreading?
3. Threads in C++: Basics
4. std::thread Class
5. Passing Arguments to Threads
6. Thread Synchronization
7. Mutex and Lock
8. Deadlock and Avoidance
9. std::unique\_lock
10. std::lock\_guard
11. Condition Variables
12. Thread-safe Containers
13. Real-time Use Case Example
14. Summary and Best Practices
15. Advanced Concurrency Features
16. Full Thread Pool Implementation
17. Concurrency Patterns

---

## 1. Introduction to Multithreading in C++

Multithreading is a programming technique where multiple threads execute independently but share the same address space. It allows applications to be more responsive and efficient by doing multiple operations simultaneously.

### What is a Thread?

A thread is a lightweight unit of a process. Each thread shares the code, data, and files of the process but has its own stack and registers.

---

## 2. Why Multithreading?

* **Responsiveness**: GUI apps remain responsive during intensive computation.
* **Performance**: Utilizes multiple CPU cores.
* **Parallelism**: Run independent tasks concurrently.
* **Resource Sharing**: Threads within a process share memory.

**Example:**

* Downloading files while updating progress bar.
* Gaming: Physics, rendering, AI can run in parallel.

---

## 3. Threads in C++: Basics

C++11 introduced `std::thread` class in the `<thread>` header.

```cpp
#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello from thread!\n";
}

int main() {
    std::thread t(hello);
    t.join();
    return 0;
}
```

* `t.join()`: Waits for the thread to finish.
* `t.detach()`: Runs independently and detaches from main thread.

---

## 4. std::thread Class

Supports various ways to launch threads:

```cpp
void task(int x) { std::cout << x * x << std::endl; }

int main() {
    std::thread t1(task, 5);
    t1.join();
}
```

---

## 5. Passing Arguments to Threads

### By Value

```cpp
void show(int x) { std::cout << x << "\n"; }
std::thread t1(show, 100);  // Passes copy
```

### By Reference

```cpp
void update(int &x) { x += 10; }
int main() {
    int val = 5;
    std::thread t(update, std::ref(val));
    t.join();
    std::cout << val; // 15
}
```

---

## 6. Thread Synchronization

To avoid race conditions:

* **Race Condition**: Multiple threads modify shared data.
* **Solution**: Use `std::mutex`

```cpp
std::mutex mtx;
int counter = 0;

void increment() {
    mtx.lock();
    ++counter;
    mtx.unlock();
}
```

---

## 7. Mutex and Lock

### Using std::lock\_guard

```cpp
void safe_increment() {
    std::lock_guard<std::mutex> lock(mtx);
    ++counter;
}
```

### Using std::unique\_lock

```cpp
void unique_increment() {
    std::unique_lock<std::mutex> lock(mtx);
    ++counter;
    lock.unlock();
}
```

---

## 8. Deadlock and Avoidance

**Deadlock**: Two threads wait indefinitely for each other’s mutex.

### Avoidance

* Always acquire locks in the same order.
* Use `std::lock()` to acquire multiple locks safely.

```cpp
std::mutex m1, m2;

void task() {
    std::lock(m1, m2);
    std::lock_guard<std::mutex> lg1(m1, std::adopt_lock);
    std::lock_guard<std::mutex> lg2(m2, std::adopt_lock);
}
```

---

## 9. std::unique\_lock vs std::lock\_guard

| Feature     | std::unique\_lock | std::lock\_guard |
| ----------- | ----------------- | ---------------- |
| Flexibility | More              | Less             |
| Lock/Unlock | Manual            | Automatic        |
| Overhead    | Slightly more     | Less             |

---

## 10. Condition Variables

Used to notify one or more threads about events.

```cpp
std::condition_variable cv;
bool ready = false;

void worker() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });
    std::cout << "Thread processing...\n";
}

void notifier() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();
}
```

---

## 11. Thread-safe Containers

Standard containers are not thread-safe.

Use `mutex` or use `concurrent` containers from libraries like:

* Intel TBB
* Microsoft PPL
* Boost

```cpp
std::vector<int> v;
std::mutex v_mutex;

void add_to_vector(int val) {
    std::lock_guard<std::mutex> lock(v_mutex);
    v.push_back(val);
}
```

---

## 12. Real-time Use Case Example

### Banking Transaction System

* One thread updates balance.
* Another prints report.
* Use mutex to protect account balance.

```cpp
class BankAccount {
    int balance;
    std::mutex m;
public:
    BankAccount() : balance(0) {}
    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(m);
        balance += amount;
    }
    int get_balance() {
        std::lock_guard<std::mutex> lock(m);
        return balance;
    }
};
```

---

## 13. Summary and Best Practices

* Always `join()` or `detach()` threads.
* Use `std::lock_guard` or `std::unique_lock`.
* Prefer condition\_variable over busy-wait.
* Protect shared data with mutex.
* Avoid deadlocks using lock ordering or `std::lock()`.
* Test multithreaded code thoroughly.

---
---

## 14. Advanced Concurrency Features

### 1. std::async and std::future

Simplifies thread management by creating asynchronous tasks.

```cpp
#include <future>
#include <iostream>

int compute(int x) {
    return x * x;
}

int main() {
    std::future<int> result = std::async(std::launch::async, compute, 10);
    std::cout << "Result: " << result.get() << std::endl;
}
```

### 2. std::packaged\_task

Wraps a callable and allows retrieving result via future.

```cpp
#include <iostream>
#include <future>

int compute(int a) { return a * 3; }

int main() {
    std::packaged_task<int(int)> task(compute);
    std::future<int> result = task.get_future();
    std::thread t(std::move(task), 7);
    t.join();
    std::cout << "Result: " << result.get();
}
```

### 3. Thread Pools (C++ doesn't have built-in thread pool)

Use external libraries or custom implementation.

---

## 16. Full Thread Pool Implementation



```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;

// Task structure: plain function pointer + void* argument
struct Task {
    void (*func)(void*);
    void* arg;
};

class ThreadPool {
public:
    // Constructor with fixed default value (no hardware_concurrency)
    ThreadPool(size_t num_threads = 4) {
        stop_ = false;
        for (size_t i = 0; i < num_threads; ++i) {
            threads_.emplace_back(&ThreadPool::worker_thread, this);
        }
    }

    // Destructor
    ~ThreadPool() {
        {
            unique_lock<mutex> lock(queue_mutex_);
            stop_ = true;
        }
        cv_.notify_all();
        for (auto& t : threads_) {
            if (t.joinable())
                t.join();
        }
    }

    // Enqueue a raw task
    void enqueue(void (*func)(void*), void* arg) {
        {
            unique_lock<mutex> lock(queue_mutex_);
            tasks_.push({func, arg});
        }
        cv_.notify_one();
    }

private:
    // Worker thread loop
    void worker_thread() {
        while (true) {
            Task task;
            {
                unique_lock<mutex> lock(queue_mutex_);
                while (tasks_.empty() && !stop_) {
                    cv_.wait(lock);
                }
                if (stop_ && tasks_.empty()) {
                    return;
                }
                task = tasks_.front();
                tasks_.pop();
            }
            task.func(task.arg);  // Execute the task
        }
    }

    vector<thread> threads_;
    queue<Task> tasks_;
    mutex queue_mutex_;
    condition_variable cv_;
    bool stop_;
};

// Sample task function
void print_task(void* arg) {
    int id = *static_cast<int*>(arg);
    cout << "Task " << id << " is running on thread "
         << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
}

int main() {
    ThreadPool pool; // Default 4 threads

    int task_ids[5] = {0, 1, 2, 3, 4}; // Must stay alive during execution

    for (int i = 0; i < 5; ++i) {
        pool.enqueue(print_task, &task_ids[i]);
    }

    // Wait for all tasks to finish
    this_thread::sleep_for(chrono::seconds(1));
    return 0;
}
```



---

## 17. Concurrency Patterns

### 1. Producer-Consumer

```cpp
std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv;
bool done = false;

void producer() {
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        {
            std::lock_guard<std::mutex> lock(mtx);
            buffer.push(i);
        }
        cv.notify_one();
    }
    {
        std::lock_guard<std::mutex> lock(mtx);
        done = true;
    }
    cv.notify_all();
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !buffer.empty() || done; });
        while (!buffer.empty()) {
            std::cout << "Consumed: " << buffer.front() << "\n";
            buffer.pop();
        }
        if (done) break;
    }
}
```

### 2. Fork-Join Pattern

```cpp
int parallel_sum(std::vector<int>& data, int start, int end) {
    if (end - start <= 1000) {
        return std::accumulate(data.begin() + start, data.begin() + end, 0);
    }
    int mid = start + (end - start) / 2;
    auto handle = std::async(std::launch::async, parallel_sum, std::ref(data), mid, end);
    int left = parallel_sum(data, start, mid);
    int right = handle.get();
    return left + right;
}
```

This pattern divides work recursively and joins results efficiently.
