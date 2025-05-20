## 🧑‍🏫 Day 2: Classes and Objects in Depth

### 🎯 Objective:

- Understand the structure of a class in C++
- Learn how to define and use objects
- Explore memory layout of class objects
- Use real-world analogies to reinforce understanding

### 🧩 What is a Class?

A **class** is a user-defined data type that serves as a blueprint for creating **objects**. It can contain **data members (variables)** and **member functions (methods)**.

```cpp
class Student {
public:
    string name;
    int rollNo;

    void display() {
        cout << "Name: " << name << ", Roll No: " << rollNo << endl;
    }
};
```

### 🧪 Creating and Using Objects

```cpp
int main() {
    Student s1;             // Object creation
    s1.name = "Alice";
    s1.rollNo = 101;
    s1.display();           // Calling member function
    return 0;
}
```

### 🧱 Real-World Analogy: Bank Account

Think of a class as a form you fill at a bank. That form doesn't store data; it's just a template. When you fill the form, you create an **object**.

```cpp
class BankAccount {
public:
    string accountHolder;
    double balance;

    void deposit(double amount) {
        balance += amount;
    }

    void showBalance() {
        cout << "Balance: Rs." << balance << endl;
    }
};
```

### 🔍 Memory Layout of Class Objects

Each object gets its own memory for:
- All non-static data members
- Shared access to member functions

**Diagram**:

📦 `Student s1`
```
| name: "Alice" |
| rollNo: 101   |
```

📦 `Student s2`
```
| name: "Bob"   |
| rollNo: 102   |
```

Both share the same `display()` function but have separate `name` and `rollNo`.

---

### ⚙️ Constructors (Introduction)

A **constructor** is a special function that gets automatically called when an object is created.

```cpp
class Animal {
public:
    string name;

    Animal() {
        name = "Unnamed";
    }

    void speak() {
        cout << name << " makes a sound." << endl;
    }
};
```

### 📌 Constructor with Parameters

```cpp
class Animal {
public:
    string name;

    Animal(string n) {
        name = n;
    }

    void speak() {
        cout << name << " makes a sound." << endl;
    }
};
```

---

### 🧠 Mini Quiz: Day 2

1. What is the purpose of a class in C++?
2. How is an object related to a class?
3. What happens if we do not define a constructor?
4. Can two objects of the same class have different data?
5. Write the syntax to call a member function using an object.

---

### 🔧 Daily Challenge / Mini Project

**Task:** Create a class `Employee` with the following:
- `id`, `name`, `salary`
- Constructor to initialize all data
- `display()` function to print data
- In `main()`, create 2 Employee objects and display their info

**Extra Challenge:**
Take input from the user using `cin` in the constructor!

---



