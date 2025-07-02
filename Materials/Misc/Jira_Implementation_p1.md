
Topics covered:

---

### ✅ OVERVIEW OF WHAT YOU'LL DO:

1. ✅ Create a Jira Account and Project
2. 🧩 Set it up for Scrum
3. 🗂️ Create Product Backlog (Stories/Tasks)
4. 🗓️ Plan Sprints (8 days → \~2 sprints)
5. 📌 Track Daily Work (Scrum board + stand-ups)
6. 📈 Review progress (Burn-down chart, sprint report)
7. 🎯 Deliver & Retrospect

---

## 🧭 STEP-BY-STEP GUIDE

---

## 1️⃣ Create Your Jira Account & Project

### A. Create Account

1. Go to: 🌐 [https://www.atlassian.com/software/jira](https://www.atlassian.com/software/jira)
2. Click **Get it Free** → Select **Jira Software Cloud**.
3. Sign up using your **email** (you can use Gmail).
4. Name your **site** (e.g., `ems-team.atlassian.net`)

---

### B. Create a New Project

1. Click **Projects → Create project**
2. Choose **Scrum** template
3. Name it: **Employee Management System**
4. Key: EMS (e.g., EMS-1, EMS-2...)

✅ Done! You're now inside your Scrum project.

---

## 2️⃣ Understand Jira Layout

| Section      | Purpose                            |
| ------------ | ---------------------------------- |
| **Backlog**  | Add user stories, plan sprints     |
| **Board**    | View and move tasks (To Do → Done) |
| **Reports**  | Burn-down charts, Sprint report    |
| **People**   | Add team members                   |
| **Releases** | Mark versions/releases             |

---

## 3️⃣ Add Product Backlog (Tasks)

These are the **main features** we discussed. Add them as **Stories** or **Tasks**.

➡ Go to **Backlog → Create Issue → Story**

Here's a sample breakdown:

| Issue Type | Summary                  | Description                              |
| ---------- | ------------------------ | ---------------------------------------- |
| Epic       | Admin Module             | All admin-related features               |
| Story      | Add employee feature     | Admin should be able to add new employee |
| Story      | Modify employee          | Admin can edit records                   |
| Story      | Delete employee          | Admin can delete employee                |
| Epic       | Employee Module          | Login, update profile                    |
| Story      | Employee login           | Employee can login securely              |
| Story      | View profile             | View own details                         |
| Epic       | Persistence              | Save/load employee data                  |
| Story      | Save to file             | Store employee list in file              |
| Story      | Auto-save (thread)       | Use background thread to save data       |
| Task       | Design Class Diagram     | UML & C++ class design                   |
| Task       | Implement multithreading | Use std::thread + mutex                  |

💡 Use **Epics** to group features (Admin, Employee, Threading)

---

## 4️⃣ Create Sprint (8-day cycle)

1. Go to **Backlog**
2. Click **Create Sprint**
3. Drag 5–6 stories/tasks into the sprint
4. Click **Start Sprint**

   * Name: Sprint 1
   * Duration: 8 days (or 2 sprints of 4 days each)

---

## 5️⃣ Track Daily Progress (Scrum Board)

Go to **Board** to see:

| Status      | Description              |
| ----------- | ------------------------ |
| To Do       | Planned, but not started |
| In Progress | Work has begun           |
| Done        | Completed and verified   |

### 🗣️ Daily Scrum Stand-up

Ask:

* What did you do yesterday?
* What will you do today?
* Any blockers?

Update each Jira card accordingly (move across the board).

---

## 6️⃣ Monitor with Reports

Go to **Reports** (left menu):

* 📉 **Burn-down chart** – how much work is left
* 📊 **Sprint report** – what was done, what was not
* 📈 **Velocity chart** – how fast your team is delivering

---

## 7️⃣ Sprint Review & Retrospective

At end of Sprint:

* Show working C++ modules
* Mark stories done/not done
* Go to **Reports → Sprint Report**
* Then click **Complete Sprint**

Create a new Sprint for remaining work.

---

## 📋 Sample Sprint 1 Plan (First 4 days)

| Task                     | Jira ID | Assignee | Status      |
| ------------------------ | ------- | -------- | ----------- |
| Design base classes      | EMS-1   | Bhima    | In Progress |
| Implement Employee class | EMS-2   | Bhima    | To Do       |
| Implement Admin CRUD     | EMS-3   | Bhima    | To Do       |
| Test class structure     | EMS-4   | Bhima    | To Do       |

---

## 📎 Optional: Setup Automation

Jira lets you:

* Auto-assign tasks when moved
* Auto-close tasks when PR is merged (via GitHub)

---

## 💡 Tips for Learning Jira as a Beginner

1. Start with only 5–6 issues and 1 Sprint
2. Practice moving cards across board
3. Use filters like “My Open Issues”
4. Use the mobile app for quick updates

---

## 🔗 BONUS – Predefined CSV Import Template

You can also bulk import stories/tasks using a CSV like:

```csv
Summary,Issue Type,Description
"Add Employee","Story","Admin adds a new employee"
"Delete Employee","Story","Admin removes employee"
"Threaded Save","Story","Save employee data using std::thread"
```

---
