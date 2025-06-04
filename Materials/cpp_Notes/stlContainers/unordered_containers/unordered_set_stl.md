
---

# 🧭 C++ STL `unordered_set` – Complete Tutorial

---

## 📘 1. Theory: What is `std::unordered_set`?

* `unordered_set` is an **unordered associative container** that stores **unique elements**.
* Internally implemented using a **hash table**.
* Elements are **not sorted** — they are organized by **hash value**.
* Provides **average constant-time (O(1))** complexity for insertion, deletion, and lookup.

---

## 📌 2. Key Characteristics

| Feature              | Description                                                |
| -------------------- | ---------------------------------------------------------- |
| Unique Elements      | Duplicate values are not allowed                           |
| No Sorting           | Elements are **not ordered** — determined by hash function |
| Fast Operations      | Insert, delete, search in **average O(1)** time            |
| Internal Mechanism   | Hash table (usually `std::hash` function)                  |
| Collision Resolution | Chaining or open addressing (handled internally by STL)    |

---

## 🎯 3. When and Why to Use `unordered_set`

* When you want to **store unique elements** and **order does not matter**.
* When you prioritize **speed over ordering**.
* Use cases:

  * Removing duplicates from a list
  * Fast membership tests (`O(1)` lookup)
  * Keeping track of visited elements in a graph

---

## 🧪 4. Syntax

```cpp
#include <unordered_set>

std::unordered_set<DataType> name;
```

### Example:

```cpp
std::unordered_set<int> mySet;
```

---

## 🔧 5. Important Methods of `unordered_set`

| Method           | Description                                       |
| ---------------- | ------------------------------------------------- |
| `insert(value)`  | Adds a new element                                |
| `emplace(value)` | Constructs and inserts the element                |
| `erase(value)`   | Removes the element                               |
| `find(value)`    | Returns iterator to value or `end()`              |
| `count(value)`   | Returns `1` if value exists, `0` otherwise        |
| `size()`         | Returns number of elements                        |
| `empty()`        | Returns `true` if set is empty                    |
| `clear()`        | Removes all elements                              |
| `begin(), end()` | Iterators                                         |
| `bucket_count()` | Number of buckets (useful for performance tuning) |
| `load_factor()`  | Current load factor (elements / buckets)          |
| `rehash(n)`      | Reorganize into `n` buckets                       |

---

## 👨‍💻 6. Full Working Example with All Methods

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<std::string> cities;

    // Insert elements
    cities.insert("Mumbai");
    cities.insert("Delhi");
    cities.insert("Chennai");
    cities.insert("Kolkata");

    // Emplace (in-place construction)
    cities.emplace("Hyderabad");

    // Display contents
    std::cout << "Cities in the set:\n";
    for (const auto& city : cities) {
        std::cout << city << "\n";
    }

    // Count & Find
    std::string searchCity = "Delhi";
    if (cities.count(searchCity)) {
        std::cout << "\n" << searchCity << " found in the set.\n";
    }

    // Using find()
    auto it = cities.find("Mumbai");
    if (it != cities.end()) {
        std::cout << *it << " is found. Erasing it.\n";
        cities.erase(it);
    }

    // Show size and load factor
    std::cout << "\nSet size: " << cities.size() << "\n";
    std::cout << "Bucket count: " << cities.bucket_count() << "\n";
    std::cout << "Load factor: " << cities.load_factor() << "\n";

    // Rehashing
    cities.rehash(20); // Force rehash into 20 buckets
    std::cout << "After rehash - New bucket count: " << cities.bucket_count() << "\n";

    // Clear
    cities.clear();
    std::cout << "Set cleared. Is empty? " << std::boolalpha << cities.empty() << "\n";

    return 0;
}
```

---

## ✅ Output

```
Cities in the set:
Chennai
Kolkata
Delhi
Mumbai
Hyderabad

Delhi found in the set.
Mumbai is found. Erasing it.

Set size: 4
Bucket count: 7
Load factor: 0.571429
After rehash - New bucket count: 20
Set cleared. Is empty? true
```

---

## 📦 7. Real-Time Use Case

### 🎯 Problem: Remove Duplicates from User Input

```cpp
#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::unordered_set<std::string> names;
    std::string name;

    std::cout << "Enter 5 names (duplicates allowed):\n";
    for (int i = 0; i < 5; ++i) {
        std::getline(std::cin, name);
        names.insert(name);
    }

    std::cout << "\nUnique names:\n";
    for (const auto& n : names) {
        std::cout << n << "\n";
    }

    return 0;
}
```

---

## 🧠 8. Practice Problems

1. **Email Filter**: Store unique email addresses submitted in a form.
2. **Student Attendance**: Mark students present only once (even if scanned multiple times).
3. **Spell Checker**: Store a dictionary of correct words and test if a word exists.
4. **Remove duplicate integers** from an input array using `unordered_set`.

---

## ✅ Summary

| Feature            | `set`                       | `unordered_set`           |
| ------------------ | --------------------------- | ------------------------- |
| Ordering           | Sorted                      | Unordered                 |
| Time Complexity    | O(log n)                    | O(1) average (O(n) worst) |
| Use Case           | When order matters          | When speed is priority    |
| Duplicate Elements | ❌ Not allowed               | ❌ Not allowed             |
| Lookup Speed       | Slower than `unordered_set` | Faster (on average)       |

---

