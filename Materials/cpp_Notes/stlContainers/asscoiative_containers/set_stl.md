---  
### C++ STL `set` Container   
---

## ✅ 1. What is `std::set` in C++?

The `std::set` is an **ordered associative container** that stores **unique elements** following a **specific sorting criterion** (by default, ascending using `<` operator).

### 🔍 Key Properties:

* **No duplicate elements**
* **Sorted automatically**
* Internally implemented as a **self-balancing binary search tree** (typically Red-Black Tree)
* Efficient operations:

  * Insertion: `O(log n)`
  * Deletion: `O(log n)`
  * Search: `O(log n)`

---

## ✅ 2. Why Use `set`?

* When you need to **store unique values** only.
* When you need the elements to be **automatically sorted**.
* Ideal for **removing duplicates**, fast **lookup**, and maintaining **sorted order**.

---

## ✅ 3. Real-world Use Case

> 🔧 **Use Case**: Unique Usernames in a System
> You are designing a system that stores all registered usernames. You want to:

* Prevent duplicate usernames.
* Keep them sorted for easy management.

`std::set<std::string>` is a great fit.

---

## ✅ 4. Syntax

```cpp
#include <set>

std::set<int> s;                         // empty set of integers
std::set<std::string> names = {"Bob", "Alice", "Charlie"}; // set with initial values
```

---

## ✅ 5. Common Methods and Operations

| Operation         | Syntax               | Description                               |
| ----------------- | -------------------- | ----------------------------------------- |
| Insert            | `s.insert(value)`    | Insert a new element                      |
| Erase by value    | `s.erase(value)`     | Remove an element                         |
| Erase by iterator | `s.erase(it)`        | Remove using iterator                     |
| Find              | `s.find(value)`      | Returns iterator to value, or `end()`     |
| Size              | `s.size()`           | Returns number of elements                |
| Empty check       | `s.empty()`          | Returns `true` if set is empty            |
| Clear all         | `s.clear()`          | Erases all elements                       |
| Lower bound       | `s.lower_bound(val)` | Iterator to **first** not less than `val` |
| Upper bound       | `s.upper_bound(val)` | Iterator to **first** greater than `val`  |
| Begin / End       | `s.begin(), s.end()` | Iterators to traverse the set             |
| Count (0 or 1)    | `s.count(val)`       | Returns 1 if present, else 0              |
| Swap              | `s1.swap(s2)`        | Swap contents of two sets                 |

---

## ✅ 6. Complete Example

```cpp
#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> usernames;

    // Insert elements
    usernames.insert("alice");
    usernames.insert("bob");
    usernames.insert("charlie");
    usernames.insert("alice"); // duplicate, will be ignored

    std::cout << "Registered usernames:\n";
    for (const auto& name : usernames) {
        std::cout << name << "\n";
    }

    // Find a username
    std::string search_name = "bob";
    if (usernames.find(search_name) != usernames.end()) {
        std::cout << search_name << " is already registered.\n";
    }

    // Erase a username
    usernames.erase("charlie");

    std::cout << "Usernames after deletion:\n";
    for (const auto& name : usernames) {
        std::cout << name << "\n";
    }

    // Show size
    std::cout << "Total users: " << usernames.size() << "\n";

    return 0;
}
```

### 🧾 Output:

```
Registered usernames:
alice
bob
charlie
bob is already registered.
Usernames after deletion:
alice
bob
Total users: 2
```

---

## ✅ 7. Variants of `set` in C++

| Variant              | Description                                |
| -------------------- | ------------------------------------------ |
| `std::set`           | Stores unique elements in sorted order     |
| `std::multiset`      | Allows **duplicate** elements              |
| `std::unordered_set` | Faster average access, no guaranteed order |

---

## ✅ 8. Interview Tip

* If you want uniqueness and **ordered data**, use `std::set`.
* If you don’t care about order but want **faster performance**, use `unordered_set`.

---

## ✅ 9. Summary

| Feature            | `std::set`                   |
| ------------------ | ---------------------------- |
| Duplicates allowed | ❌ No                         |
| Sorted             | ✅ Yes (ascending by default) |
| Search time        | `O(log n)`                   |
| Underlying         | Red-Black Tree               |

---

---

## ✅ 1. What is `std::set`?

* `std::set` is an **ordered associative container** in C++ that stores **unique elements**.
* Elements are automatically arranged in **ascending order** (by default, using `<`).
* Implemented as a **Red-Black Tree** (self-balancing BST).

### 🧠 Key Properties:

* No duplicate values allowed.
* All operations like `insert`, `erase`, `find` are `O(log n)`.

---

## ✅ 2. Why Use `std::set`?

* You need **uniqueness** of elements.
* You want elements **sorted automatically**.
* You want **efficient searching**.

