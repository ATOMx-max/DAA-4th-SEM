# 📊 DAA Project: Finding Maximum and Minimum (Divide & Conquer)

## 📌 Overview

This project implements an efficient algorithm to find the **maximum** and **minimum** elements in an array using the **Divide and Conquer** technique.

The program also counts the **number of comparisons** performed, helping analyze the algorithm’s efficiency.

---

## 🚀 Features

* Uses **Divide & Conquer** approach
* Calculates both **maximum and minimum** in a single traversal
* Tracks **total number of comparisons**
* Generates a **random array** for testing

---

## 🧠 Algorithm Used

The algorithm recursively divides the array into smaller parts:

1. **Base Case 1:**
   If the array has 1 element → max = min

2. **Base Case 2:**
   If the array has 2 elements → 1 comparison

3. **Recursive Case:**

   * Split array into two halves
   * Recursively find max & min for each half
   * Combine results using 2 comparisons

---

## 📈 Time Complexity

* **Best Case:** O(n)
* **Worst Case:** O(n)
* **Average Case:** O(n)

---

## 🔢 Comparison Analysis

* For even `n`:
  T(n) ≈ (3n/2) − 2

* For odd `n`:
  Slightly more comparisons due to recursive splitting

👉 Example:

* n = 10 → comparisons = **14 (observed)**
* Optimal possible = **13**

---

## 🛠️ Technologies Used

* Language: C
* Libraries:

  * stdio.h
  * stdlib.h
  * time.h

---

## ▶️ How to Run

### 1. Compile

```bash
gcc program.c -o program
```

### 2. Execute

```bash
./program
```

---

## 📌 Sample Output

```
Enter the length of the array: 5
Array:
23 45 12 67 34

Max = 67
Min = 12
Total Comparisons = 6
```

---

## ⚠️ Notes

* The divide-and-conquer approach is efficient but may not always achieve the **absolute minimum comparisons**.
* For optimal comparisons, a **pairwise method** can be used.

---

## 📚 Learning Outcomes

* Understanding **Divide & Conquer paradigm**
* Analyzing **algorithm efficiency**
* Working with **pointers in C**
* Measuring **comparison complexity**

---

## 👨‍💻 Author

SOUVIK SARKAR

---
