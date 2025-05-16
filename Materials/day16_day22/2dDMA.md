Dynamic memory allocation for a 2D array in C/C++ can be achieved in several ways, depending on whether you want a:

1. **Contiguous memory block** (efficient and cache-friendly)
2. **Pointer to pointer** style (more flexible, but less cache efficient)

---

### ✅ **Method 1: Pointer to Pointer (Array of Pointers)**

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 4;

    // Step 1: Allocate array of row pointers
    int** arr = new int*[rows];

    // Step 2: Allocate each row separately
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }

    // Access & initialize
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            arr[i][j] = i * cols + j;

    // Print
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    // Deallocate
    for (int i = 0; i < rows; ++i)
        delete[] arr[i];
    delete[] arr;

    return 0;
}
```

🟡 **Pros**: Flexible, each row can be a different length (jagged arrays).
🔴 **Cons**: Not cache-friendly, multiple `new[]` calls.

---

### ✅ **Method 2: Single Allocation (Contiguous Block + Row Pointers)**

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 4;

    // Allocate memory for row pointers
    int** arr = new int*[rows];

    // Allocate contiguous block for all elements
    arr[0] = new int[rows * cols];

    // Set row pointers to appropriate offsets
    for (int i = 1; i < rows; ++i)
        arr[i] = arr[0] + i * cols;

    // Initialize
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            arr[i][j] = i * cols + j;

    // Print
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    // Deallocate
    delete[] arr[0];  // delete the data block
    delete[] arr;     // delete the row pointers

    return 0;
}
```

🟢 **Pros**: Efficient, better locality, fewer allocations.
🔴 **Cons**: Slightly more complex setup.

---

### ✅ **Method 3: Flat 1D Array with Manual Indexing**

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 4;
    int* arr = new int[rows * cols];

    // Initialize
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            arr[i * cols + j] = i * cols + j;

    // Print
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << arr[i * cols + j] << " ";
        cout << endl;
    }

    // Deallocate
    delete[] arr;

    return 0;
}
```

🟢 **Pros**: Most memory-efficient and simple.
🔴 **Cons**: Manual indexing, harder to read.

---

### Summary Table:

| Method             | Flexibility                   | Performance | Memory Access        |
| ------------------ | ----------------------------- | ----------- | -------------------- |
| Pointer to Pointer | High (jagged arrays possible) | Low         | Multiple allocations |
| Contiguous Block   | Medium                        | High        | Good cache locality  |
| Flat 1D            | Low                           | Very High   | Best                 |

---
---
---

**dynamic memory allocation for 2D arrays using `malloc()` in C**, covering all three methods:

---

## ✅ **Method 1: Pointer to Pointer (`int**`) – Row-wise Allocation**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 4;

    // Step 1: Allocate array of int* (row pointers)
    int** arr = (int**)malloc(rows * sizeof(int*));

    // Step 2: Allocate each row
    for (int i = 0; i < rows; ++i) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    // Initialize
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            arr[i][j] = i * cols + j;

    // Print
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; ++i)
        free(arr[i]);
    free(arr);

    return 0;
}
```

---

## ✅ **Method 2: Single Block Allocation + Array of Row Pointers**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 4;

    // Allocate memory for row pointers
    int** arr = (int**)malloc(rows * sizeof(int*));

    // Allocate one contiguous block for all elements
    arr[0] = (int*)malloc(rows * cols * sizeof(int));

    // Point each row to the correct position
    for (int i = 1; i < rows; ++i)
        arr[i] = arr[0] + i * cols;

    // Initialize
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            arr[i][j] = i * cols + j;

    // Print
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    // Free memory
    free(arr[0]);  // single data block
    free(arr);     // row pointers

    return 0;
}
```

---

## ✅ **Method 3: Flat 1D Array with Manual Indexing**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 4;

    // Allocate 1D array
    int* arr = (int*)malloc(rows * cols * sizeof(int));

    // Initialize
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            arr[i * cols + j] = i * cols + j;

    // Print
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            printf("%d ", arr[i * cols + j]);
        printf("\n");
    }

    // Free memory
    free(arr);

    return 0;
}
```

---

### ✅ Summary (C using `malloc()`):

| Method                             | Allocation                                    | Access Style        | Freeing Required                  |
| ---------------------------------- | --------------------------------------------- | ------------------- | --------------------------------- |
| Pointer-to-pointer                 | `malloc` for rows, then each row              | `arr[i][j]`         | Free each row, then pointer array |
| Contiguous block with row pointers | One block for data, `malloc` for row pointers | `arr[i][j]`         | Free `arr[0]`, then `arr`         |
| Flat 1D array                      | Single block                                  | `arr[i * cols + j]` | Free `arr`                        |

---
---
