---

# 1. Operators and Expressions + Implement Arithmetic Operators

---

## Theory/Concept:
In C++, **operators** are special symbols that perform operations on variables and values. An **expression** combines variables, constants, and operators to compute a value. Arithmetic operators specifically deal with mathematical calculations.

Operators **boost code readability** and make complex calculations **concise**.

---
## Syntax:
```cpp
result = operand1 operator operand2;
```

**Common Arithmetic Operators:**
- `+` (Addition)
- `-` (Subtraction)
- `*` (Multiplication)
- `/` (Division)
- `%` (Modulus - remainder)

---
## Example Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 3;
    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << a / b << endl;
    cout << "Modulus: " << a % b << endl;
    return 0;
}
```

---
## Explanation:
- `a + b` => 10 + 3 = 13
- `a - b` => 10 - 3 = 7
- `a * b` => 10 * 3 = 30
- `a / b` => 10 / 3 = 3 (integer division)
- `a % b` => 10 % 3 = 1 (remainder)

---
## Useful Notes:
- **Division between integers** discards the fraction (rounds towards zero).
- **Use `float`/`double`** if you want decimal results.
  
---
## Common Pitfalls:
- Dividing by **zero** causes runtime errors.
- Forgetting types: `5/2` gives `2`, not `2.5` (use `5.0/2` for floating point division).

---
## Real-world Use Case:
- Calculating **cart totals**, **discounts**, or **taxes** in a billing system.

---
## Deep Dive:
- **Operator Overloading**: In C++, you can redefine how operators work for user-defined types (like classes).  
- **Performance tip**: Division (`/`) is slower than multiplication (`*`) on most processors. Optimize if needed.

---

# 2. Implement Relational Operators

---

## Theory/Concept:
Relational operators **compare two values**. They **return `true` or `false`** depending on the comparison.

---
## Syntax:
```cpp
result = operand1 relational_operator operand2;
```

**Operators:**
- `==` (Equal to)
- `!=` (Not equal to)
- `<` (Less than)
- `>` (Greater than)
- `<=` (Less than or equal to)
- `>=` (Greater than or equal to)

---
## Example Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;
    cout << (a == b) << endl; // 0 (false)
    cout << (a != b) << endl; // 1 (true)
    cout << (a < b) << endl;  // 1 (true)
    return 0;
}
```

---
## Explanation:
- `a == b` returns `false`.
- `a != b` returns `true`.
- `a < b` returns `true`.

---
## Useful Notes:
- Result is an **integer** (`0` for `false`, `1` for `true`).

---
## Common Pitfalls:
- Using `=` instead of `==` (assignment vs comparison).

---
## Real-world Use Case:
- **Login authentication**: Check if entered password matches stored password.

---
## Deep Dive:
- **Comparison Chaining**: Unlike Python, you can't chain comparisons directly (e.g., `a < b < c` won't work).

---

# 3. Implement Logical Operators

---

## Theory/Concept:
Logical operators combine **multiple conditions**.

---
## Syntax:
```cpp
result = condition1 logical_operator condition2;
```

**Operators:**
- `&&` (Logical AND)
- `||` (Logical OR)
- `!` (Logical NOT)

---
## Example Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 10;
    cout << (a < 10 && b > 5) << endl; // 1 (true)
    cout << (a > 10 || b > 5) << endl; // 1 (true)
    cout << !(a > 10) << endl;         // 1 (true)
    return 0;
}
```

---
## Explanation:
- `&&` returns true if **both** conditions are true.
- `||` returns true if **any** one condition is true.
- `!` flips the result.

---
## Useful Notes:
- **Short-circuiting**: `&&` stops checking if the first is `false`, `||` stops if first is `true`.

---
## Common Pitfalls:
- Misunderstanding precedence between `&&`, `||`, and `!`.

---
## Real-world Use Case:
- **Access control**: Allow user if they have either admin or editor role.

---
## Deep Dive:
- Logical operators are used in **branch prediction optimization** by modern compilers.

---

