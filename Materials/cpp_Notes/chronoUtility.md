<h1 align="center">Chrono Utility/Lib</h1>
1. **What is `chrono`?**
2. **Why use `chrono`?**
3. **Core Concepts and Terminology**
4. **Syntax and Features**
5. **Example Programs**
6. **Real-time Use Cases**
7. **Extended Features**
8. **Best Practices**

---

## 🌟 1. What is `chrono` in C++?

The `chrono` library, introduced in **C++11**, is part of the **C++ Standard Library** used to **represent and manipulate time**. It provides features to work with:

* Time durations (e.g., 5 seconds)
* Time points (e.g., current time)
* Clocks (e.g., system time, steady time)

---

## ✅ 2. Why use `chrono`?

* **Portable** and **standardized** way to measure time.
* High **precision** (nanoseconds-level).
* Avoids platform-dependent APIs (like `<ctime>` or `time.h`).
* Helps in:

  * Benchmarking code
  * Timeouts
  * Delays and sleeping
  * Real-time event scheduling

---

## 📘 3. Core Concepts and Terminology

| Term         | Description                                                     |
| ------------ | --------------------------------------------------------------- |
| `duration`   | Represents the length of time (e.g., 2 hours, 10 milliseconds). |
| `time_point` | Represents a point in time (like "now").                        |
| `clock`      | Provides current time and duration calculation.                 |

### ➕ Namespaces:

All chrono types are under `std::chrono`.

---

## 🧩 4. Syntax and Features

### 4.1. Getting Current Time

```cpp
#include <iostream>
#include <chrono>

int main() {
    auto now = std::chrono::system_clock::now();
    std::time_t timeNow = std::chrono::system_clock::to_time_t(now);

    std::cout << "Current time: " << std::ctime(&timeNow);
}
```

---

### 4.2. Measuring Execution Time

```cpp
#include <iostream>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    // Simulated work
    for (int i = 0; i < 1000000; ++i);

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution Time: " << duration.count() << " microseconds\n";
}
```

---

### 4.3. Sleeping (Delays)

```cpp
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    std::cout << "Waiting for 3 seconds...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Done!\n";
}
```

---

## 📦 5. Example Programs

### Example 1: Convert Duration

```cpp
#include <iostream>
#include <chrono>

int main() {
    std::chrono::minutes mins(5);
    std::chrono::seconds secs = std::chrono::duration_cast<std::chrono::seconds>(mins);

    std::cout << "5 minutes = " << secs.count() << " seconds\n";
}
```

---

### Example 2: Event Timer

```cpp
#include <iostream>
#include <chrono>
#include <thread>

void start_timer(int seconds) {
    std::cout << "Starting countdown for " << seconds << " seconds:\n";
    for (int i = seconds; i > 0; --i) {
        std::cout << i << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Time's up!\n";
}

int main() {
    start_timer(5);
}
```

---

## 🏗️ 6. Real-time Use Cases

| Use Case            | Application                                  |
| ------------------- | -------------------------------------------- |
| Benchmarking        | Measure performance of a function.           |
| Animation/Game Loop | Control frame rate using sleep and duration. |
| Timeouts            | Break operations if they take too long.      |
| Scheduled Tasks     | Run a function every X seconds.              |
| Stopwatch           | Start/Stop timer in apps.                    |

---

## 🛠️ 7. Extended Features in `chrono`

### 7.1. Duration Arithmetic

```cpp
std::chrono::seconds s1(10);
std::chrono::seconds s2(5);
auto total = s1 + s2;  // 15 seconds
std::cout << total.count();
```

### 7.2. Custom Duration Types

```cpp
using namespace std::chrono;
duration<int, std::milli> ms(1500);  // 1500 milliseconds
std::cout << ms.count() << " ms\n";
```

### 7.3. Different Clocks

| Clock Type              | Description                                                                                       |
| ----------------------- | ------------------------------------------------------------------------------------------------- |
| `system_clock`          | Represents the real-world time.                                                                   |
| `steady_clock`          | Monotonic (never goes backward).                                                                  |
| `high_resolution_clock` | Highest available precision (can be either `system_clock` or `steady_clock` implementation-wise). |

```cpp
auto start = std::chrono::steady_clock::now();
```

---

## 🧠 8. Best Practices

* Use `steady_clock` when measuring durations (to avoid issues if system time changes).
* Use `duration_cast` to convert between time units.
* Avoid using `system_clock` for duration measurements.
* Prefer `std::this_thread::sleep_for()` instead of platform-specific sleep APIs.
* Always suffix time types with explicit units like `seconds`, `milliseconds`.

---

## 🧾 Bonus: User-defined Timer Class

```cpp
#include <iostream>
#include <chrono>

class Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;

public:
    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "Timer took " << duration.count() << " seconds\n";
    }
};

int main() {
    Timer t;
    for (int i = 0; i < 1000000; ++i);
}
```

---

## 📚 Summary Table

| Feature          | Syntax                          | Notes                                 |
| ---------------- | ------------------------------- | ------------------------------------- |
| Get current time | `auto now = clock::now();`      | Use `system_clock` or `steady_clock`. |
| Measure duration | `end - start`                   | Use `duration_cast`.                  |
| Sleep            | `std::this_thread::sleep_for()` | Use `seconds`, `milliseconds`, etc.   |
| Convert duration | `duration_cast<unit>()`         | Converts between time units.          |

---

## 🎯 Final Thoughts

* `chrono` is your go-to **standard C++ time library**.
* Helps in writing **portable, accurate, and readable** code involving time.
* Use `chrono` with **modern C++ features** like `auto`, `RAII`, and `constexpr`.

---
