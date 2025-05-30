---

# 📂 C++ File Handling: Complete Tutorial

---

## 📌 1. What is File Handling?

**File handling** in C++ refers to reading from and writing to files stored on disk. It enables programs to:

* Store data permanently (unlike variables that live only in memory)
* Retrieve data when needed
* Log program activities
* Share data between applications

---

## 🎯 2. Why is File Handling Used?

| Feature             | Description                                    |
| ------------------- | ---------------------------------------------- |
| **Persistence**     | Store data even after the program ends         |
| **Data Exchange**   | Exchange data between users or applications    |
| **Logging**         | Save program logs or error messages            |
| **Configuration**   | Read config files instead of hardcoding values |
| **Reports/Backups** | Save reports in text or binary files           |

---

## 🧬 3. File Stream Classes in C++

C++ provides file handling through **fstream library** which includes:

| Stream     | Purpose           | Header      |
| ---------- | ----------------- | ----------- |
| `ifstream` | Read from a file  | `<fstream>` |
| `ofstream` | Write to a file   | `<fstream>` |
| `fstream`  | Read & Write both | `<fstream>` |

---

## 📘 4. Syntax Basics

### 📄 Include the Header:

```cpp
#include <fstream>
```

### 📤 Writing to a File:

```cpp
ofstream outFile("example.txt");
outFile << "Hello, file!";
outFile.close();
```

### 📥 Reading from a File:

```cpp
ifstream inFile("example.txt");
string line;
while (getline(inFile, line)) {
    cout << line << endl;
}
inFile.close();
```

---

## 🧪 5. Example 1: Writing and Reading a File

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Writing to a file
    ofstream writer("data.txt");
    writer << "Welcome to C++ file handling.\n";
    writer << "This is a sample file.\n";
    writer.close();

    // Reading from the file
    ifstream reader("data.txt");
    string line;
    cout << "Contents of the file:\n";
    while (getline(reader, line)) {
        cout << line << endl;
    }
    reader.close();

    return 0;
}
```

---

## 🔄 6. Checking File Opening

You should always check if a file is opened successfully.

```cpp
ifstream file("input.txt");
if (!file.is_open()) {
    cerr << "Error opening file!" << endl;
}
```

---

## 📄 7. File Modes

File modes determine **how** a file is opened.

| Mode          | Description                            |
| ------------- | -------------------------------------- |
| `ios::in`     | Open for reading                       |
| `ios::out`    | Open for writing                       |
| `ios::app`    | Append to the end of file              |
| `ios::ate`    | Open and move to end of file           |
| `ios::trunc`  | Truncate (erase) the file if it exists |
| `ios::binary` | Open in binary mode                    |

### ✅ Example: Append Mode

```cpp
ofstream file("log.txt", ios::app);
file << "New log entry\n";
file.close();
```

---

## 💾 8. Binary File Handling

When working with non-text data (like structs, images), you use **binary mode**.

### 🧪 Example: Writing and Reading Struct in Binary

```cpp
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int id;
    char name[30];
};

