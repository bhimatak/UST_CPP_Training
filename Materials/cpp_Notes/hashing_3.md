
---

##  **Hashing: A Complete Tutorial**

---

###  **1. Introduction to Hashing**

**Hashing** is a technique used to map data (often large or complex) to a fixed-size value, called a **hash code** or **hash value**. It helps in **fast data lookup**, **insertion**, and **deletion**.

Imagine you have a library and want to quickly find a book by its title. Instead of checking every book, you could use a hashing technique to assign each title a number (hash), and jump directly to the location.

---

###  **2. Why Hashing?**

* **Time efficiency:** On average, searching takes **O(1)** time.
* **Memory management:** Uses space smartly by avoiding unnecessary data storage.
* **Used in:** Databases, caches, compilers, cryptography, and more.

---

###  **3. Hash Function**

A **hash function** takes input (key) and converts it into an index within a range (usually array size).

#### Properties of a Good Hash Function:

* **Deterministic**: Same input → same output.
* **Fast to compute**
* **Uniform distribution**: Avoid clustering (too many keys to same index).
* **Minimize collisions**

#### Common Hashing Formula:

```text
index = hash(key) % table_size
```

---

###  **4. Hash Table**

A **Hash Table** is a data structure that stores key-value pairs using a hash function to compute an index. The keys are mapped to **buckets** in an array.

Example of a simple hash table:

| Index | Key    | Value |
| ----- | ------ | ----- |
| 0     | -      | -     |
| 1     | "dog"  | 123   |
| 2     | "cat"  | 456   |
| 3     | -      | -     |
| 4     | "fish" | 789   |

---

###  **5. Collisions**

**Collision** occurs when two different keys map to the same index in the hash table.

#### Collision Handling Techniques:

1. **Chaining (Separate Chaining)**:

   * Each index holds a **linked list** of key-value pairs.
   * Easy to implement and avoids overwriting.

2. **Open Addressing**:

   * If a slot is occupied, probe the next available one.
   * **Types:**

     * Linear Probing
     * Quadratic Probing
     * Double Hashing

---

##  Deep Dive: Chaining vs Open Addressing

| Feature            | Chaining                 | Open Addressing           |
| ------------------ | ------------------------ | ------------------------- |
| Space              | Extra space for chains   | Uses table space only     |
| Deletion           | Easier                   | Needs careful shifting    |
| Load factor effect | Handles high load better | Performance degrades fast |
| Cache performance  | Lower (pointers)         | Better (contiguous)       |

---

###  **6. Load Factor**

```text
Load Factor = number of elements / size of table
```

* High load factor → more collisions
* Rehashing is often used when load factor exceeds a threshold

---

##  Code Snippets (C++)

---

###  Hash Function (simple modulus)

```cpp
int hashFunction(int key, int tableSize) {
    return key % tableSize;
}
```

---

###  Hash Table with Chaining (using vector of lists)

```cpp
#include <iostream>
#include <list>
#include <vector>

class HashTable {
private:
    int size;
    std::vector<std::list<int>> table;

    int hash(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size);
    }

    void insert(int key) {
        int idx = hash(key);
        table[idx].push_back(key);
    }

    void display() {
        for (int i = 0; i < size; i++) {
            std::cout << i << ": ";
            for (int key : table[i]) {
                std::cout << key << " -> ";
            }
            std::cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht(5);
    ht.insert(10);
    ht.insert(15);
    ht.insert(20);
    ht.insert(3);
    ht.insert(8);
    ht.display();
    return 0;
}
```

---

###  Hash Table with Open Addressing (Linear Probing)

```cpp
#include <iostream>
#include <vector>

class HashTable {
private:
    int size;
    std::vector<int> table;

    int hash(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size, -1);
    }

    void insert(int key) {
        int idx = hash(key);
        int start = idx;
        while (table[idx] != -1) {
            idx = (idx + 1) % size;
            if (idx == start) {
                std::cout << "Hash table is full!\n";
                return;
            }
        }
        table[idx] = key;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            std::cout << i << ": " << (table[i] == -1 ? "NULL" : std::to_string(table[i])) << "\n";
        }
    }
};

int main() {
    HashTable ht(7);
    ht.insert(10);
    ht.insert(3);
    ht.insert(17); // causes collision
    ht.insert(24);
    ht.display();
    return 0;
}
```

---

### 🏁 Final Notes

* Always choose an appropriate **table size (preferably prime)** to reduce collisions.
* Monitor the **load factor** and perform **rehashing** when needed.
* Use **STL unordered\_map** for practical use, but implement your own for better understanding.

---

