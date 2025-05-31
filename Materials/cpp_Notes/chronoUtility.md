***Chrono Utility/Lib***  
---
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



---

## 🧱 9. Logging Levels

| Level   | Description                        |
| ------- | ---------------------------------- |
| DEBUG   | For developers, verbose output.    |
| INFO    | General runtime messages.          |
| WARNING | Something is off but not critical. |
| ERROR   | Something went wrong.              |

We will create a **logging system** that writes different levels of messages to a **log file**.

---

## ✏️ 10. Complete Code Example: File Handling with Logging Levels

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

// Logging Levels
enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

// Convert log level to string
std::string levelToString(LogLevel level) {
    switch (level) {
        case DEBUG: return "DEBUG";
        case INFO: return "INFO ";
        case WARNING: return "WARN ";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

// Get current time as string
std::string getCurrentTime() {
    std::time_t now = std::time(nullptr);
    std::tm *lt = std::localtime(&now);
    char buffer[32];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", lt);
    return std::string(buffer);
}

// Logger Class
class Logger {
    std::ofstream logFile;

public:
    Logger(const std::string& filename) {
        logFile.open(filename, std::ios::app);  // Append mode
        if (!logFile.is_open()) {
            std::cerr << "Failed to open log file\n";
        }
    }

    ~Logger() {
        if (logFile.is_open())
            logFile.close();
    }

    void log(LogLevel level, const std::string& message) {
        if (logFile.is_open()) {
            logFile << "[" << getCurrentTime() << "] "
                    << "[" << levelToString(level) << "] "
                    << message << std::endl;
        }
    }
};

// Main Application
int main() {
    Logger logger("app.log");

    logger.log(INFO, "Application started");
    logger.log(DEBUG, "Initializing variables");

    int x = 10, y = 0;
    logger.log(DEBUG, "x = 10, y = 0");

    if (y == 0) {
        logger.log(WARNING, "Attempt to divide by zero");
        logger.log(ERROR, "Division failed due to zero denominator");
    } else {
        int z = x / y;
        logger.log(INFO, "Division successful: " + std::to_string(z));
    }

    logger.log(INFO, "Application ended");
    return 0;
}
```

---

### 📂 Output in `app.log`:

```
[2025-05-31 14:25:01] [INFO ] Application started
[2025-05-31 14:25:01] [DEBUG] Initializing variables
[2025-05-31 14:25:01] [DEBUG] x = 10, y = 0
[2025-05-31 14:25:01] [WARN ] Attempt to divide by zero
[2025-05-31 14:25:01] [ERROR] Division failed due to zero denominator
[2025-05-31 14:25:01] [INFO ] Application ended
```

---

## 📚 11. Explanation of the Code

| Component        | Role                                         |
| ---------------- | -------------------------------------------- |
| `ofstream`       | Writes to a file (`app.log`).                |
| `enum LogLevel`  | Defines four logging levels.                 |
| `levelToString`  | Converts enum to string label.               |
| `getCurrentTime` | Fetches timestamp for each log.              |
| `Logger` class   | Manages file creation, logging, and closure. |

---

## 🧪 12. Real-time Use Cases

| Scenario              | How File Handling Helps         |
| --------------------- | ------------------------------- |
| Debugging software    | Use `DEBUG` to trace flow.      |
| Monitoring servers    | Use `INFO` for routine status.  |
| Handling exceptions   | Use `ERROR` for crash logs.     |
| Maintenance alerts    | Use `WARNING` to detect issues. |
| Auditing & compliance | Permanent log files for review. |

---

## 🧠 13. Best Practices

* Always **close files** using destructor or `RAII`.
* Use **timestamps** to track events.
* Separate **logging logic** into reusable classes.
* Use `std::flush` if real-time logs are critical.
* Don’t mix `cout` and file logging in production apps.

---

## 🎯 Summary Table

| Task                  | Code                                             |
| --------------------- | ------------------------------------------------ |
| Include file handling | `#include <fstream>`                             |
| Open file for logging | `logFile.open("file.txt", std::ios::app);`       |
| Write to file         | `logFile << "data";`                             |
| Add timestamp         | Use `std::time` and `strftime`                   |
| Enum-based log levels | `enum LogLevel { DEBUG, INFO, WARNING, ERROR };` |

---

## 📦 Optional Enhancements

* Add **log rotation** (e.g., one log per day).
* Include **thread safety** using `std::mutex`.
* Make logger a **singleton class**.
* Write logs in **JSON or CSV** format.

---



## ⏱️ **Why Use `<chrono>` in Logging?**

* Provides **precise timestamps** with millisecond or microsecond accuracy.
* Useful for **debugging performance issues** or time-sensitive applications.
* Works well with modern C++ (C++11 and beyond).
* Replaces legacy C-style time functions for better type safety and control.

---

## ✅ Updated Code with `std::chrono` Timestamp Logging

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <chrono>
#include <sstream>

// Logging Levels
enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

// Convert log level to string
std::string levelToString(LogLevel level) {
    switch (level) {
        case DEBUG: return "DEBUG";
        case INFO: return "INFO ";
        case WARNING: return "WARN ";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

// Get current time in "YYYY-MM-DD HH:MM:SS.mmm" format using chrono
std::string getCurrentTime() {
    using namespace std::chrono;

    auto now = system_clock::now();
    auto in_time_t = system_clock::to_time_t(now);
    auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
    oss << "." << std::setfill('0') << std::setw(3) << ms.count();
    return oss.str();
}

// Logger Class
class Logger {
    std::ofstream logFile;

public:
    Logger(const std::string& filename) {
        logFile.open(filename, std::ios::app);  // Append mode
        if (!logFile.is_open()) {
            std::cerr << "Failed to open log file\n";
        }
    }

    ~Logger() {
        if (logFile.is_open())
            logFile.close();
    }

    void log(LogLevel level, const std::string& message) {
        if (logFile.is_open()) {
            logFile << "[" << getCurrentTime() << "] "
                    << "[" << levelToString(level) << "] "
                    << message << std::endl;
        }
    }
};

// Main Application
int main() {
    Logger logger("app.log");

    logger.log(INFO, "Application started");
    logger.log(DEBUG, "Initializing variables");

    int x = 10, y = 0;
    logger.log(DEBUG, "x = 10, y = 0");

    if (y == 0) {
        logger.log(WARNING, "Attempt to divide by zero");
        logger.log(ERROR, "Division failed due to zero denominator");
    } else {
        int z = x / y;
        logger.log(INFO, "Division successful: " + std::to_string(z));
    }

    logger.log(INFO, "Application ended");
    return 0;
}
```

---

## 🧪 Sample Output in `app.log`

```
[2025-05-31 14:26:13.412] [INFO ] Application started
[2025-05-31 14:26:13.412] [DEBUG] Initializing variables
[2025-05-31 14:26:13.412] [DEBUG] x = 10, y = 0
[2025-05-31 14:26:13.412] [WARN ] Attempt to divide by zero
[2025-05-31 14:26:13.412] [ERROR] Division failed due to zero denominator
[2025-05-31 14:26:13.413] [INFO ] Application ended
```

> 🕒 Note how milliseconds are included (e.g., `.412`) — this is made possible with `std::chrono`.

---

## 🧠 Theory Recap of `std::chrono` Used

| Component                              | Purpose                                   |
| -------------------------------------- | ----------------------------------------- |
| `std::chrono::system_clock`            | Represents wall-clock time                |
| `std::chrono::now()`                   | Captures current system time              |
| `std::chrono::duration_cast`           | Converts to desired resolution (e.g., ms) |
| `std::chrono::milliseconds`            | Millisecond precision                     |
| `std::put_time` + `std::ostringstream` | Format time output cleanly                |

---

## 🎯 Benefits of Using `chrono` in File Handling and Logging

* 🌟 High-resolution time down to **milliseconds/microseconds**
* 📋 Accurate profiling for performance-critical systems
* ✅ Portable and type-safe (standard C++11+)
* 🔧 Easy to extend to time duration measurement for profiling

---

## ➕ Optional Extensions

| Feature                                     | How to Implement                                       |
| ------------------------------------------- | ------------------------------------------------------ |
| ✅ Log execution time of code blocks         | Use `steady_clock::now()` and compute duration         |
| ✅ Log timestamps in UTC                     | Replace `localtime` with `gmtime`                      |
| ✅ Log to different files based on log level | Create multiple `ofstream` objects                     |
| ✅ Add console + file output                 | Use both `std::cout` and `logFile` in `log()` function |

---

