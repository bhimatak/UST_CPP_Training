
---

# 📘 Hashing – In-depth Theoretical Tutorial for Beginners

---

## 🔰 Chapter 1: Introduction to Hashing

### 📌 What is Hashing?

Hashing is a **data storage and retrieval technique** that maps data to a fixed-size value, known as a **hash code**, using a **mathematical function** called a **hash function**.

Think of it like assigning a **unique locker number** to each student in a school based on their name. Instead of going through every locker (linear search), you directly open the locker linked to the student using a rule (hash function).

### 📌 Why Hashing?

Hashing is **widely used** when:

* Quick data access is needed.
* The dataset is too large for linear search.
* The key space is large but the actual data is sparse.

### 🎯 Applications of Hashing:

* Symbol table management in compilers
* Database indexing
* Caches (like DNS cache)
* Password storage (with cryptographic hash functions)
* Blockchain technology

---

## 🧠 Chapter 2: Hash Functions

A **Hash Function** is a mathematical formula that **converts a key into an array index**.

### 🔍 Desired Properties of a Good Hash Function:

| Property                 | Description                         |
| ------------------------ | ----------------------------------- |
| **Deterministic**        | Same key always gives same hash.    |
| **Uniformity**           | Spread keys uniformly across slots. |
| **Efficiency**           | Should be fast to compute.          |
| **Minimized Collisions** | Should avoid clustering.            |

### 📌 Common Hash Function Types:

1. **Modulo Division Method**
   `index = key % tableSize`
   Easiest and widely used. Use prime `tableSize` to reduce collisions.

2. **Folding Method**
   Break key into parts, sum them up and take mod with table size.

3. **Multiplication Method**
   `index = floor(tableSize * ((key * A) % 1))`
   where `A` is a constant between 0 and 1 (e.g., 0.618).

4. **Hashing Strings (Polynomial Hashing)**

   ```
   hash = s[0]*31ⁿ⁻¹ + s[1]*31ⁿ⁻² + ... + s[n-1]
   ```

---

## 📦 Chapter 3: Hash Table

A **Hash Table** is a **data structure** that maps keys to values using a hash function.

### 📌 Core Idea:

* Array of buckets (fixed size)
* Use hash function to compute index
* Store key (or key-value) at that index

### 🖼️ Visual Structure:

```
Index  | Bucket
--------------------
0      | NULL
1      | 15 → 35 → 75
2      | NULL
3      | 12
...
```

---

## ❗ Chapter 4: Collisions and Their Handling

### 🔥 What is a Collision?

When two **different keys** hash to the **same index**, it causes a **collision**.

### 📌 Why Collisions Happen?

* Limited number of indices (buckets)
* Multiple keys can result in same index
* Happens more as the **load factor increases**

### 🧰 Collision Resolution Strategies:

---

### 🎯 1. **Separate Chaining (with Linked Lists)**

* Each bucket stores a **list** (or vector) of entries.
* On collision, new key is **appended** to the list at that index.

#### ✅ Pros:

* Easy to implement.
* Can handle many collisions per slot.

#### ❌ Cons:

* Extra memory (pointers).
* Worst-case lookup time is **O(n)** if many items hash to same index.

---

### 🎯 2. **Open Addressing**

In this method, **no external list** is used. If a slot is full, probe for another slot.

#### 🛠️ Types:

1. **Linear Probing**
   Check `index+1`, `index+2`, … until empty slot.

2. **Quadratic Probing**
   Check `index + 1²`, `index + 2²`, …
   Reduces primary clustering.

3. **Double Hashing**
   Use a second hash function to calculate the probe interval:

   ```cpp
   index = (hash1(key) + i * hash2(key)) % tableSize
   ```

#### ✅ Pros:

* No extra memory.
* Cache-friendly.

#### ❌ Cons:

* Needs careful deletion (mark deleted).
* Load factor > 0.7 affects performance.

---

## 📊 Chapter 5: Load Factor & Rehashing

### 📌 Load Factor (α):

```text
α = number of keys / table size
```

* If α is too high, collisions increase.
* A good rule is to **keep α <= 0.7**.
* When α exceeds threshold → **rehashing** (create bigger table and reinsert all keys).

---

## 🧪 Chapter 6: Hash Table Operations

| Operation | Time Complexity (Avg Case) | Time Complexity (Worst Case)      |
| --------- | -------------------------- | --------------------------------- |
| Search    | O(1)                       | O(n) (chaining) or O(n) (probing) |
| Insert    | O(1)                       | O(n) in worst case                |
| Delete    | O(1)                       | O(n) in worst case                |

---

##  Chapter 7: Real-World Examples

| Use Case                  | Hashing Role                                     |
| ------------------------- | ------------------------------------------------ |
| **Password Storage**      | Use of cryptographic hash functions like SHA-256 |
| **Compiler Symbol Table** | Maps variable/function names to entries          |
| **Browser Cache**         | URL → cached webpage                             |
| **Blockchain**            | Transactions hashed into blocks                  |
| **Databases**             | Indexing for faster retrieval                    |

---

##  Chapter 8: Beginner Code Examples

###  1. Simple Hash Function

```cpp
int hash(int key, int tableSize) {
    return key % tableSize;
}
```

---

###  2. Hash Table using Chaining

```cpp
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    int size;
    vector<list<int>> table;

public:
    HashTable(int s) : size(s), table(s) {}

    int hash(int key) {
        return key % size;
    }

    void insert(int key) {
        table[hash(key)].push_back(key);
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            for (int x : table[i]) cout << x << " -> ";
            cout << "NULL\n";
        }
    }
};
```

---

###  3. Hash Table using Linear Probing

```cpp
#include <iostream>
#include <vector>
using namespace std;

class HashTable {
    vector<int> table;
    int size;

public:
    HashTable(int s) : size(s), table(s, -1) {}

    int hash(int key) {
        return key % size;
    }

    void insert(int key) {
        int idx = hash(key);
        while (table[idx] != -1) {
            idx = (idx + 1) % size;
        }
        table[idx] = key;
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << i << ": " << (table[i] == -1 ? "NULL" : to_string(table[i])) << "\n";
        }
    }
};
```

---

##  Chapter 9: Summary and Takeaways

✅ Hashing is ideal for fast access to data.
✅ A good hash function distributes keys uniformly.
✅ Collisions are inevitable—must be handled carefully.
✅ Separate chaining is easier to implement; open addressing is space efficient.
✅ Load factor must be monitored to avoid performance drops.

---

##  Optional Exercises

1. Implement a hash table to store and search student roll numbers.
2. Modify chaining with `std::vector<int>` instead of `std::list<int>`.
3. Implement deletion logic in linear probing.
4. Extend the hash table to accept key-value pairs (like `unordered_map`).

---
