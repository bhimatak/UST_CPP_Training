
---

# C++ STL `forward_list` 

---

## 🧠 1. What is `std::forward_list`?

`std::forward_list` is a **singly linked list** container introduced in **C++11**. Unlike `std::list` (which is a doubly linked list), `forward_list` supports **forward traversal only**. It uses less memory per node, making it more **space-efficient** and faster for certain operations like insertions and deletions.

---

## ✅ 2. Why Use `forward_list`?

| Feature                 | Benefit                        |
| ----------------------- | ------------------------------ |
| Singly linked structure | Lower memory overhead          |
| Constant time insertion | Especially at the front        |
| Faster splicing/merging | Compared to `vector` or `list` |
| No random access        | Forces sequential logic        |

---

## 🌐 3. Real-Time Use Cases

* **Message Queues**: Inserting messages at the front or removing oldest ones efficiently.
* **Undo/Redo Stacks**: Keeping a trace of previous states.
* **Custom Memory Allocators**: Where minimal memory footprint is critical.
* **Streaming Data Pipelines**: Lightweight buffering with fast traversal.

---

## 🧾 4. Syntax

```cpp
#include <forward_list>

std::forward_list<int> fl1;                      // Empty list
std::forward_list<int> fl2 = {10, 20, 30};       // Initializer list
std::forward_list<int> fl3(fl2);                 // Copy constructor
std::forward_list<int> fl4(5, 100);              // 5 elements, each 100
```

---

## ⚙️ 5. Complete Example

```cpp
#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> fl = {10, 20, 30};

    // Insert at front
    fl.push_front(5);

    std::cout << "Elements: ";
    for (int n : fl)
        std::cout << n << " ";
    std::cout << "\n";

    // Inserting after a specific position
    auto it = fl.before_begin();  // Special iterator before the first element
    fl.insert_after(it, 1);       // Insert 1 before 5

    std::cout << "After insert_after: ";
    for (int n : fl)
        std::cout << n << " ";
    std::cout << "\n";

    // Remove specific value
    fl.remove(20);

    std::cout << "After remove(20): ";
    for (int n : fl)
        std::cout << n << " ";
    std::cout << "\n";

    // Sort
    fl.sort();
    std::cout << "After sort: ";
    for (int n : fl)
        std::cout << n << " ";
    std::cout << "\n";

    return 0;
}
```

---

## 🧩 6. All Member Functions of `std::forward_list`

### 🔹 Modifiers

| Function                  | Description                                    |
| ------------------------- | ---------------------------------------------- |
| `push_front(val)`         | Adds element at the front                      |
| `pop_front()`             | Removes the front element                      |
| `insert_after(pos, val)`  | Inserts after iterator `pos`                   |
| `emplace_front(val)`      | Constructs in-place at front                   |
| `emplace_after(pos, val)` | Constructs in-place after `pos`                |
| `erase_after(pos)`        | Erases element after `pos`                     |
| `erase_after(pos1, pos2)` | Erases elements in a range                     |
| `remove(val)`             | Removes all occurrences of `val`               |
| `remove_if(pred)`         | Removes elements based on predicate            |
| `assign(n, val)`          | Replaces contents with `n` copies of `val`     |
| `assign(init_list)`       | Assigns from initializer list                  |
| `clear()`                 | Removes all elements                           |
| `resize(n)`               | Resizes the container (only increases allowed) |
| `swap(other)`             | Swaps content with `other`                     |

### 🔍 Capacity and Access

| Function     | Description                                 |
| ------------ | ------------------------------------------- |
| `empty()`    | Checks if list is empty                     |
| `max_size()` | Returns maximum possible number of elements |
| `front()`    | Access first element                        |

### 🔄 Operations

| Function                   | Description                             |
| -------------------------- | --------------------------------------- |
| `merge(other)`             | Merges two sorted lists                 |
| `sort()`                   | Sorts the list                          |
| `reverse()`                | Reverses the list                       |
| `unique()`                 | Removes consecutive duplicates          |
| `splice_after(pos, other)` | Moves elements from `other` after `pos` |

---

## ⚠️ Important: No Random Access!

You **cannot use indexing** like `fl[2]` with `forward_list`. Only **iterators** and **range-based for-loops** are allowed.

---

## 🧪 7. Advanced Example with All Operations

```cpp
#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> fl = {3, 1, 4, 1, 5};

    // Insert and Erase
    auto it = fl.before_begin();
    fl.insert_after(it, 9);
    fl.erase_after(it);

    // Remove and Unique
    fl.remove(1);
    fl.push_front(3);
    fl.unique();  // Remove consecutive duplicates

    // Sort and Reverse
    fl.sort();
    fl.reverse();

    // Merge
    std::forward_list<int> fl2 = {0, 2, 6};
    fl2.sort();
    fl.merge(fl2);  // Both must be sorted

    std::cout << "Final List: ";
    for (int n : fl)
        std::cout << n << " ";
    std::cout << "\n";

    return 0;
}
```

---

## 📌 8. Summary: Pros and Cons

| Pros                            | Cons                                                  |
| ------------------------------- | ----------------------------------------------------- |
| Minimal overhead                | No random access                                      |
| Fast insertion/removal at front | Only forward iteration                                |
| Good for low-memory scenarios   | Cannot resize downward easily                         |
| Ideal for queues, log chains    | Slightly harder syntax (insert\_after, before\_begin) |

---

## 💡 9. Real-Time Use Case

### **Logging System with Limited Memory**

```cpp
#include <iostream>
#include <forward_list>

#define MAX_LOGS 5

void addLog(std::forward_list<std::string>& logs, const std::string& message) {
    logs.push_front(message);
    int count = 0;
    auto it = logs.before_begin();
    for (auto next = logs.begin(); next != logs.end(); ++next) {
        count++;
        if (count >= MAX_LOGS) {
            logs.erase_after(it);
            break;
        }
        ++it;
    }
}

int main() {
    std::forward_list<std::string> logs;

    addLog(logs, "Error: Disk Full");
    addLog(logs, "Warning: High Memory");
    addLog(logs, "Info: Connection Stable");
    addLog(logs, "Info: Heartbeat OK");
    addLog(logs, "Error: Timeout");
    addLog(logs, "Info: Recovery Complete");

    std::cout << "Last " << MAX_LOGS << " Logs:\n";
    for (const auto& log : logs)
        std::cout << log << "\n";

    return 0;
}
```

---

