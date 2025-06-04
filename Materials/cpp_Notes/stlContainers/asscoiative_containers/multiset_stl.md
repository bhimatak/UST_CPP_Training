
---

<h1 align="center"> C++ STL multiset</h1> 

---

## ✅ 1. What is `std::multiset`?

* A `multiset` is an **ordered associative container** in C++ that stores **duplicate elements in sorted order**.
* Internally implemented using a **Red-Black Tree** (self-balancing BST).
* It **automatically sorts** the elements upon insertion, just like `set`.

---

## ✅ 2. Key Differences from `set`

| Feature           | `set`       | `multiset`        |
| ----------------- | ----------- | ----------------- |
| Uniqueness        | Only unique | Allows duplicates |
| Auto-sorted       | Yes         | Yes               |
| Search Efficiency | O(log n)    | O(log n)          |

---

## ✅ 3. Why Use `multiset`?

Use `multiset` when:

* You need elements **in sorted order**
* **Duplicates** must be preserved
* You want **fast search**, insertion, and deletion (`O(log n)`)

---

## ✅ 4. Real-World Use Case

🔧 **Example**: A store tracks customer purchases per product. If 3 people buy "apple", it’s inserted 3 times. But you want the names sorted automatically.

---

## ✅ 5. Syntax

```cpp
#include <set>
std::multiset<int> ms;
ms.insert(10);
ms.insert(10); // allowed
```

---

## ✅ 6. Full Working Example – All Methods

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> scores;

    // insert()
    scores.insert(70);
    scores.insert(85);
    scores.insert(70); // duplicates allowed
    scores.insert(90);
    scores.insert(85);

    std::cout << "Initial multiset:\n";
    for (int x : scores)
        std::cout << x << " ";
    std::cout << "\n";

    // count()
    std::cout << "Count of 70: " << scores.count(70) << "\n";
    std::cout << "Count of 85: " << scores.count(85) << "\n";

    // find()
    auto it = scores.find(85);
    if (it != scores.end())
        std::cout << "Found 85 at iterator.\n";

    // equal_range()
    std::cout << "\nAll 85s:\n";
    auto range = scores.equal_range(85);
    for (auto i = range.first; i != range.second; ++i)
        std::cout << *i << " ";

    // erase() one instance
    std::cout << "\n\nErasing one '85'\n";
    scores.erase(scores.find(85)); // erases only one
    for (int x : scores)
        std::cout << x << " ";

    // erase() all 70s
    std::cout << "\n\nErasing all '70'\n";
    scores.erase(70); // erases all 70s
    for (int x : scores)
        std::cout << x << " ";

    // size()
    std::cout << "\n\nSize of multiset: " << scores.size() << "\n";

    // empty()
    std::cout << "Is empty? " << (scores.empty() ? "Yes" : "No") << "\n";

    // clear()
    scores.clear();
    std::cout << "Cleared. Size now: " << scores.size() << "\n";

    // insert again for bounds
    scores.insert({30, 40, 50, 60});

    // lower_bound() and upper_bound()
    std::cout << "\nLower bound of 45: ";
    auto lb = scores.lower_bound(45);
    if (lb != scores.end()) std::cout << *lb << "\n";

    std::cout << "Upper bound of 50: ";
    auto ub = scores.upper_bound(50);
    if (ub != scores.end()) std::cout << *ub << "\n";

    // swap()
    std::multiset<int> ms2 = {100, 200};
    scores.swap(ms2);

    std::cout << "\nAfter swap:\nScores: ";
    for (int x : scores)
        std::cout << x << " ";
    std::cout << "\nMS2: ";
    for (int x : ms2)
        std::cout << x << " ";

    return 0;
}
```

---

## ✅ 7. Output

```
Initial multiset:
70 70 85 85 90 
Count of 70: 2
Count of 85: 2
Found 85 at iterator.

All 85s:
85 85 

Erasing one '85'
70 70 85 90 

Erasing all '70'
85 90 

Size of multiset: 2
Is empty? No
Cleared. Size now: 0

Lower bound of 45: 50
Upper bound of 50: 60

After swap:
Scores: 100 200 
MS2: 30 40 50 60 
```

---

## ✅ 8. Methods Summary

| Method             | Description                                  |
| ------------------ | -------------------------------------------- |
| `insert(val)`      | Insert value (duplicates allowed)            |
| `erase(val)`       | Erase **all** occurrences of `val`           |
| `erase(it)`        | Erase one occurrence at iterator             |
| `find(val)`        | Returns iterator to first occurrence         |
| `count(val)`       | Count occurrences of `val`                   |
| `equal_range(val)` | Returns range of all elements equal to `val` |
| `lower_bound(val)` | First element ≥ val                          |
| `upper_bound(val)` | First element > val                          |
| `size()`           | Number of elements                           |
| `empty()`          | Is container empty?                          |
| `clear()`          | Erase all elements                           |
| `swap(other)`      | Swaps contents with another multiset         |
| `begin()/end()`    | Iterators to start and end                   |

---

## ✅ 9. When to Prefer `multiset`

* Counting or tracking **frequencies** of values but keeping order.
* Need **automatic sorting** and **duplicates allowed**.
* Log analysis, frequency of scores, counting repeated events.

---

## ✅ 10. Comparison Table

| Feature       | `set`          | `multiset`     | `unordered_multiset` |
| ------------- | -------------- | -------------- | -------------------- |
| Duplicates    | ❌ No           | ✅ Yes          | ✅ Yes                |
| Ordering      | ✅ Sorted       | ✅ Sorted       | ❌ Not sorted         |
| Performance   | `O(log n)`     | `O(log n)`     | `O(1)` average       |
| Underlying DS | Red-Black Tree | Red-Black Tree | Hash Table           |

---

