Great! Let's walk through the **quadratic equation root-finding process** step by step with **theory**, **formula**, and a **visual breakdown**.

---

## 🔷 **Quadratic Equation Basics**

A **quadratic equation** is in the form:

$$
ax^2 + bx + c = 0
$$

Where:

* $a \neq 0$
* $b$ and $c$ are constants
* $x$ is the variable

---

## 🔷 **Roots of the Quadratic Equation**

To find the roots of the equation, we use the **quadratic formula**:

$$
x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}
$$

Let:

$$
D = b^2 - 4ac
$$

Here, $D$ is called the **discriminant**, and it determines the nature of the roots.

---

## 🔶 **Case-wise Breakdown Based on Discriminant $D$**

### ✅ **Case 1: $D > 0$** — Real and Distinct Roots

* Square root of D is real and positive.
* Two real, different roots:

  $$
  x_1 = \frac{-b + \sqrt{D}}{2a}, \quad x_2 = \frac{-b - \sqrt{D}}{2a}
  $$

🔹 Example:
Input: $a = 1, b = -5, c = 6$
$D = 25 - 24 = 1$
Roots: $x = 3, x = 2$

---

### ✅ **Case 2: $D = 0$** — Real and Equal Roots

* Square root of D is zero.
* One real root repeated twice:

  $$
  x = \frac{-b}{2a}
  $$

🔹 Example:
Input: $a = 1, b = -2, c = 1$
$D = 4 - 4 = 0$
Root: $x = 1$ (double root)

---

### ✅ **Case 3: $D < 0$** — Complex Roots

* Square root of D is imaginary.
* Roots are **complex conjugates**:

  $$
  x_1 = \frac{-b}{2a} + i \frac{\sqrt{-D}}{2a}, \quad
  x_2 = \frac{-b}{2a} - i \frac{\sqrt{-D}}{2a}
  $$

🔹 Example:
Input: $a = 1, b = 2, c = 5$
$D = 4 - 20 = -16$
Roots: $-1 + 2i, -1 - 2i$

---

## 📊 Diagram: Discriminant Decision Tree

Would you like me to generate a **diagram/flowchart** showing this decision process visually (e.g., a flowchart for how the code decides which type of root to compute)?
