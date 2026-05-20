# 🎒 Fractional Knapsack Using Merge Sort in C

A complete implementation of the **Fractional Knapsack Problem** using the **Greedy Method** and **Merge Sort** in **C Programming**.

---

## 📌 Features

✅ Random Profit & Weight Generation
✅ Profit/Weight Ratio Calculation
✅ Merge Sort Implementation
✅ Fractional Knapsack Algorithm
✅ Maximum Profit Calculation
✅ Time Complexity Analysis

---

# 📖 Problem Statement

The **Fractional Knapsack Problem** is an optimization problem where:

* Each item has:

  * 📈 Profit
  * ⚖️ Weight
* The knapsack has limited capacity.
* Items can be taken:

  * Fully
  * Partially (fractionally)

🎯 Goal: **Maximize total profit**.

---

# 🧠 Greedy Strategy

Items are selected based on the highest:

[
\frac{Profit}{Weight}
]

This value is called:

## 📊 Profit Per Weight (PPW)

[
PPW = \frac{Profit}{Weight}
]

Items with higher PPW are selected first.

---

# 🏗️ Data Structure Used

```c
struct Item
{
    int profit;
    int weight;
    float ppw;
};
```

| Variable | Description             |
| -------- | ----------------------- |
| `profit` | Profit of item          |
| `weight` | Weight of item          |
| `ppw`    | Profit per weight ratio |

---

# ⚙️ Functions Used

## 🔹 `FK()`

Implements Fractional Knapsack logic.

```c
void FK(struct Item arr[], float sol[], int m, int n);
```

### Parameters

| Parameter | Meaning                   |
| --------- | ------------------------- |
| `arr[]`   | Array of items            |
| `sol[]`   | Stores selected fractions |
| `m`       | Knapsack capacity         |
| `n`       | Number of items           |

---

## 🔹 `profit()`

Calculates total profit.

```c
void profit(struct Item arr[], float sol[], int n);
```

---

## 🔹 `m_s()`

Recursive Merge Sort function.

```c
void m_s(struct Item arr[], int low, int high);
```

---

## 🔹 `mg()`

Merge function for Merge Sort.

```c
void mg(struct Item arr[], int low, int mid, int high);
```

---

# 🔄 Algorithm

## Step 1️⃣

Input:

* Number of items
* Knapsack capacity

---

## Step 2️⃣

Generate random:

* Profit
* Weight

---

## Step 3️⃣

Calculate:

[
PPW = \frac{Profit}{Weight}
]

---

## Step 4️⃣

Sort items in descending order using Merge Sort.

---

## Step 5️⃣

Apply Fractional Knapsack:

* Take full item if possible
* Otherwise take fraction

---

## Step 6️⃣

Calculate total maximum profit.


# 🧪 Sample Output

```text
Enter number of items: 5
Enter Capacity: 30

Profit Weight P/W
80      10     8.00
45      15     3.00
90      20     4.50
60      5      12.00
30      8      3.75

After Sorting

Profit Weight P/W
60      5      12.00
80      10     8.00
90      20     4.50
30      8      3.75
45      15     3.00

Selected Fractions:
Item 1 -> 1.00
Item 2 -> 1.00
Item 3 -> 0.75
Item 4 -> 0.00
Item 5 -> 0.00

Profit is:207.50
```

---

# ⏱️ Time Complexity Analysis

## 🔹 PPW Calculation

[
O(n)
]

---

## 🔹 Merge Sort

[
O(n \log n)
]

---

## 🔹 Fractional Selection

[
O(n)
]

---

## 🔹 Profit Calculation

[
O(n)
]

---

# 🚀 Overall Time Complexity

[
O(n \log n)
]

---

# 💾 Space Complexity

[
O(n)
]

---

# 📊 Complexity Table

| Operation          | Complexity    |
| ------------------ | ------------- |
| PPW Calculation    | (O(n))        |
| Merge Sort         | (O(n \log n)) |
| Fraction Selection | (O(n))        |
| Profit Calculation | (O(n))        |
| Overall Complexity | (O(n \log n)) |
| Space Complexity   | (O(n))        |

---

# ✅ Advantages

✨ Efficient greedy solution
✨ Maximizes total profit
✨ Fast sorting using Merge Sort
✨ Supports fractional selection

---

# 🌍 Applications

* 🚚 Cargo Loading
* 📦 Resource Allocation
* 💰 Investment Planning
* 🌐 Bandwidth Management
* 📊 Budget Optimization

---

# 🎯 Conclusion

This project successfully implements the **Fractional Knapsack Algorithm** using the **Greedy Method** and **Merge Sort** in C.

The algorithm selects items according to the highest Profit/Weight ratio to achieve the **maximum possible profit** within the given knapsack capacity.

---

# 👨‍💻 Author
SOUVIK SARKAR
Developed in **C Programming Language** using:

* Greedy Algorithm
* Merge Sort
* Dynamic Arrays
* Structures

⭐ If you like this project, give it a star on GitHub!
