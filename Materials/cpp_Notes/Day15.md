

---

## 🚀 **Day 15: STL – Containers, Iterators, and Algorithms (C++14/17 Deep Dive)**

---

### 🔷 1. What Is STL?

The **Standard Template Library (STL)** is a collection of:

- 📦 **Containers** (store data)
- 🚶 **Iterators** (access data)
- ⚙️ **Algorithms** (process data)

It’s like having your own **toolbox** for every data-handling job.

---

### 🧱 2. STL Containers

These are **generic data structures** that work with any type:

| Category      | Containers                              |
|---------------|------------------------------------------|
| Sequence      | `vector`, `deque`, `list`, `array`       |
| Associative   | `set`, `map`, `multiset`, `multimap`     |
| Unordered     | `unordered_set`, `unordered_map`         |
| Adapters      | `stack`, `queue`, `priority_queue`       |

---

### 🧰 Example: Vector (Dynamic Array)

```cpp
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3};

    nums.push_back(4);  // add at end
    nums.pop_back();    // remove from end

    for (int x : nums)
        cout << x << " ";
}
```

🧠 STL containers manage memory, resizing, and safety internally.

---

### 📊 STL Containers Visualization

```
std::vector<int> v = {1, 2, 3};
    ┌───┬───┬───┐
v:  │ 1 │ 2 │ 3 │
    └───┴───┴───┘
Add: push_back(4)
Remove: pop_back()
```

---

### 🔍 3. Iterators: The STL Navigators

**Iterators** are like pointers that move through containers.

```cpp
vector<int> v = {1, 2, 3, 4};
vector<int>::iterator it;

for (it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}
```

Or more modern:

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";
```

---

### 🔄 4. Algorithms: STL’s Built-in Tools

```cpp
#include <algorithm>

vector<int> v = {3, 1, 4, 2};

sort(v.begin(), v.end());           // 1 2 3 4
reverse(v.begin(), v.end());        // 4 3 2 1
int idx = find(v.begin(), v.end(), 3) - v.begin();
```

C++ STL has over **60+ algorithms**, all optimized for performance.

---

### 🧠 Real World: Sorting Custom Structs

```cpp
struct Student {
    string name;
    int marks;
};

bool compareByMarks(const Student& a, const Student& b) {
    return a.marks > b.marks;
}

vector<Student> students = {{"Alice", 90}, {"Bob", 85}};
sort(students.begin(), students.end(), compareByMarks);
```

---

### 🔥 C++17 Enhancements

#### `std::size()` & `std::data()`

```cpp
array<int, 3> arr = {1, 2, 3};
cout << std::size(arr); // safer than arr.size()
```

#### Structured Bindings

```cpp
map<string, int> mp = {{"apple", 2}, {"banana", 3}};
for (auto& [fruit, count] : mp) {
    cout << fruit << ": " << count << endl;
}
```

---

### 🔐 5. Associative Containers – `map`, `set`

```cpp
map<string, int> age;
age["John"] = 25;
age["Alice"] = 30;

cout << age["John"]; // 25

set<int> s = {4, 2, 7, 2};
for (int x : s) cout << x << " ";  // Output: 2 4 7
```

Maps store **key-value pairs**, sets store **unique values**.

---

### 🧠 Diagram: STL Ecosystem

```
[ Container ] <--> [ Iterator ] <--> [ Algorithm ]
     vector             ↑                  sort
     map                ↑                  find
     set                ↑                 count
```

---

### ✨ 6. Container Adapters

| Adapter         | Underlying Container | Usage                     |
|-----------------|----------------------|----------------------------|
| `stack<T>`      | `deque`              | LIFO (Last-In, First-Out) |
| `queue<T>`      | `deque`              | FIFO                      |
| `priority_queue`| `vector` (by default)| Max-heap by default       |

Example:

```cpp
stack<int> s;
s.push(10); s.push(20);
s.pop();    // removes 20
```

---

### 🛠️ Hands-On Challenges

1. Implement a frequency counter using `unordered_map<string, int>`
2. Write a custom comparator for sorting integers by **absolute value**
3. Create a program that:
   - Stores student scores in a map
   - Sorts them by score using a `vector<pair<string, int>>`

---

### 📚 Homework

- Create a template function `printAll` that prints **any container**
- Compare `vector`, `deque`, `list` for insertion and access performance

---

### 🧩 STL Cheat Sheet

| Component      | Use For                          |
|----------------|----------------------------------|
| `vector`       | Fast random access               |
| `list`         | Fast insert/delete anywhere      |
| `map`          | Key-value with ordered keys      |
| `unordered_map`| Hash-based fast key lookup       |
| `set`          | Unique sorted values             |
| `sort`         | Arrange items                    |
| `find`         | Search                          |

---

