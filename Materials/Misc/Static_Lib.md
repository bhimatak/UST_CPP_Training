**complete step-by-step tutorial** on how to **create and use a Static Library in C++ using Visual Studio 2022**.

---

## 🎯 Objective:

You will learn to:

1. Create a static library (`.lib`).
2. Create a separate application project that uses this `.lib`.
3. Link and run the application using the library.

---

## ✅ Part 1: Create a Static Library Project

### Step 1: Open Visual Studio 2022

* Start **Visual Studio 2022**.
* Select **"Create a new project"**.

### Step 2: Choose "Static Library"

* In the search bar, type **"Static Library"**.
* Choose **"Static Library (C++)"**.
* Click **Next**.

### Step 3: Configure Your Project

* **Project Name**: `MyMathLib` (or anything you like).
* **Location**: Choose your folder.
* **Solution**: Select “Create new solution” (for now).
* Click **Create**.

### Step 4: Add Header and Source Files

Let’s assume we want to create math operations like add, subtract, etc.

#### Step 4.1: Add Header File

1. Right-click on **Header Files** → **Add → New Item**.
2. Choose **Header File (.h)**.
3. Name it `MathFunctions.h` and click **Add**.

**Code inside `MathFunctions.h`:**

```cpp
#pragma once

int add(int a, int b);
int subtract(int a, int b);
```

#### Step 4.2: Add Source File

1. Right-click on **Source Files** → **Add → New Item**.
2. Choose **C++ File (.cpp)**.
3. Name it `MathFunctions.cpp` and click **Add**.

**Code inside `MathFunctions.cpp`:**

```cpp
#include "MathFunctions.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}
```

### Step 5: Build the Library

1. Select **Build → Build Solution** (`Ctrl + Shift + B`).
2. Output window will show a `.lib` file being created:

   ```
   ...\x64\Debug\MyMathLib.lib
   ```

🎉 You have successfully created a static library!

---

## ✅ Part 2: Create a Console App That Uses This Library

### Step 6: Add New Project to Same Solution

1. In Solution Explorer: **Right-click on the Solution** → **Add → New Project**.
2. Choose **Console App (C++)**.
3. Name it `MathApp`.
4. Click **Create**.

### Step 7: Add Reference to Static Library

1. Right-click on `MathApp` project → **Add → Project Reference**.
2. Check the box next to `MyMathLib`.
3. Click **OK**.

### Step 8: Include Header and Use Library Functions

Replace `main.cpp` content of `MathApp` with:

```cpp
#include <iostream>
#include "../MyMathLib/MathFunctions.h"  // Update path if needed

int main() {
    int x = 10, y = 5;

    std::cout << "Add: " << add(x, y) << std::endl;
    std::cout << "Subtract: " << subtract(x, y) << std::endl;

    return 0;
}
```

> 🔺 Note: If the header file path is incorrect, right-click on **MathApp → Properties → C/C++ → General → Additional Include Directories** and add:

```
$(SolutionDir)MyMathLib
```

### Step 9: Set MathApp as Startup Project

Right-click `MathApp` → **Set as Startup Project**

### Step 10: Build and Run

1. Press `Ctrl + F5` or click **Debug → Start Without Debugging**.
2. Output should be:

```
Add: 15
Subtract: 5
```

---

## 🛠 Optional: Build Configurations

You can build in **Release** mode:

* On the top menu, change **Debug** → **Release** and build again.

The `.lib` file will be generated in:

```
...\x64\Release\MyMathLib.lib
```

---

## 📦 Summary

| Task                             | Done |
| -------------------------------- | ---- |
| Create static library project    | ✅    |
| Add functions in `.h`/`.cpp`     | ✅    |
| Build to generate `.lib`         | ✅    |
| Create console app project       | ✅    |
| Add reference and include header | ✅    |
| Link and run the executable      | ✅    |

---

## 🧠 Tips

* Static libraries are linked **at compile time**.
* They do **not require external files** at runtime (unlike DLLs).
* Use **project references** to avoid hardcoding library paths.

---

