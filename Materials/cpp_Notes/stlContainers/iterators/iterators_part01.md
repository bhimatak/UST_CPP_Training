
   
---

# 🔍 What Are Iterators in C++ STL?

An **iterator** is an object (like a pointer) that allows you to **traverse** through the elements of an STL container (like `vector`, `list`, `set`, etc.). It acts as a bridge between containers and algorithms.

---

## 🧠 Why Use Iterators?

* Access elements without knowing the internal structure.
* Work seamlessly across different container types.
* Enable the use of STL **algorithms** like `sort()`, `find()`, `copy()`, etc.
* Provide a consistent interface for traversal (forward, backward, bidirectional, random-access).

---

## 📦 Types of Iterators

| Type                 | Description                               | Supported By                        |
| -------------------- | ----------------------------------------- | ----------------------------------- |
| **Input Iterator**   | Read-only forward traversal               | `istream_iterator`, `forward_list`  |
| **Output Iterator**  | Write-only forward traversal              | `ostream_iterator`, `back_inserter` |
| **Forward Iterator** | Read/Write, one direction                 | `forward_list`, `unordered_map`     |
| **Bidirectional**    | Traverse in both directions               | `list`, `set`, `map`, `multimap`    |
| **Random-access**    | Jump to any position (like pointer arith) | `vector`, `deque`, `array`          |

---

## 🛠️ Syntax Basics

```cpp
std::vector<int> v = {1, 2, 3};
std::vector<int>::iterator it = v.begin();
```

Or use `auto` (C++11+):

```cpp
auto it = v.begin();
```

---

## 🧪 Common Iterator Functions

| Function                | Description                               |
| ----------------------- | ----------------------------------------- |
| `begin()`               | Returns iterator to the first element     |
| `end()`                 | Returns iterator to one-past-last element |
| `rbegin()`              | Reverse iterator to the last element      |
| `rend()`                | Reverse iterator to one-before-first      |
| `cbegin()`, `cend()`    | Constant iterators (read-only)            |
| `crbegin()`, `crend()`  | Constant reverse iterators (read-only)    |
| `advance(it, n)`        | Moves iterator `it` forward by `n` steps  |
| `distance(first, last)` | Number of steps between two iterators     |
| `prev(it, n)`           | Returns iterator moved `n` steps backward |
| `next(it, n)`           | Returns iterator moved `n` steps forward  |

---

