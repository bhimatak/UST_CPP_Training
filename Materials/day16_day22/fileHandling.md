  
---

# File Handling in C++

## 1. Introduction to File Handling

**File handling** is the process of reading from and writing data to files stored on a disk. It is essential for persistent data storage beyond the lifetime of a program's execution.

C++ provides powerful **file I/O (Input/Output)** capabilities through its Standard Library, primarily via the `<fstream>` header.

---

## 2. Key Concepts

* **File stream classes**:

  * `ifstream`: Input file stream — for reading files.
  * `ofstream`: Output file stream — for writing files.
  * `fstream`: File stream — for both reading and writing.
* **File modes**:

  * `ios::in` — open for reading.
  * `ios::out` — open for writing.
  * `ios::app` — append to the end.
  * `ios::binary` — open in binary mode.
  * `ios::trunc` — truncate file to zero length if it exists.
  * `ios::ate` — open and seek to end immediately.

---

## 3. Opening and Closing Files

### Opening a file:

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream ofs("example.txt"); // Open for writing
    if (!ofs) {
        cerr << "Error opening file for writing\n";
        return 1;
    }
    
    // Write to file
    ofs << "Hello, File Handling!\n";
    
    ofs.close(); // Close file
    return 0;
}
```

---

## 4. Reading from a File

```cpp
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream ifs("example.txt");  // Open for reading
    if (!ifs) {
        cerr << "Error opening file for reading\n";
        return 1;
    }

    string line;
    while (getline(ifs, line)) {  // Read line by line
        cout << line << endl;
    }
    
    ifs.close();
    return 0;
}
```

---

## 5. Writing to a File

```cpp
#include <fstream>
using namespace std;

int main() {
    ofstream ofs("example.txt", ios::app); // Append mode
    if (!ofs) {
        cerr << "Error opening file\n";
        return 1;
    }

    ofs << "Appending a new line!\n";

    ofs.close();
    return 0;
}
```

---

## 6. Using `fstream` for Read/Write

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    fstream fs("example.txt", ios::in | ios::out | ios::app);
    if (!fs) {
        cerr << "Error opening file\n";
        return 1;
    }

    fs << "Adding via fstream!\n";  // Writing

    fs.seekg(0);  // Go back to beginning for reading
    string line;
    while (getline(fs, line)) {
        cout << line << endl;
    }

    fs.close();
    return 0;
}
```

---

## 7. Binary File Handling

Binary files store data in a raw format and are used for images, audio, or custom file formats.

### Writing binary data:

```cpp
#include <fstream>
using namespace std;

struct Employee {
    int id;
    char name[20];
};

int main() {
    Employee emp = {101, "Alice"};
    
    ofstream ofs("employee.dat", ios::binary);
    if (!ofs) {
        cerr << "Cannot open file\n";
        return 1;
    }

    ofs.write(reinterpret_cast<char*>(&emp), sizeof(emp));
    ofs.close();
    return 0;
}
```

### Reading binary data:

```cpp
#include <fstream>
#include <iostream>
using namespace std;

struct Employee {
    int id;
    char name[20];
};

int main() {
    Employee emp;
    
    ifstream ifs("employee.dat", ios::binary);
    if (!ifs) {
        cerr << "Cannot open file\n";
        return 1;
    }

    ifs.read(reinterpret_cast<char*>(&emp), sizeof(emp));
    cout << "ID: " << emp.id << ", Name: " << emp.name << endl;

    ifs.close();
    return 0;
}
```

---

## 8. Error Handling and File State Checks

Important methods to check file status:

* `is_open()`: Checks if file is successfully opened.
* `eof()`: Checks if end-of-file reached.
* `fail()`: Checks for failure in last operation.
* `good()`: Checks if stream is good for I/O.

Example:

```cpp
ifstream ifs("file.txt");
if (!ifs.is_open()) {
    cerr << "Failed to open file\n";
}
```

---

## 9. Random Access in Files

Files can be read/written at arbitrary positions using:

* `seekg(pos)`: Set input position.
* `seekp(pos)`: Set output position.
* `tellg()`: Get current input position.
* `tellp()`: Get current output position.

