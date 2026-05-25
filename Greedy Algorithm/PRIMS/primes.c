#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include <stdbool.h>
#define MAX 100
int Q_grp[MAX];
int heapsize=0;
struct graph{
    int key;
    int parent;
};

void heapadj(int arr[],int i,int n)
{
    int key=arr[i];
    int j=2*i;
    while(j<=n)
    {
        if(j<n && arr[j]>arr[j+1])
        {
            j=j+1;
        }
        if(key<arr[j])break;
        arr[j/2]=arr[j];
        j=2*j;
    }
    arr[j/2]=key;
}

void swap(int arr[],int i,int j)
{
    int temp=arr[j];
    arr[j]=arr[i];
    arr[i]=temp;
}
void insert(int key)
{
    if(heapsize==MAX+1)
    {
        printf("OVERFLOW\n");
    }
    heapsize=heapsize+1;
    Q_grp[heapsize]=key;
    int i=heapsize;
    while(i>1 && Q_grp[i/2]>Q_grp[i])
    {
        swap(Q_grp,i,i/2);
        i=i/2;
    }
}
int is_empty()
{
    return heapsize==0?1:0;
}
int extract_min()
{
    if(heapsize==0)
    {
        return INT_MAX;
    }
    if(heapsize==1)
    {
        heapsize=heapsize-1;
        return Q_grp[1];
    }
    int min=Q_grp[1];
    Q_grp[1]=Q_grp[heapsize];
    heapsize--;
    heapadj(Q_grp,1,heapsize);
    return min;
}
void decrise_key(int i, int keyval)
{
    if(i < 1 || i > heapsize)
    {
        return;
    }

    Q_grp[i] = keyval;

    while(i > 1 && Q_grp[i/2] > Q_grp[i])
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
    insert(r);
    while(!is_empty())
    {
        int u=extract_min();
        MST[u]=true;
        for(int v=0;v<ver;v++)
        {
            if(w_matrix[u][v]!=0)
            {
                if(MST[v]==false && w_matrix[u][v]<grp[v].key)
                {
                    grp[v].key=w_matrix[u][v];
                    grp[v].parent=u;
                    decrise_key(v,grp[v].key);
                }
            }
        }
    }

}

int main()
{
    FILE *fp;
    fp=fopen("grp.txt","r");
    int ver,Edges;
    fscanf(fp,"%d",&ver);
    fscanf(fp,"%d",&Edges);
    printf("%d \n%d\n",ver,Edges);
    int w_matrix[ver][ver];
    for(int i=0;i<ver;i++)
    {
        for(int j=0;j<ver;j++)
        {
            fscanf(fp,"%d",&w_matrix[i][j]);
        }
    }

    for(int i=0;i<ver;i++)
    {
        for(int j=0;j<ver;j++)
        {
            printf("%d\t",w_matrix[i][j]);
        }
        printf("\n");
    }
    fclose(fp);
    struct graph grp[ver];
    bool MST[ver];
    primes(ver,w_matrix,MST,grp,0);
    return 0;
}