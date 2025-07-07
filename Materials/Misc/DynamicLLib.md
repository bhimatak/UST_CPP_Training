
---

# 🧩 Part 1: Creating a DLL Project in Visual Studio 2022

### ✅ Step 1: Open Visual Studio and Create a New DLL Project

1. Open **Visual Studio 2022**
2. Click **"Create a new project"**
3. Search for **"Dynamic-Link Library (DLL)"**
4. Select **"Dynamic-Link Library (DLL) (C++)"** → Click **Next**

---

### ✅ Step 2: Configure the Project

* **Project Name**: `MyMathDLL`
* **Location**: Choose your folder
* **Solution**: "Create new solution"
* Click **Create**

---

### ✅ Step 3: Add Header and Source Files

#### Add a Header File

1. Right-click **Header Files** → **Add → New Item**
2. Choose **Header File (.h)** → Name it: `MathFunctions.h` → Click **Add**

```cpp
// MathFunctions.h
#pragma once

#ifdef MYMATHDLL_EXPORTS
#define MYMATH_API __declspec(dllexport)
#else
#define MYMATH_API __declspec(dllimport)
#endif

extern "C" {
    MYMATH_API int add(int a, int b);
    MYMATH_API int subtract(int a, int b);
}
```

> 🔹 `MYMATH_API` macro handles export/import
> 🔹 `extern "C"` is used to prevent C++ name mangling (optional but useful if interoperable)

#### Add a Source File

1. Right-click **Source Files** → **Add → New Item**
2. Choose **C++ File (.cpp)** → Name it: `MathFunctions.cpp` → Click **Add**

```cpp
// MathFunctions.cpp
#define MYMATHDLL_EXPORTS
#include "MathFunctions.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}
```

---

### ✅ Step 4: Build the DLL

1. Select **Build → Build Solution** (`Ctrl + Shift + B`)
2. You’ll get:

   * `MyMathDLL.dll` (runtime library)
   * `MyMathDLL.lib` (import library)
   * `MathFunctions.obj` (object file)

---

# 🧪 Part 2: Create a Console App to Use the DLL

### ✅ Step 5: Add a New Project to the Solution

1. Right-click on the **Solution** → **Add → New Project**
2. Choose **"Console App (C++)"**
3. Name it: `MathApp` → Click **Create**

---

### ✅ Step 6: Configure Console App to Use DLL

#### Add DLL Header File Reference

* Right-click `MathApp` → **Add → Existing Item**
* Browse to `MathFunctions.h` from DLL project → **Add As Link** (optional)

#### Add Reference to the `.lib` File

* Right-click `MathApp` → **Properties**
* Under **Linker → Input → Additional Dependencies**, add:

  ```
  MyMathDLL.lib
  ```

#### Add Include Path

* Go to **C/C++ → General → Additional Include Directories**

  * Add path to the folder containing `MathFunctions.h`

#### Add Library Path

* Go to **Linker → General → Additional Library Directories**

  * Add path to the folder containing `MyMathDLL.lib`

---

### ✅ Step 7: Write and Run the Application

**main.cpp**

```cpp
#include <iostream>
#include "MathFunctions.h"

int main() {
    std::cout << "Add: " << add(10, 5) << std::endl;
    std::cout << "Subtract: " << subtract(10, 5) << std::endl;
    return 0;
}
```

> ⚠️ Copy `MyMathDLL.dll` into the same directory as `MathApp.exe` (usually `x64/Debug/`)

---

### ✅ Step 8: Set MathApp as Startup Project

* Right-click `MathApp` → **Set as Startup Project**

---

### ✅ Step 9: Build and Run

* Press `Ctrl + F5`
* Output should be:

```
Add: 15
Subtract: 5
```

---

# 📦 Output Files from DLL Project

| File              | Purpose                            |
| ----------------- | ---------------------------------- |
| `MyMathDLL.dll`   | Dynamic library to be distributed  |
| `MyMathDLL.lib`   | Import library (used at link time) |
| `MathFunctions.h` | API exposed to users               |

---

# 🔄 Optional: Use `extern "C"` or not?

* **Use `extern "C"`** if:

  * You're calling from C
  * You want to avoid name mangling
* You can remove it if you're using only C++

---

# 🗂 Folder Structure (Summary)

```
MySolution/
├── MyMathDLL/
│   ├── MathFunctions.h
│   ├── MathFunctions.cpp
│   ├── x64/Debug/MyMathDLL.dll
│   └── x64/Debug/MyMathDLL.lib
└── MathApp/
    ├── main.cpp
    ├── x64/Debug/MathApp.exe
    └── (Copy MyMathDLL.dll here)
```

---

# 🧠 Summary: Steps to Create and Use DLL

| Task                        | Done |
| --------------------------- | ---- |
| Create DLL Project          | ✅    |
| Add `__declspec(dllexport)` | ✅    |
| Build `.dll` and `.lib`     | ✅    |
| Create Console App          | ✅    |
| Link `.lib`, copy `.dll`    | ✅    |
| Run successfully            | ✅    |

---

