#include<stdio.h>
#include<stdlib.h>

struct EG
{
    int v1;
    int v2;
    int w;
};

int p[100];

struct EG solution[100];

void m_s(struct EG arr[], int low, int high);
void mg(struct EG arr[], int low, int mid, int high);

void kruskal(struct EG arr[], int e, int ver);

void makeset(int ver);
int find(int v);
void unionset(int u, int v);

int k = 0;

void makeset(int ver)
{
    for(int i=0; i<ver; i++)
    {
        p[i] = -1;
    }
}

int find(int v)
{
    while(p[v] != -1)
    {
        v = p[v];
    }

    return v;
}

void unionset(int u, int v)
{
    p[v] = u;
}

void kruskal(struct EG arr[], int e, int ver)
{
    makeset(ver);

    int cost = 0;

    for(int i=0; i<e; i++)
    {
        int u = find(arr[i].v1);
        int v = find(arr[i].v2);

        if(u != v)
        {
            solution[k] = arr[i];
            unionset(u, v);
            cost += arr[i].w;
            k++;
            if(k == ver - 1)
            {
                break;
            }
        }
    }

    printf("\nSOLUTION ARRAY:\n");
    printf("V1 V2 W\n");

    for(int i=0; i<k; i++)
    {
        printf("%d %d %d\n",
               solution[i].v1,
               solution[i].v2,
               solution[i].w);
    }

    printf("\nTotal Cost = %d\n", cost);

    if(k != ver - 1)
    {
        printf("Graph is disconnected\n");
    }
}

void m_s(struct EG arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        m_s(arr, low, mid);
        m_s(arr, mid + 1, high);

        mg(arr, low, mid, high);
    }
}

void mg(struct EG arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    struct EG temp[high + 1];

    while(i <= mid && j <= high)
    {
        if(arr[i].w > arr[j].w)
        {
            temp[k] = arr[j];
            j++;
        }
        else
        {
            temp[k] = arr[i];
            i++;
        }

        k++;
    }

    while(i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    FILE *fp;

    fp = fopen("graph.txt", "r");

    if(fp == NULL)
    {
        printf("ERROR");
        exit(1);
    }

    int ver, eg;

    fscanf(fp, "%d", &ver);
    fscanf(fp, "%d", &eg);

    struct EG side[eg];

    printf("Vertex = %d\nEdges = %d\n", ver, eg);

    for(int i=0; i<eg; i++)
    {
        fscanf(fp,"%d%d%d",&side[i].v1,&side[i].v2,&side[i].w);
    }

    fclose(fp);

    printf("\nOriginal Edges:\n");
    printf("V1 V2 W\n");

    for(int i=0; i<eg; i++)
    {
        printf("%d %d %d\n",side[i].v1,side[i].v2,side[i].w);
    }

    m_s(side, 0, eg - 1);

    printf("\nSorted Edges:\n");
    printf("V1 V2 W\n");

    for(int i=0; i<eg; i++)
    {
        printf("%d %d %d\n",side[i].v1,side[i].v2,side[i].w);
    }

    kruskal(side, eg, ver);

    return 0;
}