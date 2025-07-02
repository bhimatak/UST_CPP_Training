
---

# ✅ 1. 📁 **CSV Template for Jira Import (Stories, Tasks)**

You can **bulk import this CSV** into Jira and save time manually creating each story.

### 🧾 Sample CSV (Copy into Excel or Google Sheets and export as CSV)

```csv
Summary,Issue Type,Description,Priority,Epic Link
Design Class Structure,Task,"Design core classes for Employee and Admin",High,Architecture
Implement Employee Class,Story,"Employee class with attributes and methods",Medium,Architecture
Implement Admin Class,Story,"Admin class with CRUD capabilities",Medium,Admin Module
Add Employee Functionality,Story,"Admin adds new employee record",High,Admin Module
Delete Employee Functionality,Story,"Admin deletes employee by ID",High,Admin Module
Modify Employee Record,Story,"Admin modifies employee details",High,Admin Module
View All Employees,Story,"Admin views complete list",Medium,Admin Module
Employee Login Feature,Story,"Employee can login using ID/password",High,Employee Module
Update Own Profile,Story,"Employee can update their info",Medium,Employee Module
File Save (Manual),Story,"Save data to file using std::ofstream",High,Persistence
Auto Save Threaded,Story,"Use std::thread to auto-save every X min",High,Multithreading
Thread Safety with Mutex,Story,"Use std::mutex for thread-safe access",High,Multithreading
Test Core Modules,Task,"Write unit tests for base classes",Medium,Testing
Final Integration,Story,"Link all modules together",High,Final Build
```

> 🔁 **How to Import in Jira**:
>
> * Go to **Jira > Project > Issues > Import Issues from CSV**
> * Upload the file, map fields like `Summary`, `Issue Type`, etc.

---

# ✅ 2. 🧱 **Epic/Story Structure for Jira (Readable Outline)**

```markdown
## 🔵 Epics and Their Stories

### 🔹 Epic: Architecture
- Story: Design Class Structure
- Story: Implement Employee Class
- Story: Implement Admin Class

### 🔹 Epic: Admin Module
- Story: Add Employee Functionality
- Story: Delete Employee Functionality
- Story: Modify Employee Record
- Story: View All Employees

### 🔹 Epic: Employee Module
- Story: Employee Login Feature
- Story: Update Own Profile

### 🔹 Epic: Persistence
- Story: File Save (Manual)
- Story: Auto Save Threaded

### 🔹 Epic: Multithreading
- Story: Auto Save Threaded
- Story: Thread Safety with Mutex

### 🔹 Epic: Testing
- Task: Test Core Modules

### 🔹 Epic: Final Build
- Story: Final Integration
```

You can create these Epics manually in Jira (just create a new issue → select "Epic"), then link the Stories to them using the "Epic Link" field.

---

# ✅ 3. 🖼️ Visual Scrum Board Template (like Trello or Physical Jira Board)

You can replicate this in Jira's **Board view**. Here’s how the statuses work visually:

```plaintext
+------------------+------------------+------------------+
|     TO DO        |   IN PROGRESS    |      DONE        |
+------------------+------------------+------------------+
| Design Classes   | Implement Admin  | Design Complete  |
| Add Employee     | Login Feature    |                  |
| Save to File     |                  |                  |
+------------------+------------------+------------------+
```

> You move each card/story from **To Do → In Progress → Done** as you work on it.

---

# ✅ 4. 📋 Daily Checklist Template (for Sprint Tracking)

Here’s a simple **Daily Scrum Standup Checklist** (you can do this in Jira comments or separately in Notion/Excel):

| Date  | Member | What I Did Yesterday        | What I’ll Do Today    | Blockers         |
| ----- | ------ | --------------------------- | --------------------- | ---------------- |
| Day 1 | Bhima  | Setup project, studied Jira | Start class structure | None             |
| Day 2 | Bhima  | Wrote Employee class        | Start Admin module    | File save format |
| ...   | ...    | ...                         | ...                   | ...              |

---

# ✅ 5. 💼 Project Folder Structure for EMS (in C++)

```plaintext
EMS_Project/
│
├── src/
│   ├── main.cpp
│   ├── employee.cpp
│   ├── admin.cpp
│   ├── manager.cpp
│
├── include/
│   ├── employee.hpp
│   ├── admin.hpp
│   ├── manager.hpp
│
├── threads/
│   ├── autosave.cpp
│
├── tests/
│   ├── test_employee.cpp
│
├── data/
│   └── employees.txt
│
├── CMakeLists.txt
└── README.md
```

---

# ✅ 6. 🚀 Sprint Plan for 8 Days (Split to 2 Sprints)

## 🏁 Sprint 1 (Days 1–4)

| Jira ID | Story                      | Owner | Est. Time |
| ------- | -------------------------- | ----- | --------- |
| EMS-1   | Design Class Structure     | Bhima | 1d        |
| EMS-2   | Implement Employee Class   | Bhima | 1d        |
| EMS-3   | Add/Delete/Modify Employee | Bhima | 1.5d      |
| EMS-4   | View All Employees         | Bhima | 0.5d      |

## 🏁 Sprint 2 (Days 5–8)

| Jira ID | Story                    | Owner | Est. Time |
| ------- | ------------------------ | ----- | --------- |
| EMS-5   | Login and Profile Update | Bhima | 1d        |
| EMS-6   | File Save + Auto Save    | Bhima | 1.5d      |
| EMS-7   | Thread Safety + Mutex    | Bhima | 1d        |
| EMS-8   | Integration Testing      | Bhima | 0.5d      |

---

