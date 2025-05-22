
---

## 📦 **Day 20: STL Deep Dive – Part 1: Containers (Vector, List, Map, Set, Unordered Variants)**

---

### 🔷 1. Why Use STL Containers?

- ✅ Pre-built, efficient data structures
- ✅ Type-safe with templates
- ✅ Automatically manage memory
- ✅ Work seamlessly with algorithms

---

### 🧱 2. Categories of STL Containers

| Type         | Examples                 | Features                                      |
|--------------|--------------------------|-----------------------------------------------|
| Sequence     | `vector`, `deque`, `list`| Maintain insertion order                      |
| Associative  | `set`, `map`             | Auto-sorted based on keys                     |
| Unordered    | `unordered_map`, `unordered_set` | Fast lookup via hash tables             |
| Adapter      | `stack`, `queue`, `priority_queue` | Built on top of sequence containers   |

---

### 🎯 3. `vector<T>` – Dynamic Array

```cpp
vector<int> nums = {1, 2, 3};
nums.push_back(4);
nums[2] = 10;
```

✅ Random access (O(1))  
⚠️ Insertion/deletion in middle = O(n)

#### Real-world use:
- Store sensor readings
- Game coordinates
- Logs, history states

---

### 🧪 Useful `vector` Functions

```cpp
nums.size();       // Number of elements
nums.empty();      // Check if vector is empty
nums.front();      // First element
nums.back();       // Last element
nums.pop_back();   // Remove last element
```

#### 🔁 Loop with `auto`:

```cpp
for (auto x : nums)
    cout << x << " ";
```

---

### 🔄 4. `list<T>` – Doubly Linked List

```cpp
list<string> names = {"Alice", "Bob", "Carol"};
names.push_front("Zoe");
names.pop_back();
```

✅ Efficient insert/delete at any position  
⚠️ No random access

#### Real-world use:
- Undo-redo stacks
- Real-time event queues
- Music player playlist

---

### 💥 5. `deque<T>` – Double-Ended Queue

```cpp
deque<int> dq = {1, 2, 3};
dq.push_front(0);   // 0 1 2 3
dq.push_back(4);    // 0 1 2 3 4
```

✅ Fast push/pop at both ends  
✅ Random access like `vector`  
⚠️ Slightly slower than vector

---

### 🗂️ 6. `set<T>` – Unique, Ordered Collection

```cpp
set<int> s = {4, 2, 1, 3};
s.insert(5);   // {1, 2, 3, 4, 5}
```

✅ Auto-sorted  
✅ No duplicates  
⚠️ No random access

```cpp
s.find(3);     // Returns iterator if found
s.count(5);    // 0 or 1
```

---

### 📑 7. `map<Key, Value>` – Key-Value, Ordered

```cpp
map<string, int> ages;
ages["Alice"] = 25;
ages["Bob"] = 30;
```

✅ Keys auto-sorted  
✅ Lookup in O(log n)

```cpp
for (auto& [name, age] : ages)
    cout << name << " is " << age << " years old.\n";
```

#### Real-world use:
- Phonebook
- Caching systems
- Config storage

---

### ⚡ 8. Unordered Versions – `unordered_set`, `unordered_map`

```cpp
unordered_map<string, string> capitals = {
    {"India", "New Delhi"},
    {"France", "Paris"}
};
```

✅ Faster (avg O(1)) lookup using hash table  
⚠️ No ordering  
⚠️ Worst case O(n) if many hash collisions

---

### 🔍 9. Comparisons – When to Use What?

| Container        | Best For                              | Avoid When                      |
|------------------|----------------------------------------|----------------------------------|
| `vector`         | Index-based access                     | Frequent insertions in middle   |
| `list`           | Frequent insertions/removals           | Need for random access          |
| `deque`          | Push/pop from both ends                | N/A                             |
| `set`            | Unique sorted values                   | Need duplicates                 |
| `unordered_set`  | Fast checks (existence)                | Order matters                   |
| `map`            | Key-value sorted data                  | Speed-critical apps             |
| `unordered_map`  | Fast key-value lookup                  | Need sorted keys                |

---

### 🧠 Real-World Use Cases

| Scenario                        | Container               |
|---------------------------------|-------------------------|
| Leaderboard (sorted by score)   | `map<int, string>`      |
| Real-time chat messages         | `deque<string>`         |
| Word frequency counter          | `unordered_map<string, int>` |
| Playlist management             | `list<string>`          |
| Game entity coordinates         | `vector<Point>`         |

---

### 📘 Exercises

1. Implement a simple **command history** using `deque<string>`.
2. Build a **student database** using `map<roll_no, student_name>`.
3. Use `unordered_map` to count **character frequency** in a string.
4. Create a `set<int>` and demonstrate insertions and lookups.
5. Simulate a playlist using `list<string>` with `next()` and `previous()` operations.

---

### 🔨 Mini Project

📂 **Inventory System**

- Track item name → quantity
- Use `unordered_map<string, int>`
- Functions: `addItem()`, `removeItem()`, `printInventory()`

---

### 📌 Summary Table

| STL Component     | Description                    |
|-------------------|--------------------------------|
| `vector`          | Dynamic array                  |
| `deque`           | Double-ended queue             |
| `list`            | Doubly linked list             |
| `set`             | Unique sorted values           |
| `unordered_set`   | Unique, fast lookup            |
| `map`             | Sorted key-value store         |
| `unordered_map`   | Fast key-value store           |

---