Example:

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    fstream fs("example.txt", ios::in | ios::out);
    if (!fs) {
        cerr << "File open error\n";
        return 1;
    }

    // Move write pointer to end
    fs.seekp(0, ios::end);
    fs << "\nNew line at end.";

    // Move read pointer to beginning
    fs.seekg(0);
    string line;
    while (getline(fs, line)) {
        cout << line << endl;
    }

    fs.close();
    return 0;
}
```

---

## 10. Best Practices

* Always check if file opens successfully.
* Use RAII pattern with file stream objects for automatic closing.
* Prefer binary mode for non-text data.
* Flush output with `flush()` or on stream close.
* Avoid mixing C-style `FILE*` and C++ file streams.
* Handle exceptions (`std::ios_base::failure`) if using exception-enabled streams.

---

## 11. Advanced: File Locking and Concurrency

Standard C++ does not provide built-in file locking — this is platform-specific.

* On POSIX systems: Use `fcntl()` or `flock()`.
* On Windows: Use `LockFile()` APIs.

---

## Summary Table:

| Operation        | Class/Method           | Mode Flags    |            |
| ---------------- | ---------------------- | ------------- | ---------- |
| Open for reading | `ifstream`             | `ios::in`     |            |
| Open for writing | `ofstream`             | `ios::out`    |            |
| Read/write both  | `fstream`              | \`ios::in     | ios::out\` |
| Append           | any with `ios::app`    | `ios::app`    |            |
| Binary mode      | any with `ios::binary` | `ios::binary` |            |

---

  
---

# Advanced File Handling in C++

## 1. File Parsing — Reading Structured Data

When reading files with structured data (like CSV, logs, config files), you often parse line-by-line and extract tokens.

### Example: Parsing a CSV File

Suppose you have a file `data.csv` with this content:

```
101,John,5000
102,Alice,6000
103,Bob,4500
```

We want to read each line and extract employee data (ID, Name, Salary).

```cpp
#include <fstream>
#include <iostream>
#include <sstream>  // for std::istringstream
#include <string>
using namespace std;

int main() {
    ifstream file("data.csv");
    if (!file) {
        cerr << "Could not open file.\n";
        return 1;
    }

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string idStr, name, salaryStr;

        if (getline(ss, idStr, ',') &&
            getline(ss, name, ',') &&
            getline(ss, salaryStr, ',')) {
            
            int id = stoi(idStr);
            double salary = stod(salaryStr);

            cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << '\n';
        }
    }

    file.close();
    return 0;
}
```

---

## 2. Exception Handling with File Streams

C++ file streams can throw exceptions if configured.

### Enabling exceptions:

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream file;
    file.exceptions(ifstream::failbit | ifstream::badbit);

    try {
        file.open("nonexistent.txt");
        string content;
        file >> content;
    }
    catch (const ios_base::failure& e) {
        cerr << "Exception opening/reading file: " << e.what() << endl;
    }

    return 0;
}
```

* `failbit` triggers on logical errors (e.g., fail to open).
* `badbit` triggers on serious errors (hardware failure, etc).
* Catch exceptions derived from `std::ios_base::failure`.

---

## 3. Reading/Writing Complex Data Structures

### Writing multiple records of a struct in binary:

```cpp
#include <fstream>
#include <iostream>
using namespace std;

struct Employee {
    int id;
    char name[20];
    double salary;
};

int main() {
    Employee employees[3] = {
        {101, "John", 5000.0},
        {102, "Alice", 6000.0},
        {103, "Bob", 4500.0}
    };

    ofstream ofs("employees.bin", ios::binary);
    if (!ofs) {
        cerr << "Cannot open file for writing.\n";
        return 1;
    }

    ofs.write(reinterpret_cast<char*>(employees), sizeof(employees));
    ofs.close();
    return 0;
}
```

### Reading those records back:

```cpp
#include <fstream>
#include <iostream>
using namespace std;

struct Employee {
    int id;
    char name[20];
    double salary;
};

int main() {
    Employee employees[3];

    ifstream ifs("employees.bin", ios::binary);
    if (!ifs) {
        cerr << "Cannot open file for reading.\n";
        return 1;
    }

    ifs.read(reinterpret_cast<char*>(employees), sizeof(employees));

    for (const auto& emp : employees) {
        cout << "ID: " << emp.id << ", Name: " << emp.name << ", Salary: " << emp.salary << '\n';
    }

    ifs.close();
    return 0;
}
```

---

## 4. Tips for Complex Data File Handling

* Always match `write()` and `read()` with exact same struct layout and sizes.
* Be cautious with padding in structs (use `#pragma pack` or `alignas` if needed).
* For portability, consider serializing data in a text format (e.g., JSON, XML).
* For large files, consider buffered I/O or memory-mapped files (platform dependent).
* Use `std::getline` and string streams to safely parse textual data.

---

## 5. Bonus: Reading Large Files Efficiently

When reading very large files:

* Process line-by-line rather than loading the whole file.
* Use buffer streams (`std::ifstream` already buffered).
* For binary data, read in chunks (e.g., arrays of structs) instead of single records.

---

