#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#define MAX 10
int heapsize=0;
void swap(int Q_grp[],int i,int j)
{
    int temp=Q_grp[i];
    Q_grp[i]=Q_grp[j];
    Q_grp[j]=temp;
}
void print(int arr[],int n)
{
    for(int i=1;i<=n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int getmin(int Q_grp[])
{
    if(heapsize==0)return INT_MAX;
    return Q_grp[1];
}

void insert(int Q_grp[],int key)
{
    if(heapsize==MAX)
    {
        printf("Stack overflow\n");
        return;
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
//follow MAX heap
void adjhip(int arr[],int i,int n)
{
    int j=2*i;
    int key=arr[i];
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

int extract_min(int arr[],int n)
{
    if(heapsize==0)return INT_MAX;
    if(heapsize==1)
    {
        heapsize=heapsize-1;
        return arr[1];
    }
    int min=arr[1];
    arr[1]=arr[heapsize];
    heapsize=heapsize-1;
    adjhip(arr,1,heapsize);
    return min;
}

void decrise_key(int arr[],int i,int keyval)
{
    if(i<1 || i>heapsize)
    {
        printf("NP\n");
        return;
    }
    arr[i]=keyval;
    while(i>1 && arr[i/2]>arr[i])
    {
        swap(arr,i,i/2);
        i=i/2;
    }
}
void delete_key(int arr[],int i,int n)
{
    if(i<1 || i>heapsize)
    {
        printf("NP\n");
        return;
    }
    decrise_key(arr,i,INT_MIN);
    extract_min(arr,n);
}

int main()
{
    int Q_grp[MAX + 1];

    printf("%d\n", getmin(Q_grp));

    insert(Q_grp, 10);
    insert(Q_grp, 20);
    insert(Q_grp, 30);
    insert(Q_grp, 40);
    insert(Q_grp, 50);
    insert(Q_grp, 60);
    insert(Q_grp, 70);
    insert(Q_grp, 80);
    insert(Q_grp, 90);
    insert(Q_grp, 15);

    printf("%d\n", getmin(Q_grp));
    print(Q_grp,heapsize);
    printf("%d\n", extract_min(Q_grp,MAX+1));
    print(Q_grp,heapsize);
    decrise_key(Q_grp,2,6);
    print(Q_grp,heapsize);
    delete_key(Q_grp,1,MAX+1);
    print(Q_grp,heapsize);
    return 0;
}
