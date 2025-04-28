#  **Part 2**  

---

# 4. Implement Assignment, Increment, and Decrement Operators

---

## Theory/Concept:
**Assignment operators** are used to assign values to variables.  
**Increment/Decrement operators** are shorthand to **add or subtract 1**.

---
## Syntax:
```cpp
// Assignment
variable = value;

// Increment/Decrement
variable++;
++variable;
variable--;
--variable;
```

---
## Example Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    x += 3; // x = x + 3
    cout << x << endl;

    int y = 10;
    cout << y++ << endl; // Post-increment
    cout << ++y << endl; // Pre-increment
    return 0;
}
```

---
## Explanation:
- `x += 3` adds 3 to `x`.
- `y++` returns current `y`, then increments it.
- `++y` increments `y`, then returns it.

---
## Useful Notes:
- **Pre-increment** (`++x`) is usually faster than **post-increment** (`x++`) for **non-primitive types** (like objects).

---
## Common Pitfalls:
- Misunderstanding **post vs pre increment**.

---
## Real-world Use Case:
- **Loop counters**, **ID generators**.

---
## Deep Dive:
- You can **overload** `++`/`--` in **C++ classes**.
- Assignment chaining:  
  ```cpp
  a = b = c = 100; // All three get 100
  ```

---

# 5. Implement Bitwise Operators

---

## Theory/Concept:
**Bitwise operators** work **at the bit level**. They manipulate individual bits directly.

---
## Syntax:
```cpp
result = operand1 bitwise_operator operand2;
```

**Operators:**
- `&` (AND)
- `|` (OR)
- `^` (XOR)
- `~` (NOT)
- `<<` (Left Shift)
- `>>` (Right Shift)

---
## Example Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5;   // 0101
    int b = 3;   // 0011

    cout << (a & b) << endl; // 0001 -> 1
    cout << (a | b) << endl; // 0111 -> 7
    cout << (a ^ b) << endl; // 0110 -> 6
    cout << (~a) << endl;    // flips bits
    cout << (a << 1) << endl; // 1010 -> 10
    cout << (a >> 1) << endl; // 0010 -> 2
    return 0;
}
```

---
## Explanation:
- `&`: Bits both 1 -> 1 else 0
- `|`: Any bit 1 -> 1
- `^`: Different bits -> 1
- `~`: Flips all bits
- `<<`: Shift bits left
- `>>`: Shift bits right

---
## Useful Notes:
- Shifting left multiplies by powers of 2.
- Shifting right divides by powers of 2.

---
## Common Pitfalls:
- Left-shifting by too much can cause **overflow**.

---
## Real-world Use Case:
- **Embedded systems**, **cryptography**, **flags/settings**.

---
## Deep Dive:
- **Bit masking** is a huge real-world pattern:
  ```cpp
  flags = flags | (1 << 2); // Set 3rd bit
  ```

---

# 6. Implement the `sizeof` Operator

---

## Theory/Concept:
`sizeof` gives the **size of a variable or type** in bytes.

---
## Syntax:
```cpp
sizeof(expression);
```

---
## Example Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Size of int: " << sizeof(a) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    return 0;
}
```

---
## Explanation:
- Prints memory size needed to store a type or variable.

---
## Useful Notes:
- `sizeof(char)` is **always 1** byte (but a byte ≠ 8 bits on all machines historically).

---
## Common Pitfalls:
- Forgetting that **sizeof an array** inside a function decays into pointer size!

---
## Real-world Use Case:
- **Memory optimization**, **serialization**.

---
## Deep Dive:
- Use `sizeof` carefully with **dynamic arrays** vs **static arrays**.

---

# 7. Implement the Comma Operator

---

## Theory/Concept:
The comma operator `,` evaluates **multiple expressions** but **returns only the last one**.

---
## Syntax:
```cpp
(result = (expr1, expr2));
```

---
## Example Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = (1, 2, 3); 
    cout << a << endl; // 3
    return 0;
}
```

---
## Explanation:
- `(1, 2, 3)` evaluates all, but returns 3.

---
## Useful Notes:
- Commonly used in **for loops**.

---
## Common Pitfalls:
- Misusing comma as if it adds or combines values.

---
## Real-world Use Case:
- Compact **multiple updates** inside a loop.
  
---
## Deep Dive:
- Rarely used directly. Compiler optimizes chained evaluation sequences using comma.

---

**[Pause Point: You're halfway! 🔥]**

Next up:
- **Operator precedence & associativity**
- **if / if-else / nested if-else**
- **switch-case**
- **?: conditional operator**
- **goto** (and why it's risky)

---
