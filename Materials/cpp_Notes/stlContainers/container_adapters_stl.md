
---

# C++ STL Container Adapters – Complete Tutorial

---

## 1. Theory: What are Container Adapters?

* **Container adapters** are wrappers around existing container classes that provide a **restricted interface**.
* They provide **specific data structures** by adapting underlying containers like `deque`, `vector`, or `list`.
* Unlike regular containers (`vector`, `list`, `set`), container adapters **do not expose iterators**.
* They restrict operations to only those relevant for the data structure they implement.

---

## 2. Types of Container Adapters

| Adapter Name     | Description                         | Underlying Default Container | Usage                               |
| ---------------- | ----------------------------------- | ---------------------------- | ----------------------------------- |
| `stack`          | Last-In-First-Out (LIFO) structure  | `deque` (by default)         | Backtracking, Undo, Syntax parsing  |
| `queue`          | First-In-First-Out (FIFO) structure | `deque` (by default)         | Task scheduling, Print queue        |
| `priority_queue` | Elements sorted by priority         | `vector` (by default)        | Event simulation, Scheduling, Heaps |

---

## 3. Why Use Container Adapters?

* To **simplify the interface** for common data structures.
* To **prevent access to irrelevant operations** (e.g., no random access on stack).
* To **guarantee data structure behavior** (LIFO for stack, FIFO for queue).
* Often used in algorithms where these abstract data types are required.

---

## 4. Syntax and Basic Operations

### Stack

```cpp
#include <stack>

std::stack<int> stk;

stk.push(10);      // Insert element at top
stk.pop();         // Remove top element
int top = stk.top(); // Access top element
bool empty = stk.empty(); // Check if stack is empty
size_t size = stk.size(); // Number of elements
```

### Queue

```cpp
#include <queue>

std::queue<int> q;

q.push(10);        // Insert element at back
q.pop();           // Remove front element
int front = q.front(); // Access front element
int back = q.back();   // Access back element
bool empty = q.empty();
size_t size = q.size();
```

### Priority Queue

```cpp
#include <queue>

std::priority_queue<int> pq;

pq.push(10);       // Insert element
pq.pop();          // Remove top (largest by default)
int top = pq.top();   // Access top element
bool empty = pq.empty();
size_t size = pq.size();
```

---

## 5. Complete Example Code Demonstrating All Adapters

```cpp
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <functional> // For std::greater

int main() {
    // Stack example (LIFO)
    std::stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    std::cout << "Stack top: " << stk.top() << "\n"; // 30
    stk.pop();
    std::cout << "Stack top after pop: " << stk.top() << "\n"; // 20

    // Queue example (FIFO)
    std::queue<std::string> q;
    q.push("Alice");
    q.push("Bob");
    q.push("Charlie");
    std::cout << "\nQueue front: " << q.front() << "\n"; // Alice
    std::cout << "Queue back: " << q.back() << "\n";    // Charlie
    q.pop();
    std::cout << "Queue front after pop: " << q.front() << "\n"; // Bob

    // Priority queue example (max-heap by default)
    std::priority_queue<int> pq;
    pq.push(40);
    pq.push(10);
    pq.push(30);
    pq.push(20);
    std::cout << "\nPriority queue top (max): " << pq.top() << "\n"; // 40
    pq.pop();
    std::cout << "Priority queue top after pop: " << pq.top() << "\n"; // 30

    // Min-heap priority queue example using std::greater
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
    min_pq.push(40);
    min_pq.push(10);
    min_pq.push(30);
    min_pq.push(20);
    std::cout << "\nMin-heap priority queue top: " << min_pq.top() << "\n"; // 10

    return 0;
}
```

---

## 6. Sample Output

```
Stack top: 30
Stack top after pop: 20

Queue front: Alice
Queue back: Charlie
Queue front after pop: Bob

Priority queue top (max): 40
Priority queue top after pop: 30

Min-heap priority queue top: 10
```

---

## 7. Real-World Use Cases

* **Stack**
  Undo mechanisms, expression evaluation, backtracking algorithms (e.g., maze solving).

* **Queue**
  Task scheduling, breadth-first search (BFS) in graphs, print queue management.

* **Priority Queue**
  Dijkstra’s shortest path algorithm, event-driven simulation, job scheduling based on priority.

---

## 8. Summary Table

| Adapter          | Behavior                             | Underlying Container | Use Case Example                |
| ---------------- | ------------------------------------ | -------------------- | ------------------------------- |
| `stack`          | LIFO                                 | `deque`              | Undo functionality              |
| `queue`          | FIFO                                 | `deque`              | Task scheduling                 |
| `priority_queue` | Priority-based (max heap by default) | `vector`             | Shortest path, event simulation |

---

