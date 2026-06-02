# M-Coloring Problem Using Backtracking (Next Value Algorithm)

## Aim

To solve the **M-Coloring Problem** using the **Backtracking Technique** and the **Next Value Algorithm**.

---

## Problem Statement

Given a graph and `m` colors, assign colors to all vertices such that:

* No two adjacent vertices have the same color.
* All possible valid color assignments are generated.

---

## Algorithm

### NextValue(k)

1. Assign the next available color to vertex `k`.
2. If all colors are exhausted, return `0`.
3. Check whether the assigned color conflicts with any adjacent previously colored vertex.
4. If no conflict exists, accept the color and return.
5. Otherwise, try the next color.

### M-Coloring(k)

1. Call `NextValue(k)` to assign a valid color.
2. If no color is possible (`x[k] = 0`), backtrack.
3. If all vertices are colored, print the solution.
4. Otherwise, recursively color the next vertex.
5. Continue until all possible color assignments are explored.

---

## Source Code

```c
#include<stdio.h>
#include<stdlib.h>

void print(int ver,int g[ver+1][ver+1])
{
    printf("GRAPH is:\n");
    for(int i=1;i<=ver;i++)
    {
        for(int j=1;j<=ver;j++)
        {
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
}

void nextvalue(int k,int m,int ver,int x[ver+1],int g[ver+1][ver+1])
{
    while(1)
    {
        x[k]=(x[k]+1)%(m+1);

        if(x[k]==0)
            return;

        int j;

        for(j=1;j<=k-1;j++)
        {
            if(g[j][k]==1 && x[j]==x[k])
                break;
        }

        if(j==k)
            return;
    }
}

void m_coloring(int k,int m,int ver,int x[ver+1],int g[ver+1][ver+1])
{
    while(1)
    {
        nextvalue(k,m,ver,x,g);

        if(x[k]==0)
            return;

        if(k==ver)
        {
            printf("SOLUTION:");
            for(int i=1;i<=ver;i++)
                printf("%3d",x[i]);

            printf("\n");
        }
        else
        {
            m_coloring(k+1,m,ver,x,g);
        }
    }
}

int main()
{
    FILE *fp;
    fp=fopen("graph.txt","r");

    if(fp==NULL)
    {
        printf("File not found!\n");
        exit(0);
    }

    int ver;
    fscanf(fp,"%d",&ver);

    int g[ver+1][ver+1];

    for(int i=1;i<=ver;i++)
    {
        for(int j=1;j<=ver;j++)
        {
            fscanf(fp,"%d",&g[i][j]);
        }
    }

    printf("Vertices = %d\n",ver);

    print(ver,g);

    int m;
    printf("Enter the total colors: ");
    scanf("%d",&m);

    int x[ver+1];

    for(int i=0;i<=ver;i++)
        x[i]=0;

    m_coloring(1,m,ver,x,g);

    return 0;
}
```

---

## Input File Format (`graph.txt`)

### Example

```text
4
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
```

### Explanation

* First line → Number of vertices.
* Remaining lines → Adjacency matrix of the graph.

---

## Sample Input

```text
Vertices = 4

Adjacency Matrix:
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0

Number of Colors = 3
```

---

## Sample Output

```text
SOLUTION:  1  2  3  1
SOLUTION:  1  3  2  1
SOLUTION:  2  1  3  2
SOLUTION:  2  3  1  2
SOLUTION:  3  1  2  3
SOLUTION:  3  2  1  3
```

---

## Time Complexity

In the worst case, each vertex can be assigned any of the `m` colors.

O(m^n)

where:

* `n` = Number of vertices
* `m` = Number of colors

---

## Space Complexity

[
O(n)
]

for storing the color assignment array and recursion stack.

---

## Applications

* Map Coloring
* Register Allocation in Compilers
* Frequency Assignment Problems
* Scheduling Problems
* Constraint Satisfaction Problems (CSP)

---

## Conclusion

The M-Coloring Problem is solved using **Backtracking**. The **Next Value Algorithm** systematically tries colors for each vertex and backtracks whenever a conflict occurs, generating all valid color assignments for the graph.
