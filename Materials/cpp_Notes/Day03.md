

---

## 🚀 **Day 3: Control Structures in C++14/17 – Decision Making and Loops**

---

### 1. Introduction to Control Structures

Control structures help manage the **flow of execution** in a program. They enable decision-making, repetition, and branching, allowing us to build dynamic and interactive logic.

> **Real-World Analogy:** Imagine traffic signals (if-else), roundabouts (loops), and toll exits (switch). Control structures decide how and where the "traffic" of execution flows.

---

### 2. Conditional Statements

#### **if, if-else, else-if**

```cpp
int age = 20;
if (age >= 18)
    cout << "Eligible to vote";
else
    cout << "Not eligible";
```

#### **Modern `if` with `constexpr` (C++17)**
```cpp
constexpr int limit = 100;
if constexpr (limit > 50) {
    cout << "Limit is above threshold\n";
}
```
> `if constexpr` allows **compile-time** decision making.

---

### 3. Looping Constructs

| Loop Type | Use Case                        | Syntax Example |
|-----------|----------------------------------|----------------|
| `for`     | Known iterations                | `for (int i = 0; i < 5; ++i)` |
| `while`   | Unknown iterations              | `while (x > 0)` |
| `do-while`| At least one execution          | `do { ... } while (cond)` |

#### C++17: Range-based for with `auto`
```cpp
vector<int> nums = {1, 2, 3};
for (auto val : nums) {
    cout << val << " ";
}
```

---

### 4. `switch` Statement

Efficient multi-branch selection based on integral or enum values.

```cpp
int choice = 2;
switch (choice) {
    case 1: cout << "Option 1"; break;
    case 2: cout << "Option 2"; break;
    default: cout << "Invalid choice";
}
```

> `switch` does **not** support `string` (use `if-else` or `unordered_map` instead)

---

### 5. Real-World Use Case: Parking Fee System

| Feature               | Control Used    | Logic                                  |
|----------------------|-----------------|----------------------------------------|
| Vehicle Type         | `switch`        | Different fees for cars, bikes, buses  |
| Time Validation      | `if`            | Check if parking time is within limits |
| Daily Summary Report | `for` loop      | Iterate over all entries               |

---

### 6. Best Practices

✅ Prefer `for-each` (`auto`) loops when index isn’t needed  
✅ Use `if constexpr` when compile-time branching is possible  
✅ Avoid deeply nested ifs — consider early returns  
✅ Always include a `default` in switch statements  
✅ Choose loop type based on need: `for` for known, `while` for unknown iterations

---

### 7. Hands-On Lab

**Task:**  
Write a menu-driven program that:
- Displays 3 options: Add, Subtract, Exit
- Uses `switch` to handle user selection
- Loops until the user exits

---

### 8. Quiz

**Q1:** What loop guarantees execution at least once?  
> **A:** `do-while`

**Q2:** Which C++17 feature allows compile-time if conditions?  
> **A:** `if constexpr`

**Q3:** True or False: A `switch` can be used with `std::string`  
> **A:** False

**Q4:** What loop type is ideal for iterating through a `vector`?  
> **A:** `range-based for`

---

### 9. Daily Challenge / Mini Project

**Project:**  
Create a **"Banking Menu System"** that allows the user to:
- Check balance
- Deposit amount
- Withdraw amount
- Exit

Use:
- `while` for main loop
- `switch` for option selection
- `if` for validations (e.g., insufficient balance)

**Bonus:** Use `auto` and `vector` to store transaction history

---

### 10. Summary

- Control structures guide program logic  
- Use `if`, `else`, `switch` for decision-making  
- Use `for`, `while`, `do-while` for looping  
- C++14/17 offers cleaner syntax like `auto`, `if constexpr`, and range-based loops

---

### 11. Homework

- Modify the banking system to support multiple accounts using a `vector` of balances  
- Add a transaction summary using `for` loop

---

### 12. Resources

- [Control Structures in C++](https://www.geeksforgeeks.org/decision-making-cpp/)
- [Range-based Loops – C++17](https://en.cppreference.com/w/cpp/language/range-for)
- [C++ switch-case Guide](https://cplusplus.com/doc/tutorial/control/)

---

