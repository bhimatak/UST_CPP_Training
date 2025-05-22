

---

## 🧠 **Day 22 – STL Part 3: Functors, Predicates & Custom Comparators**

---

### ⚙️ 1. What Is a Functor (Function Object)?

A **functor** is any object that can be **called like a function**.

> In C++, this means defining the `operator()` in a class/struct.

#### ✅ Example:

```cpp
struct Square {
    int operator()(int x) {
        return x * x;
    }
};

Square s;
cout << s(5);  // Output: 25
```

🧠 Think of functors as **objects with memory** that also behave like functions.

---

### 🧰 Why Use Functors?

- Can **store state** (e.g., counters, thresholds)
- **Reusable**, **testable**, and often **more performant** than lambdas (esp. in older compilers)
- Essential for **custom sorting/comparisons**

---

### 🧪 Real-World Functor: Discount Calculator

```cpp
struct Discount {
    float rate;  // in percentage

    float operator()(float price) const {
        return price * (1 - rate / 100.0f);
    }
};

Discount summerSale{15};
cout << summerSale(1000);  // 850
```

---

### ✅ 2. Predicate Functions

A **predicate** is a function (or lambda/functor) that returns a **boolean**.

Used in:

- `find_if`, `count_if`, `remove_if`, etc.

#### Example: Check if number is even

```cpp
bool isEven(int x) {
    return x % 2 == 0;
}

count_if(v.begin(), v.end(), isEven);
```

#### Lambda version:

```cpp
count_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
```

---

### 🔀 3. Custom Comparators with `sort()`

You can define your own **sort order** using lambdas or functors.

#### ✨ Sort by absolute value:

```cpp
vector<int> v = {-5, 2, -3, 1};

sort(v.begin(), v.end(), [](int a, int b){
    return abs(a) < abs(b);
});
```

#### Sort a `vector<pair<string, int>>` by second element:

```cpp
vector<pair<string, int>> data = {
    {"A", 3}, {"B", 1}, {"C", 2}
};

sort(data.begin(), data.end(), [](auto &a, auto &b){
    return a.second < b.second;
});
```

---

### 🔁 4. Custom Comparators in `set` or `map`

To store **complex types** in a `set/map`, we define a **custom comparator**.

#### Example: Sort `set` of students by marks descending

```cpp
struct Student {
    string name;
    int marks;
};

struct Compare {
    bool operator()(const Student &a, const Student &b) const {
        return a.marks > b.marks;
    }
};

set<Student, Compare> toppers;
```

---

### 🧪 Real-World Case – Task Prioritizer

```cpp
struct Task {
    string name;
    int priority;
};

struct PrioritySort {
    bool operator()(const Task &a, const Task &b) const {
        return a.priority > b.priority;  // Higher priority first
    }
};

set<Task, PrioritySort> taskQueue;
```

---

### 🔍 5. Functor vs Lambda vs Function Pointer

| Feature            | Functor          | Lambda               | Function Pointer     |
|--------------------|------------------|-----------------------|----------------------|
| Can hold state     | ✅ Yes            | ✅ (if captured)       | ❌                  |
| Inline syntax      | ❌ Verbose        | ✅ Very concise        | ✅ Simple            |
| Template friendly  | ✅ Yes            | ✅ Yes                 | ⚠️ Less flexible     |
| Performance        | ✅ Excellent      | ✅ Excellent           | ⚠️ Depends           |

---

### 🎓 Mini Project: Student Grading & Ranking

- Structure: `Student{name, grade, total}`
- Store in `set<Student, CustomComparator>`
- Custom comparator: higher grade, then name alphabetically

```cpp
struct Student {
    string name;
    int grade;
    int total;
};

struct Compare {
    bool operator()(const Student &a, const Student &b) const {
        if (a.grade == b.grade)
            return a.name < b.name;
        return a.grade > b.grade;
    }
};
```

🧩 Add functions to:
- Insert students
- Print top N
- Filter by grade threshold using `find_if`

---

### 💪 Exercises

1. Create a functor that returns `true` if a number is prime.
2. Sort a vector of strings by length (lambda).
3. Create a `map<string, int>` and sort entries by value using a vector of pairs + custom comparator.
4. Implement a functor to count vowels in a string.
5. Store custom structs in `set` with descending sort order.

---

### 📌 Summary

| Concept         | Use Case                           |
|------------------|------------------------------------|
| Functor          | Object that acts like function     |
| Predicate        | Any function returning bool        |
| Lambda           | Inline, anonymous function         |
| Custom Comparator| For `sort`, `set`, `map` sorting   |

---


