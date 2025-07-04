
---

# 📘 **CMake Tutorial for Visual Studio 2022**

---

## 🔧 **1. What is CMake?**

CMake is a cross-platform build system generator. It does **not build** your code directly, but **generates** build files (e.g., Visual Studio solutions or Makefiles) that are then used by compilers or IDEs.

* CMake supports multiple platforms (Windows, Linux, macOS).
* It's widely used in C++ projects.
* It works with Visual Studio, Make, Ninja, Xcode, etc.

---

## 📁 **2. Directory Structure (Recommended)**

Always keep your source and build files separate.

```
/MyProject
│
├── CMakeLists.txt
├── src/
│   └── main.cpp
└── build/
```

---

## 💡 **3. Install Tools**

### ✅ Requirements:

* **Visual Studio 2022** with the following components:

  * Desktop development with C++
  * CMake tools for Windows
* **CMake** (comes bundled with Visual Studio 2022, but you can also install [from official site](https://cmake.org/download/))

---

## 🚀 **4. Basic Hello World with CMake**

### 🔸 main.cpp

```cpp
#include <iostream>

int main() {
    std::cout << "Hello from CMake!" << std::endl;
    return 0;
}
```

---

### 🔸 CMakeLists.txt (minimum)

```cmake
cmake_minimum_required(VERSION 3.20)  # Minimum required CMake version

project(MyProject)  # Project name

add_executable(MyApp src/main.cpp)  # Output binary and source files
```

---

## 🛠️ **5. Step-by-Step: Build with CMake in Visual Studio 2022**

### 🔹 Option A: Open folder directly

1. **Open Visual Studio 2022**
2. Click on **"File → Open → Folder..."**
3. Choose the folder containing `CMakeLists.txt`
4. Visual Studio will detect CMake and configure the project automatically.
5. To build:

   * Go to **Build → Build All**
6. To run:

   * Go to **Debug → Start Without Debugging**

---

### 🔹 Option B: Manually configure with CMake GUI

1. Open **CMake GUI**
2. **Source code**: Path to your project folder (with `CMakeLists.txt`)
3. **Build directory**: A separate folder, e.g., `build/`
4. Click **Configure**

   * Choose **Visual Studio 17 2022** as generator
   * Select **x64** or **Win32**
5. Click **Generate**
6. Open the generated `.sln` file in Visual Studio
7. Build and run as usual

---

## 📖 **6. Detailed Syntax Explained**

### 🔹 `cmake_minimum_required(VERSION 3.20)`

* Ensures compatibility with features available in version 3.20+
* Always put this at the top

### 🔹 `project(MyProject VERSION 1.0 LANGUAGES CXX)`

* Sets the project name and version
* `LANGUAGES` defines programming languages used

### 🔹 `add_executable(MyApp src/main.cpp)`

* Builds an executable named `MyApp`
* Can also accept multiple `.cpp` files or `*.cpp`

```cmake
add_executable(MyApp
    src/main.cpp
    src/utils.cpp
    src/logic.cpp
)
```

---

### 🔹 `add_library(...)`

Used when you want to build a **library** instead of an executable.

```cmake
add_library(MyLib STATIC src/mylib.cpp)
# STATIC = .lib (default)
# SHARED = .dll
```

---

### 🔹 `target_include_directories(...)`

Specify include directories for header files.

```cmake
target_include_directories(MyApp PRIVATE include)
```

* `PRIVATE`: Only this target
* `PUBLIC`: This and anything linking against it
* `INTERFACE`: Only consumers, not this target

---

### 🔹 `target_link_libraries(...)`

Link your app to external libraries.

```cmake
target_link_libraries(MyApp PRIVATE MyLib)
```

---

## 📦 **7. Build Types**

CMake supports different build types:

```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake -DCMAKE_BUILD_TYPE=Release ..
```

With Visual Studio:

* You select the build type (Debug/Release) inside Visual Studio's drop-down.

---

## ⚙️ **8. Common CMake Options**

| Option                     | Description                               |
| -------------------------- | ----------------------------------------- |
| `-G`                       | Generator (e.g., "Visual Studio 17 2022") |
| `-S`                       | Source directory                          |
| `-B`                       | Build directory                           |
| `-DCMAKE_BUILD_TYPE=Debug` | Build type for non-MSVC generators        |
| `-DVAR=VALUE`              | Set CMake variable                        |

**Example:**

```bash
cmake -G "Visual Studio 17 2022" -A x64 -S . -B build
```

---

## 📌 **9. CMake Presets (Optional for VS 2022)**

Modern versions support **presets**. Add a `CMakePresets.json` in the root.

```json
{
  "version": 3,
  "cmakeMinimumRequired": {
    "major": 3,
    "minor": 20
  },
  "configurePresets": [
    {
      "name": "default",
      "generator": "Ninja",
      "binaryDir": "${sourceDir}/build"
    }
  ]
}
```

Visual Studio 2022 uses these automatically when present.

---

## 🔍 **10. Debugging Tips in Visual Studio**

* Use **CMake Output** pane (View → Output → CMake)
* Add breakpoints in your source files
* Use **Start Debugging** or **F5** to debug

---

## 📘 **11. Recommended CMake Practices**

* Always use out-of-source builds (keep build dir separate)
* Avoid hardcoding paths
* Use `target_*` commands instead of global ones (e.g., `include_directories`)
* Use variables wisely: `set(MY_SOURCES ...)`

---

## 📚 **12. Resources**

* 📘 [CMake Documentation](https://cmake.org/cmake/help/latest/)
* 📗 [Modern CMake Book](https://cliutils.gitlab.io/modern-cmake/)
* 🎥 YouTube: Search *“CMake Visual Studio tutorial”*

---
