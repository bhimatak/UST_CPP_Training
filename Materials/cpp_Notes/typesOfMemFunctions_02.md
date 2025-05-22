**real-world use case** in **C++** that demonstrates:

* `static` functions
* `const` member functions
* `friend` functions

---

### 💼 **Use Case: Bank Account Management System**

We’ll simulate a simplified bank account system where:

* Every account keeps track of the balance.
* A static function keeps track of the total number of accounts.
* A const function is used to safely view the balance.
* A friend function is used by an external auditor class to access private data.

---

### ✅ **Code Example**

```cpp
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string ownerName;
    double balance;
    static int totalAccounts;  // Static data member

public:
    // Constructor
    BankAccount(string name, double initialBalance) : ownerName(name), balance(initialBalance) {
        totalAccounts++;  // Update count when account is created
    }

    // Static function - doesn't depend on object
    static int getTotalAccounts() {
        return totalAccounts;
    }

    // Const function - guarantees not to modify object
    double getBalance() const {
        return balance;
    }

    // Member function
    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    // Friend function declaration
    friend void auditAccount(const BankAccount& acc);
};

// Initialize static member
int BankAccount::totalAccounts = 0;

// Friend function definition
void auditAccount(const BankAccount& acc) {
    cout << "Audit Report\n";
    cout << "Owner: " << acc.ownerName << "\n";
    cout << "Balance: $" << acc.balance << "\n";
}

// Main function to test
int main() {
    BankAccount acc1("Alice", 1500.0);
    BankAccount acc2("Bob", 2300.5);

    acc1.deposit(500);
    acc2.deposit(200);

    cout << "Total accounts: " << BankAccount::getTotalAccounts() << "\n";

    cout << "Alice's Balance (via const function): $" << acc1.getBalance() << "\n";
    cout << "Bob's Balance (via const function): $" << acc2.getBalance() << "\n";

    // Friend function accessing private members
    auditAccount(acc1);
    auditAccount(acc2);

    return 0;
}
```

---

### 🔍 **Explanation of Key Concepts**

| Concept           | Where It’s Used      | Purpose                                                        |
| ----------------- | -------------------- | -------------------------------------------------------------- |
| `static` function | `getTotalAccounts()` | Returns total number of accounts; works at class level.        |
| `const` function  | `getBalance() const` | Ensures balance is read-only in this context.                  |
| `friend` function | `auditAccount()`     | External function accessing private `ownerName` and `balance`. |

---

### 📘 Summary

* Use `**static functions**` when the logic doesn't depend on any specific object instance.
* Use `**const functions**` to guarantee that your function won’t alter the object.
* Use `**friend functions**` carefully when an external function or class needs controlled access to private members.