# 📘 Full Example: Demonstrating All Iterator Concepts

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // 1. Normal Iterator
    std::cout << "Using normal iterator:\n";
    std::vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 2. Reverse Iterator
    std::cout << "Using reverse iterator:\n";
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << "\n";

    // 3. Constant Iterator
    std::cout << "Using const_iterator (read-only):\n";
    for (std::vector<int>::const_iterator cit = vec.cbegin(); cit != vec.cend(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << "\n";

    // 4. Modify values with iterator
    std::cout << "Doubling each element:\n";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        *it *= 2;
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 5. Using advance and next
    std::list<std::string> names = {"Alice", "Bob", "Charlie", "Diana"};
    auto lit = names.begin();
    std::advance(lit, 2);  // move 2 positions forward
    std::cout << "2nd index in list: " << *lit << "\n";

    // 6. Using prev
    auto prevIt = std::prev(lit);
    std::cout << "Previous element: " << *prevIt << "\n";

    // 7. Using distance
    std::cout << "Distance from start to lit: " << std::distance(names.begin(), lit) << "\n";

    // 8. Using inserter and copy
    std::set<int> s = {100, 200};
    std::copy(vec.begin(), vec.end(), std::inserter(s, s.begin()));
    std::cout << "Set after inserting vector elements:\n";
    for (int x : s) std::cout << x << " ";
    std::cout << "\n";

    // 9. ostream_iterator
    std::cout << "Using ostream_iterator to print vector:\n";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    return 0;
}
```

---

# 🧪 Output (Condensed)

```
Using normal iterator:
10 20 30 40 50
Using reverse iterator:
50 40 30 20 10
Using const_iterator (read-only):
10 20 30 40 50
Doubling each element:
20 40 60 80 100
2nd index in list: Charlie
Previous element: Bob
Distance from start to lit: 2
Set after inserting vector elements:
20 40 60 80 100 200
Using ostream_iterator to print vector:
20 40 60 80 100
```

---

## 🎯 Real-World Use Cases

1. **Traversing Collections:** Iterators provide a consistent way to loop through `vector`, `set`, `map`, etc.
2. **Using Algorithms:** Algorithms like `std::find`, `std::sort`, `std::copy` require iterators.
3. **Custom Iterator Logic:** Implement filters, transformations, subranges.
4. **Generic Programming:** Iterators allow writing container-agnostic code using templates.

---

## 🧩 Recap: When to Use Which Iterator?

| Container         | Use Which Iterators                       |
| ----------------- | ----------------------------------------- |
| `vector`, `deque` | Random-access, reverse, const, normal     |
| `list`            | Bidirectional, reverse, const             |
| `set`, `map`      | Bidirectional (not random-access!)        |
| `forward_list`    | Forward only                              |
| Custom Algorithms | Use `std::advance`, `std::distance`, etc. |

---

---

# 🔁 C++ STL Iterators – Types and Usage

In C++, **iterators** act like pointers and are used to traverse containers (e.g., `vector`, `list`, `set`). They help you access and manipulate elements in a **container-independent** manner.

---

## 🔹 Why Iterators?

* Abstraction over different container types.
* Unified syntax for traversal.
* Can be used with STL algorithms like `sort`, `copy`, `find`, etc.
* Support various capabilities: forward, backward, random access, etc.

---

## 📚 Categories of Iterators

There are **5 main types** of iterators in STL:

| Type                          | Traversal          | Write | Read | Move | Jump | Applicable Containers              |
| ----------------------------- | ------------------ | ----- | ---- | ---- | ---- | ---------------------------------- |
| **1. Input Iterator**         | Forward            | ❌     | ✅    | ✅    | ❌    | `istream_iterator`, `forward_list` |
| **2. Output Iterator**        | Forward            | ✅     | ❌    | ✅    | ❌    | `ostream_iterator`                 |
| **3. Forward Iterator**       | Forward            | ✅     | ✅    | ✅    | ❌    | `forward_list`, `unordered_set`    |
| **4. Bidirectional Iterator** | Forward & Backward | ✅     | ✅    | ✅    | ❌    | `list`, `set`, `map`, `multimap`   |
| **5. Random Access Iterator** | Any                | ✅     | ✅    | ✅    | ✅    | `vector`, `deque`, `array`         |

---

## 🔍 1. Input Iterator

* Reads data in **one direction** (forward only).
* Can read **once**; can't go back.

### 🔹 Example:

```cpp
#include <iostream>
#include <iterator>
#include <vector>
int main() {
    std::istream_iterator<int> in(std::cin), eof;
    std::vector<int> v(in, eof); // reads all input into vector
}
```

---

## 🔍 2. Output Iterator

* Writes data in **one direction**.
* Cannot read or access previous elements.

### 🔹 Example:

```cpp
#include <iostream>
#include <iterator>
#include <vector>
int main() {
    std::vector<int> v = {1, 2, 3};
    std::ostream_iterator<int> out(std::cout, " ");
    std::copy(v.begin(), v.end(), out);  // Output: 1 2 3
}
```

---

## 🔍 3. Forward Iterator

* Can **read/write** and **revisit elements**.
* Useful for containers like `forward_list`.

### 🔹 Example:

```cpp
#include <forward_list>
#include <iostream>

int main() {
    std::forward_list<int> fl = {1, 2, 3};
    for (auto it = fl.begin(); it != fl.end(); ++it)
        std::cout << *it << " ";
}
```

---

## 🔍 4. Bidirectional Iterator

* Moves **forward and backward**.
* Cannot perform random access (`it + 2` not allowed).
* Used in `list`, `set`, `map`.

### 🔹 Example:

```cpp
#include <list>
#include <iostream>

int main() {
    std::list<int> lst = {1, 2, 3};
    auto it = lst.end();
    --it;  // Bidirectional movement
    std::cout << *it;  // Output: 3
}
```

---

## 🔍 5. Random Access Iterator

* All capabilities: `++`, `--`, `+`, `-`, indexing `[]`.
* Found in `vector`, `deque`, `array`.

### 🔹 Example:

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {10, 20, 30, 40};
    auto it = v.begin();
    it += 2;
    std::cout << *it;  // Output: 30
}
```

---

## 🛠️ Iterator Functions

| Function    | Description                       |
| ----------- | --------------------------------- |
| `begin()`   | Returns iterator to first element |
| `end()`     | Returns iterator to one past last |
| `rbegin()`  | Reverse begin (last element)      |
| `rend()`    | Reverse end (before first)        |
| `cbegin()`  | Const begin                       |
| `cend()`    | Const end                         |
| `crbegin()` | Const reverse begin               |
| `crend()`   | Const reverse end                 |

---

## 🧪 STL Algorithms That Use Iterators

| Algorithm       | Purpose                            |
| --------------- | ---------------------------------- |
| `std::copy`     | Copy elements using iterators      |
| `std::find`     | Find element in a range            |
| `std::sort`     | Sort elements (random access only) |
| `std::for_each` | Apply function to each element     |

---

## 🧠 Summary Table

| Container           | Iterator Category |
| ------------------- | ----------------- |
| `vector`            | Random Access     |
| `deque`             | Random Access     |
| `array`             | Random Access     |
| `list`              | Bidirectional     |
| `set`, `map`        | Bidirectional     |
| `unordered_set/map` | Forward           |
| `forward_list`      | Forward           |

---

## 🔎 Real-World Usage

| Task                                | Iterator Type          |
| ----------------------------------- | ---------------------- |
| Reading a file to vector            | Input Iterator         |
| Writing vector to console           | Output Iterator        |
| Processing singly linked list       | Forward Iterator       |
| Navigating sorted student IDs (set) | Bidirectional Iterator |
| Binary search in an array           | Random Access Iterator |

---


---

## 🔁 Iterators in STL: Container-wise Exploration

---

### ✅ 1. **Vector (Random-Access Iterator)**

#### ✔️ Iterator Types:

* `iterator`, `const_iterator`
* `reverse_iterator`, `const_reverse_iterator`

#### 🔹 Sample Code:

```cpp
std::vector<int> v = {10, 20, 30};

// Normal iteration
for (auto it = v.begin(); it != v.end(); ++it) std::cout << *it << " ";

// Reverse
for (auto rit = v.rbegin(); rit != v.rend(); ++rit) std::cout << *rit << " ";
```

#### 🧠 Notes:

* Supports all iterator operations: `it + n`, `it - n`, `[]`, `distance`, etc.
* Ideal for random-access and performance-critical traversals.

---

### ✅ 2. **List (Bidirectional Iterator)**

#### ✔️ Iterator Types:

* `iterator`, `const_iterator`
* `reverse_iterator`, `const_reverse_iterator`

#### 🔹 Sample Code:

```cpp
std::list<std::string> names = {"Alice", "Bob", "Charlie"};

// Forward
for (auto it = names.begin(); it != names.end(); ++it) std::cout << *it << "\n";

// Reverse
for (auto rit = names.rbegin(); rit != names.rend(); ++rit) std::cout << *rit << "\n";
```

#### 🧠 Notes:

* No random access (no `it + 2`), only forward/backward with `++it`, `--it`.

---

### ✅ 3. **Forward\_List (Forward Iterator Only)**

#### ✔️ Iterator Types:

* `iterator`, `const_iterator`

#### 🔹 Sample Code:

```cpp
std::forward_list<int> fl = {1, 2, 3, 4};

for (auto it = fl.begin(); it != fl.end(); ++it) {
    std::cout << *it << " ";
}
```

#### 🧠 Notes:

* Only supports forward traversal.
* Lightweight container, minimal memory footprint.

---

### ✅ 4. **Deque (Random-Access Iterator)**

#### ✔️ Iterator Types:

* Same as `vector`: all iterator types

#### 🔹 Sample Code:

```cpp
std::deque<char> dq = {'A', 'B', 'C'};

for (auto it = dq.begin(); it != dq.end(); ++it) std::cout << *it;
```

#### 🧠 Notes:

* Efficient at both ends; behaves like vector with more flexibility.
* All iterator arithmetic operations are supported.

---

### ✅ 5. **Array (Random-Access Iterator)**

#### ✔️ Iterator Types:

* `iterator`, `const_iterator`, `reverse_iterator`

#### 🔹 Sample Code:

```cpp
std::array<int, 5> arr = {1, 2, 3, 4, 5};

for (auto it = arr.begin(); it != arr.end(); ++it) std::cout << *it << " ";
```

#### 🧠 Notes:

* Fixed size, fast random access.
* Similar to `vector` in iterator usage.

---

### ✅ 6. **Set / Multiset (Bidirectional Iterator)**

#### ✔️ Iterator Types:

* `iterator`, `const_iterator`, `reverse_iterator`

#### 🔹 Sample Code:

```cpp
std::set<int> s = {10, 20, 30};

for (auto it = s.begin(); it != s.end(); ++it) std::cout << *it << " ";
```

#### 🧠 Notes:

* Elements are sorted.
* No random access.
* Modifying values using iterators not allowed (as it breaks ordering).

---

### ✅ 7. **Map / Multimap (Bidirectional Iterator)**

#### ✔️ Iterator Types:

* `iterator`, `const_iterator`

#### 🔹 Sample Code:

```cpp
std::map<std::string, int> age = {{"Alice", 25}, {"Bob", 30}};

for (auto it = age.begin(); it != age.end(); ++it)
    std::cout << it->first << ": " << it->second << "\n";
```

#### 🧠 Notes:

* Iterators point to `pair<const Key, Value>`.
* Modifying `key` part is not allowed.

---

### ✅ 8. **Unordered Containers (Forward Iterator)**

Applies to:

* `unordered_set`, `unordered_multiset`
* `unordered_map`, `unordered_multimap`

#### ✔️ Iterator Types:

* Only forward iterators (`iterator`, `const_iterator`)

#### 🔹 Sample Code:

```cpp
std::unordered_map<std::string, int> m = {{"one", 1}, {"two", 2}};

for (auto it = m.begin(); it != m.end(); ++it)
    std::cout << it->first << " -> " << it->second << "\n";
```

#### 🧠 Notes:

* No ordering guarantees.
* No random-access or bidirectional traversal.

---

## 📑 Iterator Utilities from `<iterator>`

| Utility               | Description                             |
| --------------------- | --------------------------------------- |
| `std::advance`        | Move iterator forward/backward by N     |
| `std::distance`       | Number of steps between two iterators   |
| `std::next`           | Returns iterator advanced forward by N  |
| `std::prev`           | Returns iterator moved backward by N    |
| `std::inserter`       | Insert elements via an iterator         |
| `std::back_inserter`  | Append at the end using an iterator     |
| `std::front_inserter` | Insert at the front (list, deque, etc.) |

---

## 🧠 Summary Table

| Container        | Iterator Type(s)  | Random Access | Reverse | Forward | Bidirectional |
| ---------------- | ----------------- | ------------- | ------- | ------- | ------------- |
| `vector`         | all               | ✅             | ✅       | ✅       | ✅             |
| `list`           | all except random | ❌             | ✅       | ✅       | ✅             |
| `forward_list`   | forward only      | ❌             | ❌       | ✅       | ❌             |
| `deque`          | all               | ✅             | ✅       | ✅       | ✅             |
| `array`          | all               | ✅             | ✅       | ✅       | ✅             |
| `set`/`multiset` | bidirectional     | ❌             | ✅       | ✅       | ✅             |
| `map`/`multimap` | bidirectional     | ❌             | ✅       | ✅       | ✅             |
| `unordered_*`    | forward only      | ❌             | ❌       | ✅       | ❌             |

---

## 💡 Real-Time Use Cases

| Use Case                           | Container       | Iterators Used                  |
| ---------------------------------- | --------------- | ------------------------------- |
| Filter students with even roll no. | `vector<int>`   | `std::copy_if`, `back_inserter` |
| Unique IP logs                     | `unordered_set` | `forward_iterator`              |
| Word frequency counter             | `unordered_map` | iterate `pair<string, int>`     |
| Sorted top scores                  | `set<int>`      | `iterator`, `advance`           |
| Display student list in reverse    | `list<string>`  | `reverse_iterator`              |

---


---

# 🧭 C++ Iterators on `std::array`: A Step-by-Step Tutorial

## 🔷 What is `std::array`?

`std::array` is a **fixed-size array** container introduced in C++11. It’s a safer and more powerful alternative to raw C-style arrays. Since it’s part of the Standard Template Library (STL), it supports **iterators**, **algorithms**, **range-based loops**, and **container-like features**.

---

## 🎯 Why use Iterators with `std::array`?

Using iterators with `std::array` lets you:

* Traverse the container in a **standardized way**
* Use STL algorithms like `sort`, `reverse`, `accumulate`
* Write **generic** and **safe** code
* Support **const-correctness** and **reverse traversal**

---

## 📌 Step-by-Step: Types of Iterators Supported by `std::array`

| Iterator Type            | Description                 | Method                 |
| ------------------------ | --------------------------- | ---------------------- |
| `iterator`               | Read/write forward iterator | `begin()`, `end()`     |
| `const_iterator`         | Read-only forward iterator  | `cbegin()`, `cend()`   |
| `reverse_iterator`       | Read/write reverse iterator | `rbegin()`, `rend()`   |
| `const_reverse_iterator` | Read-only reverse iterator  | `crbegin()`, `crend()` |

---

## 🧪 Use Case: **Grade Analysis of 10 Students**

**Problem Statement**:
You are given an array of 10 student grades (integers out of 100).
You need to:

* Print the grades in reverse.
* Replace failed grades (<40) with 40 using forward iterator.
* Count how many passed (>= 50) using const\_iterator.
* Display the sorted list of grades using STL algorithm.

---

## 🧾 Full Code with Step-by-Step Explanations

```cpp
#include <iostream>
#include <array>
#include <algorithm>
#include <numeric> // for accumulate

int main() {
    // Step 1: Initialize std::array with student grades
    std::array<int, 10> grades = {78, 92, 35, 44, 89, 55, 67, 29, 49, 100};

    std::cout << "Original Grades (Reverse Order): ";
    // Step 2: Traverse in reverse using reverse_iterator
    for (std::array<int, 10>::reverse_iterator rit = grades.rbegin(); rit != grades.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << "\n";

    // Step 3: Fix failing grades (<40) using forward iterator
    for (std::array<int, 10>::iterator it = grades.begin(); it != grades.end(); ++it) {
        if (*it < 40) {
            *it = 40; // Replace with minimum pass mark
        }
    }

    std::cout << "Grades after fixing failures: ";
    for (int g : grades) std::cout << g << " ";
    std::cout << "\n";

    // Step 4: Count how many passed (>=50) using const_iterator
    int pass_count = 0;
    for (std::array<int, 10>::const_iterator cit = grades.cbegin(); cit != grades.cend(); ++cit) {
        if (*cit >= 50) ++pass_count;
    }
    std::cout << "Number of students who passed: " << pass_count << "\n";

    // Step 5: Sort using STL algorithm
    std::sort(grades.begin(), grades.end());

    std::cout << "Sorted Grades: ";
    for (int g : grades) std::cout << g << " ";
    std::cout << "\n";

    return 0;
}
```

---

## ✅ Output:

```
Original Grades (Reverse Order): 100 49 29 67 55 89 44 35 92 78 
Grades after fixing failures: 78 92 40 44 89 55 67 40 49 100 
Number of students who passed: 7
Sorted Grades: 40 40 44 49 55 67 78 89 92 100 
```

---

## 📘 Recap: Concepts Used

| Concept            | Applied In                          |
| ------------------ | ----------------------------------- |
| `reverse_iterator` | Reverse printing                    |
| `iterator`         | Modifying array elements (failures) |
| `const_iterator`   | Read-only counting of passed grades |
| `std::sort()`      | Uses iterators internally           |

---

## 🛠 STL Functions That Work with Iterators

| Function       | Description           |
| -------------- | --------------------- |
| `sort()`       | Sort the array        |
| `accumulate()` | Sum of elements       |
| `count()`      | Count occurrences     |
| `find()`       | Search for an element |
| `copy()`       | Copy contents         |
| `reverse()`    | Reverse contents      |

---

## 💡 Pro Tip

Iterators abstract away the details of how the container works internally. That means you can **write generic functions** that work on any container — `array`, `vector`, `list`, etc.

---



---

# 🧭 C++ Iterators on `std::vector`: A Complete Tutorial

---

## 🔷 What is `std::vector`?

`std::vector` is a **dynamic array** container in C++. It allows resizing at runtime, offers random-access like an array, and is the most widely used container due to its versatility and performance.

---

## 🎯 Why Use Iterators with `std::vector`?

Iterators allow you to:

* Traverse, modify, or read elements
* Use STL algorithms (`sort`, `count`, `find`, etc.)
* Write generic and safe code
* Enable reverse and const traversal

---

## 📌 Supported Iterator Types for `std::vector`

| Iterator Type            | Description                | Method                 |
| ------------------------ | -------------------------- | ---------------------- |
| `iterator`               | Mutable forward iterator   | `begin()`, `end()`     |
| `const_iterator`         | Read-only forward iterator | `cbegin()`, `cend()`   |
| `reverse_iterator`       | Mutable reverse iterator   | `rbegin()`, `rend()`   |
| `const_reverse_iterator` | Read-only reverse iterator | `crbegin()`, `crend()` |

---

## 📚 Use Case: **E-Commerce Cart Checkout**

**Problem Statement**:
You have a list of prices in a shopping cart.
You need to:

1. Print the cart in reverse order.
2. Apply a discount of ₹50 to items priced over ₹500.
3. Count how many items are free (< ₹1).
4. Sort the cart and print total value using `accumulate()`.

---

## 🧾 Full Code with Step-by-Step Explanation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for accumulate

int main() {
    // Step 1: Initialize vector with cart prices
    std::vector<int> cart = {199, 599, 999, 1, 0, 75, 1200};

    std::cout << "Cart Prices in Reverse: ";
    // Step 2: Use reverse_iterator to print cart in reverse
    for (std::vector<int>::reverse_iterator rit = cart.rbegin(); rit != cart.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << "\n";

    // Step 3: Apply ₹50 discount to items over ₹500
    for (std::vector<int>::iterator it = cart.begin(); it != cart.end(); ++it) {
        if (*it > 500) *it -= 50;
    }

    std::cout << "Cart after Discount: ";
    for (int price : cart) std::cout << price << " ";
    std::cout << "\n";

    // Step 4: Count free items (< ₹1) using const_iterator
    int free_items = 0;
    for (std::vector<int>::const_iterator cit = cart.cbegin(); cit != cart.cend(); ++cit) {
        if (*cit < 1) ++free_items;
    }
    std::cout << "Number of Free Items: " << free_items << "\n";

    // Step 5: Sort cart and compute total using accumulate
    std::sort(cart.begin(), cart.end());
    int total = std::accumulate(cart.begin(), cart.end(), 0);

    std::cout << "Sorted Cart: ";
    for (int p : cart) std::cout << p << " ";
    std::cout << "\nTotal Checkout Amount: ₹" << total << "\n";

    return 0;
}
```

---

## ✅ Sample Output:

```
Cart Prices in Reverse: 1200 75 0 1 999 599 199 
Cart after Discount: 199 549 949 1 0 75 1150 
Number of Free Items: 1
Sorted Cart: 0 1 75 199 549 949 1150 
Total Checkout Amount: ₹2923
```

---

## 🔁 Quick Recap of Concepts

| Concept             | Code Used                        |
| ------------------- | -------------------------------- |
| `reverse_iterator`  | Reverse printing of vector       |
| `iterator`          | Modify elements (apply discount) |
| `const_iterator`    | Count free items                 |
| `std::sort()`       | Sort items                       |
| `std::accumulate()` | Sum up total price               |

---

## 🛠 STL Algorithms You Can Use with Iterators

* `sort(begin, end)`
* `reverse(begin, end)`
* `accumulate(begin, end, initial)`
* `find(begin, end, value)`
* `count_if(begin, end, lambda)`
* `copy(begin, end, output_iterator)`

---

## 💡 Tip for Trainers and Learners

Encourage learners to **replace loop logic** with **STL algorithms** as a second step in practice. This helps reinforce iterator use and STL fluency.

---


---

## 🧭 C++ STL Tutorial: `std::map` and `std::multimap` with Iterators

---

## 🔷 What is `std::map`?

* `std::map` is an **associative container** that stores key-value pairs.
* Each **key is unique** and automatically sorted.
* Backed by **balanced binary search tree** (usually Red-Black Tree).

### 🔧 Syntax

```cpp
std::map<KeyType, ValueType> map_name;
```

---

## 🔷 What is `std::multimap`?

* Similar to `std::map`, but **allows duplicate keys**.
* Still sorted by key using `operator<`.

### 🔧 Syntax

```cpp
std::multimap<KeyType, ValueType> mmap_name;
```

---

## 📌 Supported Iterator Types

| Iterator Type            | Description                |
| ------------------------ | -------------------------- |
| `iterator`               | Mutable forward iterator   |
| `const_iterator`         | Read-only forward iterator |
| `reverse_iterator`       | Mutable reverse iterator   |
| `const_reverse_iterator` | Read-only reverse iterator |

---

## 📚 Use Case: `std::map` – **Student Roll Number to Name Mapping**

### 🎯 Problem Statement:

You are maintaining a register of students:

1. Add names for each roll number.
2. Update a name by roll number.
3. Print all students in ascending roll order.
4. Search and remove a specific roll number.

---

### 🧾 Code: `std::map` with Iterators

```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<int, std::string> studentMap;

    // Insertion using insert() and []
    studentMap[101] = "Alice";
    studentMap[102] = "Bob";
    studentMap.insert({103, "Charlie"});

    // Update using operator[]
    studentMap[102] = "Bobby";

    // Traversing using iterator
    std::cout << "Student List:\n";
    for (std::map<int, std::string>::iterator it = studentMap.begin(); it != studentMap.end(); ++it) {
        std::cout << "Roll: " << it->first << ", Name: " << it->second << "\n";
    }

    // Searching
    int roll_to_search = 103;
    std::map<int, std::string>::iterator searchIt = studentMap.find(roll_to_search);
    if (searchIt != studentMap.end()) {
        std::cout << "Found: " << searchIt->first << " -> " << searchIt->second << "\n";
    }

    // Erasing by key
    studentMap.erase(101);

    std::cout << "\nAfter deletion:\n";
    for (auto &p : studentMap) {
        std::cout << p.first << " => " << p.second << "\n";
    }

    return 0;
}
```

---

## ✅ Sample Output

```
Student List:
Roll: 101, Name: Alice
Roll: 102, Name: Bobby
Roll: 103, Name: Charlie
Found: 103 -> Charlie

After deletion:
102 => Bobby
103 => Charlie
```

---

## 📚 Use Case: `std::multimap` – **Books by Author**

### 🎯 Problem Statement:

In a library system:

1. Multiple books can be written by the same author.
2. Display books grouped by author.
3. Find and display all books by a given author.

---

### 🧾 Code: `std::multimap` with Iterators

```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::multimap<std::string, std::string> booksByAuthor;

    // Inserting books (duplicates allowed for keys)
    booksByAuthor.insert({"Dan Brown", "Inferno"});
    booksByAuthor.insert({"Dan Brown", "The Da Vinci Code"});
    booksByAuthor.insert({"J.K. Rowling", "Harry Potter"});
    booksByAuthor.insert({"J.R.R. Tolkien", "The Hobbit"});

    // Display all entries
    std::cout << "Library Books:\n";
    for (std::multimap<std::string, std::string>::iterator it = booksByAuthor.begin(); it != booksByAuthor.end(); ++it) {
        std::cout << it->first << " -> " << it->second << "\n";
    }

    // Finding all books by "Dan Brown"
    std::string author = "Dan Brown";
    std::cout << "\nBooks by " << author << ":\n";
    auto range = booksByAuthor.equal_range(author);
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << "\n";
    }

    return 0;
}
```

---

## ✅ Sample Output

```
Library Books:
Dan Brown -> Inferno
Dan Brown -> The Da Vinci Code
J.K. Rowling -> Harry Potter
J.R.R. Tolkien -> The Hobbit

