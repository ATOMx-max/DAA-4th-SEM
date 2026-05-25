# Min Heap Priority Queue in C

## Overview

This project implements a **Min Heap Priority Queue** using arrays in the C programming language.

The heap follows the Min Heap property:

Parent \leq Children

which means the smallest element is always stored at the root.

---

# Features

* Insert elements into heap
* Get minimum element
* Extract minimum element
* Decrease key operation
* Delete any node
* Heapify / Adjust heap
* Array based implementation
* 1-based indexing

---

# Data Structure Used

## Min Heap

A Min Heap is a complete binary tree where every parent node is smaller than or equal to its children.

Example:

```text id="n1svhp"
        10
      /    \
    15      30
   /  \    /  \
 40  50  60  70
```

---

# Functions

## `insert()`

Inserts a new element into the heap.

### Time Complexity

O(\log n)

---

## `getmin()`

Returns the minimum element from heap.

### Time Complexity

O(1)

---

## `extract_min()`

Removes the minimum element from the heap and reorganizes the heap.

### Time Complexity

O(\log n)

---

## `decrise_key()`

Decreases the value of a node and restores Min Heap property.

### Time Complexity

O(\log n)

---

## `delete_key()`

Deletes any node from heap.

### Time Complexity

O(\log n)

---

# Heap Property Verification

Example Output:

```text id="vz3m8j"
15  40  30  80  50  60  70  90
```

This is a valid Min Heap because:

* 15 < 40, 30
* 40 < 80, 50
* 30 < 60, 70

A heap is NOT fully sorted.

It only maintains:

Parent \leq Children

---

# Compilation

Compile using GCC:

```bash id="x2ocx7"
gcc minheap.c -o minheap
```

Run:

```bash id="tnn8k5"
./minheap
```

---

# Example Output

```text id="v8z2z0"
2147483647
10
10 15 30 40 50 60 70 80 90 20
10
15 40 30 80 50 60 70 90
```

---

# Applications

* Priority Queue
* Dijkstra Algorithm
* Prim’s Algorithm
* Operating System Scheduling
* Event Simulation
* Huffman Coding

---

# Author

Made using C Programming Language.
