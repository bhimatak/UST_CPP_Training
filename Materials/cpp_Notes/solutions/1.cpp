// Problem 1: Academic Result Management
#include <iostream>
using namespace std;

class Student {
protected:
    int rollNo;
    string name;
    int age;
public:
    Student(int r, string n, int a) : rollNo(r), name(n), age(a) {}
    void display() {
        cout << "Student Info:\n";
        cout << "Roll No: " << rollNo << "\nName: " << name << "\nAge: " << age << endl;
    }
};

class Marks : public Student {
    int m1, m2, m3;
    int total;
    float avg;
public:
    Marks(int r, string n, int a, int a1, int a2, int a3) : Student(r, n, a), m1(a1), m2(a2), m3(a3) {
        calculate();
    }
    void calculate() {
        total = m1 + m2 + m3;
        avg = total / 3.0;
    }
    void display(bool full) {
        if (!full) Student::display();
        else {
            cout << "\nFull Result:\n";
            cout << "Total Marks: " << total << "\nAverage Marks: " << avg << endl;
        }
    }
};

// Problem 2: Employee Salary Calculation
class Employee {
protected:
    int empId;
    string name;
public:
    Employee(int id, string n) : empId(id), name(n) {}
};

class Developer : virtual public Employee {
protected:
    int codingHours;
public:
    Developer(int id, string n, int hrs) : Employee(id, n), codingHours(hrs) {}
};

class Manager : virtual public Employee {
protected:
    int teamSize;
public:
    Manager(int id, string n, int size) : Employee(id, n), teamSize(size) {}
};

class TechLead : public Developer, public Manager {
public:
    TechLead(int id, string n, int hrs, int size)
        : Employee(id, n), Developer(id, n, hrs), Manager(id, n, size) {}

    void calculateSalary() {
        cout << "\nTech Lead Info:\nEmpId: " << empId << "\nName: " << name << endl;
        int base = codingHours * 500;
        cout << "\nSalary based on coding: \u20B9" << base << endl;
    }

    void calculateSalary(bool includeTeam) {
        if (includeTeam) {
            int total = codingHours * 500 + teamSize * 5000;
            cout << "Salary based on coding + team: \u20B9" << total << endl;
        }
    }
};

// Problem 3: Vehicle Rental System
class Vehicle {
protected:
    string vehicleId;
    string type;
    int ratePerKm;
public:
    Vehicle(string id, string t, int rate) : vehicleId(id), type(t), ratePerKm(rate) {}
};

class Car : public Vehicle {
public:
    Car(string id, string t, int rate) : Vehicle(id, t, rate) {}
    void calculateFare(int distance) {
        cout << "Fare without discount: \u20B9" << distance * ratePerKm << endl;
    }
    void calculateFare(int distance, int days) {
        float fare = distance * ratePerKm;
        if (days > 2) fare *= 0.9;
        cout << "Fare with long-term discount: \u20B9" << fare << endl;
    }
};

// Problem 4: Library Management
class Book {
protected:
    string bookId, title;
public:
    Book(string id, string t) : bookId(id), title(t) {}
};

class Publisher {
protected:
    string name, city;
public:
    Publisher(string n, string c) : name(n), city(c) {}
};

class LibraryItem : public Book, public Publisher {
public:
    LibraryItem(string id, string t, string n, string c)
        : Book(id, t), Publisher(n, c) {}
    void displayDetails() {
        cout << "\nLibrary Entry:\n";
        cout << "Book ID: " << bookId << "\nTitle: " << title;
        cout << "\nPublisher: " << name << "\nCity: " << city << endl;
    }
};

// Problem 5: University Placement Analysis
class Department {
protected:
    string deptName;
    int numberOfStudents;
public:
    Department(string name, int count) : deptName(name), numberOfStudents(count) {}
};

class Placement : public Department {
    int placed;
public:
    Placement(string name, int total, int p) : Department(name, total), placed(p) {}

    void placementStats() {
        float percent = (placed * 100.0) / numberOfStudents;
        cout << "\nDepartment: " << deptName;
        cout << "\nPlacement Percentage: " << percent << "%" << endl;
    }

    void placementStats(bool gap) {
        if (gap) {
            int notPlaced = numberOfStudents - placed;
            cout << "Placement Gap: " << notPlaced << " students" << endl;
        }
    }
};

// main()
int main() {
    // Problem 1
    Marks m1(101, "Alice", 20, 89, 76, 91);
    m1.display(false);
    m1.display(true);

    // Problem 2
    TechLead t1(501, "Rajesh", 120, 5);
    t1.calculateSalary();
    t1.calculateSalary(true);

    // Problem 3
    Car c1("C100", "Car", 15);
    c1.calculateFare(100);
    c1.calculateFare(100, 3);

    // Problem 4
    LibraryItem l1("B123", "Modern C++", "Pearson", "New Delhi");
    l1.displayDetails();

    // Problem 5
    Placement p1("CSE", 120, 98);
    p1.placementStats();
    p1.placementStats(true);

    return 0;
}