Books by Dan Brown:
Inferno
The Da Vinci Code
```

---

## 🧠 STL `map` & `multimap` Iterator Notes

* Use `auto` for cleaner iterator syntax:

  ```cpp
  for (auto it = map.begin(); it != map.end(); ++it)
  ```
* `map` elements are ordered by key (ascending by default).
* `multimap` is useful when one key maps to **multiple values**.

---

## 🛠 List of Key Functions

| Method               | Description                          |
| -------------------- | ------------------------------------ |
| `insert()`           | Add key-value pair                   |
| `find(key)`          | Returns iterator to element if found |
| `erase(key)`         | Removes element with given key       |
| `clear()`            | Removes all elements                 |
| `size()`             | Number of elements                   |
| `empty()`            | Check if map is empty                |
| `equal_range(key)`   | Range of elements matching the key   |
| `begin()`, `end()`   | Iterators for traversal              |
| `rbegin()`, `rend()` | Reverse iterators                    |

---


---

## 🧭 C++ STL Tutorial: `std::set` and `std::multiset` with Iterators

---

### 🔷 What is `std::set`?

* A `set` is an **associative container** that stores **unique elements** in a sorted manner.
* Elements are **sorted automatically** (ascending by default).
* Internally implemented as a **Balanced BST** (like Red-Black Tree).
* No duplicate values allowed.

#### 🔧 Syntax

```cpp
std::set<DataType> s;
```

---

### 🔷 What is `std::multiset`?

* Similar to `set`, but **allows duplicate elements**.
* Also stores elements in sorted order.
* Internally also uses a Red-Black Tree.

#### 🔧 Syntax

```cpp
std::multiset<DataType> ms;
```

---

## 📌 Iterator Types in `set` and `multiset`

| Iterator Type            | Purpose                                                       |
| ------------------------ | ------------------------------------------------------------- |
| `iterator`               | Allows read-only traversal (modifiable only via insert/erase) |
| `const_iterator`         | Read-only iterator                                            |
| `reverse_iterator`       | Reverse direction                                             |
| `const_reverse_iterator` | Reverse read-only iterator                                    |

---

## 📚 Use Case: `std::set` – **Unique Course Codes**

### 🎯 Problem Statement:

You want to track **unique course codes** students register for. Duplicates are invalid.

---

### 🧾 Code: `std::set` with Iterators

```cpp
#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> courseSet;

    // Inserting unique course codes
    courseSet.insert("CS101");
    courseSet.insert("MA102");
    courseSet.insert("PH103");
    courseSet.insert("CS101");  // Duplicate, will be ignored

    // Display using iterator
    std::cout << "Registered Unique Course Codes:\n";
    for (auto it = courseSet.begin(); it != courseSet.end(); ++it) {
        std::cout << *it << "\n";
    }

    // Search for a course
    std::string searchCode = "MA102";
    if (courseSet.find(searchCode) != courseSet.end()) {
        std::cout << searchCode << " is registered.\n";
    }

    // Erase a course
    courseSet.erase("PH103");

    std::cout << "\nAfter deletion:\n";
    for (const auto &code : courseSet) {
        std::cout << code << "\n";
    }

    return 0;
}
```

---

### ✅ Output

```
Registered Unique Course Codes:
CS101
MA102
PH103
MA102 is registered.

