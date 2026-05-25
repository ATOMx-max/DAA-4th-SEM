#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10
//Floow max heap
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
        if(key>arr[j])break;
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