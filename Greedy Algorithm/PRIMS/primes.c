#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include <stdbool.h>
#define MAX 100
//for priority hep queue here we nedd to short with weight not vertex
int heapsize=0;
struct graph{
    int key;
    int parent;
};
struct priority
{
    int vertex;
    int key;
    int parent;
};
struct priority Q_grp[MAX];
void heapadj(struct priority arr[], int i, int n)
{
    struct priority temp = arr[i];
    int j = 2 * i;
    while(j <= n)
    {
        if(j < n && arr[j].key > arr[j+1].key)
            j++;

        if(temp.key <= arr[j].key)
            break;

        arr[j/2] = arr[j];
        j = 2 * j;
    }
    arr[j/2] = temp;
}

void swap(struct priority arr[], int i, int j)
{
    struct priority temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void insert(int v,int key,int p)
{
    if(heapsize==MAX+1)
    {
        printf("OVERFLOW\n");
    }
    heapsize=heapsize+1;
    Q_grp[heapsize].key=key;
    Q_grp[heapsize].vertex=v;
    Q_grp[heapsize].parent=p;
    int i=heapsize;
    while(i>1 && Q_grp[i/2].key>Q_grp[i].key)
    {
        swap(Q_grp,i,i/2);
        i=i/2;
    }
}
int is_empty()
{
    return heapsize==0?1:0;
}
struct priority extract_min()
{
    struct priority minnode;

    minnode.vertex = -1;
    minnode.key = INT_MAX;
    minnode.parent = -1;

    if(heapsize == 0)
        return minnode;

    minnode = Q_grp[1];

    if(heapsize == 1)
    {
        heapsize--;
        return minnode;
    }

    Q_grp[1] = Q_grp[heapsize];
    heapsize--;

    heapadj(Q_grp,1,heapsize);

    return minnode;
}
void decrise_key(int i, int keyval)
{
    if(i < 1 || i > heapsize)
    {
        return;
    }
    Q_grp[i].key = keyval;

    while(i > 1 && Q_grp[i/2].key > Q_grp[i].key)
    {
        swap(Q_grp, i, i/2);

        i = i/2;
    }
}


void primes(int ver,int w_matrix[ver][ver],bool MST[],struct graph grp[],int r)
{
    for(int i=0;i<ver;i++)
    {
        grp[i].key=INT_MAX;
        grp[i].parent=-1;
        MST[i]=false;
    }
    grp[r].key=0;
    insert(r,0,-1);
    while(!is_empty())
    {
        struct priority node = extract_min();
        int u = node.vertex;
        MST[u]=true;
        for(int v=0;v<ver;v++)
        {
            if(w_matrix[u][v]!=0)
            {
                if(MST[v]==false && w_matrix[u][v]<grp[v].key)
                {
                    grp[v].key=w_matrix[u][v];
                    grp[v].parent=u;
                    insert(v,grp[v].key,grp[v].parent);
                }
            }
        }
    }
}
int main()
{
    FILE *fp = fopen("grp.txt", "r");

    if(fp == NULL)
    {
        printf("File not found\n");
        return 0;
    }

    int ver, edges;

    fscanf(fp, "%d", &ver);
    fscanf(fp, "%d", &edges);

    int w_matrix[ver][ver];

    for(int i=0; i<ver; i++)
    {
        for(int j=0; j<ver; j++)
        {
            fscanf(fp, "%d", &w_matrix[i][j]);
        }
    }

    fclose(fp);

    struct graph grp[ver];
    bool MST[ver];

    primes(ver, w_matrix, MST, grp, 0);

    printf("\nMST Edges:\n");

    int cost = 0;

    for(int i=1; i<ver; i++)
    {
        printf("%d - %d : %d\n",
               grp[i].parent,
               i,
               grp[i].key);

        cost += grp[i].key;
    }

    printf("\nTotal Cost = %d\n", cost);

    return 0;
}