After deletion:
CS101
MA102
```

---

## 📚 Use Case: `std::multiset` – **Word Frequency Counter**

### 🎯 Problem Statement:

Count word occurrences from a stream of inputs, allowing duplicates.

---

### 🧾 Code: `std::multiset` with Iterators

```cpp
#include <iostream>
#include <set>
#include <string>

int main() {
    std::multiset<std::string> wordMultiset;

    // Simulating word inputs
    wordMultiset.insert("apple");
    wordMultiset.insert("banana");
    wordMultiset.insert("apple");
    wordMultiset.insert("orange");
    wordMultiset.insert("banana");

    // Display words (duplicates allowed)
    std::cout << "Words Entered:\n";
    for (const auto &word : wordMultiset) {
        std::cout << word << "\n";
    }

    // Count occurrences
    std::string search = "apple";
    std::cout << "\nOccurrences of '" << search << "': " 
              << wordMultiset.count(search) << "\n";

    // Erase all instances of a word
    wordMultiset.erase("banana");

    std::cout << "\nAfter deleting 'banana':\n";
    for (auto it = wordMultiset.begin(); it != wordMultiset.end(); ++it) {
        std::cout << *it << "\n";
    }

    return 0;
}
```

---

### ✅ Output

```
Words Entered:
apple
apple
banana
banana
orange

