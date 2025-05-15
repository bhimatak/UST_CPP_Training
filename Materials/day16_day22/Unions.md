  
---

## 🧠 What is a Union in C++?

A **union** is a user-defined type similar to a **struct**, but with a key difference:

> **All members of a union share the same memory location.**

This means a union can store **only one of its members at a time**.

---

## 🧬 Syntax of Union

```cpp
union Data {
    int i;
    float f;
    char c;
};
```

Each member overlays the same memory block.

---

## 📊 Memory Layout Example

```cpp
union Data {
    int i;      // 4 bytes
    float f;    // 4 bytes
    char c;     // 1 byte
};
```

* Total size = size of the **largest** member: **4 bytes**
* `c`, `i`, and `f` share the same memory location.
* Changing one member will overwrite the other.

---

## 🧪 Sample Code Demonstrating Behavior

```cpp
#include <iostream>
using namespace std;

union Data {
    int i;
    float f;
    char c;
};

int main() {
    Data d;
    d.i = 65;
    cout << "d.i = " << d.i << endl;
    d.c = 'B'; // Overwrites `i`
    cout << "d.c = " << d.c << endl;
    cout << "d.i after c = " << d.i << endl; // Data corrupted

    return 0;
}
```

🔍 Output:

```
d.i = 65
d.c = B
d.i after c = 66
```

---

## 🆚 Difference Between `struct` and `union`

| Feature  | `struct`                              | `union`                                  |
| -------- | ------------------------------------- | ---------------------------------------- |
| Memory   | Members have **separate** memory      | Members **share** same memory            |
| Size     | Sum of all members (+padding)         | Size of the **largest** member           |
| Use Case | Group unrelated data                  | Hold one of many possible data types     |
| Access   | All members can be used independently | Only one member should be used at a time |

---

## 📌 Real-Time Use Cases of Unions

### 1. **Variant Data Types (Tagged Union / Discriminated Union)**

Used to store different data types under a single variable.

```cpp
enum TypeTag { INT, FLOAT, CHAR };

struct Variant {
    TypeTag type;
    union {
        int i;
        float f;
        char c;
    } data;
};
```

🔍 **Use Case**: JSON parser, configuration files, or scripting languages.

---

### 2. **Memory Optimization in Embedded Systems**

Unions are great where memory is tight (e.g., 8-bit microcontrollers).

```cpp
union SensorData {
    uint16_t analogValue;
    uint8_t bytes[2];
};
```

🔍 **Use Case**: Transmitting 2-byte sensor data over I2C/SPI as 2 `uint8_t`.

---

### 3. **Interpreting Raw Memory (Type-Punning)**

Accessing the same memory as different types—commonly in **device drivers** or **networking**.

```cpp
union IP {
    uint32_t addr;
    uint8_t bytes[4];
};

void printIP(IP ip) {
    cout << (int)ip.bytes[0] << "."
         << (int)ip.bytes[1] << "."
         << (int)ip.bytes[2] << "."
         << (int)ip.bytes[3] << "\n";
}
```

🔍 **Use Case**: Decoding IPv4 address.

---

### 4. **Network Packet Interpreters / Protocol Headers**

Parsing binary packets received from a network.

```cpp
struct PacketHeader {
    uint8_t type;
    union {
        uint16_t length;
        uint32_t sequence;
    };
};
```

🔍 **Use Case**: TCP/IP stack implementation or custom protocol parsers.

---

### 5. **Union with Structs and Bitfields**

Useful for bit manipulation or accessing hardware registers.

```cpp
union Register {
    uint8_t value;
    struct {
        uint8_t bit0 : 1;
        uint8_t bit1 : 1;
        uint8_t bit2 : 1;
        uint8_t reserved : 5;
    } bits;
};
```

🔍 **Use Case**: Microcontroller I/O register manipulation.

---

## ⚠️ Important Notes on Using Unions

* Only **one member** should be active at a time.
* Do **not access an inactive member** (undefined behavior).
* C++17 introduced `std::variant` as a **type-safe alternative** to unions.

---

## 🆕 C++11/14/17 Additions for Unions

| Version | Feature                     | Description                              |
| ------- | --------------------------- | ---------------------------------------- |
| C++11   | Non-trivial types in unions | Unions can have constructors/destructors |
| C++11   | Anonymous unions in classes | Can use union members directly           |
| C++17   | `std::variant`              | Type-safe tagged union                   |

---

## ✅ Summary

* A union stores **one member at a time**.
* Saves memory and is useful for **variant types** and **low-level manipulation**.
* Real-time usage in **protocols, embedded systems, and binary data parsing**.
* For **modern C++**, consider `std::variant` for type-safe alternatives.

---

  
---

### Union Memory Layout Example:

```cpp
union Data {
    int i;      // 4 bytes
    float f;    // 4 bytes
    char c;     // 1 byte
};
```

---

### Memory Representation (All members share the same memory):

```
+----+----+----+----+
| i  | i  | i  | i  |   <-- int (4 bytes)
| f  | f  | f  | f  |   <-- float (4 bytes, same location as int)
| c  |    |    |    |   <-- char (1 byte, same first byte)
+----+----+----+----+
Address:  0    1    2    3
```

* `i` and `f` occupy **all 4 bytes** starting at offset 0.
* `c` occupies the **first byte** only (byte 0).
* Changing `c` overwrites the first byte of `i` and `f`.
* The total size of the union is equal to the size of its largest member (here, 4 bytes).

---

### Visual Diagram:

```
+----------------------------------+
| Union Data (4 bytes total)        |
+----------------------------------+
| Byte 0 | Byte 1 | Byte 2 | Byte 3|
+----------------------------------+
|   c    |        |        |       |  <-- char c uses Byte 0 only
|   i    |   i    |   i    |   i   |  <-- int i uses all 4 bytes
|   f    |   f    |   f    |   f   |  <-- float f uses all 4 bytes
+----------------------------------+
```

---