---

## ✅ 3. Real-world Use Case

> 🚀 **Example**: In a web application, you want to maintain a list of unique logged-in users, sorted alphabetically.

---

## ✅ 4. Syntax

```cpp
#include <set>

std::set<int> s; // Declare a set of integers
s.insert(10);    // Add value
```

---

## ✅ 5. All Major Methods – Demonstrated

```cpp
#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> users;

    // insert()
    users.insert("alice");
    users.insert("bob");
    users.insert("charlie");
    users.insert("alice"); // ignored, already exists

    std::cout << "\nInitial set:\n";
    for (const auto& u : users)
        std::cout << u << "\n"; // sorted and unique

    // find()
    std::cout << "\nSearching for 'bob': ";
    auto it = users.find("bob");
    if (it != users.end())
        std::cout << "Found\n";
    else
        std::cout << "Not Found\n";

    // count()
    std::cout << "'charlie' exists? " << users.count("charlie") << "\n";
    std::cout << "'david' exists? " << users.count("david") << "\n";

    // erase() by value
    users.erase("charlie");
    std::cout << "\nAfter erasing 'charlie':\n";
    for (const auto& u : users)
        std::cout << u << "\n";

    // size()
    std::cout << "\nCurrent size: " << users.size() << "\n";

    // empty()
    std::cout << "Is set empty? " << (users.empty() ? "Yes" : "No") << "\n";

    // insert more for bounds
    users.insert("david");
    users.insert("eve");

    // lower_bound()
    auto lb = users.lower_bound("bob"); // >= "bob"
    std::cout << "\nLower bound of 'bob': " << (lb != users.end() ? *lb : "None") << "\n";

    // upper_bound()
    auto ub = users.upper_bound("bob"); // > "bob"
    std::cout << "Upper bound of 'bob': " << (ub != users.end() ? *ub : "None") << "\n";

    // erase() by iterator
    if (!users.empty()) {
        users.erase(users.begin()); // Erase first element
        std::cout << "\nAfter erasing first element:\n";
        for (const auto& u : users)
            std::cout << u << "\n";
    }

    // clear()
    users.clear();
    std::cout << "\nAfter clear(), size = " << users.size() << "\n";

    // swap()
    std::set<int> a = {1, 2, 3};
    std::set<int> b = {10, 20};

    std::cout << "\nBefore swap:\nSet A: ";
    for (int x : a) std::cout << x << " ";
    std::cout << "\nSet B: ";
    for (int x : b) std::cout << x << " ";

    a.swap(b);

    std::cout << "\n\nAfter swap:\nSet A: ";
    for (int x : a) std::cout << x << " ";
    std::cout << "\nSet B: ";
    for (int x : b) std::cout << x << " ";

    return 0;
}
```

---

## ✅ 6. Output

```
Initial set:
alice
bob
charlie

Searching for 'bob': Found
'charlie' exists? 1
'david' exists? 0

After erasing 'charlie':
alice
bob

Current size: 2
Is set empty? No

Lower bound of 'bob': bob
Upper bound of 'bob': david

After erasing first element:
bob
david
eve

After clear(), size = 0

Before swap:
Set A: 1 2 3 
Set B: 10 20 

After swap:
Set A: 10 20 
Set B: 1 2 3 
```

---

## ✅ 7. Summary of Methods Used

| Method             | Purpose                            |
| ------------------ | ---------------------------------- |
| `insert()`         | Insert a unique value              |
| `erase(val)`       | Remove a value                     |
| `erase(it)`        | Remove by iterator                 |
| `find(val)`        | Returns iterator to val or `end()` |
| `count(val)`       | Returns 1 if present, 0 otherwise  |
| `size()`           | Number of elements                 |
| `empty()`          | Checks if set is empty             |
| `clear()`          | Removes all elements               |
| `lower_bound(val)` | First element ≥ val                |
| `upper_bound(val)` | First element > val                |
| `swap(other)`      | Swaps with another set             |
| `begin()/end()`    | Iterators to start and end of set  |

---

## ✅ 8. Comparison: `set` vs `unordered_set` vs `multiset`

| Feature         | `set`          | `unordered_set` | `multiset`          |
| --------------- | -------------- | --------------- | ------------------- |
| Uniqueness      | ✅ Yes          | ✅ Yes           | ❌ No (allows dupes) |
| Sorted          | ✅ Yes          | ❌ No            | ✅ Yes               |
| Time Complexity | `O(log n)`     | `O(1)` (avg)    | `O(log n)`          |
| Underlying DS   | Red-Black Tree | Hash Table      | Red-Black Tree      |

---

## ✅ 9. Real-World Applications

* Maintaining sorted and unique user IDs
* Leaderboards with unique scores
* Maintaining an alphabetically sorted contact list

---
