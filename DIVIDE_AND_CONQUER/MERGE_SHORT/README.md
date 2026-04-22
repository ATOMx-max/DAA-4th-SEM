# 📊 DAA Project: Merge Sort with Comparison Count (C)

## 📌 Overview

This project implements the **Merge Sort algorithm** using the **Divide and Conquer** technique.

In addition to sorting, the program calculates:

* ✔ **Actual number of comparisons (practical)**
* ✔ **Theoretical number of comparisons**

This helps analyze the difference between **theoretical complexity and real execution**.

---

## 🧠 Concepts Used

* Divide & Conquer
* Recursion
* Merge Sort
* Time Complexity Analysis
* Comparison Counting

---

## 🚀 Features

* Sorts an array using Merge Sort
* Generates random input data
* Counts **actual comparisons** during merging
* Computes **theoretical comparisons** using formula
* Displays both results for comparison

---

## 🔍 Algorithm Explanation

### 1. Divide

* Split array into two halves recursively

### 2. Conquer

* Sort each half

### 3. Combine (Merge)

* Merge two sorted halves
* Count comparisons during merging

---

## 📈 Complexity Analysis

| Case    | Time Complexity |
| ------- | --------------- |
| Best    | O(n log n)      |
| Average | O(n log n)      |
| Worst   | O(n log n)      |

---

## 🔢 Comparison Analysis

### 🔹 Theoretical Comparisons:

[
T(n) = n \log_2 n - n + 1
]

### 🔹 Practical Comparisons:

* Depends on input distribution
* Usually slightly **less than or equal to theoretical value**

---

## ▶️ How to Run

### 1. Compile

```bash
gcc mergesort.c -o mergesort -lm
```

### 2. Execute

```bash
./mergesort
```

---

## 📌 Sample Output

```
Enter the length of the array: 10
BEFORE: 45 12 78 23 56 9 34 67 11 90

AFTER: 9 11 12 23 34 45 56 67 78 90

Actual Comparisons = 23
Theoretical Comparisons ≈ 24
```

---

## ⚠️ Notes

* Theoretical value represents **worst-case comparisons**
* Actual comparisons may vary depending on input
* Requires `<math.h>` for `log2()`

---

## 📚 Learning Outcomes

* Understanding Merge Sort deeply
* Analyzing algorithm efficiency
* Comparing theoretical vs practical performance
* Working with recursion and arrays in C

---

## 👨‍💻 Author

SOUVIK SARKAR

---
