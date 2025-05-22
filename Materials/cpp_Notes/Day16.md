

---

## 🚀 **Day 16: STL Algorithms Deep Dive & Lambdas (C++14/17)**

---

### 🔷 1. STL Algorithms – Overview

STL provides a rich set of **generic algorithms** that work on iterators. They're found in the `<algorithm>` header and categorized into:

| Category              | Examples                                      |
|-----------------------|-----------------------------------------------|
| **Non-modifying**     | `find`, `count`, `all_of`, `any_of`, `none_of` |
| **Modifying**         | `copy`, `replace`, `remove`, `transform`      |
| **Sorting**           | `sort`, `stable_sort`, `partial_sort`         |
| **Partitioning**      | `partition`, `stable_partition`               |
| **Set operations**    | `set_union`, `set_intersection`, etc.         |
| **Heap operations**   | `make_heap`, `push_heap`, `pop_heap`          |

---

### ⚙️ 2. Commonly Used Algorithms with Examples

#### ✅ `std::find`

```cpp
vector<int> v = {10, 20, 30};
auto it = find(v.begin(), v.end(), 20);
if (it != v.end()) cout << "Found at index: " << it - v.begin();
```

#### ✅ `std::count`

```cpp
int c = count(v.begin(), v.end(), 20);  // Counts occurrences
```

#### ✅ `std::sort`

```cpp
sort(v.begin(), v.end());  // Ascending sort
```

#### ✅ `std::reverse`

```cpp
reverse(v.begin(), v.end());
```

#### ✅ `std::transform`

```cpp
vector<int> v = {1, 2, 3};
vector<int> out(3);

transform(v.begin(), v.end(), out.begin(), [](int x) { return x * x; });
// out = {1, 4, 9}
```

---

### 🧠 3. Lambdas – Inline Anonymous Functions

Lambdas are short, powerful, and inline functions used mostly with STL. C++14 & C++17 make them even better with features like **auto parameters** and **generalized capture**.

#### 🧪 Syntax:

```cpp
[capture](parameters) -> return_type {
    // function body
};
```

#### 🔥 Example:

```cpp
auto sum = [](int a, int b) -> int { return a + b; };
cout << sum(5, 3); // 8
```

#### With STL:

```cpp
vector<int> v = {1, 2, 3, 4, 5};

for_each(v.begin(), v.end(), [](int x) {
    cout << x << " ";
});
```

---

### 🎯 4. Capturing Variables in Lambdas

```cpp
int a = 10, b = 5;

auto f = [a, &b]() {
    cout << "a: " << a << ", b: " << b << endl;
    b++;
};

f();  // a captured by value, b by reference
```

---

### ⚡ 5. Advanced STL with Lambdas

#### 🧩 Filtering with `remove_if`

```cpp
vector<int> v = {1, 2, 3, 4, 5};

v.erase(remove_if(v.begin(), v.end(),
                  [](int x) { return x % 2 == 0; }),
        v.end());

// Removes even numbers → v = {1, 3, 5}
```

#### 🎯 Counting with a Condition: `count_if`

```cpp
int countOdd = count_if(v.begin(), v.end(),
                        [](int x) { return x % 2 != 0; });
```

#### 🧪 All, Any, None Checks

```cpp
all_of(v.begin(), v.end(), [](int x){ return x > 0; });   // true
any_of(v.begin(), v.end(), [](int x){ return x > 3; });   // true
none_of(v.begin(), v.end(), [](int x){ return x < 0; });  // true
```

---

### 🔁 6. `for_each` with Side Effects

```cpp
vector<string> names = {"John", "Alice", "Bob"};
for_each(names.begin(), names.end(),
         [](const string& name) {
             cout << "Name: " << name << endl;
         });
```

---

### 🔍 7. Sorting Custom Structures

```cpp
struct Product {
    string name;
    double price;
};

vector<Product> items = {
    {"Pen", 1.5},
    {"Notebook", 3.0},
    {"Pencil", 0.5}
};

sort(items.begin(), items.end(), [](const Product& a, const Product& b) {
    return a.price < b.price;
});
```

---

### 🧱 Diagram: Lambda in STL Workflow

```
Container → Algorithm → Lambda → Result
  [1, 2, 3] → transform → [](x){ return x*x; } → [1, 4, 9]
```

---

### 🔧 8. Practical Use Case: Filtering and Transforming

**Problem**: Square only the even numbers from a list

```cpp
vector<int> v = {1, 2, 3, 4, 5, 6};

vector<int> evenSquares;
for_each(v.begin(), v.end(), [&](int x) {
    if (x % 2 == 0)
        evenSquares.push_back(x * x);
});
```

---

### 💥 C++14/17 Features in Lambdas

#### C++14: Auto in Parameters

```cpp
auto multiply = [](auto a, auto b) {
    return a * b;
};
cout << multiply(3, 4.5);  // 13.5
```

#### C++17: Init capture (move semantics)

```cpp
auto p = make_unique<int>(10);

auto f = [ptr = move(p)]() {
    cout << *ptr << endl;
};
```

---

### 🧠 Exercises

1. Use `transform` with a lambda to convert strings to uppercase
2. Write a function that removes all strings less than 3 characters
3. Create a vector of students with marks and sort them using lambdas

---

### 📚 Homework

- Implement a generic `filter` function that accepts:
  - A container
  - A predicate lambda
  - Returns a new container with only matching elements

- Build a small contact list app:
  - Stores contacts in `map<string, string>`
  - Allows search using lambdas

---

### ✅ Summary Table

| Feature            | Purpose                        |
|--------------------|--------------------------------|
| `find`, `count`    | Search or count elements       |
| `sort`, `reverse`  | Order manipulation             |
| `transform`        | Element-wise modification      |
| `remove_if`        | Conditional erase              |
| Lambdas            | In-place function objects      |
| Capture `[=]`, `[&]` | Value or reference capture   |

---

