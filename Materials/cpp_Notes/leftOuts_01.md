
---

## 🔹 1. Using Built-in Functions: `system()`, `delay()`, `sleep()`

### ✅ `system()`

* Executes OS commands from your C++ program.

```cpp
#include <cstdlib>
int main() {
    system("cls");  // Clears the screen (Windows)
    system("pause"); // Pauses the execution
    return 0;
}
```

### ✅ `sleep()` and `delay()`

* `sleep()` is POSIX; `Sleep()` is from Windows.h.
* `delay()` is from `dos.h` (mostly obsolete, Turbo C++).

#### For Windows:

```cpp
#include <windows.h>
int main() {
    Sleep(2000); // Sleep for 2000 ms (2 seconds)
    return 0;
}
```

#### For POSIX (Linux/macOS):

```cpp
#include <unistd.h>
int main() {
    sleep(2); // Sleep for 2 seconds
    return 0;
}
```

---

## 🔹 2. Built-in Functions: `ceil()` and `floor()`

### 📌 `ceil()` - Rounds up

### 📌 `floor()` - Rounds down

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x = 4.7;
    cout << "Ceil of " << x << " is " << ceil(x) << endl;
    cout << "Floor of " << x << " is " << floor(x) << endl;
    return 0;
}
```

---

## 🔹 3. Using `rand()` and `srand()` for Random Values

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Seed random with system time
    for (int i = 0; i < 5; i++) {
        cout << rand() % 100 << endl; // Random number between 0 and 99
    }
    return 0;
}
```

---

## 🔹 4. Math Function Categories in C++

### Categories:

* Trigonometric: `sin()`, `cos()`, `tan()`
* Exponential: `exp()`, `log()`, `pow()`
* Rounding: `ceil()`, `floor()`, `round()`
* Absolute: `abs()`, `fabs()`
* Misc: `sqrt()`, `fmod()`

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "cos(0) = " << cos(0) << endl;
    cout << "sqrt(25) = " << sqrt(25) << endl;
    cout << "pow(2, 3) = " << pow(2, 3) << endl;
    return 0;
}
```

---

## 🔹 5. Using `ctime` to Output Date and Time

```cpp
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "Current date and time: " << dt << endl;
    return 0;
}
```

---

## 🔹 6. Format Specifiers in C++

| Format | Description  |
| ------ | ------------ |
| `%d`   | Integer      |
| `%f`   | Float        |
| `%c`   | Character    |
| `%s`   | String       |
| `%u`   | Unsigned int |
| `%ld`  | Long         |
| `%lf`  | Double       |

But in modern C++, use:

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double x = 123.456789;
    cout << fixed << setprecision(2) << x << endl; // 123.46
    return 0;
}
```

---

## 🔹 7. Storage Classes and Specifiers

### Types:

* `auto`: default for local variables.
* `register`: suggests storing in CPU register.
* `static`: retains value between function calls.
* `extern`: refers to a global variable defined elsewhere.

```cpp
#include <iostream>
using namespace std;

void counter() {
    static int count = 0;
    count++;
    cout << "Count = " << count << endl;
}

int main() {
    counter();
    counter();
    counter();
    return 0;
}
```

---

## 🔹 8. Storage Class Modifiers: `signed`, `unsigned`, `short`, `long`

```cpp
#include <iostream>
using namespace std;

int main() {
    unsigned int x = 10;
    signed int y = -10;
    long z = 100000L;
    short a = 32767;

    cout << "Unsigned: " << x << "\nSigned: " << y
         << "\nLong: " << z << "\nShort: " << a << endl;
    return 0;
}
```

---

## 🔹 9. Using `volatile` Variables

* `volatile` tells the compiler not to optimize this variable.

```cpp
#include <iostream>
using namespace std;

volatile int flag = 0;

int main() {
    while (!flag) {
        // Waiting for flag to change
    }
    cout << "Flag changed!" << endl;
    return 0;
}
```

---

## 🔹 10. Sign Bit and Use of `signed`/`unsigned`

### 🔸 `signed` → allows positive and negative.

### 🔸 `unsigned` → only positive.

```cpp
#include <iostream>
using namespace std;

int main() {
    signed int a = -5;
    unsigned int b = 5;

    cout << "Signed: " << a << "\nUnsigned: " << b << endl;
    return 0;
}
```

---

## 🔹 11. Using `short`, `long` Modifiers + Format Specifiers

```cpp
#include <iostream>
using namespace std;

int main() {
    short s = 100;
    long l = 1000000;
    long long ll = 9223372036854775807;

    cout << "Short: " << s << endl;
    cout << "Long: " << l << endl;
    cout << "Long Long: " << ll << endl;
    return 0;
}
```

> Use format specifiers in `printf()` (if using C-style I/O):

```cpp
#include <cstdio>

int main() {
    short s = 100;
    long l = 1000000;
    long long ll = 9223372036854775807;

    printf("Short: %hd\nLong: %ld\nLong Long: %lld\n", s, l, ll);
    return 0;
}
```

---

## ✅ Summary Table

| Concept                         | Header File(s) | Function/Modifier                      |
| ------------------------------- | -------------- | -------------------------------------- |
| `system()`, `srand()`, `rand()` | `<cstdlib>`    | `system()`, `rand()`, `srand()`        |
| `ceil()`, `floor()`, `pow()`    | `<cmath>`      | `ceil()`, `floor()`, `pow()`           |
| Time handling                   | `<ctime>`      | `time()`, `ctime()`                    |
| Formatting                      | `<iomanip>`    | `setprecision()`, `fixed`              |
| Storage classes                 | Built-in       | `auto`, `static`, `extern`, `register` |
| Type modifiers                  | Built-in       | `signed`, `unsigned`, `short`, `long`  |
| `volatile`                      | Built-in       | Prevents compiler optimization         |

---

