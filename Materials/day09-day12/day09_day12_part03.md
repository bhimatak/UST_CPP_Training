#  **Part 3**  
---

# 8. Operator Precedence and Associativity

---

## Theory/Concept:
When multiple operators appear in an expression, **precedence** determines **which operator is evaluated first**.  
**Associativity** defines **how operators of the same precedence are grouped** (left-to-right or right-to-left).

---
## Syntax:
There’s no syntax change — it’s about **how C++ reads your code**.

---
## Example Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int result = 10 + 20 * 30;
    cout << result << endl;
    return 0;
}
```

---
## Explanation:
- Multiplication `*` has **higher precedence** than addition `+`.
- So `20 * 30 = 600` is evaluated first, then `10 + 600 = 610`.

---
## Useful Notes:
- Always use **parentheses** `()` to make your intended order **crystal clear**.
  
---
## Common Pitfalls:
- Assuming left-to-right execution without knowing operator priorities.

---
## Real-world Use Case:
- **Complex calculations** (e.g., billing, physics engines).

---
## Deep Dive:
- Assignment (`=`) has **right-to-left** associativity.
- Logical `&&` and `||` have **left-to-right** associativity.

**Example Table:**
| Operator | Precedence | Associativity |
|:---------|:-----------|:--------------|
| `*`, `/`, `%` | High | Left to Right |
| `+`, `-` | Medium | Left to Right |
| `=`, `+=`, `-=` | Low | Right to Left |

---

# 9. `if` Statements (including Nested `if`)

---

## Theory/Concept:
An `if` statement lets you **conditionally execute** a block of code based on whether a condition is **true**.

---
## Syntax:
```cpp
if (condition) {
    // code block
}
```

For Nested `if`:
```cpp
if (condition1) {
    if (condition2) {
        // code block
    }
}
```

---
## Example Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int marks = 85;
    if (marks > 80) {
        cout << "Excellent!" << endl;
    }
    return 0;
}
```

---
## Explanation:
- If `marks > 80`, print "Excellent!".
- Otherwise, nothing happens.

---
## Useful Notes:
- **Curly braces `{}` are always recommended**, even for a single line, to prevent bugs.

---
## Common Pitfalls:
- Forgetting `{}` leads to misleading control flow, especially when adding new lines later.

---
## Real-world Use Case:
- **Authentication checks**, **validating input**.

---
## Deep Dive:
- C++ compilers use **branch prediction** internally for optimizing `if` statements.

---

# 10. `if-else` Statements

---

## Theory/Concept:
`if-else` adds an **alternate path** if the condition is **false**.

---
## Syntax:
```cpp
if (condition) {
    // if block
} else {
    // else block
}
```

---
## Example Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int temp = 15;
    if (temp > 20) {
        cout << "Warm day!" << endl;
    } else {
        cout << "Cold day!" << endl;
    }
    return 0;
}
```

---
## Explanation:
- Based on `temp`, it prints "Warm day!" or "Cold day!".

---
## Useful Notes:
- Both `if` and `else` blocks are **optional**, but **one must match**.

---
## Common Pitfalls:
- Accidentally using `=` instead of `==` inside the condition.

---
## Real-world Use Case:
- **Shipping logic**: Free shipping if cart total > $100.

---
## Deep Dive:
- **else-if ladder** is a chain of if-else blocks — leads to complex branching.

---

# 11. Nested `if-else` Statements

---

## Theory/Concept:
You can place an `if-else` **inside another `if-else`**.

---
## Syntax:
```cpp
if (condition1) {
    if (condition2) {
        // block
    } else {
        // block
    }
} else {
    // block
}
```

---
## Example Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 18;
    if (age >= 18) {
        if (age >= 21) {
            cout << "Eligible for drinking" << endl;
        } else {
            cout << "Eligible for voting" << endl;
        }
    } else {
        cout << "Not eligible for voting" << endl;
    }
    return 0;
}
```

---
## Explanation:
- If `age` is 18–20, eligible for voting but not drinking.

