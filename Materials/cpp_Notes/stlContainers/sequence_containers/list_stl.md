---

# C++ STL `list` Container 

---

## 🧠 1. What is `std::list`?

`std::list` is a **sequence container** in C++ STL implemented as a **doubly linked list**. Unlike arrays or vectors, it allows **efficient insertion and deletion at any position** (including middle), but **does not provide random access**.

Each element in a list holds:

* The value (data).
* A pointer to the **previous** node.
* A pointer to the **next** node.

---

## ✅ 2. Why Use `std::list`?

| Feature                           | Benefit                                                                             |
| --------------------------------- | ----------------------------------------------------------------------------------- |
| Fast insertions/removals anywhere | O(1) at front/back, O(1) with iterator                                              |
| Doubly linked structure           | Allows forward and backward traversal                                               |
| Stable iterators                  | Insertions/removals don’t invalidate other iterators (unless the element is erased) |
| Built-in sorting and splicing     | Can sort, merge, and splice without extra memory or copying                         |

---

## 🌐 3. Real-Time Use Cases

* **Task scheduling queues** with priorities (insert anywhere).
* **Undo-redo mechanisms**.
* **Editor buffers** for fast text editing.
* **Job dispatch queues** that require frequent insertions/removals from both ends or middle.
* **Navigable history logs** with forward/backward traversals.

---

## 🧾 4. Syntax

```cpp
#include <list>

std::list<datatype> list_name;
std::list<datatype> list_name(size);               // default-initialized
std::list<datatype> list_name(size, initial_value);
std::list<datatype> list_name = { val1, val2, ... };
```

---

## ⚙️ 5. Complete Working Example

```cpp
#include <iostream>
#include <list>
#include <algorithm>

void printList(const std::list<int>& lst) {
    for (int val : lst) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    std::list<int> myList = {10, 20, 30};

    myList.push_front(5);      // Add at front
    myList.push_back(40);      // Add at back

    std::cout << "After push_front and push_back:\n";
    printList(myList);

    myList.pop_front();        // Remove from front
    myList.pop_back();         // Remove from back

    std::cout << "After pop_front and pop_back:\n";
    printList(myList);

    auto it = myList.begin();
    std::advance(it, 1);       // Move iterator to second element
    myList.insert(it, 15);     // Insert before 2nd element

    std::cout << "After insert at 2nd position:\n";
    printList(myList);

    it = myList.begin();
    std::advance(it, 1);
    myList.erase(it);          // Erase 2nd element

    std::cout << "After erase at 2nd position:\n";
    printList(myList);

    myList.push_back(25);
    myList.push_back(5);
    myList.push_back(20);
    std::cout << "Before sorting:\n";
    printList(myList);

    myList.sort();             // Sort list
    std::cout << "After sort:\n";
    printList(myList);

    myList.unique();           // Remove consecutive duplicates
    std::cout << "After unique:\n";
    printList(myList);

    myList.reverse();          // Reverse the list
    std::cout << "After reverse:\n";
    printList(myList);

    return 0;
}
```

---

## 📚 6. All Member Functions of `std::list`

### 🧩 Modifiers

| Function             | Description                            |
| -------------------- | -------------------------------------- |
| `push_back(val)`     | Adds `val` at the end                  |
| `push_front(val)`    | Adds `val` at the front                |
| `pop_back()`         | Removes element at end                 |
| `pop_front()`        | Removes element at front               |
| `insert(pos, val)`   | Inserts `val` before `pos`             |
| `emplace(pos, val)`  | Constructs `val` in-place before `pos` |
| `emplace_back(val)`  | Constructs at end                      |
| `emplace_front(val)` | Constructs at front                    |
| `erase(pos)`         | Removes element at `pos`               |
| `clear()`            | Removes all elements                   |
| `assign(n, val)`     | Assigns `n` copies of `val`            |
| `resize(n)`          | Changes list size to `n`               |
| `swap(list2)`        | Swaps contents with another list       |

### 🧪 Access

| Function  | Description   |
| --------- | ------------- |
| `front()` | First element |
| `back()`  | Last element  |

### 🚀 Capacity

| Function     | Description                   |
| ------------ | ----------------------------- |
| `empty()`    | Returns true if list is empty |
| `size()`     | Number of elements            |
| `max_size()` | Maximum elements possible     |

### 🧮 Operations

| Function             | Description                                             |
| -------------------- | ------------------------------------------------------- |
| `sort()`             | Sorts list                                              |
| `unique()`           | Removes consecutive duplicates                          |
| `merge(list2)`       | Merges two sorted lists                                 |
| `reverse()`          | Reverses list                                           |
| `splice(pos, list2)` | Moves all elements from `list2` into this list at `pos` |
| `remove(val)`        | Removes all elements equal to `val`                     |
| `remove_if(cond)`    | Removes elements satisfying condition                   |
| `clear()`            | Removes all elements                                    |

### 🧭 Iterators

| Function              | Description                 |
| --------------------- | --------------------------- |
| `begin()` / `end()`   | Iterators for start and end |
| `rbegin()` / `rend()` | Reverse iterators           |
| `cbegin()` / `cend()` | Const iterators             |

---

## 🧪 7. Example: All Methods in Action

```cpp
#include <iostream>
#include <list>

bool isOdd(int x) { return x % 2 != 0; }

int main() {
    std::list<int> l1 = {10, 20, 20, 30, 40};

    l1.push_front(5);
    l1.push_back(50);
    l1.emplace_back(60);
    l1.emplace_front(2);
    l1.insert(l1.begin(), 1);

    std::cout << "List after insertions:\n";
    for (int x : l1) std::cout << x << " ";
    std::cout << "\n";

    l1.remove(20);             // Remove all 20s
    std::cout << "After remove(20):\n";
    for (int x : l1) std::cout << x << " ";
    std::cout << "\n";

    l1.remove_if(isOdd);       // Remove odd numbers
    std::cout << "After remove_if (odd):\n";
    for (int x : l1) std::cout << x << " ";
    std::cout << "\n";

    l1.reverse();
    std::cout << "After reverse:\n";
    for (int x : l1) std::cout << x << " ";
    std::cout << "\n";

    l1.clear();
    std::cout << "Size after clear: " << l1.size() << "\n";

    return 0;
}
```

---

## 🧮 8. Comparison: `list` vs `vector` vs `deque`

| Feature                  | `list`                          | `vector`             | `deque`                   |
| ------------------------ | ------------------------------- | -------------------- | ------------------------- |
| Memory layout            | Non-contiguous                  | Contiguous           | Segment-based             |
| Random access (`[]`)     | ❌                               | ✅                    | ✅                         |
| Insert/delete front/back | ✅ (fast)                        | ❌ (slow front)       | ✅                         |
| Insert/delete middle     | ✅                               | ❌                    | ❌                         |
| Sorting                  | ✅ (built-in)                    | ✅ (via `sort`)       | ✅                         |
| Preferred when           | Frequent insert/delete anywhere | Random access needed | Double-ended queue needed |

---

## 🧵 9. Compilation & Execution

```bash
g++ -std=c++11 stl_list_example.cpp -o list
./list
```

---

## 🧾 10. Summary

| Concept                    | Description                                   |
| -------------------------- | --------------------------------------------- |
| Structure                  | Doubly linked list                            |
| Best for                   | Frequent insertions/deletions at any position |
| Not suitable for           | Random access                                 |
| Has built-in functions for | Sorting, merging, splicing, unique removal    |
| Preferred in               | Undo-redo, editor buffers, command history    |

---
