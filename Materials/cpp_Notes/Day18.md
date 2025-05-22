

---

## ⚠️ **Day 18: Exception Handling + RAII (Resource Acquisition Is Initialization)**

---

### 🔷 1. The Need for Exception Handling

Programs fail. Maybe it’s a file that doesn’t exist, invalid user input, memory errors, or division by zero. In traditional C, you'd return error codes. In C++, we raise **exceptions**, which help us **separate the error handling logic from regular logic**.

---

### ✅ 2. Basic Try-Catch in C++

```cpp
try {
    // Risky code
    throw runtime_error("Something went wrong!");
} catch (const exception& e) {
    cout << "Caught error: " << e.what() << endl;
}
```

#### 🔥 Multiple Catch Blocks:

```cpp
try {
    // logic...
} catch (const out_of_range& e) {
    cout << "Out of range: " << e.what();
} catch (const exception& e) {
    cout << "Generic error: " << e.what();
}
```

#### 💡 `throw` inside functions:

```cpp
void divide(int a, int b) {
    if (b == 0) throw invalid_argument("Divide by zero");
    cout << a / b << endl;
}
```

---

### 💥 3. Exception Safety Levels

| Level                | Meaning                                                 |
|----------------------|---------------------------------------------------------|
| No-throw guarantee   | Nothing fails, ever (rare)                              |
| Strong guarantee     | Either operation succeeds or state is unchanged         |
| Basic guarantee      | No leaks, but state may be inconsistent                 |

You aim for at least **basic**, ideally **strong** safety.

---

### 🧠 Real-World Scenario 1: File Handling

```cpp
ifstream file("data.txt");
if (!file) throw runtime_error("File not found");

// Read safely
string line;
while (getline(file, line)) {
    cout << line << endl;
}
```

---

### 🔧 4. RAII – The Modern Way

**RAII** = Resource Acquisition Is Initialization

- Allocate in constructor
- Release in destructor
- Leverage **automatic object lifetime**

```cpp
class FileHandler {
    ifstream file;
public:
    FileHandler(const string& filename) {
        file.open(filename);
        if (!file) throw runtime_error("Cannot open file!");
    }

    ~FileHandler() {
        cout << "Closing file...\n";
        file.close();
    }

    void read() {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
    }
};
```

#### 🔥 Usage:

```cpp
try {
    FileHandler f("notes.txt");
    f.read();
} catch (const exception& e) {
    cout << "Error: " << e.what();
}
```

Boom. No memory leaks. No open file handles. **RAII saves the day.**

---

### 🧩 5. Exception Safety with Smart Pointers

Smart pointers use RAII internally.

```cpp
void useResource() {
    unique_ptr<int> p = make_unique<int>(100);
    if (*p > 50)
        throw runtime_error("Too big!");
    // Memory still freed when exception occurs
}
```

---

### 🏗️ 6. Real-World Scenario 2: Database Connection Class

```cpp
class DBConnection {
public:
    DBConnection() {
        cout << "Connecting to DB..." << endl;
        // simulate db connection
    }

    ~DBConnection() {
        cout << "Disconnecting DB..." << endl;
    }

    void query(const string& q) {
        if (q.empty()) throw runtime_error("Empty query!");
        cout << "Running: " << q << endl;
    }
};

void runQuery() {
    DBConnection db;
    db.query("SELECT * FROM users");
}
```

RAII here makes sure even if an exception occurs in `query()`, the destructor will still run and clean up.

---

### 🧠 Real-World Scenario 3: Lock Guards (RAII in Multi-threading)

```cpp
mutex m;

void update() {
    lock_guard<mutex> lock(m); // Auto-locks on construction
    // Safe thread access
}  // Unlocks automatically on destruction
```

Imagine doing this manually and forgetting to unlock — you're looking at a **deadlock** 💀. RAII handles this beautifully.

---

### 🔄 7. Custom RAII Resource Wrapper

Let’s build our own simplified RAII manager.

```cpp
class Buffer {
    char* data;
public:
    Buffer(size_t size) {
        data = new char[size];
        cout << "Buffer acquired\n";
    }

    ~Buffer() {
        delete[] data;
        cout << "Buffer released\n";
    }

    void write(const char* msg) {
        strcpy(data, msg);
    }
};
```

---

### 💣 8. Best Practices for Exception Handling

- Always catch exceptions **by reference**
- Prefer standard exceptions (`std::runtime_error`, `std::logic_error`, etc.)
- Don't catch what you can't handle
- RAII-friendly classes make exception-safe code easier

---

### 📌 Summary Table

| Feature          | Purpose                        |
|------------------|--------------------------------|
| `try-catch`      | Handle runtime exceptions      |
| `throw`          | Raise an exception             |
| RAII             | Resource safety via destructors|
| `ifstream`, etc. | Use RAII-based system classes  |
| `smart_ptr`      | Auto memory management         |
| `lock_guard`     | Auto mutex management          |

---

### 📚 Exercises

1. Build a `Logger` class that writes to a file. Ensure:
   - The file is properly closed on exception
   - It uses RAII internally
2. Write a `TransactionManager` that:
   - Throws on invalid balance
   - Uses `shared_ptr` to track active clients
3. Implement exception-safe resource allocation with `unique_ptr` for buffers

---

### 🛠 Homework Project

Build a small **File Copy Utility**:

- Input: source + destination filenames
- Uses `ifstream` + `ofstream`
- Exception-safe with RAII
- Custom `FileManager` class using RAII internally

---

### 🔮 Up Next: **Day 19 – Templates Deep Dive: Functions, Classes & Type Traits**

Templates are the **lifeblood** of STL and generic programming in C++. Next, we’ll crack open how templates enable reusable, type-safe code—plus some tricks like **SFINAE** and **`enable_if`**.

---

