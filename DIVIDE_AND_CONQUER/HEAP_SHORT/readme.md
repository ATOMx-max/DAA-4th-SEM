````md
# Heap Sort Using Max Heap in C

## Overview

This project implements **Heap Sort** using the **Max Heap** concept in the C programming language.

Heap Sort is an efficient comparison-based sorting algorithm that uses a **Binary Heap Data Structure**.

The program:
- Generates random numbers
- Converts the array into a Max Heap
- Sorts the array using Heap Sort
- Prints the original and sorted array

---

# What is Heap?

A Heap is a special type of **Complete Binary Tree**.

## Types of Heap

| Heap Type | Property |
|------------|------------|
| Max Heap | Parent node is greater than child nodes |
| Min Heap | Parent node is smaller than child nodes |

This project uses a **Max Heap**.

Example:

```text
        90
      /    \
    70      50
   /  \    /  \
 20  40  10  30
````

---

# Heap Sort Working

Heap Sort works in two phases:

## 1. Build Max Heap

Convert the array into a valid Max Heap.

## 2. Sorting Phase

* Swap the root with the last element
* Reduce heap size
* Restore heap property
* Repeat until array is sorted

---

# Code

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10

void print(int arr[]);
void MS(int arr[], int n);
void makeheap(int arr[], int n);
void heapadj(int arr[], int i, int n);

void print(int arr[])
{
    for(int i=1;i<=MAX;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void MS(int arr[],int n)
{
    makeheap(arr,n);

    for(int i=n;i>=1;i--)
    {
        int t=arr[1];
        arr[1]=arr[i];
        arr[i]=t;

        heapadj(arr,1,i-1);
    }
}

void makeheap(int arr[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        heapadj(arr,i,n);
    }
}

void heapadj(int arr[],int i,int n)
{
    int j=2*i;
    int key=arr[i];

    while(j<=n)
    {
        if(j<n && arr[j]<arr[j+1])
        {
            j=j+1;
        }

        if(key>arr[j])
            break;

        arr[j/2]=arr[j];
        j=2*j;
    }

    arr[j/2]=key;
}

int main()
{
    int arr[MAX + 1];

    srand(time(0));

    for(int i = 1; i <= MAX; i++)
    {
        arr[i] = rand() % 100;
    }

    printf("Original Array:\n");
    print(arr);

    MS(arr, MAX);

    printf("Sorted Array:\n");
    print(arr);

    return 0;
}
```

---

# Function Explanation

## `print()`

Prints all array elements.

---

## `MS()`

Main Heap Sort function.

### Steps:

1. Create Max Heap
2. Swap largest element with last element
3. Restore heap
4. Repeat

---

## `makeheap()`

Creates Max Heap from array.

### Important Point

Loop starts from:

```c
n/2
```

Because nodes after `n/2` are leaf nodes.

---

## `heapadj()`

Maintains Max Heap property.

### Logic

* Compare parent with children
* Find larger child
* Swap if needed
* Continue downward

---

# Dry Run

## Original Array

```text
20 40 10 90 60
```

## After Max Heap

```text
90 60 10 40 20
```

## After Sorting

```text
10 20 40 60 90
```

---

# Time Complexity

| Operation   | Complexity |
| ----------- | ---------- |
| Build Heap  | O(n)       |
| Heap Adjust | O(log n)   |
| Heap Sort   | O(n log n) |

---

# Space Complexity

```text
O(1)
```

Heap Sort is an **in-place sorting algorithm**.

---

# Advantages

* Efficient sorting
* No extra memory required
* Good performance for large datasets
* Guaranteed O(n log n)

---

# Disadvantages

* Not stable
* More complex than simple sorting algorithms

---

# Compilation

```bash
gcc heap_sort.c -o heap
```

---

# Run

```bash
./heap
```

---

# Example Output

```text
Original Array:
45 12 89 34 67 23 90 11 56 78

Sorted Array:
11 12 23 34 45 56 67 78 89 90
```

---

# Concepts Used

* Heap Data Structure
* Max Heap
* Complete Binary Tree
* Heapify
* In-place Sorting
* Time Complexity Optimization

---

# Author

Implemented in C using Heap Sort with Max Heap.

```
```
