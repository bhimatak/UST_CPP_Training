#  Part2
---

# 6. Work with Bitwise Operators in C++

## Theory/Concept
Bitwise operators directly manipulate bits of integer types. They are **blazing fast** and important for low-level operations, encryption, graphics, etc.

## Syntax
```cpp
&, |, ^, ~, <<, >>
```
- `&` — AND
- `|` — OR
- `^` — XOR
- `~` — NOT (bit inversion)
- `<<` — left shift
- `>>` — right shift

## Example Code
```cpp
#include<iostream>
using namespace std;

int main() {
    int a = 5;  // 0101
    int b = 3;  // 0011

    cout << "a & b: " << (a & b) << endl; // 0001 -> 1
    cout << "a | b: " << (a | b) << endl; // 0111 -> 7
    cout << "a ^ b: " << (a ^ b) << endl; // 0110 -> 6
    cout << "~a: " << (~a) << endl;       // Inverts bits
}
```

## Explanation
Each operator works at the binary level.

## Useful Notes
- Shifting left (`<<`) is equivalent to multiplying by 2.
- Shifting right (`>>`) divides by 2.

## Common Pitfalls
- Negative numbers behave differently when shifted right (arithmetic shift).

## Real-world Use Case
- File permissions (Unix).
- Graphics programming (pixel data).

## More Details
- In C++17, you can use `constexpr` with bitwise logic for compile-time calculations.

```cpp
constexpr int mask = 0xFF;
```

---

# 7. Work with Assignment Operators in C++

## Theory/Concept
Assignment operators assign values to variables.

## Syntax
```cpp
=, +=, -=, *=, /=, %=
```

## Example Code
```cpp
#include<iostream>
using namespace std;

int main() {
    int x = 5;
    x += 3; // x = x + 3

    cout << "x: " << x << endl;
}
```

## Explanation
Assignment + arithmetic combined into one step.

## Useful Notes
- Compound assignment improves readability and slightly optimizes code.

## Common Pitfalls
- Forgetting parentheses when needed in complex expressions.

## Real-world Use Case
Counting items in a loop.

## More Details
- Operator overloading allows customizing assignment behavior for user-defined types.

---

# 8. Work with Compound Assignment Operators

(Already covered above, but expanding!)

## Advanced Example (C++14/17 style)
```cpp
#include<iostream>
using namespace std;

int main() {
    int a = 4, b = 2;
    a *= b + 3; // a = a * (b + 3)

    cout << "Result: " << a << endl;
}
```
⚡ **Tip:** Always be careful about **operator precedence**!

---

# 9. Use the `if` Statement for Branching

## Theory/Concept
`if` controls the program's flow based on conditions.

## Syntax
```cpp
if(condition) {
   // code
} else {
   // code
}
```

## Example Code
```cpp
#include<iostream>
using namespace std;

int main() {
    int score = 85;
    if(score >= 90) {
        cout << "Grade A" << endl;
    } else if(score >= 75) {
        cout << "Grade B" << endl;
    } else {
        cout << "Grade C" << endl;
    }
}
```

## Explanation
Program chooses between different blocks based on conditions.

## Useful Notes
- Use `{}` braces even for one-liners (traditional best practice).
- C++17: `if constexpr` — compile-time if!

Example:

```cpp
template<typename T>
void showType(T val) {
    if constexpr (is_integral<T>::value) {
        cout << "Integral Type" << endl;
    } else {
        cout << "Non-Integral Type" << endl;
    }
}
```

---

# 10. Use a `for` Loop in C++

## Theory/Concept
`for` loop is best when the number of iterations is **known**.

## Syntax
```cpp
for(initialization; condition; update) {
    // code
}
```

## Example Code
```cpp
#include<iostream>
using namespace std;

int main() {
    for(int i = 0; i < 5; i++) {
        cout << "i: " << i << endl;
    }
}
```

## C++11/14/17 Bonus: Range-Based `for`
```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    for(auto num : nums) {
        cout << num << " ";
    }
}
```

## Useful Notes
- Prefer `auto` in range-based loops to avoid type mistakes.

---

# 11. Use a `while` Loop

## Theory/Concept
`while` loop is best when the number of iterations is **unknown**.

## Syntax
```cpp
while(condition) {
    // code
}
```

## Example Code
```cpp
#include<iostream>
using namespace std;

int main() {
    int i = 0;
    while(i < 5) {
        cout << i << " ";
        i++;
    }
}
```

---

# 12. Use a `do while` Loop

## Theory/Concept
`do-while` guarantees **at least one execution**.

## Syntax
```cpp
do {
    // code
} while(condition);
```

## Example Code
```cpp
#include<iostream>
using namespace std;

int main() {
    int num = 1;
    do {
        cout << num << " ";
        num++;
    } while(num <= 5);
}
```

---

# 13. Use the `switch` Statement

## Theory/Concept
`switch` provides multiple possible paths for one variable.

## Syntax
```cpp
switch(expression) {
    case value1:
        // code
        break;
    case value2:
        // code
        break;
    default:
        // code
}
```

## Example Code
```cpp
#include<iostream>
using namespace std;

int main() {
    int day = 3;
    switch(day) {
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        default: cout << "Invalid day";
    }
}
```

---

# 14. Create a Basic C++ Application Using Data Types and Looping Constructs

## Example Code
```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> numbers;
    int n;
    
    cout << "Enter 5 numbers:" << endl;
    for(int i = 0; i < 5; i++) {
        cin >> n;
        numbers.push_back(n);
    }

    cout << "Numbers greater than 10:" << endl;
    for(auto num : numbers) {
        if(num > 10) {
            cout << num << " ";
        }
    }
}
```

---

# Summary of Additional Advanced Details:

| Feature         | More Details |
|-----------------|--------------|
| C++14 Features   | `auto` return types, `decltype(auto)`, digit separators (`1'000'000`) |
| C++17 Features   | `if constexpr`, structured bindings (`auto [a, b] = pair`), fold expressions, filesystem API |
| Optimization Tip | Prefer `constexpr` when possible for compile-time calculations. |
| Performance Tip  | Use `std::vector` instead of raw arrays for dynamic collections. |

---

