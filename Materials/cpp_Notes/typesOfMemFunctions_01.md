
1. **Static Function**
2. **Const Function**
3. **Friend Function**

---

## ✅ 1. Static Function – *Real-world Use Case: Tracking Total Number of Objects*

### 📘 Use Case:

In a banking system, every time an account is created, we want to track how many accounts exist — **regardless of the specific account instance**.

### 🔢 Code Example:

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    static int accountCount;  // Static member variable

public:
    BankAccount() {
        accountCount++;       // Increment count when object is created
    }

    static int getAccountCount() { // Static function
        return accountCount;       // Accesses static member
    }
};

// Definition of static member outside the class
int BankAccount::accountCount = 0;

int main() {
    BankAccount acc1;
    BankAccount acc2;
    BankAccount acc3;

    // Static function called using class name
    cout << "Total number of accounts: " << BankAccount::getAccountCount() << endl;

    return 0;
}
```

### 📘 Explanation:

* `accountCount` is shared across all objects.
* `getAccountCount()` is a static function — it doesn't need an object to be called.
* Perfect for tracking **class-wide information**.

---

## ✅ 2. Const Function – *Real-world Use Case: Read-Only Access to Data*

### 📘 Use Case:

Users should be able to **view their balance**, but not modify it accidentally during the call.

### 🔢 Code Example:

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    double getBalance() const {  // Const member function
        return balance;          // Ensures no modification to object
    }

    void deposit(double amount) {
        balance += amount;
    }
};

int main() {
    BankAccount acc(1000.0);
    acc.deposit(500.0);

    // Call to const function
    cout << "Current balance: $" << acc.getBalance() << endl;

    return 0;
}
```

### 📘 Explanation:

* `getBalance()` is marked `const` — it promises **not to change the object’s state**.
* Helps when dealing with **read-only operations** or **const references to objects**.

---

## ✅ 3. Friend Function – *Real-world Use Case: External Audit Tool Accessing Private Data*

### 📘 Use Case:

An **Auditor** (external to the BankAccount class) needs read access to **private members** for reporting.

### 🔢 Code Example:

```cpp
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string name, double bal) : accountHolder(name), balance(bal) {}

    // Friend function declaration
    friend void auditReport(const BankAccount& acc);
};

// Friend function definition
void auditReport(const BankAccount& acc) {
    cout << "[AUDIT REPORT]" << endl;
    cout << "Account Holder: " << acc.accountHolder << endl;
    cout << "Balance: $" << acc.balance << endl;
}

int main() {
    BankAccount acc("Alice", 2500.0);

    // Friend function accessing private members
    auditReport(acc);

    return 0;
}
```

### 📘 Explanation:

* `auditReport()` is a **non-member** function that can **access private members**.
* Useful when a class needs to **grant selective access** to another function or class without exposing everything.


---

## ✅ **Friend Function Between Two Different Classes**

### 📘 Real-world Use Case:

An **Auditor** class needs access to **private data** from a `BankAccount` class for verification — but `Auditor` is not a member of `BankAccount`.

---

### 🔢 **Code Example:**

```cpp
#include <iostream>
#include <string>
using namespace std;

class BankAccount;  // Forward declaration

class Auditor {
public:
    void verifyAccount(const BankAccount& acc);  // Regular member function
};

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string name, double bal) : accountHolder(name), balance(bal) {}

    // Grant Auditor::verifyAccount access to private members
    friend void Auditor::verifyAccount(const BankAccount& acc);
};

// Member function of Auditor that is a friend of BankAccount
void Auditor::verifyAccount(const BankAccount& acc) {
    cout << "[Auditor Report]\n";
    cout << "Account Holder: " << acc.accountHolder << endl;
    cout << "Balance: $" << acc.balance << endl;
}

int main() {
    BankAccount acc("John Doe", 3200.75);
    Auditor auditor;

    auditor.verifyAccount(acc);  // Accesses private members of BankAccount

    return 0;
}
```

---

### 📘 Explanation:

| Concept                    | Role                                                                       |
| -------------------------- | -------------------------------------------------------------------------- |
| `friend void Auditor::...` | Grants a **specific method** in another class access to private data.      |
| `Auditor::verifyAccount()` | Can directly access `BankAccount`’s private `accountHolder` and `balance`. |
| `forward declaration`      | Required before defining `Auditor::verifyAccount()` as a friend.           |

---

### 🧠 Key Notes:

* You can grant friendship to:

  * An entire class (e.g., `friend class Auditor;`)
  * A **specific method** of another class, as done above.
* This maintains encapsulation while allowing **controlled access**.

---