int main() {
    Student s1 = {1, "Alice"};

    // Write binary data
    ofstream out("student.dat", ios::binary);
    out.write((char*)&s1, sizeof(s1));
    out.close();

    // Read binary data
    Student s2;
    ifstream in("student.dat", ios::binary);
    in.read((char*)&s2, sizeof(s2));
    in.close();

    cout << "ID: " << s2.id << ", Name: " << s2.name << endl;

    return 0;
}
```

---

## 📂 9. Real-Time Use Cases

| Use Case              | Description                                 |
| --------------------- | ------------------------------------------- |
| **Database Backup**   | Export user records to `.dat` or `.csv`     |
| **User Logs**         | Save logs for login/logout activities       |
| **System Config**     | Store and read settings in `.ini` or `.txt` |
| **Report Generation** | Export data reports to `.txt` or `.csv`     |
| **Game Save Data**    | Save progress using binary files            |

---

## 🧠 10. Key Concepts Summary

| Concept            | Explanation                                             |
| ------------------ | ------------------------------------------------------- |
| **Streams**        | Objects that allow reading/writing                      |
| **Text vs Binary** | Text is human-readable; Binary is raw memory            |
| **File Modes**     | Define how files are opened (read, write, append, etc.) |
| **Error Handling** | Check if file opened successfully                       |
| **close()**        | Always close files to flush buffer & release resources  |

---

## 🧪 11. Practice Problems

1. Write a program to save student names and marks in a text file.
2. Read a file containing numbers and calculate the sum.
3. Write a program to copy content from one file to another.
4. Implement a phone book using a binary file with `struct`.
5. Implement a login system that appends login times to a file.

---

## 🧾 12. Sample Project: Student Record System

### Features:

* Add student records to a file
* View all records
* Save and load from file

Would you like this mini-project as well?

---

## 📘 Final Thoughts

C++ file handling is essential for:

* Working with persistent data
* Logging and debugging
* Saving user state
* Interfacing with external tools

---

---

# 📂 Extended C++ File Handling Tutorial – Advanced Operations

### 🎯 Audience: Beginner to Intermediate

---

## 🧠 Quick Recap: File Streams

| Stream     | Purpose             |
| ---------- | ------------------- |
| `ifstream` | Reading from files  |
| `ofstream` | Writing to files    |
| `fstream`  | Reading and writing |

---

## 🚀 NEW SECTION: File Pointer Operations

### 🧭 Why Use File Pointers?

File pointer manipulation helps you:

* Navigate large files efficiently
* Jump to specific positions for editing or reading
* Work with fixed-format records (like in binary files)

---

## 📍 File Pointers: `tellg`, `tellp`, `seekg`, `seekp`

| Function  | Purpose                                      |
| --------- | -------------------------------------------- |
| `tellg()` | Get current **get pointer** (read) position  |
| `tellp()` | Get current **put pointer** (write) position |
| `seekg()` | Move the get pointer to a specific position  |
| `seekp()` | Move the put pointer to a specific position  |

---

### 🔎 `tellg()` and `seekg()` (For Reading)

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("sample.txt");

    if (fin.is_open()) {
        // Move to 5th byte from beginning
        fin.seekg(5, ios::beg);

        cout << "Current position (get pointer): " << fin.tellg() << endl;

        char ch;
        fin.get(ch);
        cout << "Character at position 5: " << ch << endl;

        fin.close();
    }
    return 0;
}
```

### 💡 `ios::beg`, `ios::cur`, `ios::end`

| Flag       | Meaning                |
| ---------- | ---------------------- |
| `ios::beg` | From beginning of file |
| `ios::cur` | From current position  |
| `ios::end` | From end of file       |

---

### 📝 `tellp()` and `seekp()` (For Writing)

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream fout("log.txt");
    fout << "1234567890"; // 10 characters
    cout << "Put pointer at: " << fout.tellp() << endl;

    fout.seekp(5, ios::beg); // Go to position 5
    fout << "X"; // Overwrite '6' with 'X'

    fout.close();
    return 0;
}
```

---

## 💾 Binary File Handling in Detail

When using **binary files**, you deal with raw bytes and must use:

* `write()` for output
* `read()` for input

These functions require **casting your object to `char*`**.

---

### 🧪 Binary Example with File Pointer

```cpp
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int roll;
    char name[20];
};

int main() {
    Student s1 = {101, "Alice"}, s2;

    // Write to binary file
    ofstream fout("student.dat", ios::binary);
    fout.write((char*)&s1, sizeof(s1));
    fout.close();

    // Read from binary file using seek
    ifstream fin("student.dat", ios::binary);
    fin.seekg(0, ios::beg); // Go to beginning

    // Tell position
    cout << "Reading from position: " << fin.tellg() << endl;

    fin.read((char*)&s2, sizeof(s2));
    cout << "Student Roll: " << s2.roll << ", Name: " << s2.name << endl;

    fin.close();
    return 0;
}
```

---

## 🔁 Practical Use Case: Update Record in Binary File

To **update** a specific record in a binary file (e.g., modify student info), we:

1. Locate the record using `seekp()`
2. Overwrite the record with `write()`

### 🛠️ Code: Update 2nd Student Record

```cpp
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int roll;
    char name[20];
};

int main() {
    Student s;

    // Updating the second record
    fstream file("students.dat", ios::in | ios::out | ios::binary);

    if (!file) {
        cerr << "Cannot open file.\n";
        return 1;
    }

    // Move to 2nd record (1-based index → index 1)
    file.seekp(sizeof(Student) * 1, ios::beg);

    Student updated = {202, "Bob"};

    file.write((char*)&updated, sizeof(updated));
    file.close();

    cout << "2nd record updated successfully.\n";
    return 0;
}
```

---

## 📐 Understanding File Sizes with `tellg()` and `seekg()`

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("sample.txt", ios::binary);
    file.seekg(0, ios::end); // Move to end
    cout << "File size: " << file.tellg() << " bytes\n";
    file.close();
    return 0;
}
```

