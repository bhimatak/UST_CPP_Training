
---

# C++ STL `vector` Container 

---

## 🧠 1. What is `std::vector`?

`std::vector` is a **dynamic array** provided by the C++ Standard Template Library (STL). Unlike a static array (`std::array`), a vector can **grow or shrink** in size at runtime.

It is implemented as a **contiguous memory block**, allowing fast access by index, just like arrays, but with the added flexibility of automatic resizing.

---

## ✅ 2. Why Use `std::vector`?

| Feature                | Benefit                                         |
| ---------------------- | ----------------------------------------------- |
| Dynamic size           | Can grow/shrink automatically                   |
| STL compatibility      | Works with algorithms like `sort`, `find`, etc. |
| Bounds-checked access  | Via `at()` method                               |
| Easy insertion/removal | Especially at the end (`push_back`, `pop_back`) |
| Memory-efficient       | Manages memory allocation internally            |
| Safer than raw arrays  | Supports exception safety and RAII principles   |

---

## 🌐 3. Real-Time Use Cases

* **Inventory systems** in games or shops where the number of items is unknown.
* **Dynamic record lists** like student marks, employee data, etc.
* **Text editors** to store lines of text or characters.
* **Graph implementations** using adjacency lists.

---

## 🧾 4. Syntax

```cpp
#include <vector>

std::vector<datatype> vec;                     // Empty vector
std::vector<datatype> vec(size);              // Vector with default-initialized values
std::vector<datatype> vec(size, value);       // Vector with all elements set to `value`
std::vector<datatype> vec = {val1, val2, ...}; // Initializer list
```

---

## ⚙️ 5. Complete Working Code Example

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void printVector(const std::vector<int>& v) {
    for (int num : v) std::cout << num << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> vec = {10, 20, 30};

    // Add elements
    vec.push_back(40);
    vec.push_back(50);

    std::cout << "Vector after push_back: ";
    printVector(vec);

    // Access elements
    std::cout << "Element at index 2: " << vec.at(2) << "\n";
    std::cout << "Front: " << vec.front() << "\n";
    std::cout << "Back: " << vec.back() << "\n";

    // Remove last element
    vec.pop_back();
    std::cout << "After pop_back: ";
    printVector(vec);

    // Insert at specific position
    vec.insert(vec.begin() + 1, 15);
    std::cout << "After insert at position 1: ";
    printVector(vec);

    // Erase element at position 2
    vec.erase(vec.begin() + 2);
    std::cout << "After erase at position 2: ";
    printVector(vec);

    // Resize
    vec.resize(6, 100);
    std::cout << "After resize to 6: ";
    printVector(vec);

    // Sorting
    std::sort(vec.begin(), vec.end());
    std::cout << "After sorting: ";
    printVector(vec);

    // Clear
    vec.clear();
    std::cout << "Size after clear: " << vec.size() << "\n";

    return 0;
}
```

---

## 📚 6. All Member Functions with Explanation

| Method                | Description                                              |
| --------------------- | -------------------------------------------------------- |
| `push_back(value)`    | Adds an element to the end                               |
| `pop_back()`          | Removes the last element                                 |
| `at(index)`           | Returns element at index with bounds checking            |
| `operator[]`          | Access element without bounds checking                   |
| `front()`             | Returns the first element                                |
| `back()`              | Returns the last element                                 |
| `insert(pos, value)`  | Inserts element at specified position                    |
| `erase(pos)`          | Removes element at specified position                    |
| `clear()`             | Removes all elements                                     |
| `size()`              | Returns the number of elements                           |
| `capacity()`          | Returns allocated memory size                            |
| `resize(n)`           | Resizes the vector to hold `n` elements                  |
| `resize(n, val)`      | Resizes to `n` elements, initializes new ones with `val` |
| `empty()`             | Checks if the vector is empty                            |
| `begin()` / `end()`   | Iterator to beginning/end                                |
| `rbegin()` / `rend()` | Reverse iterators                                        |
| `cbegin()` / `cend()` | Constant iterators                                       |
| `assign(n, val)`      | Assigns `n` elements with value `val`                    |
| `swap(v)`             | Swaps contents with another vector                       |
| `emplace(pos, val)`   | Constructs element in-place at position                  |
| `emplace_back(val)`   | Constructs element in-place at end                       |
| `shrink_to_fit()`     | Requests reduction of capacity to fit size               |
| `data()`              | Returns pointer to internal array                        |

---

## 🧪 7. Extra Example: All Methods in Action

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    v.assign(5, 10); // 5 elements of value 10
    std::cout << "After assign: ";
    for (auto x : v) std::cout << x << " ";
    std::cout << "\n";

    v.push_back(20);
    v.emplace_back(25); // Similar to push_back but in-place
    std::cout << "After push_back and emplace_back: ";
    for (auto x : v) std::cout << x << " ";
    std::cout << "\n";

    v.insert(v.begin() + 2, 15);
    v.emplace(v.begin() + 3, 17);
    std::cout << "After insert and emplace: ";
    for (auto x : v) std::cout << x << " ";
    std::cout << "\n";

    v.erase(v.begin() + 1);
    std::cout << "After erase at index 1: ";
    for (auto x : v) std::cout << x << " ";
    std::cout << "\n";

    v.resize(3);
    std::cout << "After resize to 3: ";
    for (auto x : v) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Capacity: " << v.capacity() << "\n";
    std::cout << "Size: " << v.size() << "\n";

    v.shrink_to_fit();
    std::cout << "After shrink_to_fit, Capacity: " << v.capacity() << "\n";

    std::vector<int> v2 = {1, 2, 3};
    v.swap(v2);
    std::cout << "After swap with v2: ";
    for (auto x : v) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
```

---

## 📦 8. Compilation and Execution

Use:

```bash
g++ -std=c++11 stl_vector_example.cpp -o vector
./vector
```

---

## 💬 9. Summary

| Feature       | Description                                                              |
| ------------- | ------------------------------------------------------------------------ |
| Flexibility   | Automatically resizes as elements are added/removed                      |
| Safety        | Bounds-checked access, exception-safe memory                             |
| Performance   | Random access is fast (O(1)), insertion/removal at end is amortized O(1) |
| Compatibility | Works seamlessly with STL algorithms (`sort`, `find`, etc.)              |

---
