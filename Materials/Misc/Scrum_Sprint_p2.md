
Topics covered:

1. Overview of the system
2. Technologies to be used
3. Scrum setup (roles, artifacts)
4. Sprint plan for 8 days
5. Breakdown with C++ tasks per sprint
6. Learning and development strategy

---

## 🧩 1. Project Use Case: Employee Management System (EMS)

**Goal:** Build a console-based EMS that allows Admin and Employees to manage records.

### 🎯 Features:

* Admin can:

  * Add, edit, delete employees
  * View all records
  * Assign roles
  * Save/load data (file or DB)
* Employee can:

  * View & update their profile
  * View attendance/leaves

---

## 🛠 2. Technology Stack

| Layer           | Technology/Feature                              |
| --------------- | ----------------------------------------------- |
| Language        | C++14 or later                                  |
| Threading       | `std::thread`, `std::mutex`, `std::async`       |
| Containers      | `std::vector`, `std::map`, `std::unordered_map` |
| File I/O        | `fstream` for persistent storage                |
| Design Patterns | Singleton (for DB simulation), Factory          |
| OOP Concepts    | Classes, Inheritance, Polymorphism              |
| Build System    | CMake or Makefile                               |
| Testing         | Google Test (optional, if time permits)         |

---

## 👥 3. Scrum Setup

| Role          | Team Member Example                      |
| ------------- | ---------------------------------------- |
| Product Owner | Trainer or Project Lead                  |
| Scrum Master  | One team member responsible for tracking |
| Developers    | The learners/students (2–4 people)       |

### 📦 Artifacts:

* **Product Backlog**: High-level features/tasks
* **Sprint Backlog**: Tasks for the current sprint
* **Definition of Done**: Compilable, test-passed, meets feature requirement
* **Burn Down Chart** *(Optional)*: Tracks remaining work daily

---

## 🗓 4. 8-Day Sprint Plan

| Day | Activity                                                                |
| --- | ----------------------------------------------------------------------- |
| 1   | Kick-off, understand Scrum, EMS requirements, tech prep                 |
| 2   | Design class structure, backlog grooming, start Sprint 1 (Core classes) |
| 3   | Finish Sprint 1, start Sprint 2 (Admin module)                          |
| 4   | Complete Admin module, review and test                                  |
| 5   | Sprint 3: Employee module, multithreading for data access               |
| 6   | Sprint 4: File I/O, persistence, error handling                         |
| 7   | Integration testing, polishing UI (console), retrospective              |
| 8   | Final demo, feedback, knowledge sharing                                 |

---

## 🧱 5. Sample Sprint Backlogs with C++ Tasks

---

### 🏁 **Sprint 1: Class Design & Base Structure (1.5 Days)**

#### Goals:

* Learn C++ OOP concepts
* Set up class hierarchy

#### Tasks:

* Design classes: `Employee`, `Admin`, `EmployeeManager`
* Use `std::vector` to store employee data
* Implement class-based menu system

✅ **C++ Concepts**: Classes, Inheritance, STL containers

---

### 🛠 **Sprint 2: Admin Features (1.5 Days)**

#### Goals:

* Implement admin CRUD operations

#### Tasks:

* Add, modify, delete employee
* Display all employees using `std::map` for faster lookup
* Role-based access control

✅ **C++ Concepts**: Map, File I/O basics, Encapsulation

---

### 🧵 **Sprint 3: Multithreading + Employee Module (2 Days)**

#### Goals:

* Simulate concurrent access to employee database

#### Tasks:

* Use `std::mutex` to protect shared data
* Use `std::thread` to allow background saving
* Implement employee login and profile update

✅ **C++ Concepts**: `std::thread`, `std::lock_guard`, lambda functions

---

### 💾 **Sprint 4: File I/O and Integration (1.5 Days)**

#### Goals:

* Add save/load to/from file
* Final polishing

#### Tasks:

* Load employee data on startup
* Save on exit or periodically via background thread
* Add input validation and exception handling

✅ **C++ Concepts**: `fstream`, `std::exception`, RAII

---

## 📘 6. Learning Plan for the Team

Each morning starts with a **Daily Stand-up (15 mins)**:

* What did you do yesterday?
* What will you do today?
* Any blockers?

### 📚 Learning Materials

| Day | Focus Topic                | Resources or Practice          |
| --- | -------------------------- | ------------------------------ |
| 1   | C++ Classes & STL          | cppreference, GeeksForGeeks    |
| 2   | Inheritance & Polymorphism | Learn with sample EMS classes  |
| 3   | File I/O & Maps            | Practice saving records        |
| 4   | Threads & Mutex            | Basic threading demo           |
| 5   | Exception Handling         | Try-catch and error-safe input |
| 6   | Final Integration          | Combine all modules            |

---

## 🧪 Sample Code Snippet: Threaded Save Operation

```cpp
#include <thread>
#include <mutex>
#include <fstream>
#include <vector>

class Employee {
    //...
};

class EmployeeManager {
    std::vector<Employee> employees;
    std::mutex dataLock;

public:
    void saveToFile() {
        std::lock_guard<std::mutex> lock(dataLock);
        std::ofstream ofs("employees.txt");
        // Serialize and save employees
    }

    void startAutoSave() {
        std::thread([this]() {
            while (true) {
                std::this_thread::sleep_for(std::chrono::minutes(5));
                saveToFile();
            }
        }).detach();
    }
};
```

---

## 📈 Final Deliverables on Day 8

* Working EMS with Admin & Employee roles
* Multithreaded background saving
* Console UI
* Codebase using C++14/17 features
* Documentation:

  * Class Diagram (UML)
  * Sprint Summary
  * What was learned and improved

---
