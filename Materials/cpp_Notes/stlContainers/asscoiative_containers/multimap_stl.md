---

# 🎯 C++ STL `multimap` – Full Tutorial

---

## 📘 1. Theory: What is `std::multimap`?

* `std::multimap` is an **associative container** in STL that **stores key-value pairs**.
* Unlike `std::map`, it **allows duplicate keys**.
* Internally, it is implemented as a **Red-Black Tree** like `map`.
* The elements are **automatically sorted** by key in ascending order.

### ✅ Key Properties

| Feature           | Behavior                                               |
| ----------------- | ------------------------------------------------------ |
| Duplicate keys    | Allowed (unlike `map`)                                 |
| Sorting           | Keys are sorted (by default in ascending order)        |
| Access            | No operator `[]`; only `insert`, `find`, and iterators |
| Lookup complexity | O(log n)                                               |

---

## 📦 2. Why and When to Use `multimap`?

* When **multiple values must be associated** with the same key.
* Use cases like:

  * Storing students in the same class
  * Multiple error logs with the same timestamp
  * Word-to-synonyms mappings

---

## 🧑‍💻 3. Real-Time Use Case: Department → Employees

An organization has departments, and each department may have **multiple employees**.
You can use a `std::multimap<std::string, std::string>` to store this mapping.

---

## 🧪 4. Syntax

```cpp
#include <map>

std::multimap<KeyType, ValueType> mapName;
```

**Example**:

```cpp
std::multimap<std::string, std::string> department;
```

---

## 🧰 5. Member Functions of `std::multimap`

| Function               | Description                                    |
| ---------------------- | ---------------------------------------------- |
| `insert({key, value})` | Insert a key-value pair                        |
| `emplace(key, value)`  | Construct and insert in-place                  |
| `erase(key)`           | Remove all pairs with the given key            |
| `erase(iterator)`      | Remove element at iterator                     |
| `find(key)`            | Returns iterator to first element matching key |
| `count(key)`           | Returns number of pairs with the key           |
| `equal_range(key)`     | Returns range of elements with the same key    |
| `clear()`              | Clears the container                           |
| `size()`               | Number of elements                             |
| `empty()`              | Checks if map is empty                         |
| `begin(), end()`       | Iterators to traverse the container            |
| `lower_bound(key)`     | First element not less than key                |
| `upper_bound(key)`     | First element greater than key                 |

---

## 🧑‍💻 6. Full Working Example: All Methods in Action

```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::multimap<std::string, std::string> department;

    // Insert employees into departments
    department.insert({"HR", "Alice"});
    department.insert({"HR", "Bob"});
    department.insert({"IT", "Charlie"});
    department.insert({"IT", "David"});
    department.insert({"Finance", "Eve"});

    // Emplace
    department.emplace("IT", "Irene");

    // Display all entries
    std::cout << "Department Employees:\n";
    for (const auto& entry : department) {
        std::cout << entry.first << ": " << entry.second << "\n";
    }

    // Count number of employees in HR
    std::cout << "\nHR has " << department.count("HR") << " employees.\n";

    // Find first occurrence of key
    auto it = department.find("Finance");
    if (it != department.end()) {
        std::cout << "\nFirst employee in Finance: " << it->second << "\n";
    }

    // Display all employees in IT using equal_range
    auto range = department.equal_range("IT");
    std::cout << "\nIT Department Employees:\n";
    for (auto itr = range.first; itr != range.second; ++itr) {
        std::cout << itr->second << "\n";
    }

    // Erase one IT employee using iterator
    if (range.first != department.end())
        department.erase(range.first);

    // Display after erasing
    std::cout << "\nAfter erasing one IT employee:\n";
    for (const auto& entry : department) {
        std::cout << entry.first << ": " << entry.second << "\n";
    }

    // Clear the map
    department.clear();
    std::cout << "\nMultimap cleared. Is empty? " << std::boolalpha << department.empty() << "\n";

    return 0;
}
```

---

## 🧾 Output:

```
Department Employees:
Finance: Eve
HR: Alice
HR: Bob
IT: Charlie
IT: David
IT: Irene

HR has 2 employees.

First employee in Finance: Eve

IT Department Employees:
Charlie
David
Irene

After erasing one IT employee:
Finance: Eve
HR: Alice
HR: Bob
IT: David
IT: Irene

Multimap cleared. Is empty? true
```

---

## 🧠 7. Practice Ideas

1. **Word synonyms**: Create a thesaurus mapping word → synonyms.
2. **Student course enrollment**: One student can enroll in multiple courses.
3. **Timestamped events**: Multiple logs for the same time.
4. **City to landmarks**: A city can have multiple landmarks.

---

## 📘 Summary

| Feature        | `map`        | `multimap`                     |
| -------------- | ------------ | ------------------------------ |
| Unique Keys    | ✅ Yes        | ❌ No                           |
| Duplicate Keys | ❌ No         | ✅ Yes                          |
| Value Access   | `[]`, `at()` | `find`, `equal_range`          |
| Use Case       | ID → Data    | Grouped data (many values/key) |

---
