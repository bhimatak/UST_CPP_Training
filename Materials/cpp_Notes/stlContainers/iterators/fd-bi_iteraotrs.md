
---

## 🔁 Difference Between Forward Iterator and Bidirectional Iterator

| Feature          | Forward Iterator      | Bidirectional Iterator             |
| ---------------- | --------------------- | ---------------------------------- |
| Direction        | Can move forward only | Can move both forward and backward |
| Operator Support | `++`                  | `++`, `--`                         |
| Examples         | `std::forward_list`   | `std::list`, `std::set`, etc.      |

---

## 📘 Example Code to Demonstrate the Difference

### ✅ Forward Iterator (e.g., `std::forward_list`)

```cpp
#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> fl = {10, 20, 30};

    std::forward_list<int>::iterator it = fl.begin();

    std::cout << "Forward traversal in forward_list:\n";
    while (it != fl.end()) {
        std::cout << *it << " ";
        ++it;  // ✅ Only forward movement is allowed
    }

    // ❌ --it is invalid here
    // --it; // Error!

    return 0;
}
```

---

### ✅ Bidirectional Iterator (e.g., `std::list`)

```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {10, 20, 30};

    std::list<int>::iterator it = lst.begin();

    std::cout << "Forward traversal in list:\n";
    while (it != lst.end()) {
        std::cout << *it << " ";
        ++it;
    }

    std::cout << "\nBackward traversal in list:\n";
    // Move to the last valid element
    it = lst.end();
    --it;  // ❗ Valid: Bidirectional iterator supports --it

    while (true) {
        std::cout << *it << " ";
        if (it == lst.begin())
            break;
        --it;
    }

    return 0;
}
```

---

## 🔎 Summary

* `forward_list` allows only **forward traversal** using `++it`.
* `list`, `set`, `map` and other bidirectional iterator-based containers allow both `++it` and `--it`.

---
