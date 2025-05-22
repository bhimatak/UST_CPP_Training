
---

## 🛠️ **Day 21: STL Deep Dive Part 2 – Iterators, Algorithms & Lambda Functions**

---

### 🧭 1. Iterators – The STL Navigators

Iterators are like **pointers** that traverse containers. STL algorithms rely on them.

| Iterator Type      | Example Containers      |
|--------------------|-------------------------|
| Input              | `istream_iterator`      |
| Output             | `ostream_iterator`      |
| Forward            | `forward_list`          |
| Bidirectional      | `list`, `set`, `map`    |
| Random Access      | `vector`, `deque`       |

#### Example:

```cpp
vector<int> v = {10, 20, 30};
vector<int>::iterator it = v.begin();
cout << *it; // 10
```

#### C++11 Style (Clean!):

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";
```

---

### 🧪 Real-World: Searching for a User in a List

```cpp
list<string> users = {"alice", "bob", "carol"};
auto it = find(users.begin(), users.end(), "bob");
if (it != users.end()) cout << "Found Bob!";
```

---

### 🔍 2. STL Algorithms – Your Toolkit

> `<algorithm>` contains over **60+ functions**: sort, search, transform, count, etc.

#### 💡 Common Ones

| Function            | Purpose                                  |
|---------------------|------------------------------------------|
| `sort()`            | Sort elements                            |
| `reverse()`         | Reverse container                        |
| `count()`           | Count occurrences                        |
| `find()`            | Find a value                             |
| `accumulate()`      | Sum elements (needs `<numeric>`)         |
| `for_each()`        | Apply a function to each element         |
| `transform()`       | Modify values in-place or to new dest    |

#### ✅ Example: Sorting

```cpp
vector<int> nums = {5, 3, 8, 1};
sort(nums.begin(), nums.end());  // Ascending
sort(nums.rbegin(), nums.rend()); // Descending
```

---

### 🔁 `for_each` and `transform`

```cpp
vector<int> nums = {1, 2, 3};

for_each(nums.begin(), nums.end(), [](int x){
    cout << x * x << " ";
});
```

---

### ⚡ `accumulate()`

```cpp
vector<int> nums = {1, 2, 3, 4};
int sum = accumulate(nums.begin(), nums.end(), 0);
```

---

### 🧠 3. Lambda Functions – Anonymous Power

Lambdas are **inline functions** without a name. Super useful with STL!

```cpp
auto square = [](int x) { return x * x; };
cout << square(5); // 25
```

#### Syntax:

```cpp
[capture_list](parameter_list) -> return_type { body }
```

---

### 💡 Lambda + Algorithm Combo

```cpp
vector<int> v = {1, 2, 3, 4, 5};

// Print even numbers
for_each(v.begin(), v.end(), [](int x){
    if (x % 2 == 0) cout << x << " ";
});
```

---

### 🎯 `find_if()` with Lambda

```cpp
vector<int> v = {5, 7, 8, 9, 10};
auto it = find_if(v.begin(), v.end(), [](int x){
    return x % 2 == 0;
});
if (it != v.end()) cout << "First even: " << *it;
```

---

### 🧪 Real-Time Use Case – Filter Students

```cpp
struct Student {
    string name;
    int marks;
};

vector<Student> students = {
    {"Alice", 85}, {"Bob", 60}, {"Carol", 92}
};

auto top = find_if(students.begin(), students.end(), [](Student s){
    return s.marks > 90;
});
if (top != students.end()) cout << top->name << " is a topper!";
```

---

### 🔐 Capture Mechanisms in Lambdas

```cpp
int threshold = 5;

// By value
auto f1 = [threshold](int x) { return x > threshold; };

// By reference
auto f2 = [&threshold](int x) { return x > threshold; };
```

---

### 🔁 Use `transform()` to Modify Values

```cpp
vector<int> v = {1, 2, 3};
transform(v.begin(), v.end(), v.begin(), [](int x){
    return x * 2;
});
```

---

### 🧪 Exercise Bank

1. Use `find_if()` to search names starting with 'A'.
2. Use `count_if()` to count even numbers in a list.
3. Use `transform()` to convert a `vector<string>` to uppercase.
4. Sort a list of pairs by second element using `sort()` + lambda.
5. Create a lambda that checks if a string is palindrome.

---

### 📊 Mini Project – Student Ranking System

```cpp
struct Student {
    string name;
    int marks;
};

vector<Student> students = {
    {"Zoe", 78}, {"Alice", 92}, {"Bob", 85}
};

sort(students.begin(), students.end(), [](Student a, Student b){
    return a.marks > b.marks; // Descending
});
```

✅ Then print the rankings. Add a lambda to highlight top 3.

---

### 🎯 Summary Table

| Concept        | Key Use                          |
|----------------|----------------------------------|
| Iterators      | Traverse any STL container       |
| `sort()`       | Sort containers                  |
| `find()`       | Locate values                    |
| `transform()`  | Apply function to all elements   |
| Lambdas        | One-liners for inline behavior   |

---

### 💼 Real-World Benefits

- Replace verbose loops with `for_each()`
- Write data filters using `find_if()`, `count_if()`
- Custom sort logic via lambdas
- Build reusable algorithms cleanly

---

### ⏭️ Coming Up Next: **Day 22 – STL Part 3: Function Objects (Functors), Predicate Functions, and Custom Comparators**

This is where we explore **custom behavior** for sorting, filtering, and functional programming patterns — all using C++’s *function objects and predicates* 🧠⚙️

---
