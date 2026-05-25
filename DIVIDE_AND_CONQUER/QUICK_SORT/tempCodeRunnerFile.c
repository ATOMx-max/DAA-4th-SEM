#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void QS(int arr[],int low,int high,int *T_COMP);
int Lpartiction(int arr[],int low,int high,int *T_COMP);
void swap(int arr[],int i,int j);

void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}


void QS(int arr[],int low,int high,int *T_COMP)
{
    if(low<high)
    {
        int pi=Lpartiction(arr,low,high,T_COMP);
        QS(arr,low,pi-1,T_COMP);
        QS(arr,pi+1,high,T_COMP);
    }
}
int Lpartiction(int arr[],int low,int high,int *T_COMP)
{
    int i=low-1;
    int privo=arr[high];
    for(int j=low;j<high;j++)
    {
        (*T_COMP)++;
        if(arr[j]<privo)
        {
            i++;
            swap(arr,i,j);
        }
    }
    i++;
    swap(arr,i,high);//privo
    return i;
}

int main()
{
    srand(time(0));
    int n=rand()%20+1;
    printf("Total number of element:%d\n",n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100;
    }
    printf("Before:");
    for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
    int T_COMP=0;
    QS(arr,0,n-1,&T_COMP);
    printf("AFTER:");
    for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");

    return 0;
}