Occurrences of 'apple': 2

After deleting 'banana':
apple
apple
orange
```

---

## 🧠 STL `set` and `multiset` – Iterator Tips

* Sets do not allow modifying values via iterators (keys are constant).
* Use `auto` for clean syntax:

  ```cpp
  for (auto it = s.begin(); it != s.end(); ++it)
  ```

---

## 🔍 List of Common Methods

| Method             | Description                                                |
| ------------------ | ---------------------------------------------------------- |
| `insert(val)`      | Inserts value (ignores duplicates in `set`)                |
| `find(val)`        | Returns iterator to value if found                         |
| `count(val)`       | Returns count of value (0 or 1 in `set`, ≥0 in `multiset`) |
| `erase(val)`       | Removes all occurrences of `val`                           |
| `size()`           | Returns number of elements                                 |
| `clear()`          | Removes all elements                                       |
| `empty()`          | Returns true if container is empty                         |
| `begin(), end()`   | Returns iterator range                                     |
| `lower_bound(val)` | First position not less than `val`                         |
| `upper_bound(val)` | First position greater than `val`                          |
| `equal_range(val)` | Returns pair of lower and upper bounds                     |

---

## 🚀 Real-World Use Cases

| Use Case                        | Container  |
| ------------------------------- | ---------- |
| Tracking unique student IDs     | `set`      |
| Counting word frequency         | `multiset` |
| Filtering duplicates in emails  | `set`      |
| Logging error types with repeat | `multiset` |

---

## 📘 Summary

* Use `set` for uniqueness.
* Use `multiset` for counting and allowing duplicates.
* Both offer **sorted access**, fast lookup, and iterator support.

---



---

## 🧭 C++ STL Iterators Tutorial: `iterator`, `const_iterator`, and `reverse_iterator`

---

### 📌 What is an **Iterator**?

In STL, **iterators** act like pointers used to **access container elements**. They provide a standard way to traverse elements regardless of container type (`vector`, `list`, `set`, etc.).

---

### 🔶 Types of Iterators

| Type                     | Description                                                         |
| ------------------------ | ------------------------------------------------------------------- |
| `iterator`               | Read-write access; allows modifying the elements.                   |
| `const_iterator`         | Read-only access; you **cannot modify** elements via this iterator. |
| `reverse_iterator`       | Traverses the container in **reverse** order.                       |
| `const_reverse_iterator` | Reverse and read-only access.                                       |

---

## 1️⃣ `iterator` – Read/Write Traversal

### ✅ Use Case: Updating student scores stored in a `vector<int>`

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> scores = {80, 90, 70};

    // iterator: read and write access
    for (vector<int>::iterator it = scores.begin(); it != scores.end(); ++it) {
        *it += 5;  // bonus marks
    }

    cout << "Updated Scores: ";
    for (int score : scores)
        cout << score << " ";  // Output: 85 95 75
}
```

