
---

# C++ STL unordered\_multiset – Complete Tutorial

---

### 1. Theory: What is `unordered_multiset`?

* `unordered_multiset` is an **unordered associative container** that stores **multiple elements with the same value**.
* Internally implemented as a **hash table**.
* Unlike `unordered_set`, it **allows duplicate elements**.
* Elements are **not sorted**, stored based on their hash values.
* Provides average **constant time (O(1))** complexity for insertion, deletion, and search operations.

---

### 2. Key Characteristics

| Feature                 | Description                                 |
| ----------------------- | ------------------------------------------- |
| Duplicate Elements      | Allowed                                     |
| Ordering                | No specific order (unordered)               |
| Average Operation Time  | O(1) for insert, erase, find (average case) |
| Internal Implementation | Hash table                                  |
| Collision Handling      | Handled internally by STL                   |

---

### 3. Why and When to Use `unordered_multiset`?

* When you need to **store multiple duplicate values efficiently**.
* When **fast lookup** and **insertion** are required, and **order does not matter**.
* Useful for counting occurrences of items with fast lookup, e.g.,:

  * Counting word frequencies
  * Tracking repeated events or logs
  * Multiset operations where order isn’t important

---

### 4. Syntax

```cpp
#include <unordered_set>

std::unordered_multiset<DataType> name;
```

Example:

```cpp
std::unordered_multiset<int> numbers;
```

---

### 5. Important Methods

| Method            | Description                                           |
| ----------------- | ----------------------------------------------------- |
| `insert(value)`   | Inserts a new element                                 |
| `emplace(value)`  | Constructs and inserts element in-place               |
| `erase(value)`    | Removes all elements equal to value                   |
| `erase(iterator)` | Removes element at iterator                           |
| `find(value)`     | Returns iterator to first matching element or `end()` |
| `count(value)`    | Returns the number of elements equal to value         |
| `size()`          | Returns the total number of elements                  |
| `empty()`         | Checks if container is empty                          |
| `clear()`         | Removes all elements                                  |
| `begin(), end()`  | Iterators to traverse elements                        |
| `bucket_count()`  | Number of buckets in hash table                       |
| `load_factor()`   | Average number of elements per bucket                 |
| `rehash(n)`       | Adjusts the number of buckets                         |

---

### 6. Complete Example: All Key Methods Demonstrated

```cpp
#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::unordered_multiset<std::string> words;

    // Insert elements (duplicates allowed)
    words.insert("apple");
    words.insert("banana");
    words.insert("apple");
    words.insert("orange");
    words.insert("banana");
    words.emplace("apple"); // Emplace

    // Display all elements
    std::cout << "All words (including duplicates):\n";
    for (const auto& w : words) {
        std::cout << w << "\n";
    }

    // Count occurrences of "apple"
    std::cout << "\nCount of 'apple': " << words.count("apple") << "\n";

    // Find "banana"
    auto it = words.find("banana");
    if (it != words.end()) {
        std::cout << "'banana' found, erasing one occurrence.\n";
        words.erase(it); // Erase one occurrence of "banana"
    }

    // Display after erasing one "banana"
    std::cout << "\nWords after erasing one 'banana':\n";
    for (const auto& w : words) {
        std::cout << w << "\n";
    }

    // Erase all "apple"
    size_t erased = words.erase("apple");
    std::cout << "\nErased " << erased << " occurrences of 'apple'.\n";

    // Show size
    std::cout << "Size after erasing all 'apple': " << words.size() << "\n";

    // Clear all
    words.clear();
    std::cout << "Cleared all words. Is empty? " << std::boolalpha << words.empty() << "\n";

    return 0;
}
```

---

### 7. Sample Output

```
All words (including duplicates):
banana
orange
apple
banana
apple
apple

Count of 'apple': 3
'banana' found, erasing one occurrence.

Words after erasing one 'banana':
orange
banana
apple
banana
apple
apple

Erased 3 occurrences of 'apple'.
Size after erasing all 'apple': 2
Cleared all words. Is empty? true
```

---

### 8. Real-World Use Case Example

Counting frequencies of words in a text where duplicates matter but ordering does not:

```cpp
#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::unordered_multiset<std::string> wordFreq;
    std::string text[] = {"dog", "cat", "dog", "bird", "cat", "dog"};

    for (const auto& w : text) {
        wordFreq.insert(w);
    }

    std::cout << "Occurrences of 'dog': " << wordFreq.count("dog") << "\n";
    std::cout << "Occurrences of 'cat': " << wordFreq.count("cat") << "\n";

    return 0;
}
```

---

### 9. Summary Table

| Feature           | unordered\_set     | unordered\_multiset         |
| ----------------- | ------------------ | --------------------------- |
| Allow Duplicates  | No                 | Yes                         |
| Ordering          | Unordered          | Unordered                   |
| Lookup Complexity | O(1) average       | O(1) average                |
| Use Case          | Unique fast lookup | Multiple duplicates allowed |

---