---

## ✅ Summary Table: Common File Operations

| Operation            | Function                           |
| -------------------- | ---------------------------------- |
| Write text           | `ofstream << data;`                |
| Read text            | `ifstream >> data;` or `getline()` |
| Write binary         | `write((char*)&obj, sizeof(obj));` |
| Read binary          | `read((char*)&obj, sizeof(obj));`  |
| Get position (read)  | `tellg()`                          |
| Get position (write) | `tellp()`                          |
| Move read pointer    | `seekg(pos, base);`                |
| Move write pointer   | `seekp(pos, base);`                |
| Close file           | `close()`                          |
| Check if open        | `is_open()`                        |

---

## 🎯 Real-World Scenarios Using File Pointer Operations

| Scenario                          | Usage                                          |
| --------------------------------- | ---------------------------------------------- |
| Editing a specific line in a file | Use `seekp()` to go to that line/byte          |
| Implementing a database           | Use `seekg()` to locate and retrieve records   |
| Fixed-size record processing      | Calculate offset: `record_no * sizeof(record)` |
| Backup and restore tools          | Read entire file into memory using binary mode |
| Save game features in games       | Save/load structured binary data using structs |

---

## 🧪 Hands-On Practice Problems

1. Write a C++ program to read a file, jump to the 10th byte, and print the next 5 characters.
2. Implement a system that overwrites the Nth record in a binary file.
3. Write a program to display the file size using file pointers.
4. Create a file and write records using structs, then update a particular field using `seekp()`.

---

---

## 🔍 `seekg` vs `seekp`: Quick Overview

| Function  | Purpose                      | Applies to                            | Use with           |
| --------- | ---------------------------- | ------------------------------------- | ------------------ |
| `seekg()` | Move **get** (read) pointer  | `ifstream`, `fstream` (in read mode)  | Reading operations |
| `seekp()` | Move **put** (write) pointer | `ofstream`, `fstream` (in write mode) | Writing operations |

---

## 📌 WHEN TO USE `seekg()`

Use `seekg()` when you want to:

### ✅ 1. **Read from a specific byte/position in a file**

```cpp
ifstream fin("data.txt");
fin.seekg(10, ios::beg); // Go to 10th byte from start
```

### ✅ 2. **Jump to a record in a binary file**

```cpp
fin.seekg(record_number * sizeof(Record), ios::beg);
```

### ✅ 3. **Re-read a portion of the file after already reading past it**

```cpp
fin.seekg(0); // Go back to beginning
```

### ✅ 4. **Measure file size**

```cpp
fin.seekg(0, ios::end);
int size = fin.tellg(); // total bytes in file
```

---

## 📌 WHEN TO USE `seekp()`

Use `seekp()` when you want to:

### ✅ 1. **Overwrite part of a file at a specific location**

```cpp
ofstream fout("log.txt");
fout.seekp(5, ios::beg); // Move write pointer
fout << "X"; // Overwrites the 6th character
```

### ✅ 2. **Update a specific record in a binary file**

```cpp
fstream file("students.dat", ios::in | ios::out | ios::binary);
file.seekp(2 * sizeof(Student), ios::beg); // Jump to 3rd record
file.write((char*)&updated, sizeof(updated));
```

### ✅ 3. **Append or fix partially written files**

Sometimes you want to seek to the end or somewhere in between to resume writing.

---

## 🎯 Typical Use Case Scenarios

| Use Case                                   | Use `seekg` or `seekp`? |
| ------------------------------------------ | ----------------------- |
| Jump to a specific read location in a file | `seekg()`               |
| Find total file size                       | `seekg()` + `tellg()`   |
| Update an entry in a binary database file  | `seekp()`               |
| Rewind the file to read again              | `seekg()`               |
| Partially overwrite file contents          | `seekp()`               |

---

## 🧠 Tip: Dual Mode with `fstream`

If you're using `fstream` with both input and output, use **`seekg()` for reading** and **`seekp()` for writing**, even in the same program.

```cpp
fstream file("info.dat", ios::in | ios::out | ios::binary);

file.seekg(0, ios::end);
int filesize = file.tellg(); // reading

file.seekp(0, ios::beg);
file.write(...); // writing
```

---

## ❗ Important Notes

* Always ensure the file is **opened in the correct mode** (`binary`, `in`, `out`, `in | out`).
* For binary files, `seekg`/`seekp` is usually preferred over reading/writing line-by-line for performance and precision.
* `seekg()`/`seekp()` are **byte-based**, so positioning depends on the file content format.

---