🧠 Use when:

* You want to **modify elements**.
* You are **iterating in forward** direction.

---

## 2️⃣ `const_iterator` – Read-Only Traversal

### ✅ Use Case: Displaying elements without modifying them

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> names = {"Alice", "Bob", "Charlie"};

    // const_iterator: read-only access
    for (vector<string>::const_iterator it = names.cbegin(); it != names.cend(); ++it) {
        cout << *it << " ";
        // *it = "Test";  ❌ Not allowed
    }
}
```

🧠 Use when:

* You need to **ensure safety against modification**.
* You're reading from **const containers** or passing containers by `const&`.

---

## 3️⃣ `reverse_iterator` – Backward Traversal

### ✅ Use Case: Displaying elements in reverse order (latest to oldest)

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<string> recentFiles = {"file1.txt", "file2.txt", "file3.txt"};

    // reverse_iterator: backward traversal
    cout << "Recent Files (Most Recent First):\n";
    for (deque<string>::reverse_iterator rit = recentFiles.rbegin(); rit != recentFiles.rend(); ++rit) {
        cout << *rit << "\n";
    }
}
```

🧠 Use when:

* You want to **traverse in reverse**.
* Typical in LIFO operations, reverse printing, undo stack, etc.

---

## 🔄 Using Auto for Simplicity

