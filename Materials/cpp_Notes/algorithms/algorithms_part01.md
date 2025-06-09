
---

##  STL Algorithms Overview

###  What are STL Algorithms?

STL algorithms are **built-in functions** provided by the C++ Standard Library that operate on ranges of elements using **iterators**. They perform tasks such as searching, sorting, counting, modifying, and more.

---

###  Why Use STL Algorithms?

* **Efficiency**: Well-optimized and faster than writing your own from scratch.
* **Reusability**: Prevents code duplication.
* **Readability**: Expressive and clean code.
* **Portability**: Consistent across platforms.

---

### 📌 Real-Time Use Cases

* Finding the top scorer in a list of scores.
* Removing duplicate entries from a static config list.
* Sorting sensor data from IoT devices before analysis.
* Counting how many times a particular error code appears in a system log.

---

### 🧠 Types of Algorithms

Let’s now categorize and list STL algorithms commonly used with arrays:

---

## 📚 Categories of STL Algorithms (With Syntax)

> **Note**: For an `std::array<T, N> arr`, use `arr.begin()` and `arr.end()` for iterator-based operations.

### 1.  **Non-modifying Algorithms**

Used for **observations** or **queries**. They do **not alter** the array.

| Algorithm     | Syntax                               | Description                                    |
| ------------- | ------------------------------------ | ---------------------------------------------- |
| `all_of`      | `all_of(begin, end, pred)`           | Checks if all elements satisfy predicate       |
| `any_of`      | `any_of(begin, end, pred)`           | Checks if any element satisfies predicate      |
| `none_of`     | `none_of(begin, end, pred)`          | Checks if no element satisfies predicate       |
| `count`       | `count(begin, end, value)`           | Counts occurrences of a value                  |
| `count_if`    | `count_if(begin, end, pred)`         | Counts elements satisfying predicate           |
| `find`        | `find(begin, end, value)`            | Finds first occurrence                         |
| `find_if`     | `find_if(begin, end, pred)`          | Finds first element matching predicate         |
| `find_if_not` | `find_if_not(begin, end, pred)`      | Finds first element **not** matching predicate |
| `mismatch`    | `mismatch(begin1, end1, begin2)`     | Finds first mismatch between two ranges        |
| `equal`       | `equal(begin1, end1, begin2)`        | Checks if two ranges are equal                 |
| `search`      | `search(begin1, end1, begin2, end2)` | Finds first subrange match                     |

---

### 2.  **Modifying Algorithms**

These change values in the range.

| Algorithm    | Syntax                                  | Description                                      |
| ------------ | --------------------------------------- | ------------------------------------------------ |
| `copy`       | `copy(begin, end, dest_begin)`          | Copies elements to new range                     |
| `copy_if`    | `copy_if(begin, end, dest_begin, pred)` | Copies matching elements                         |
| `fill`       | `fill(begin, end, value)`               | Fills range with value                           |
| `fill_n`     | `fill_n(begin, count, value)`           | Fills `n` elements                               |
| `transform`  | `transform(begin, end, dest, op)`       | Applies operation to each element                |
| `replace`    | `replace(begin, end, old_val, new_val)` | Replaces value                                   |
| `replace_if` | `replace_if(begin, end, pred, new_val)` | Replaces elements matching predicate             |
| `remove`     | `remove(begin, end, val)`               | Marks elements for removal (doesn't change size) |
| `remove_if`  | `remove_if(begin, end, pred)`           | Removes matching elements                        |
| `unique`     | `unique(begin, end)`                    | Removes consecutive duplicates                   |
| `reverse`    | `reverse(begin, end)`                   | Reverses order of elements                       |
| `rotate`     | `rotate(begin, middle, end)`            | Rotates elements                                 |

---

### 3. **Sorting and Order**

| Algorithm         | Syntax                             | Description                    |
| ----------------- | ---------------------------------- | ------------------------------ |
| `sort`            | `sort(begin, end)`                 | Sorts elements                 |
| `stable_sort`     | `stable_sort(begin, end)`          | Maintains relative order       |
| `partial_sort`    | `partial_sort(begin, middle, end)` | Partially sorts                |
| `nth_element`     | `nth_element(begin, nth, end)`     | nth element in sorted order    |
| `is_sorted`       | `is_sorted(begin, end)`            | Checks if sorted               |
| `is_sorted_until` | `is_sorted_until(begin, end)`      | Returns first unsorted element |

---

### 4. **Set Algorithms** (for sorted ranges)

| Algorithm                  | Syntax                                          | Description                     |
| -------------------------- | ----------------------------------------------- | ------------------------------- |
| `set_union`                | `set_union(begin1, end1, begin2, end2, result)` | Union of sets                   |
| `set_intersection`         | `set_intersection(...)`                         | Common elements                 |
| `set_difference`           | `set_difference(...)`                           | Elements in 1st not in 2nd      |
| `set_symmetric_difference` | `set_symmetric_difference(...)`                 | Elements in either but not both |

---

### 5. **Binary Search Algorithms** (sorted only)

| Algorithm       | Syntax                           | Description             |
| --------------- | -------------------------------- | ----------------------- |
| `binary_search` | `binary_search(begin, end, val)` | True if val exists      |
| `lower_bound`   | `lower_bound(begin, end, val)`   | First pos `>= val`      |
| `upper_bound`   | `upper_bound(begin, end, val)`   | First pos `> val`       |
| `equal_range`   | `equal_range(begin, end, val)`   | Range of equal elements |

---

### 6.  **Min/Max Operations**

| Algorithm        | Syntax                       | Description         |
| ---------------- | ---------------------------- | ------------------- |
| `min_element`    | `min_element(begin, end)`    | Iterator to min     |
| `max_element`    | `max_element(begin, end)`    | Iterator to max     |
| `minmax_element` | `minmax_element(begin, end)` | Pair of min and max |

---

### 7.  **Permutation and Heap**

| Algorithm          | Syntax                         | Description                    |
| ------------------ | ------------------------------ | ------------------------------ |
| `next_permutation` | `next_permutation(begin, end)` | Next lexicographic permutation |
| `prev_permutation` | `prev_permutation(begin, end)` | Previous permutation           |
| `make_heap`        | `make_heap(begin, end)`        | Makes max-heap                 |
| `push_heap`        | `push_heap(begin, end)`        | Adds element to heap           |
| `pop_heap`         | `pop_heap(begin, end)`         | Removes max                    |
| `sort_heap`        | `sort_heap(begin, end)`        | Converts heap to sorted        |

---

### 8. **Numeric Algorithms** (in `<numeric>`)

| Algorithm             | Syntax                                      | Description                 |
| --------------------- | ------------------------------------------- | --------------------------- |
| `accumulate`          | `accumulate(begin, end, init)`              | Sums elements               |
| `inner_product`       | `inner_product(begin1, end1, begin2, init)` | Dot product                 |
| `adjacent_difference` | `adjacent_difference(begin, end, dest)`     | Difference between elements |
| `partial_sum`         | `partial_sum(begin, end, dest)`             | Running totals              |

---
