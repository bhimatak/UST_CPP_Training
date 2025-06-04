

---

# Practice Problems on Container Adapters

---

### 1. **Browser History Navigation (Stack)**

**Problem:**
Simulate a browser’s back and forward buttons using two stacks.

* When the user visits a new URL, push it onto the “back” stack and clear the “forward” stack.
* When the user clicks "Back," pop the current page from the “back” stack and push it to the “forward” stack.
* When the user clicks "Forward," pop the top page from the “forward” stack back to the “back” stack.

**Input:**
A sequence of commands:

* `"visit <URL>"`
* `"back"`
* `"forward"`

**Output:**
Print the current URL after each command.

---

### 2. **Print Job Scheduling (Queue)**

**Problem:**
You have a queue of print jobs. Each job has a user name and a number of pages. Print jobs are processed in order, but if a job exceeds 10 pages, it should be split into chunks of 10 pages and processed as multiple jobs.

**Input:**
A list of print jobs in the format: `<username> <pages>`

**Output:**
Print the order in which jobs are processed, showing the user and pages printed per chunk.

---

### 3. **Task Priority Scheduler (Priority Queue)**

**Problem:**
You need to schedule tasks based on their priority. Each task has a string description and a priority integer. Process tasks starting with the highest priority first.

**Input:**
A list of tasks with descriptions and priority values.

**Output:**
Print tasks in order of execution.

---

### 4. **Balanced Parentheses Checker (Stack)**

**Problem:**
Given a string containing characters '(', ')', '{', '}', '\[' and ']', check if the parentheses are balanced using a stack.

**Input:**
A string expression.

**Output:**
Print `"Balanced"` or `"Not Balanced"`.

---

### 5. **Emergency Room Queue (Priority Queue with Custom Comparator)**

**Problem:**
Patients arrive at the emergency room. Each patient has a name, age, and severity score. Patients with higher severity are treated first. If severity is the same, older patients have higher priority.

**Input:**
List of patients in format: `<name> <age> <severity>`

**Output:**
Print patients in order of treatment.

---



## **Sample input and output test cases**  

---

# 1. Browser History Navigation (Stack)

### Sample Input:

```
visit google.com
visit stackoverflow.com
back
visit github.com
back
forward
forward
```

### Expected Output:

```
Current page: google.com
Current page: stackoverflow.com
Current page: google.com
Current page: github.com
Current page: google.com
Current page: github.com
Current page: github.com
```

### Explanation:

* Visit google.com → back stack = \[google.com], forward stack empty
* Visit stackoverflow\.com → back = \[google.com, stackoverflow\.com], forward cleared
* Back → move stackoverflow\.com to forward stack, current is google.com
* Visit github.com → back = \[google.com, github.com], forward cleared
* Back → move github.com to forward stack, current google.com
* Forward → move github.com back to back stack, current github.com
* Forward → no forward pages left, stays github.com

---

# 2. Print Job Scheduling (Queue)

### Sample Input:

```
Alice 15
Bob 8
Charlie 23
```

### Expected Output:

```
Processing: Alice 10 pages
Processing: Alice 5 pages
Processing: Bob 8 pages
Processing: Charlie 10 pages
Processing: Charlie 10 pages
Processing: Charlie 3 pages
```

---

# 3. Task Priority Scheduler (Priority Queue)

### Sample Input:

```
FixBug 5
ImplementFeature 8
CodeReview 3
Deploy 8
```

### Expected Output:

```
Execute: ImplementFeature with priority 8
Execute: Deploy with priority 8
Execute: FixBug with priority 5
Execute: CodeReview with priority 3
```

---

# 4. Balanced Parentheses Checker (Stack)

### Sample Input 1:

```
{[()]}
```

### Output 1:

```
Balanced
```

### Sample Input 2:

```
{[(])}
```

### Output 2:

```
Not Balanced
```

---

# 5. Emergency Room Queue (Priority Queue with Custom Comparator)

### Sample Input:

```
John 65 5
Alice 70 5
Bob 30 7
Eve 40 5
```

### Expected Output:

```
Treating: Bob, Age: 30, Severity: 7
Treating: Alice, Age: 70, Severity: 5
Treating: John, Age: 65, Severity: 5
Treating: Eve, Age: 40, Severity: 5
```

---

# Summary Table of Test Cases

| Problem No. | Test Input                     | Expected Output Description                       |
| ----------- | ------------------------------ | ------------------------------------------------- |
| 1           | visit/back/forward commands    | Current URL printed after each command            |
| 2           | Users and print page counts    | Print jobs split in chunks of max 10 pages        |
| 3           | Tasks and priorities           | Tasks executed in descending priority order       |
| 4           | Parentheses string             | Balanced or Not Balanced                          |
| 5           | Patients with age and severity | Patients treated by severity, then age descending |

---


