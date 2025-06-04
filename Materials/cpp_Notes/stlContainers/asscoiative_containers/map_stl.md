
---

# 🧭 C++ STL `map` Container – Complete Tutorial

---

## 🧠 Theory: What is `std::map`?

* `std::map` is an **associative container** in the Standard Template Library (STL).
* It stores elements as **key-value pairs** in **sorted order based on keys**.
* Each **key is unique** and maps to a **single value**.
* Internally, `std::map` is usually implemented as a **Red-Black Tree** (self-balancing BST).

### 📌 Key Characteristics

| Feature      | Behavior                                               |
| ------------ | ------------------------------------------------------ |
| Keys         | Unique and automatically sorted (ascending by default) |
| Value Access | Through `[]` or `at()`                                 |
| Performance  | O(log n) insertion, deletion, and search               |
| Iteration    | In ascending key order                                 |

---

## 🔍 Why Use `std::map`?

* When you want **fast lookup, insertion, and deletion** of elements based on **keys**.
* When the **key-value** relationship is central to your data model.
* When you need to maintain elements in **sorted order of keys**.

---

## 🎯 Real-Time Use Case: Student Record Lookup

In an education portal, we may want to store student records using their **roll numbers as keys** and their **names/grades** as values.
This lets us efficiently **insert**, **search**, or **delete** student data by roll number.

---

## 🧪 Syntax

```cpp
#include <map>

std::map<KeyType, ValueType> mapName;
```

### Example:

```cpp
std::map<int, std::string> studentMap;
```

---

## 🧰 Commonly Used Member Functions of `std::map`

| Function               | Description                                   |
| ---------------------- | --------------------------------------------- |
| `insert({key, value})` | Inserts a key-value pair                      |
| `emplace(key, value)`  | Constructs in-place                           |
| `erase(key)`           | Removes the element with the given key        |
| `find(key)`            | Returns iterator to key or `end()`            |
| `clear()`              | Removes all elements                          |
| `size()`               | Returns number of elements                    |
| `empty()`              | Checks if map is empty                        |
| `at(key)`              | Access value at key (throws if key not found) |
| `operator[]`           | Access/Insert value at key                    |
| `count(key)`           | Returns 1 if key exists, 0 otherwise          |
| `begin(), end()`       | Iterators                                     |
| `lower_bound(key)`     | First not less than key                       |
| `upper_bound(key)`     | First greater than key                        |

---

## 🧑‍💻 Full Example: Demonstrating All Key Methods of `std::map`

```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<int, std::string> students;

    // Insert using insert()
    students.insert({101, "Alice"});
    students.insert({102, "Bob"});
    
    // Insert using operator[]
    students[103] = "Charlie";

    // Insert using emplace()
    students.emplace(104, "Diana");

    // Access using at()
    std::cout << "Student 102: " << students.at(102) << "\n";

    // Access using operator[]
    std::cout << "Student 103: " << students[103] << "\n";

    // Check size
    std::cout << "Total students: " << students.size() << "\n";

    // Check existence using count()
    if (students.count(105) == 0)
        std::cout << "Student 105 not found.\n";

    // Find element
    auto it = students.find(101);
    if (it != students.end())
        std::cout << "Found Student 101: " << it->second << "\n";

    // Erase a student
    students.erase(102);
    std::cout << "After erasing 102, size: " << students.size() << "\n";

    // Iterate over the map
    std::cout << "All students:\n";
    for (const auto& pair : students) {
        std::cout << "Roll: " << pair.first << ", Name: " << pair.second << "\n";
    }

    // lower_bound and upper_bound
    std::cout << "Lower bound of 103: " << students.lower_bound(103)->first << "\n";
    if (students.upper_bound(103) != students.end())
        std::cout << "Upper bound of 103: " << students.upper_bound(103)->first << "\n";

    // Clear all entries
    students.clear();
    std::cout << "Map cleared. Empty? " << std::boolalpha << students.empty() << "\n";

    return 0;
}
```

---

## 🎓 Output

```
Student 102: Bob
Student 103: Charlie
Total students: 4
Student 105 not found.
Found Student 101: Alice
After erasing 102, size: 3
All students:
Roll: 101, Name: Alice
Roll: 103, Name: Charlie
Roll: 104, Name: Diana
Lower bound of 103: 103
Upper bound of 103: 104
Map cleared. Empty? true
```

---

## 📘 Summary

| Feature             | Description                                  |
| ------------------- | -------------------------------------------- |
| Sorted Key Storage  | Keys are always sorted in ascending order    |
| Fast Lookup         | O(log n) complexity for insert/search/delete |
| Key-Value Mapping   | One key maps to one value                    |
| Flexible Operations | Emplace, Insert, Access, Erase, Find         |

---

## 🧠 Practice Ideas

1. Implement a phonebook using `map<string, string>`.
2. Count frequency of characters in a string using `map<char, int>`.
3. Store city names with pin codes and sort them automatically.
4. Design a dictionary app where words (key) map to definitions (value).

---
