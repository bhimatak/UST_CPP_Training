---

# C++ STL `deque` Container 

---

## 🧠 1. What is `std::deque`?

`std::deque` (double-ended queue) is a **sequence container** that allows **fast insertion and deletion** of elements **at both the front and back**. Unlike `std::vector`, which supports fast insertion only at the back, `std::deque` offers flexibility at both ends.

It is implemented as a **dynamic array of fixed-size arrays**, making front insertions efficient without needing to shift all elements.

---

## ✅ 2. Why Use `std::deque`?

| Feature                   | Benefit                                |
| ------------------------- | -------------------------------------- |
| Fast front/back insertion | Use `push_front` and `push_back`       |
| Random access like arrays | Fast element access via `[]` or `at()` |
| Automatic resizing        | Handles memory dynamically             |
| Balanced performance      | Between `std::vector` and `std::list`  |

---

## 🌐 3. Real-Time Use Cases

* **Task scheduling systems** (add tasks at front/back).
* **Undo-redo stacks** in applications.
* **Palindrome checkers** using front/back comparison.
* **Sliding window algorithms** for maximum/minimum in ranges.
* **History navigation** in browsers (back/forward).

---

## 🧾 4. Syntax

```cpp
#include <deque>

std::deque<datatype> dq;
std::deque<datatype> dq(size);
std::deque<datatype> dq(size, value);
std::deque<datatype> dq = {val1, val2, ...};
```

---

## ⚙️ 5. Complete Working Code Example

```cpp
#include <iostream>
#include <deque>
#include <algorithm>

void printDeque(const std::deque<int>& dq) {
    for (int num : dq)
        std::cout << num << " ";
    std::cout << "\n";
}

int main() {
    std::deque<int> dq = {10, 20, 30};

    // Insert at both ends
    dq.push_front(5);
    dq.push_back(40);

    std::cout << "After push_front and push_back: ";
    printDeque(dq);

    // Access elements
    std::cout << "Front: " << dq.front() << "\n";
    std::cout << "Back: " << dq.back() << "\n";
    std::cout << "Element at index 2: " << dq.at(2) << "\n";

    // Remove from both ends
    dq.pop_front();
    dq.pop_back();
    std::cout << "After pop_front and pop_back: ";
    printDeque(dq);

    // Insert at specific position
    dq.insert(dq.begin() + 1, 15);
    std::cout << "After insert at index 1: ";
    printDeque(dq);

    // Erase element at specific position
    dq.erase(dq.begin() + 2);
    std::cout << "After erase at index 2: ";
    printDeque(dq);

    // Resize deque
    dq.resize(6, 99);
    std::cout << "After resize to 6: ";
    printDeque(dq);

    // Sort elements
    std::sort(dq.begin(), dq.end());
    std::cout << "After sorting: ";
    printDeque(dq);

    // Clear all elements
    dq.clear();
    std::cout << "Size after clear: " << dq.size() << "\n";

    return 0;
}
```

---

## 📚 6. All Member Functions of `std::deque`

| Method               | Description                                  |
| -------------------- | -------------------------------------------- |
| `push_back(val)`     | Inserts `val` at the end                     |
| `push_front(val)`    | Inserts `val` at the beginning               |
| `pop_back()`         | Removes element from the end                 |
| `pop_front()`        | Removes element from the beginning           |
| `insert(pos, val)`   | Inserts `val` at specified position          |
| `erase(pos)`         | Removes element at specified position        |
| `clear()`            | Removes all elements                         |
| `size()`             | Returns number of elements                   |
| `max_size()`         | Maximum elements deque can hold              |
| `resize(n)`          | Resizes to hold `n` elements                 |
| `resize(n, val)`     | Resizes with `val` for new elements          |
| `empty()`            | Checks if deque is empty                     |
| `front()`            | Returns first element                        |
| `back()`             | Returns last element                         |
| `at(index)`          | Returns element at `index` (bounds-checked)  |
| `operator[]`         | Returns element at `index` (no bounds check) |
| `assign(n, val)`     | Assigns `n` copies of `val`                  |
| `begin(), end()`     | Returns iterators to beginning/end           |
| `rbegin(), rend()`   | Returns reverse iterators                    |
| `cbegin(), cend()`   | Constant iterators                           |
| `shrink_to_fit()`    | Reduces capacity (non-binding request)       |
| `swap(dq2)`          | Swaps contents with another deque            |
| `emplace(pos, val)`  | Constructs in-place at `pos`                 |
| `emplace_back(val)`  | Constructs at end                            |
| `emplace_front(val)` | Constructs at front                          |
| `data()`             | Not available in deque (unlike `vector`)     |

---

## 🧪 7. Extra Example: All Methods in Action

```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq;

    dq.assign(5, 100); // 5 elements with value 100
    std::cout << "After assign: ";
    for (int x : dq) std::cout << x << " ";
    std::cout << "\n";

    dq.push_back(200);
    dq.push_front(50);
    dq.emplace_back(300);
    dq.emplace_front(25);
    std::cout << "After push and emplace: ";
    for (int x : dq) std::cout << x << " ";
    std::cout << "\n";

    dq.insert(dq.begin() + 2, 150);
    dq.emplace(dq.begin() + 3, 175);
    std::cout << "After insert and emplace: ";
    for (int x : dq) std::cout << x << " ";
    std::cout << "\n";

    dq.erase(dq.begin() + 1);
    std::cout << "After erase: ";
    for (int x : dq) std::cout << x << " ";
    std::cout << "\n";

    dq.resize(4);
    std::cout << "After resize: ";
    for (int x : dq) std::cout << x << " ";
    std::cout << "\n";

    dq.swap(std::deque<int>{1, 2, 3});
    std::cout << "After swap: ";
    for (int x : dq) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
```

---

## ⚖️ 8. `deque` vs `vector` vs `list`

| Feature                   | `deque`             | `vector`                 | `list`                            |
| ------------------------- | ------------------- | ------------------------ | --------------------------------- |
| Fast front insert/remove  | ✅                   | ❌                        | ✅                                 |
| Fast back insert/remove   | ✅                   | ✅                        | ✅                                 |
| Random access (via index) | ✅                   | ✅                        | ❌                                 |
| Memory locality           | Moderate            | High                     | Low                               |
| Use case                  | Double-ended access | Stack-like dynamic array | Frequent mid-insertions/deletions |

---

## 🧵 9. Compilation and Execution

```bash
g++ -std=c++11 stl_deque_example.cpp -o deque
./deque
```

---

## 📌 10. Summary

| Feature                      | Benefit                                   |
| ---------------------------- | ----------------------------------------- |
| Fast operations at both ends | `push_front`, `push_back`                 |
| Random access                | Like arrays using `[]`, `at()`            |
| STL-friendly                 | Works with `sort`, `reverse`, etc.        |
| Dynamic sizing               | Grows/shrinks automatically               |
| Practical uses               | Queues, history tracking, sliding windows |

---

