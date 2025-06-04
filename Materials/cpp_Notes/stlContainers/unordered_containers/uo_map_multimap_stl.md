
---

# C++ STL `unordered_map` and `unordered_multimap` – Complete Tutorial

---

## 1. Theory

### `unordered_map`

* An **unordered associative container** that stores **key-value pairs** with **unique keys**.
* Internally implemented as a **hash table**.
* Provides **average constant-time (O(1))** complexity for insertion, deletion, and lookup.
* Keys are unique, so inserting a new element with an existing key will **overwrite** the previous value.
* Elements are **not sorted**; their order depends on the hash function.

### `unordered_multimap`

* Similar to `unordered_map`, but allows **multiple elements with the same key**.
* Also uses a **hash table** internally.
* Useful when you need to associate multiple values with the same key.
* Average time complexity for operations remains **O(1)** on average.
* Elements are unordered.

---

## 2. Why and When to Use

| Container            | When to Use                                                        |
| -------------------- | ------------------------------------------------------------------ |
| `unordered_map`      | When you need fast lookup with unique keys                         |
| `unordered_multimap` | When keys may repeat and you want to store multiple values per key |

---

## 3. Syntax

```cpp
#include <unordered_map>

// unordered_map<KeyType, ValueType>
std::unordered_map<int, std::string> myMap;

// unordered_multimap<KeyType, ValueType>
std::unordered_multimap<int, std::string> myMultiMap;
```

---

## 4. Common Methods

| Method                                         | Description                                             |
| ---------------------------------------------- | ------------------------------------------------------- |
| `insert(pair)`                                 | Insert a key-value pair                                 |
| `emplace(key, value)`                          | Construct and insert in-place                           |
| `erase(key)`                                   | Remove element(s) by key                                |
| `erase(iterator)`                              | Remove element at iterator                              |
| `find(key)`                                    | Returns iterator to element with key or `end()`         |
| `count(key)`                                   | Returns number of elements with the key                 |
| `operator[]` (only `unordered_map`)            | Access or insert element by key (creates if not exists) |
| `size()`                                       | Returns the number of elements                          |
| `empty()`                                      | Checks if container is empty                            |
| `clear()`                                      | Removes all elements                                    |
| `begin()`, `end()`                             | Iterators for traversal                                 |
| `bucket_count()`, `load_factor()`, `rehash(n)` | Bucket and hash table tuning methods                    |

---

## 5. Example Code

```cpp
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

void demo_unordered_map() {
    std::unordered_map<int, std::string> umap;

    // Insert elements
    umap.insert({1, "One"});
    umap.emplace(2, "Two");
    umap[3] = "Three";  // Insert or update

    // Access element
    std::cout << "Key 2: " << umap[2] << "\n";

    // Update element
    umap[2] = "Two Updated";

    // Find element
    auto it = umap.find(3);
    if (it != umap.end()) {
        std::cout << "Found key 3 with value: " << it->second << "\n";
    }

    // Erase element
    umap.erase(1);

    // Iterate over map
    std::cout << "unordered_map contents:\n";
    for (const auto& [key, value] : umap) {
        std::cout << key << " => " << value << "\n";
    }

    std::cout << "Size: " << umap.size() << "\n";
}

void demo_unordered_multimap() {
    std::unordered_multimap<int, std::string> umultimap;

    // Insert multiple elements with same key
    umultimap.insert({1, "One"});
    umultimap.emplace(1, "Uno");
    umultimap.insert({2, "Two"});
    umultimap.emplace(2, "Dos");
    umultimap.insert({3, "Three"});

    // Count elements with key 1
    std::cout << "\nCount for key 1: " << umultimap.count(1) << "\n";

    // Find and iterate all elements with key 1
    auto range = umultimap.equal_range(1);
    std::cout << "Values for key 1:\n";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << "\n";
    }

    // Erase all elements with key 2
    size_t erased = umultimap.erase(2);
    std::cout << "Erased " << erased << " elements with key 2\n";

    // Iterate entire multimap
    std::cout << "unordered_multimap contents:\n";
    for (const auto& [key, value] : umultimap) {
        std::cout << key << " => " << value << "\n";
    }
}

int main() {
    demo_unordered_map();
    demo_unordered_multimap();
    return 0;
}
```

---

## 6. Sample Output

```
Key 2: Two
Found key 3 with value: Three
unordered_map contents:
2 => Two Updated
3 => Three
Size: 2

Count for key 1: 2
Values for key 1:
One
Uno
Erased 2 elements with key 2
unordered_multimap contents:
1 => One
1 => Uno
3 => Three
```

---

## 7. Real-World Use Cases

* `unordered_map`:
  Fast lookup of user profiles by unique user ID.
  Example: `unordered_map<UserID, UserData>`

* `unordered_multimap`:
  Storing tags or categories for articles, where an article ID (key) can have multiple tags (values).
  Example: `unordered_multimap<ArticleID, Tag>`

---

## 8. Summary Table

| Feature         | unordered\_map             | unordered\_multimap             |
| --------------- | -------------------------- | ------------------------------- |
| Key Uniqueness  | Unique keys only           | Multiple identical keys allowed |
| Value Type      | Single value per key       | Multiple values per key         |
| Access via `[]` | Yes                        | No                              |
| Lookup Time     | Average O(1)               | Average O(1)                    |
| Use Case        | Key-value with unique keys | Key-value with multiple values  |

---

