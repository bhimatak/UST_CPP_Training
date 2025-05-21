

---

## 🚀 **Day 13: Operator Overloading & Functors (C++14/17 Deep Dive)**

---

### 🔷 1. What Is Operator Overloading?

C++ lets you redefine how **operators** (`+`, `-`, `==`, etc.) work for **user-defined types**.

For example, what if you want to **add two complex numbers** using `+` instead of calling `.add()`?

```cpp
Complex c1(2, 3), c2(4, 5);
Complex c3 = c1 + c2; // 👈 This is operator overloading
```

---

### 🔧 2. Syntax of Operator Overloading

Inside your class:

```cpp
ReturnType operatorOp(const ClassName& other);
```

Example:

```cpp
class Point {
    int x, y;
public:
    Point(int x_, int y_) : x(x_), y(y_) {}

    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};
```

```cpp
int main() {
    Point p1(1, 2), p2(3, 4);
    Point p3 = p1 + p2;
    p3.display();  // Output: (4, 6)
}
```

---

### 📊 Diagram: Operator Overloading Logic

```
p1: (1, 2)
p2: (3, 4)
p1 + p2 → operator+(p1, p2) → new Point(4, 6)
```

---

### 🔷 3. Commonly Overloaded Operators

| Operator | Use Case                            |
|----------|--------------------------------------|
| `+ - * /`| Arithmetic with custom types         |
| `== !=`  | Comparisons                          |
| `[]`     | Indexing for container-like classes  |
| `()`     | Functors – callable objects          |
| `<< >>`  | Stream I/O for easy output/input     |
| `->`     | Smart pointers                       |

---

### 🔶 4. Real-World Example: Complex Number Class

```cpp
class Complex {
    double real, imag;
public:
    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};
```

```cpp
int main() {
    Complex c1(2.5, 3.5), c2(1.5, 2.0);
    Complex c3 = c1 + c2;
    cout << c3 << endl; // Output: 4 + 5.5i
}
```

---

### 🔷 5. Overloading `==` and `!=`

```cpp
bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
}
```

This allows:

```cpp
if (p1 == p2) cout << "Equal!";
```

---

### 🔷 6. Functors: Overloading the `()` Operator

A **functor** is an object that acts like a function.

```cpp
class Adder {
    int val;
public:
    Adder(int v) : val(v) {}

    int operator()(int x) const {
        return x + val;
    }
};
```

```cpp
Adder add5(5);
cout << add5(10); // Output: 15
```

Functors are widely used in STL (`std::sort`, predicates, etc.).

---

### 🔥 Real-World Use Case: Custom Sort with Functor

```cpp
struct Compare {
    bool operator()(int a, int b) {
        return a > b; // Descending
    }
};

vector<int> v = {3, 1, 4, 2};
sort(v.begin(), v.end(), Compare());
```

---

### ⚙️ 7. Overloading `[]` – Like Arrays!

```cpp
class Array {
    int data[10];
public:
    int& operator[](int index) {
        return data[index];
    }
};
```

```cpp
Array arr;
arr[3] = 10;
cout << arr[3];
```

---

### 🔷 8. Best Practices

✅ Return **const references** or values appropriately  
✅ Use `const` correctness  
✅ Don’t overuse: maintain readability  
✅ Be consistent with built-in operator behavior

---

### 🧠 Design Tip: Combine Operator Overloading with Templates

You can make your class **generic** and still support overloading:

```cpp
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}

    Box operator+(const Box& other) {
        return Box(value + other.value);
    }
};
```

---

### 🛠️ Hands-On Exercise

1. Create a `Vector2D` class
2. Overload:
   - `+`, `-` (vector addition/subtraction)
   - `*` (scalar multiplication)
   - `==`
   - `<<` for easy printing

3. Make a functor class `Multiplier` that multiplies a number by a stored factor

---

### 📚 Homework

- Implement a `Rational` class for fractions
  - Overload `+`, `-`, `*`, `/`
  - Reduce to lowest terms
  - Add `==` and stream output support

---

### 💡 Summary Table

| Operator     | Purpose                       |
|--------------|-------------------------------|
| `+`, `-`, `*`| Arithmetic                     |
| `==`, `!=`   | Comparison                     |
| `[]`         | Indexing                      |
| `()`         | Functors (callable objects)   |
| `<<`, `>>`   | I/O Streams                    |

---

