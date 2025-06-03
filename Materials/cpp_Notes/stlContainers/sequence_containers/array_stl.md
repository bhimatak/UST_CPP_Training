
---

# **C++ STL `array` Container**

---

## 🧠 1. What is `std::array`?

The `std::array` is a **container** that encapsulates **fixed-size arrays**. It is a wrapper around raw arrays with added functionality, safety, and interoperability with STL algorithms.

Introduced in **C++11**, it is part of the **Standard Template Library (STL)** and defined in the `<array>` header.

---

## ✅ 2. Why Use `std::array` Instead of Raw Arrays?

| Feature                   | `std::array` | Raw Array |
| ------------------------- | ------------ | --------- |
| Size info (`.size()`)     | ✅            | ❌         |
| Bound checking (`.at()`)  | ✅            | ❌         |
| STL-compatible            | ✅            | ❌         |
| Assignable                | ✅            | ❌         |
| Usable in range-based for | ✅            | ❌         |
| Supports member functions | ✅            | ❌         |

---

## 🌐 3. Real-Time Use Case

* **Embedded systems**: where array sizes are known at compile-time, but STL-style safety and readability is desired.
* **Game development**: fixed set of game states or keys.
* **Signal processing**: for buffers with a fixed number of samples.

---

## 🧾 4. Syntax

```cpp
#include <array>

std::array<datatype, size> array_name;
```

---

## ⚙️ 5. Complete Working Example

```cpp
#include <iostream>
#include <array>
#include <algorithm> // for sort, reverse

int main() {
    // Declare and initialize an array of 5 integers
    std::array<int, 5> arr = {10, 20, 30, 40, 50};

    // Accessing elements
    std::cout << "Element at index 2 (using at): " << arr.at(2) << std::endl;
    std::cout << "First element: " << arr.front() << std::endl;
    std::cout << "Last element: " << arr.back() << std::endl;

    // Size and empty check
    std::cout << "Size of array: " << arr.size() << std::endl;
    std::cout << "Is array empty? " << (arr.empty() ? "Yes" : "No") << std::endl;

    // Fill array
    arr.fill(7);
    std::cout << "After fill: ";
    for (int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    // Reassign values
    arr = {1, 4, 3, 2, 5};

    // Sort array
    std::sort(arr.begin(), arr.end());
    std::cout << "After sorting: ";
    for (int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    // Reverse array
    std::reverse(arr.begin(), arr.end());
    std::cout << "After reversing: ";
    for (int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    // Data pointer access
    int* p = arr.data();
    std::cout << "Pointer to first element: " << *p << std::endl;

    return 0;
}
```

---

## 📚 6. Detailed Member Functions

| Method                  | Description                                             |
| ----------------------- | ------------------------------------------------------- |
| `at(index)`             | Returns element at given index with bounds checking     |
| `operator[]`            | Returns element at index (no bounds checking)           |
| `front()`               | Returns the first element                               |
| `back()`                | Returns the last element                                |
| `data()`                | Returns a pointer to the first element (like raw array) |
| `begin()` / `end()`     | Returns iterator to the beginning/end                   |
| `rbegin()` / `rend()`   | Returns reverse iterators                               |
| `cbegin()` / `cend()`   | Constant iterators to begin/end                         |
| `crbegin()` / `crend()` | Constant reverse iterators                              |
| `empty()`               | Returns `true` if size is 0                             |
| `size()`                | Returns the number of elements                          |
| `max_size()`            | Same as `size()` (fixed-size)                           |
| `fill(value)`           | Sets all elements to given value                        |
| `swap(other)`           | Swaps contents with another array of same type and size |

---

## 📊 7. Example: Display All Member Functions

```cpp
#include <iostream>
#include <array>

void displayArray(const std::array<int, 5>& arr) {
    std::cout << "Array elements: ";
    for (auto x : arr) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    std::array<int, 5> arr1 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2;

    std::cout << "Original arr1: ";
    displayArray(arr1);

    // Using fill()
    arr2.fill(9);
    std::cout << "After fill, arr2: ";
    displayArray(arr2);

    // Using swap
    arr1.swap(arr2);
    std::cout << "After swap, arr1: ";
    displayArray(arr1);
    std::cout << "After swap, arr2: ";
    displayArray(arr2);

    // Access using at(), front(), back()
    std::cout << "arr1.at(2): " << arr1.at(2) << std::endl;
    std::cout << "arr1.front(): " << arr1.front() << std::endl;
    std::cout << "arr1.back(): " << arr1.back() << std::endl;

    // Use data() to manipulate array directly
    int* ptr = arr1.data();
    ptr[0] = 100;
    std::cout << "After modifying via data(): ";
    displayArray(arr1);

    return 0;
}
```

---

## 💬 8. Summary

| Feature        | Benefit                                 |
| -------------- | --------------------------------------- |
| Fixed-size     | Known at compile time → Fast, efficient |
| STL-compatible | Works with `sort`, `find`, etc.         |
| Safer access   | `at()` throws exception on error        |
| Readability    | Clean and self-documenting syntax       |

---

## 📦 9. Compilation and Run

Use:

```bash
g++ -std=c++11 stl_array_example.cpp -o array
./array
```

---
