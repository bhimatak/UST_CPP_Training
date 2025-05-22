
1. ✅ Characteristics of C++ Data Types
2. ✅ Working with UTF-16, UTF-32, and Wide Characters (`wchar_t`, `char16_t`, `char32_t`)

---

## 🔹 Part 1: Characteristics of C++ Data Types

### ✅ Categories of C++ Data Types

| Category         | Types Included                                   |
| ---------------- | ------------------------------------------------ |
| **Basic**        | `int`, `float`, `char`, `bool`, `double`, `void` |
| **Derived**      | `array`, `pointer`, `function`, `reference`      |
| **User-defined** | `struct`, `class`, `union`, `enum`               |
| **Abstract**     | `interface`, `abstract class`                    |

---

### ✅ Characteristics of Built-in Types

| Data Type | Size (Typical) | Range                | Signed/Unsigned | Notes                        |
| --------- | -------------- | -------------------- | --------------- | ---------------------------- |
| `int`     | 4 bytes        | ±2B                  | Yes             | Whole numbers                |
| `float`   | 4 bytes        | \~±3.4E±38           | Signed          | 6-7 digit precision          |
| `double`  | 8 bytes        | \~±1.7E±308          | Signed          | 15-16 digit precision        |
| `char`    | 1 byte         | -128 to 127 or 0–255 | Yes             | ASCII or UTF-8               |
| `bool`    | 1 byte         | true/false           | N/A             | Logical values               |
| `void`    | 0 bytes        | N/A                  | N/A             | For functions with no return |

```cpp
#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    int a = 5;
    float b = 5.5;
    char c = 'A';
    bool d = true;

    cout << "Type of a: " << typeid(a).name() << ", Size: " << sizeof(a) << endl;
    cout << "Type of b: " << typeid(b).name() << ", Size: " << sizeof(b) << endl;
    cout << "Type of c: " << typeid(c).name() << ", Size: " << sizeof(c) << endl;
    cout << "Type of d: " << typeid(d).name() << ", Size: " << sizeof(d) << endl;
    return 0;
}
```

---

### ✅ Modifiers That Affect Data Types

* `signed`, `unsigned`: affect sign storage
* `short`, `long`: affect size

```cpp
short s = 32767;
unsigned int u = 4294967295;
long long ll = 9223372036854775807;
```

Use `sizeof()` to confirm size on your platform.

---

## 🔹 Part 2: Working with UTF-16, UTF-32, and Wide Characters

### ✅ 1. `wchar_t` – Wide Character (UTF-16 or UTF-32 depending on platform)

```cpp
#include <iostream>
using namespace std;

int main() {
    wchar_t w = L'₹';  // L prefix = wide character
    wcout << L"Wide character: " << w << endl;
    return 0;
}
```

> Compile with: `g++ -fexec-charset=UTF-16 filename.cpp`

### ✅ 2. `char16_t` – UTF-16 Characters (C++11 and later)

```cpp
#include <iostream>
using namespace std;

int main() {
    char16_t ch[] = u"नमस्ते";  // u = UTF-16
    cout << "UTF-16 data stored.\n";
    return 0;
}
```

> You need special libraries or conversion functions to display or process UTF-16 characters.

### ✅ 3. `char32_t` – UTF-32 Characters (C++11 and later)

```cpp
#include <iostream>
using namespace std;

int main() {
    char32_t ch[] = U"こんにちは";  // U = UTF-32
    cout << "UTF-32 data stored.\n";
    return 0;
}
```

### ✅ 4. Print Wide/UTF Strings using `<codecvt>` and `<locale>` (C++11)

```cpp
#include <iostream>
#include <locale>
#include <codecvt>

int main() {
    std::u16string utf16 = u"हैलो";
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
    std::string narrowStr = convert.to_bytes(utf16);

    std::cout << "UTF-16 as UTF-8: " << narrowStr << std::endl;
    return 0;
}
```

> Note: `<codecvt>` is deprecated in C++17, and should be replaced with third-party libs like ICU or `iconv` for robust UTF support.

---

### ✅ Summary: Character Type Usage

| Type       | Size (bytes)           | Encoding    | Introduced In |
| ---------- | ---------------------- | ----------- | ------------- |
| `char`     | 1                      | ASCII/UTF-8 | C/C++         |
| `wchar_t`  | 2 (Windows), 4 (Linux) | UTF-16/32   | C++           |
| `char16_t` | 2                      | UTF-16      | C++11         |
| `char32_t` | 4                      | UTF-32      | C++11         |

---

### 🧠 Tip for Teaching

To visualize UTF formats in output:

* Use platforms that support Unicode (VS Code terminal, Linux, or PowerShell with UTF-8).
* Use `wcout` and `setlocale()` to display wide characters:

```cpp
#include <iostream>
#include <locale>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    wchar_t w = L'漢';
    wcout << L"Wide char output: " << w << endl;
    return 0;
}
```

---
