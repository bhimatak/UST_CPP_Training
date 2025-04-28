#  Part 1  
---

# 1. Recognize the Characteristics of C++ Data Types

## Theory/Concept
Data types define the type of data a variable can hold — numbers, characters, decimals, etc. In C++, they are *strongly typed* — meaning a variable’s type is fixed at compile time. This strictness prevents many bugs.

## Syntax
```cpp
int age;
float weight;
char grade;
bool isPassed;
```

## Example Code
```cpp
#include<iostream>
using namespace std;

int main() {
    int age = 21;
    float weight = 65.5;
    char grade = 'A';
    bool isPassed = true;

    cout << "Age: " << age << ", Weight: " << weight << ", Grade: " << grade << ", Passed: " << isPassed << endl;
}
```

## Explanation
Each variable is declared with a type. `cout` outputs their values. `bool` outputs as `1` (true) or `0` (false).

## Useful Notes
- Always initialize variables.
- Floating-point numbers (float, double) can have rounding errors — use `double` for more precision.

## Common Pitfalls
- Forgetting to initialize variables (leading to garbage values).
- Mismatching types (e.g., storing a decimal in an `int`).

## Real-world Use Case
Building a student information system — you'd use various data types for name (string), marks (float), and pass/fail status (bool).

## More Details
- `sizeof(type)` gives memory size.
- Type promotions (e.g., `int + float -> float`) happen during operations.

---

# 2. Work with UTF-16, UTF-32, and Wide Characters

## Theory/Concept
C++ traditionally used `char` for 1-byte characters (ASCII). For international languages (like Chinese, Hindi, etc.), you need multi-byte encoding like UTF-16/UTF-32.

## Syntax
```cpp
wchar_t wideChar = L'あ'; // Japanese Hiragana character
char16_t utf16Char = u'あ';
char32_t utf32Char = U'あ';
```

## Example Code
```cpp
#include<iostream>
using namespace std;

int main() {
    wchar_t wc = L'あ';
    char16_t c16 = u'あ';
    char32_t c32 = U'あ';

    wcout << L"Wide char: " << wc << endl;
}
```

## Explanation
- `wchar_t` is for wide characters.
- `char16_t` for UTF-16 encoding.
- `char32_t` for UTF-32 encoding.

## Useful Notes
- `wcout` is needed to print `wchar_t`.
- UTF-16/32 don't directly print well without conversions.

## Common Pitfalls
- Mixing normal `cout` with wide characters — leads to junk output.

## Real-world Use Case
Developing software that needs to support multi-language text (e.g., Microsoft Word).

## More Details
- `wchar_t` size can vary across systems (2 or 4 bytes).
- Libraries like ICU or C++20’s `<format>` help with Unicode better.

---

# 3. Work with C++ Data Type Modifiers

## Theory/Concept
Modifiers change the size or properties of a data type: `signed`, `unsigned`, `short`, `long`.

## Syntax
```cpp
unsigned int age = 23;
long long population = 7000000000;
```

## Example Code
```cpp
#include<iostream>
using namespace std;

int main() {
    unsigned int age = 25;
    long long int bigNumber = 9223372036854775807LL;

    cout << "Age: " << age << ", Big Number: " << bigNumber << endl;
}
```

## Explanation
- `unsigned` means no negatives allowed, bigger positive range.
- `long long` is used for *huge* numbers.

## Useful Notes
- Always use `unsigned` for quantities that can't be negative (like age, population).

## Common Pitfalls
- Assigning a negative value to an `unsigned` — unpredictable behavior.

## Real-world Use Case
Handling file sizes or memory addresses, which can't be negative.

## More Details
- `std::uint32_t` and friends from `<cstdint>` give fixed width types (best practice for portability).

---

# 4. Use Arithmetic Operators

## Theory/Concept
Arithmetic operators perform basic math.

## Syntax
```cpp
+, -, *, /, %
```

## Example Code
```cpp
#include<iostream>
using namespace std;

int main() {
    int a = 10, b = 3;
    cout << "Addition: " << a + b << endl;
    cout << "Division: " << a / b << endl;
    cout << "Modulus: " << a % b << endl;
}
```

## Explanation
Simple math between `a` and `b`.

## Useful Notes
- Integer division truncates decimals. Use floats for exact results.

## Common Pitfalls
- Division by zero crashes the program!

## Real-world Use Case
Calculating bill amounts, percentages in apps.

## More Details
- `std::fmod()` for modulus of floating points.

---

# 5. Work with Relational and Logical Operators

## Theory/Concept
Relational operators compare values, logical operators combine conditions.

## Syntax
```cpp
==, !=, >, <, >=, <= // Relational
&&, ||, !            // Logical
```

## Example Code
```cpp
#include<iostream>
using namespace std;

int main() {
    int a = 5, b = 10;

    if(a < b && b > 0) {
        cout << "Both conditions are true!" << endl;
    }
}
```

## Explanation
Checks if `a` is less than `b` *and* `b` is positive.

## Useful Notes
- Always group complex logical expressions with parentheses for clarity.

## Common Pitfalls
- Mixing `=` (assignment) with `==` (comparison).

## Real-world Use Case
Login validation (`username == "admin" && password == "1234"`).

## More Details
- Short-circuiting: In `&&`, if first condition fails, second isn't checked.

---

