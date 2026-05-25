# 📊 DAA Project: Graph Representation using Adjacency List (C)

## 📌 Overview

This project converts a graph from an **Adjacency Matrix** representation into an **Adjacency List** using **linked lists in C**.

It reads the graph data from a file and dynamically builds a linked list for each vertex.

---

## 🧠 Concept Used

* Graph Representation
* Adjacency Matrix → Adjacency List Conversion
* Linked List
* Dynamic Memory Allocation (`malloc`)

---

## 🚀 Features

* Reads graph from file (`ex.txt`)
* Converts matrix to adjacency list
* Uses **linked list for efficient storage**
* Displays graph in readable format

---

## 📂 Input File Format (`ex.txt`)

```
n
a11 a12 a13 ... a1n
a21 a22 a23 ... a2n
...
an1 an2 an3 ... ann
```

### 🔹 Example:

```
4
0 1 1 0
1 0 1 1
1 1 0 0
0 1 0 0
```

👉 Here:

* `n = 4` (number of vertices)
* `1` means edge exists
* `0` means no edge

---

## ▶️ How to Run

### 1. Compile

```bash
gcc graph.c -o graph
```

### 2. Run

```bash
./graph
```

---

## 📌 Output Format

```
0 -> 1 -> 2 -> NULL
1 -> 0 -> 2 -> 3 -> NULL
2 -> 0 -> 1 -> NULL
3 -> 1 -> NULL
```

---

## 🔍 Working Explanation

1. Read `n` from file
2. Store adjacency matrix in 2D array
3. For each vertex:

   * Traverse row
   * If value = 1 → add node in linked list
4. Print adjacency list

---

## 📈 Complexity Analysis

| Operation            | Complexity |
| -------------------- | ---------- |
| Matrix Input         | O(n²)      |
| Conversion           | O(n²)      |
| Adjacency List Space | O(n + e)   |

---

## ⚠️ Notes

* Ensure `ex.txt` is in the same directory
* Program assumes valid input
* Memory should be freed after use (recommended improvement)

---

## 📚 Learning Outcomes

* Understanding graph representations
* Using linked lists in real problems
* File handling in C
* Space optimization techniques

---

## 👨‍💻 Author

SOUVIK SARKAR
---
