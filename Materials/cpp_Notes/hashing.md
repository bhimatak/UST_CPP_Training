---

#  **Hashing in C++: A Complete Tutorial**

---

##  **1. Introduction to Hashing**

###  What is Hashing?

Hashing is a **data processing technique** where a large amount of data is mapped to a smaller fixed-size value (called a **hash value** or **hash code**) using a **hash function**.

This mapping allows for **fast data access**, typically in **constant time O(1)**, under ideal conditions.

###  Hash Function

A **hash function** takes an input (or "key") and returns an integer, called a **hash code**, which determines the **index in the underlying data structure** (typically an array or table).

---

##  **2. Why is Hashing Used?**

Hashing is mainly used for:

*  **Fast Data Access** (e.g., lookups, insertions, deletions in O(1))
*  **Avoiding Linear Search** in large datasets
*  **Duplicate Detection**
*  **Set Membership Testing**
*  **Cryptographic Applications** (advanced)

---

##  **3. Real-Time Use Cases**

| Use Case                    | Description                                                     |
| --------------------------- | --------------------------------------------------------------- |
| **Hash Tables**             | Used in compilers, databases, interpreters, caches, etc.        |
| **Password Storage**        | Hashes are used to securely store passwords.                    |
| **Spell Checkers**          | Words are hashed and looked up quickly.                         |
| **Compilers/Symbol Tables** | Variables and functions are hashed for efficient symbol lookup. |
| **Detecting Duplicates**    | Fast identification of repeated entries in log files, etc.      |

---

##  **4. Hashing in C++ – STL Approach**

C++ Standard Library (STL) provides containers like:

* `std::unordered_map`
* `std::unordered_set`

These use **hashing internally** for fast operations.

---

##  **5. Syntax and Basic Examples**

###  **Unordered Map (Key-Value Store)**

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> studentMarks;

    // Insert values
    studentMarks["Alice"] = 85;
    studentMarks["Bob"] = 92;

    // Access a value
    cout << "Bob's marks: " << studentMarks["Bob"] << endl;

    // Iterate through map
    for (auto &entry : studentMarks) {
        cout << entry.first << " has marks " << entry.second << endl;
    }

    return 0;
}
```

###  **Unordered Set (Only Keys, No Values)**

```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> uniqueNumbers;

    uniqueNumbers.insert(10);
    uniqueNumbers.insert(20);
    uniqueNumbers.insert(10);  // Duplicate, won't be added

    for (int num : uniqueNumbers)
        cout << num << " ";

    return 0;
}
```

---

##  **6. Hash Table Internals (How it Works)**

###  Hash Table Structure

* Backed by an **array of buckets**
* **Hash function** maps key to an index
* If **two keys map to the same index**, it's called a **collision**
* **Collision resolution techniques**:

  * **Chaining (Linked Lists)**
  * **Open Addressing (Linear Probing, Quadratic Probing)**

###  Example:

If a hash function is: `hash(key) = key % 10`

Then:

* `key = 23 → hash = 3`
* `key = 33 → hash = 3` → Collision with key 23

---

##  **7. Custom Hash Functions**

You can define custom hash functions using `std::hash` and `struct`.

### ✏ Example – Hashing a Pair

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

// Custom hash function
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ hash<T2>()(p.second);
    }
};

int main() {
    unordered_map<pair<int, int>, string, pair_hash> myMap;

    myMap[{1, 2}] = "Point A";
    myMap[{3, 4}] = "Point B";

    cout << myMap[{1, 2}] << endl;

    return 0;
}
```

---

##  **8. Collision Handling in Detail**

###  **1. Chaining**

Each bucket has a **linked list** of entries that hashed to that bucket.

**Pros**: Simple, handles high load well
**Cons**: Can degrade to O(n) in worst-case

###  **2. Open Addressing**

If collision occurs, try finding another open slot.

* **Linear Probing**: Try next index: `index + 1`
* **Quadratic Probing**: Try `index + i²`
* **Double Hashing**: Use a second hash function to jump to a different index

---

##  **9. Performance Analysis**

| Operation | Average Time | Worst Case |
| --------- | ------------ | ---------- |
| Search    | O(1)         | O(n)       |
| Insert    | O(1)         | O(n)       |
| Delete    | O(1)         | O(n)       |

**Factors Affecting Performance:**

* Load factor
* Quality of hash function
* Collision handling mechanism

---

##  **10. Practice Problems**

1. **Detect Duplicates in an Array**
   Use `unordered_set` to check if any element repeats.

2. **Count Frequency of Words**
   Use `unordered_map<string, int>` to count occurrences of each word in a paragraph.

3. **Two Sum Problem**
   Use hashing to find if two numbers add up to a target.

4. **Find Intersection of Two Arrays**
   Use `unordered_set` to efficiently detect common elements.

---

##  **11. Summary & Key Takeaways**

| Concept                | Summary                                                   |
| ---------------------- | --------------------------------------------------------- |
| **Hashing**            | Mapping of data to fixed-size values using hash functions |
| **STL Containers**     | `unordered_map`, `unordered_set` offer built-in hashing   |
| **Collision Handling** | Chaining, Open Addressing                                 |
| **Performance**        | Average O(1), but collisions can degrade it               |
| **Customization**      | You can define your own hash functions                    |

---

##  **12. Suggested Exercises (For Practice)**

| Problem                                        | Description                                             |
| ---------------------------------------------- | ------------------------------------------------------- |
| **LeetCode 1. Two Sum**                        | Classic problem using `unordered_map`                   |
| **GFG: Count Distinct Elements**               | Use `unordered_set`                                     |
| **LeetCode 128. Longest Consecutive Sequence** | Efficient hashing-based solution                        |
| **Design a HashMap**                           | Implement from scratch with chaining or open addressing |

---

##  **13. Advanced Topics (Optional)**

* Perfect Hashing
* Cryptographic Hash Functions (MD5, SHA-256)
* Bloom Filters
* Hashing with Tries
* Cache Implementations (e.g., LRU Cache using hashing + DLL)

---

