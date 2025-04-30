---

## 🔹 13. `std::string` Member Functions (Categorized)

Here’s a breakdown of member functions with code samples to illustrate usage.

---

### 🏗️ **Construction and Assignment**

```cpp
std::string s1("hello");
std::string s2(s1);                     // Copy constructor
std::string s3(std::move(s2));          // Move constructor

std::string s4(10, '*');                // "**********"
std::string s5 = std::string{'A'};      // From char

s4 = s1;                                // Copy assignment
s5 = std::move(s1);                     // Move assignment
```

---

### 📏 **Size and Capacity**

```cpp
std::string s = "OpenAI GPT";

// Size-related
s.size();              // returns 9
s.length();            // same as size()
s.capacity();          // current allocated storage

// Resize with fill character
s.resize(15, '.');     // "OpenAI GPT......"

// Shrink-to-fit
s.shrink_to_fit();     // optional — may reduce memory
```

---

### 🧼 **Modification**

```cpp
std::string s = "Example";

// Append
s.append(" String");         // "Example String"
s += " More";                // "Example String More"

// Insert
s.insert(7, "Cool ");        // "ExampleCool  String More"

// Replace
s.replace(0, 7, "Test");     // "TestCool  String More"

// Erase
s.erase(4, 5);               // Removes 5 chars from index 4

// Clear
s.clear();                   // s == ""

// Push/Pop
s.push_back('!');
s.pop_back();                // removes last char
```

---

### 🔍 **Search Functions**

```cpp
std::string s = "C++ is powerful";

// Find first occurrence
s.find("is");                // index of "is"

// Find last occurrence
s.rfind("o");                // reverse find

// Find any of a set of chars
s.find_first_of("aeiou");    // index of first vowel
s.find_last_of("aeiou");

// Not in string
std::string::npos            // special value = -1

// Example:
if (s.find("Java") == std::string::npos) {
    std::cout << "Not found!\n";
}
```

---

### ✂️ **Substring Extraction**

```cpp
std::string s = "Programming";

// Substring from index
std::string sub = s.substr(3, 4);   // "gram"

// substr(pos, n) — returns n characters from pos
```

---

### 🔁 **Comparison**

```cpp
std::string a = "abc";
std::string b = "xyz";

// Operator-based
if (a < b) std::cout << "a comes before b";

// Function-based
int res = a.compare(b);  // <0 if a<b, 0 if equal, >0 if a>b

// Compare with part of another string
a.compare(0, 1, b, 0, 1); // compare first chars
```

---

### 🧪 **String Testing**

While `std::string` doesn’t include built-in testing like `starts_with` or `ends_with` in C++14, C++20 introduces them.

But you can manually do:

```cpp
bool starts_with(const std::string& s, const std::string& prefix) {
    return s.compare(0, prefix.size(), prefix) == 0;
}

bool ends_with(const std::string& s, const std::string& suffix) {
    if (s.length() >= suffix.length())
        return s.compare(s.length() - suffix.length(), suffix.length(), suffix) == 0;
    return false;
}
```

---

## 🔹 14. Using `std::transform` for Case Conversion

```cpp
#include <algorithm>
#include <cctype>

std::string str = "Hello World";

// To uppercase
std::transform(str.begin(), str.end(), str.begin(), ::toupper);

// To lowercase
std::transform(str.begin(), str.end(), str.begin(), ::tolower);
```

---

## 🔹 15. Tokenizing a `std::string` (Manual Split)

No native split in C++14, but here's a reusable function:

```cpp
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
```

---

## 🔹 16. Trimming Whitespace (Custom Utility)

```cpp
std::string trim(const std::string& s) {
    const auto start = s.find_first_not_of(" \t\n\r");
    const auto end = s.find_last_not_of(" \t\n\r");

    if (start == std::string::npos)
        return "";  // only whitespace

    return s.substr(start, end - start + 1);
}
```

---

## 🔹 17. Escaping and Unescaping Strings

Useful in serialization/parsing:

```cpp
std::string escape_quotes(const std::string& input) {
    std::string result;
    for (char c : input) {
        if (c == '"') result += "\\\"";
        else result += c;
    }
    return result;
}
```

---

## 🔹 18. Efficient String Concatenation

### Avoid this in loops:
```cpp
std::string result;
for (int i = 0; i < 1000; ++i)
    result += std::to_string(i);  // many reallocs
```

### Prefer:
```cpp
std::ostringstream oss;
for (int i = 0; i < 1000; ++i)
    oss << i;
std::string result = oss.str();
```

---

## 🔹 19. Working with Raw Buffers

```cpp
std::string binary(4, '\0');
binary[0] = 0xDE;
binary[1] = 0xAD;
binary[2] = 0xBE;
binary[3] = 0xEF;

// Use .data() or .c_str() when passing to functions
some_c_api(binary.data(), binary.size());
```

---

## 🔹 20. Safe Iteration with `.at()`

```cpp
std::string s = "C++";

// Safe access (throws std::out_of_range)
try {
    char ch = s.at(10);  // throws
} catch (const std::out_of_range& e) {
    std::cout << "Index out of range!\n";
}
```

---

## 🧠 Summary Table of Key Functions

| Operation       | Function                 | Notes                           |
|----------------|--------------------------|---------------------------------|
| Append          | `append`, `+=`           | Also supports chaining          |
| Replace         | `replace()`              | Replace substring               |
| Find            | `find`, `rfind`          | Position of substring           |
| Substring       | `substr(pos, len)`       | Extract part of string          |
| Compare         | `compare()`              | Richer than `==`                |
| Clear           | `clear()`                | Empty the string                |
| Reserve         | `reserve(size)`          | Optimize capacity               |
| Push/Pop        | `push_back`, `pop_back`  | Char-level control              |

---
