
---

##  **What are Input and Output Iterators?**

C++ STL defines several types of iterators based on their capabilities. Two foundational types are:

### 1. **Input Iterator**

* **Purpose**: Read **sequential** data **only once** (single-pass).
* **Usage**: Used when reading data **from input streams**, files, or containers where only single traversal is required.
* **Example Use Case**: Reading integers from `std::cin` or file streams.

### 2. **Output Iterator**

* **Purpose**: Write data sequentially, one element at a time.
* **Usage**: Used when **writing** data to output streams, files, or inserting into containers.
* **Example Use Case**: Writing data to `std::cout`, file streams, or containers using `std::back_inserter`.

---

##  **Input Iterator Example: Reading from cin**

```cpp
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::istream_iterator<int> inIt(std::cin);        // begin of input stream
    std::istream_iterator<int> endIt;                 // end-of-stream iterator

    std::vector<int> numbers(inIt, endIt);            // reads until EOF (Ctrl+Z in Windows or Ctrl+D in Linux)

    for (int n : numbers) {
        std::cout << n << " ";
    }

    return 0;
}
```

###  Explanation:

* `istream_iterator<int> inIt(std::cin)` constructs an input iterator to read from `cin`.
* It can read values until the end of stream.

---

##  **Output Iterator Example: Writing to cout**

```cpp
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {10, 20, 30, 40};

    std::ostream_iterator<int> outIt(std::cout, " ");   // output with a space
    std::copy(v.begin(), v.end(), outIt);               // write to output stream

    return 0;
}
```

###  Explanation:

* `ostream_iterator<int>` writes data to `cout` with a delimiter.
* `std::copy` copies elements from vector to output stream using iterator.

---

##  **Using Output Iterator with back\_inserter (writing to a container)**

```cpp
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<int> source = {1, 2, 3, 4};
    std::vector<int> destination;

    std::copy(source.begin(), source.end(), std::back_inserter(destination));

    for (int x : destination)
        std::cout << x << " ";

    return 0;
}
```

###  Explanation:

* `std::back_inserter(destination)` creates an output iterator that calls `push_back`.

---

##  **Use Case: File Copy with Input and Output Iterators**

```cpp
#include <fstream>
#include <iterator>
#include <algorithm>

int main() {
    std::ifstream inFile("input.txt");
    std::ofstream outFile("output.txt");

    std::istream_iterator<std::string> inIt(inFile), endIt;
    std::ostream_iterator<std::string> outIt(outFile, "\n");

    std::copy(inIt, endIt, outIt);

    return 0;
}
```

* Copies each word from `input.txt` to `output.txt` using STL iterators.

---

##  Key Differences:

| Feature          | Input Iterator        | Output Iterator       |
| ---------------- | --------------------- | --------------------- |
| Direction        | Forward-only          | Forward-only          |
| Operation        | Read-only             | Write-only            |
| Multiple passes  | No (Single-pass only) | No (Single-pass only) |
| Valid Operations | `*it`, `++it`         | `*it = val`, `++it`   |

---

##  When to Use:

* **Input Iterator**:

  * Reading from `cin`, files, or streams
  * One-time traversals (e.g., processing input only once)

* **Output Iterator**:

  * Writing to `cout`, files
  * Inserting into containers dynamically (`back_inserter`, `inserter`, `front_inserter`)

---
