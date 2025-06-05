
## 🔁 Iterator Tutorial Series – Table of Contents

### Part 1: \[✓] Basics (Completed)

* Types: `iterator`, `const_iterator`, `reverse_iterator`
* Syntax, use-cases, and container-specific behavior

---

### 🔸 Part 2: Iterators with STL Containers

We will now explore iterators in each major container:

---

### 📌 `vector` Iterators – Modifiable Sequential Data

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> scores = {10, 20, 30};

    // iterator
    for (auto it = scores.begin(); it != scores.end(); ++it)
        *it += 10;

    // const_iterator
    for (vector<int>::const_iterator it = scores.cbegin(); it != scores.cend(); ++it)
        cout << *it << " ";  // Output: 20 30 40
}
```

🧠 Use `vector` iterators for:

* Sequential modifications
* Dynamic arrays
* Sorting, traversal

---

### 📌 `list` Iterators – Bidirectional Traversal

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<string> tasks = {"Eat", "Code", "Sleep"};

    // Reverse iterator
    for (auto rit = tasks.rbegin(); rit != tasks.rend(); ++rit)
        cout << *rit << " -> ";  // Output: Sleep -> Code -> Eat ->
}
```

🧠 `list` supports:

* `iterator`, `const_iterator`, `reverse_iterator`
* Efficient insert/delete at both ends and middle

---

### 📌 `map` Iterators – Key-Value Access

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> age = {{"Alice", 30}, {"Bob", 25}};

    for (auto it = age.begin(); it != age.end(); ++it)
        cout << it->first << ": " << it->second << endl;
}
```

🧠 Use map iterators to:

* Iterate over sorted keys
* Access key-value pairs
* Do not modify key (modifying value is okay)

---

### 📌 `set` Iterators – Sorted Unique Elements

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> numbers = {10, 20, 30};

    for (auto it = numbers.begin(); it != numbers.end(); ++it)
        cout << *it << " ";
}
```

🧠 No direct modification to elements — they are const.

---

### 🔁 Visual Flow (For All)

```text
          +--------------------------+
iterator: | -> -> -> ->             |
          +--------------------------+

const_iterator: (same direction, but read-only)
reverse_iterator: <- <- <- <-
```

---

## ✍️ Assignments: Hands-On Practice

### 🧪 Problem 1: Reverse Lookup

> Given a `list<string>` of customer names in the order of registration, print them in reverse order using reverse iterators.

**Sample Input**:
`"Ravi", "Nina", "Amit"`

**Expected Output**:
`Amit Nina Ravi`

---

### 🧪 Problem 2: Map Rank Adjuster

> Given a `map<string, int>` with student names and marks, increase marks by 5 if current mark is below 50.

---

### 🧪 Problem 3: Track Recent Items

> Use a `deque<string>` to simulate recent items used in a program (most recent at the front). Use `reverse_iterator` to print history.

---

### 🧪 Problem 4: Set Filter

> Use a `set<int>` to store even numbers from a list and print using `const_iterator`.

---

### 🧪 Problem 5: Count Unique Words

> Read `vector<string>` of words. Use `set<string>::iterator` to find and display unique ones.

---

## 📦 Assignment Packaging & Rubric

| Criteria                                        | Points |
| ----------------------------------------------- | ------ |
| Correct usage of iterator types                 | 10     |
| Container appropriate to the use-case           | 5      |
| Logical correctness (input/output)              | 10     |
| Use of const/reverse iterators where applicable | 5      |
| Code structure & readability                    | 5      |
| **Total**                                       | **35** |

---

