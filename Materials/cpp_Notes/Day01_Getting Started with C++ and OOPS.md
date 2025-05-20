## 🧑‍🏫 Day 1: Getting Started with C++ and OOPS

### 🎯 Objective:

- Understand what C++ is and why we use it
- Set up the development environment
- Learn how to compile and run a basic program
- Introduction to OOPS

---

### 🧠 What is C++?

C++ is a general-purpose programming language created by Bjarne Stroustrup in 1979 as an extension of the C language. It supports both **procedural** and **object-oriented** programming paradigms.

> Think of C++ as C with superpowers!

### ⚡ Why C++?

- High performance
- Low-level memory manipulation
- System programming (OS, drivers)
- Game engines (e.g., Unreal Engine)
- Competitive programming
- Foundation for learning other modern languages

---

### 🖥️ Setting Up C++ Development

#### 🪟 Windows:

- Install [Code::Blocks](http://www.codeblocks.org/)
- Or use [Visual Studio Community](https://visualstudio.microsoft.com/)

#### 🐧 Linux:

```bash
sudo apt update
sudo apt install g++
```

#### 🍎 macOS:

```bash
xcode-select --install
```

#### ✅ Online Compiler (No Installation):

- [https://www.onlinegdb.com/online_c++_compiler](https://www.onlinegdb.com/online_c++_compiler)
- [https://godbolt.org/](https://godbolt.org/) (Advanced)

---

### 🚀 Your First C++ Program

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```

#### 🔧 Compilation (Command Line)

```bash
g++ hello.cpp -o hello
./hello
```

#### 🧪 Output:

```
Hello, World!
```

---

### 🧰 Keywords You Used

| Keyword    | Meaning                       |
| ---------- | ----------------------------- |
| `#include` | Includes libraries            |
| `main()`   | Entry point of the program    |
| `cout`     | Standard output               |
| `<<`       | Output stream insertion       |
| `return`   | Ends the function and returns |

---

### 🧪 Activity: Modify & Try

1. Change the message to your name.
2. Print two lines using two `cout` statements.
3. Try printing a number: `cout << 5 << endl;`

---

### 🎓 Introduction to OOPS (Object-Oriented Programming)

**OOPS = Modeling real-world objects in code**

Real-life Example:

- **Object**: Car
- **Attributes**: brand, color, speed
- **Behavior**: start(), accelerate(), brake()

In C++, we represent this as:

```cpp
class Car {
public:
    string brand;
    int speed;

    void start() {
        cout << "Car started!" << endl;
    }
};
```

---

### 📦 Summary

- C++ is a powerful and versatile language
- Your first program runs with just 5 lines of code
- OOPS helps us model the real world

---

### 📚 Homework

✅ Install a compiler or use an online IDE\
✅ Run the "Hello, World!" program\
✅ Write your own class for `MobilePhone` with brand and price as attributes

---

### 🧠 Mini Quiz: Day 1

1. What does `#include <iostream>` do in C++?
2. Which function is mandatory in every C++ program?
3. What is the output of `cout << "Sum: " << 3 + 4;`?
4. What keyword is used to define a class in C++?
5. Name two features of C++ that make it suitable for system programming.

📝 Try answering them before peeking into the next session!

---

### 🔧 Daily Challenge / Mini Project

**Task:** Create a class called `Book` with the following:

- Attributes: `title`, `author`, `price`
- Method: `displayInfo()` that prints book details
- In `main()`, create two book objects and call their methods

```cpp
class Book {
public:
    string title;
    string author;
    float price;

    void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
    }
};
```

🚀 Tip: Practice input/output by reading values from the user using `cin`.

---


