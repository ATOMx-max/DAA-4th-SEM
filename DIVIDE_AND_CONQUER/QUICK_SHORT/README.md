# 📘 Quick Sort Analysis Project (Lomuto vs Hoare vs Randomized)

## 🔹 Project Objective

To implement and compare different versions of Quick Sort:

* Lomuto Partition
* Hoare Partition
* Randomized Quick Sort (Hoare-based)

The comparison is based on:

* Number of comparisons (practical)
* Theoretical time complexity

---

## 🔹 Algorithms Used

### 1. Lomuto Partition

* Pivot = last element
* Places pivot at correct final position
* Simple and easy to implement

### 2. Hoare Partition

* Pivot = first element
* Uses two pointers (i, j)
* More efficient (fewer swaps)

### 3. Randomized Quick Sort

* Pivot chosen randomly
* Uses Hoare partition
* Reduces probability of worst-case

---

## 🔹 Key Functions

* `QSL()` → Quick Sort using Lomuto
* `QSH()` → Quick Sort using Hoare
* `RQS()` → Randomized Quick Sort (Hoare)
* `Lpartition()` → Lomuto partition logic
* `Hpartition()` → Hoare partition logic
* `swap()` → Swap utility

---

## 🔹 Important Concepts

### ✔ time(0)

* Returns current time in seconds since 1 Jan 1970
* Used to seed random generator:

```c
srand(time(0));
```

---

### ✔ In-Place Property

* Quick Sort is an **in-place algorithm**
* It does not require extra memory (only recursion stack)
* Space complexity:

```text
O(log n)  (average recursion stack)
```

👉 Works directly on the same array

---

### ✔ Stability

* Quick Sort is **NOT stable**

👉 Meaning:

* Equal elements may change their relative order

Example:

```text
Input:  (5a, 3, 5b)
Output: (3, 5b, 5a)
```

👉 Order of 5a and 5b changed ❌

---

### ✔ Why Randomization?

* Avoids worst-case O(n²)
* Gives expected O(n log n)
* Makes pivot selection unbiased

---

### ✔ Comparison Counting

* Counts number of times condition is checked

```c
(*T_COMP)++;
```

* Helps compare practical performance

---

## 🔹 Theoretical Analysis

### Best Case

* Balanced partition
* Time Complexity:

```text
O(n log n)
```

* Approx comparisons:

```text
n log₂ n
```

---

### Worst Case

* Pivot always smallest/largest
* Time Complexity:

```text
O(n²)
```

* Exact comparisons:

```text
n(n - 1) / 2
```

---

### Average Case

* Random input or randomized pivot

```text
≈ 1.39 n log n
```

---

## 🔹 Key Questions & Answers

### ❓ Does comparison depend on randomization?

✔ Yes

* Depends on pivot selection
* Randomization improves expected performance

---

### ❓ Which partition is better?

* Hoare → more efficient
* Lomuto → simpler

---

### ❓ Which is best overall?

* Randomized + Hoare → best performance
* Lomuto → best for learning

---

### ❓ Can we use Hoare in randomized Quick Sort?

✔ Yes

* Randomization only changes pivot
* Partition can be Lomuto or Hoare

---

### ❓ Why Lomuto is used?

* Simple implementation
* Easy recursion
* Pivot gets exact position

---

### ❓ Why Hoare is faster?

* Fewer swaps
* Better partitioning

---

### ❓ Is worst case formula n(n+1)/2 correct?

❌ No
✔ Correct:

```text
n(n - 1) / 2
```

---

## 🔹 Observations

* Hoare uses fewer comparisons than Lomuto
* Randomized Hoare performs best
* Practical results vary due to randomness

---

## 🔹 Conclusion

* Quick Sort is **in-place but not stable**
* Performance depends on pivot selection
* Randomization improves efficiency
* Hoare partition is faster in practice
* Lomuto is easier for implementation

---

## 🔹 How to Compile

```bash
gcc program.c -lm
./a.out
```

---

## 🔹 Final Insight

👉
**“Quick Sort is an efficient in-place sorting algorithm, but its performance depends heavily on pivot selection.”**

---

## 🚀 Future Improvements

* Add swap count comparison
* Run multiple iterations and average results
* Plot graph of comparisons vs n

---
SOUVIK SARKAR