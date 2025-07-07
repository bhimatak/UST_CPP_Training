Let’s **break down CI/CD step-by-step** for a **Visual Studio 2022 C++ project using GitHub Actions and CMake**, in a very beginner-friendly manner.

---

## ✅ Goal

You want:

* **CI (Continuous Integration):** Automatically build and test your code whenever you push changes to GitHub.
* **CD (Continuous Deployment):** Optionally package, upload, or deploy artifacts when the build and tests succeed.

---

## 🔧 Step-by-Step Guide

---

### **STEP 1: Project Setup in Visual Studio 2022**

1. **Open Visual Studio 2022**

2. **Create a CMake Project**

   * File → New → Project
   * Search: “CMake Project”
   * Name it: `UST_Training` (or any name)
   * Folder structure should look like:

     ```
     /UST_Training
     ├── CMakeLists.txt
     ├── main.cpp
     ├── mylib/
     │   ├── utils.h
     │   └── utils.cpp
     └── tests/
         └── test_main.cpp
     ```

3. **Add CMakeLists.txt** files:

   * **Top-level `CMakeLists.txt`** (to orchestrate build)
   * **Subdirectory CMake files** (optional)

---

### **STEP 2: Write the Code**

#### `main.cpp`

```cpp
#include <iostream>
#include "mylib/utils.h"

int main() {
    std::cout << "Hello from main!\n";
    std::cout << "Sum of 3 and 4 is: " << add(3, 4) << std::endl;
    return 0;
}
```

#### `mylib/utils.h`

```cpp
#pragma once
int add(int a, int b);
```

#### `mylib/utils.cpp`

```cpp
#include "utils.h"
int add(int a, int b) {
    return a + b;
}
```

#### `tests/test_main.cpp`

```cpp
#include <cassert>
#include "mylib/utils.h"

int main() {
    assert(add(2, 3) == 5);
    return 0;
}
```

---

### **STEP 3: Create `CMakeLists.txt`**

#### Root `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.15)
project(UST_Training)

add_subdirectory(mylib)
add_executable(MainApp main.cpp)
target_link_libraries(MainApp PRIVATE MyLib)

enable_testing()
add_test(NAME RunMyTests COMMAND test_main)
```

#### `mylib/CMakeLists.txt`:

```cmake
add_library(MyLib utils.cpp)
target_include_directories(MyLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```

#### `tests/CMakeLists.txt` (optional, or include in root):

```cmake
add_executable(test_main tests/test_main.cpp)
target_link_libraries(test_main PRIVATE MyLib)
```

---

### **STEP 4: Push Code to GitHub**

1. Create a GitHub repo
2. Push all your files including `.github/workflows/ci.yml` (next step)

---

### **STEP 5: Setup GitHub Actions (CI)**

Create this folder and file:

```text
.github/workflows/ci.yml
```

#### `ci.yml`:

```yaml
name: Build and Test

on:
  push:
    branches: [ main ]
  pull_request:
    branches: [ main ]

jobs:
  build:
    runs-on: windows-latest

    steps:
    - name: Checkout code
      uses: actions/checkout@v4

    - name: Setup CMake
      uses: lukka/get-cmake@latest

    - name: Configure
      run: cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

    - name: Build
      run: cmake --build build --config Release

    - name: Run Tests
      run: ctest --test-dir build --output-on-failure -C Release
```

✅ This does:

* Checkout code
* Build with CMake
* Run tests

---

### **STEP 6: Add CD (Optional)**

To deploy artifacts (like your `.exe`), add to the bottom of your workflow:

```yaml
    - name: Upload Executable
      uses: actions/upload-artifact@v4
      with:
        name: MainApp
        path: build/Release/MainApp.exe
```

This stores the built `.exe` in GitHub Actions → Artifacts tab.

---

### **STEP 7: Verify Workflow in GitHub**

1. Push to GitHub
2. Go to **GitHub → Actions Tab**
3. You’ll see:

   * ✅ Checkout
   * ✅ Configure
   * ✅ Build
   * ✅ Run Tests
   * ✅ Upload Executable (if added)

---

### 🧠 Extra: What Are Runners?

* **GitHub Runners** are virtual machines (e.g., Windows, Ubuntu) that run your workflow.
* `runs-on: windows-latest` tells GitHub to spin up a **Windows runner**, suitable for Visual Studio builds.

You don’t need to install anything — GitHub takes care of this unless you want to self-host runners (advanced).

---

### ✅ Summary Checklist

| Step | Task                                                   |
| ---- | ------------------------------------------------------ |
| ✅ 1  | Create C++ project using Visual Studio 2022 with CMake |
| ✅ 2  | Add necessary source and header files                  |
| ✅ 3  | Write a proper `CMakeLists.txt` file                   |
| ✅ 4  | Push code to GitHub                                    |
| ✅ 5  | Add GitHub Actions workflow (`ci.yml`)                 |
| ✅ 6  | Use `ctest -C Release` to fix config issue             |
| ✅ 7  | (Optional) Upload `.exe` as artifact (CD)              |

---