You can avoid long type declarations using `auto`:

```cpp
for (auto it = v.begin(); it != v.end(); ++it) { ... }
for (auto it = v.cbegin(); it != v.cend(); ++it) { ... }
for (auto it = v.rbegin(); it != v.rend(); ++it) { ... }
```

---

## 📌 Differences Summary

| Feature             | `iterator` | `const_iterator`     | `reverse_iterator`       |
| ------------------- | ---------- | -------------------- | ------------------------ |
| Direction           | Forward    | Forward              | Reverse                  |
| Modifiable Element? | Yes        | ❌ No                 | Yes (if non-const)       |
| Use Case            | Read/write | Read-only for safety | LIFO traversal / Reverse |
| Supports `auto`     | ✅          | ✅                    | ✅                        |

---

## 🔍 Advanced Example: `set` with All Three

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> data = {10, 20, 30, 40, 50};

    cout << "Forward:\n";
    for (auto it = data.begin(); it != data.end(); ++it)
        cout << *it << " ";

    cout << "\nReverse:\n";
    for (auto rit = data.rbegin(); rit != data.rend(); ++rit)
        cout << *rit << " ";

    cout << "\nRead-only check:\n";
    for (set<int>::const_iterator cit = data.cbegin(); cit != data.cend(); ++cit) {
        cout << *cit << " ";
        // *cit += 5; // ❌ error
    }
}
```

---

## 🧠 Real-Time Use Cases

| Iterator Type      | Real-Life Example                                          |
| ------------------ | ---------------------------------------------------------- |
| `iterator`         | Modifying marks, salary, price in-place                    |
| `const_iterator`   | Display-only views of catalogs, dashboards                 |
| `reverse_iterator` | Browser history, undo stack, recent files in reverse order |

---

## 📘 Best Practices

* Use `const_iterator` for safety if no modification is required.
* Use `reverse_iterator` when order matters (like stack trace).
* Prefer `auto` for readability.
* Use `.cbegin()`, `.cend()` for read-only containers.

---

