
---

#  **Hash Functions and Hashing Algorithms in C++**

---

##  **1. What is a Hash Function?**

A **hash function** is a mathematical function that converts input (keys) into a **fixed-size integer value** (called the **hash code** or **hash value**). This hash code is used to determine the **index in a hash table**.

###  **Key Characteristics of a Good Hash Function**:

* **Deterministic**: Same input must always give the same output.
* **Efficient**: Should compute quickly.
* **Uniform distribution**: Should distribute keys evenly to minimize collisions.
* **Minimize collisions**: Fewer keys should hash to the same value.
* **Deterministic output size**: Outputs fixed-size value (like 32-bit or 64-bit integers).

---

##  **2. Common Hashing Algorithms (Non-Cryptographic)**

###  a. **Modulo-Based Hashing**

Most basic method:

```cpp
hash = key % tableSize;
```

> Used in integer hashing. Simple, but poor distribution if `tableSize` is a factor of common key patterns.

---

###  b. **Multiplicative Hashing**

Knuth’s suggestion:

```cpp
hash = floor(tableSize * fmod(key * A, 1));
```

Where `A` is a constant in (0, 1), e.g., 0.6180339887 (Golden Ratio fraction).

---

###  c. **FNV Hash (Fowler–Noll–Vo)**

Good for strings:

```cpp
unsigned int fnv_hash(string key) {
    const int fnv_prime = 0x811C9DC5;
    unsigned int hash = 0;
    for (char c : key) {
        hash *= fnv_prime;
        hash ^= c;
    }
    return hash;
}
```

---

###  d. **DJB2 Hash (Daniel J. Bernstein’s)**

Simple and popular string hash function:

```cpp
unsigned long djb2_hash(string str) {
    unsigned long hash = 5381;
    for (char c : str)
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash;
}
```

---

###  e. **CRC32 / MurmurHash / CityHash / xxHash**

These are advanced, high-performance hash functions used in production systems:

* MurmurHash → Fast, used in HashMaps (non-cryptographic)
* CityHash → Designed by Google
* xxHash → Extremely fast hashing

Note: These are available through external libraries and are **not in STL**.

---

##  **3. Using Hash Function in C++ STL**

The STL already provides default `std::hash<T>` for built-in types like `int`, `string`, `char`, `bool`, etc.

###  Example: Hashing Strings with `std::hash`

```cpp
#include <iostream>
#include <string>
#include <functional>

using namespace std;

int main() {
    hash<string> stringHasher;
    string s = "hello";
    cout << "Hash value of '" << s << "' is " << stringHasher(s) << endl;
    return 0;
}
```

---

##  **4. Custom Hash Function for Complex Data Types**

###  Example: Custom Hash for `pair<int, int>`

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

int main() {
    unordered_map<pair<int, int>, string, pair_hash> points;
    points[{1, 2}] = "Origin";
    cout << points[{1, 2}] << endl;
    return 0;
}
```

---

##  **5. Handling Collisions**

When two inputs produce the same hash value, a **collision** occurs.

###  **Collision Resolution Techniques**:

| Method              | Description                                                 |
| ------------------- | ----------------------------------------------------------- |
| **Chaining**        | Use a linked list for each bucket                           |
| **Open Addressing** | Find the next free slot (linear probing, quadratic probing) |
| **Double Hashing**  | Use another hash function to jump further                   |

---

##  **6. Performance Notes**

| Metric                       | Detail                                            |
| ---------------------------- | ------------------------------------------------- |
| Time Complexity (Average)    | O(1) for insert/search/delete                     |
| Time Complexity (Worst-case) | O(n) due to collision chains                      |
| Load Factor                  | n / number of buckets → affects rehashing         |
| Rehashing                    | Automatic in STL when size grows beyond threshold |

---

##  **7. Real-Time Applications of Hash Functions**

| Application                      | Purpose                                   |
| -------------------------------- | ----------------------------------------- |
| **Compilers (Symbol Table)**     | Quickly look up variable names            |
| **Web Browsers**                 | Cache recently visited pages using hashes |
| **Blockchain**                   | Cryptographic hash for block integrity    |
| **Databases**                    | Hash indexes for fast record access       |
| **File Systems (Deduplication)** | Hash content to find duplicates           |

---

## 🧪 **8. Mini Projects / Exercises**

1. **Implement your own `unordered_map` using chaining**
2. **Build a symbol table using hashing**
3. **Design a login system where passwords are stored as hashes**
4. **Detect anagram groups using string hashing**
5. **Find first non-repeating character using hash map**

---

##  **9. Summary of Key Hash Functions**

| Function         | Type                   | Use                         |
| ---------------- | ---------------------- | --------------------------- |
| `std::hash<T>()` | Built-in               | Use with STL containers     |
| `djb2`           | Simple string hash     | Good for learning           |
| `FNV`            | Lightweight            | String-intensive scenarios  |
| `MurmurHash`     | High-speed, non-crypto | Real-time systems           |
| `SHA-256`        | Cryptographic          | Security-based applications |

---

##  Bonus: Hashing vs Cryptographic Hashing

| Feature    | General Hash              | Cryptographic Hash           |
| ---------- | ------------------------- | ---------------------------- |
| Focus      | Speed and lookup          | Security and integrity       |
| Collisions | Avoid but tolerable       | Must be impossible (one-way) |
| Examples   | `std::hash`, `MurmurHash` | `SHA-256`, `MD5`, `bcrypt`   |
| Usage      | Maps, sets, caches        | Passwords, blockchain, SSL   |

---

