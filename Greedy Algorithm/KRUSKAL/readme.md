# 🌳 Kruskal’s Algorithm Using Merge Sort in C

<div align="center">

![Language](https://img.shields.io/badge/Language-C-blue)
![Algorithm](https://img.shields.io/badge/Algorithm-Kruskal-green)
![Sorting](https://img.shields.io/badge/Sorting-Merge%20Sort-orange)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

</div>

---

# 📌 Overview

This project implements **Kruskal’s Algorithm** in **C language** to find the **Minimum Spanning Tree (MST)** of a weighted graph.

The program:

* Reads graph data from a file
* Sorts edges using Merge Sort
* Uses Union-Find (Disjoint Set)
* Generates the Minimum Spanning Tree
* Calculates total minimum cost

---

# 🎯 Aim

To implement **Kruskal's Algorithm using Merge Sort** in C language for finding the **Minimum Spanning Tree (MST)** of a weighted graph.

---

# 📚 Theory

## 🌐 Minimum Spanning Tree (MST)

A **Minimum Spanning Tree** is a subset of edges of a connected weighted graph that:

* Connects all vertices
* Contains no cycles
* Has minimum total weight

For a graph with `V` vertices:

```text
MST contains (V - 1) edges
```

---

# ⚡ Kruskal’s Algorithm

## 🔹 Steps

1. Sort all edges in increasing order of weight.
2. Select the smallest edge.
3. Check whether adding the edge forms a cycle.
4. If no cycle forms, include the edge in MST.
5. Repeat until MST contains `(V - 1)` edges.

---

# 🧠 Concepts Used

## 1️⃣ Merge Sort

Used to sort edges according to edge weight.

### ⏱ Time Complexity

```text
O(E log E)
```

Where:

* `E` = Number of edges

---

## 2️⃣ Disjoint Set / Union-Find

Used for cycle detection.

### 🔧 Operations

| Function     | Purpose                |
| ------------ | ---------------------- |
| `find()`     | Finds parent/root node |
| `unionset()` | Joins two sets         |

---

# 🏗 Data Structure

```c
struct EG
{
    int v1;
    int v2;
    int w;
};
```

## 📖 Members

| Member | Description        |
| ------ | ------------------ |
| `v1`   | Source Vertex      |
| `v2`   | Destination Vertex |
| `w`    | Edge Weight        |

---

# 🛠 Functions Used

| Function     | Purpose                 |
| ------------ | ----------------------- |
| `m_s()`      | Recursive Merge Sort    |
| `mg()`       | Merge Function          |
| `makeset()`  | Initialize Parent Array |
| `find()`     | Find Root Parent        |
| `unionset()` | Union of Sets           |
| `kruskal()`  | Construct MST           |

---

# 🔄 Algorithm

## 📌 Merge Sort Algorithm

1. Divide array into two halves.
2. Recursively sort both halves.
3. Merge sorted halves.

---

## 📌 Kruskal Algorithm

1. Initialize all vertices as separate sets.
2. Traverse sorted edges.
3. If two vertices belong to different sets:

   * Include edge in MST
   * Union both sets
4. Stop after selecting `(V - 1)` edges.

---

# 📥 Input Format

```text
Number_of_Vertices
Number_of_Edges
v1 v2 weight
v1 v2 weight
...
```

---

# 🧪 Example Input

```text
7
9
0 1 2
0 6 2
1 6 2
1 3 3
3 6 1
3 5 3
3 4 3
4 5 3
5 6 4
```

---

# ✅ Expected Output

```text
SOLUTION ARRAY:
V1 V2 W

3 6 1
0 1 2
0 6 2
3 5 3
3 4 3

Total Cost = 11
```

---

# 📊 Time Complexity Analysis

| Operation             | Complexity   |
| --------------------- | ------------ |
| Merge Sort            | `O(E log E)` |
| Union-Find Operations | `O(E)`       |
| Overall Complexity    | `O(E log E)` |

---

# 🌟 Advantages

* Efficient for sparse graphs
* Easy cycle detection
* Produces minimum cost spanning tree
* Faster sorting using Merge Sort

---

# 🚀 Applications

* Network Design
* Road Construction
* Electrical Wiring
* Computer Networks
* Water Pipeline Systems

---

# ⚙ Compilation

Using GCC:

```bash
gcc main.c -o kruskal
```

---

# ▶ Run Program

```bash
./kruskal
```

---

# 📁 Project Structure

```text
project/
│
├── main.c
├── graph.txt
└── README.md
```

---

# 🎓 Conclusion

The program successfully implements **Kruskal's Algorithm** using:

* Merge Sort
* Union-Find Technique
* File Handling in C

# Author
SOUVIK SARKAR