---
## Useful Notes:
- Indent properly for **better readability**.

---
## Common Pitfalls:
- **Dangling else** problem — C++ pairs `else` with the nearest `if`.

---
## Real-world Use Case:
- Multi-stage verification (ex: Age + ID check).

---
## Deep Dive:
- Replace **deep nested ifs** with **early return** or **switch-case** if possible for cleaner code.

---

# 12. `switch` Statements with Case Values

---

## Theory/Concept:
`switch` lets you select one among **multiple blocks of code** based on the value of a variable.

---
## Syntax:
```cpp
switch (expression) {
    case value1:
        // block
        break;
    case value2:
        // block
        break;
    default:
        // block
}
```

---
## Example Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int choice = 2;
    switch (choice) {
        case 1:
            cout << "Option 1" << endl;
            break;
        case 2:
            cout << "Option 2" << endl;
            break;
        default:
            cout << "Invalid" << endl;
    }
    return 0;
}
```

---
## Explanation:
- `choice == 2` matches case 2, executes "Option 2".

---
## Useful Notes:
- `break` prevents **fall-through**.
- Always use `default` to catch unexpected values.

---
## Common Pitfalls:
- Forgetting `break`, causing unintentional fall-through.

---
## Real-world Use Case:
- **Menu systems**, **command selection**.

---
## Deep Dive:
- C++17 introduces **switch with `constexpr`** and **compile-time evaluation** — super optimized.

---

# 13. Conditional Operator `?:`

---

## Theory/Concept:
The conditional operator (`?:`) is a **short-hand for `if-else`**.

---
## Syntax:
```cpp
(condition) ? expression_if_true : expression_if_false;
```

---
## Example Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;
    int max = (a > b) ? a : b;
    cout << max << endl;
    return 0;
}
```

---
## Explanation:
- `max` gets the greater value between `a` and `b`.

---
## Useful Notes:
- Super useful for **compact expressions**.

---
## Common Pitfalls:
- Overusing it for complex logic makes code unreadable.

---
## Real-world Use Case:
- **Get the higher score** in a game quickly.

---
## Deep Dive:
- Nesting ternary operators is legal but **not recommended** due to readability issues.

---

# 14. `goto` Statement for Unconditional Branching

---

## Theory/Concept:
`goto` moves the execution **unconditionally** to a **labeled statement**.

---
## Syntax:
```cpp
goto label;
...
label:
    statement;
```

---
## Example Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 1;
    if (n == 1)
        goto skip;
    cout << "This will not print" << endl;
    
skip:
    cout << "Skipped to here" << endl;
    return 0;
}
```

---
## Explanation:
- `goto` jumps directly to `skip:` label.

---
## Useful Notes:
- Use **only when absolutely necessary** (like breaking nested loops).

---
## Common Pitfalls:
- **Spaghetti code**: Hard to follow, hard to debug.

---
## Real-world Use Case:
- **Error handling** in legacy C/C++ low-level code.

---
## Deep Dive:
- Modern C++ encourages **structured programming** using functions and loops — avoid `goto` unless you’re doing **kernel development** or **manual memory management**.

---

# 🎯 WRAP-UP for this Segment:
You've now mastered:
- All C++ operators and expressions.
- If-else logic and switching controls.
- Unconditional jumps (`goto`) and why we *respect but avoid* them.

---

# ⚡ Quick Visual Summary (Mental Map):

| Concept | Usage | Modern Tip |
|:--------|:------|:-----------|
| Arithmetic, Relational, Logical | Calculations and decisions | Use float if needed |
| Assignment, Increment/Decrement | Setting and updating | Pre-increment preferred for objects |
| Bitwise | Systems-level code | Mask carefully |
| sizeof, comma | Memory size and sequential ops | Use consciously |
| if, if-else, switch | Control flow | Prefer switch for simple value branching |
| ?: operator | Ternary short `if-else` | Keep it simple |
| goto | Jump anywhere (dangerous!) | Avoid unless critical |

---
