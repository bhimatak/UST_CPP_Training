---

## ✅ 1. `std::array` – Use Case: **Sensor Readings in Embedded Systems**

### 🧠 Why?

Fixed-size arrays are ideal in memory-constrained environments like embedded systems, where the number of readings is known and doesn't change.

### 📌 Scenario:

Storing 5 temperature sensor readings and finding their average.

### ✅ Code:

```cpp
#include <iostream>
#include <array>

int main() {
    std::array<float, 5> temps = {36.5, 37.0, 36.8, 37.1, 36.9};
    float sum = 0;

    for (float temp : temps)
        sum += temp;

    std::cout << "Average temperature: " << sum / temps.size() << "°C\n";
    return 0;
}
```

---

## ✅ 2. `std::vector` – Use Case: **Dynamic User Inputs**

### 🧠 Why?

`std::vector` allows dynamic resizing, making it ideal when the number of inputs is unknown at compile time.

### 📌 Scenario:

Reading a list of scores from users and computing the highest score.

### ✅ Code:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> scores;
    int score;

    std::cout << "Enter scores (-1 to stop): ";
    while (std::cin >> score && score != -1)
        scores.push_back(score);

    auto max_score = *std::max_element(scores.begin(), scores.end());
    std::cout << "Highest score: " << max_score << "\n";
    return 0;
}
```

---

## ✅ 3. `std::list` – Use Case: **Task Scheduling with Prioritized Insertions and Removals**

### 🧠 Why?

Doubly-linked lists are ideal when frequent insertions/removals occur at both ends or in the middle.

### 📌 Scenario:

A to-do list where urgent tasks can be inserted before less important ones.

### ✅ Code:

```cpp
#include <iostream>
#include <list>
#include <string>

int main() {
    std::list<std::string> tasks = {"Pay bills", "Buy groceries", "Check email"};
    auto it = std::find(tasks.begin(), tasks.end(), "Buy groceries");
    tasks.insert(it, "Urgent: Doctor Appointment");

    std::cout << "Task List:\n";
    for (const auto& task : tasks)
        std::cout << "- " << task << "\n";

    tasks.remove("Check email");
    std::cout << "\nUpdated Task List:\n";
    for (const auto& task : tasks)
        std::cout << "- " << task << "\n";

    return 0;
}
```

---

## ✅ 4. `std::forward_list` – Use Case: **Lightweight Logging System**

### 🧠 Why?

`forward_list` is a singly-linked list using less memory, suitable for keeping a history of events/logs with fast insertions at the front.

### 📌 Scenario:

Storing the last N log messages in a monitoring tool.

### ✅ Code:

```cpp
#include <iostream>
#include <forward_list>
#include <string>

void addLog(std::forward_list<std::string>& logs, const std::string& msg, int max_logs) {
    logs.push_front(msg);
    auto it = logs.before_begin();
    int count = 0;
    for (auto next = logs.begin(); next != logs.end(); ++next) {
        ++count;
        if (count == max_logs) {
            logs.erase_after(it);
            break;
        }
        ++it;
    }
}

int main() {
    std::forward_list<std::string> logs;
    int max_logs = 3;

    addLog(logs, "Booting system...", max_logs);
    addLog(logs, "Checking disk...", max_logs);
    addLog(logs, "Network initialized", max_logs);
    addLog(logs, "Service started", max_logs);

    std::cout << "Recent logs:\n";
    for (const auto& log : logs)
        std::cout << log << "\n";

    return 0;
}
```

---

## ✅ 5. `std::deque` – Use Case: **Browser History (Forward & Back Navigation)**

### 🧠 Why?

Double-ended queues allow insertion and deletion from both ends, suitable for maintaining recent browsing history with forward and back navigation.

### 📌 Scenario:

Maintaining recent visited pages.

### ✅ Code:

```cpp
#include <iostream>
#include <deque>
#include <string>

int main() {
    std::deque<std::string> history;

    // Simulating browsing
    history.push_back("google.com");
    history.push_back("openai.com");
    history.push_back("github.com");

    std::cout << "Current Page: " << history.back() << "\n";

    // Go back
    history.pop_back();
    std::cout << "Back to: " << history.back() << "\n";

    // Add new site, clearing forward history (not shown in code)
    history.push_back("cppreference.com");
    std::cout << "Visited new: " << history.back() << "\n";

    std::cout << "\nBrowsing History:\n";
    for (const auto& site : history)
        std::cout << "- " << site << "\n";

    return 0;
}
```

---

## 🧾 Summary Table

| Container      | Use Case                            | Key Feature                           |
| -------------- | ----------------------------------- | ------------------------------------- |
| `array`        | Fixed-size sensor logs              | Compile-time size, fast access        |
| `vector`       | User input list                     | Dynamic resizing                      |
| `list`         | Task queue with priority insertions | Fast insert/delete anywhere           |
| `forward_list` | Lightweight logs                    | Fast front insertions, minimal memory |
| `deque`        | Browser history navigation          | Fast front and back insert/delete     |

---
