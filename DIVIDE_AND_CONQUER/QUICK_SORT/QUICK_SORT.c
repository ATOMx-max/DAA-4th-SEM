#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void QSL(int arr[],int low,int high,int *T_COMP);
void QSH(int arr[],int low,int high,int *T_COMP);
int Lpartiction(int arr[],int low,int high,int *T_COMP);
int Hpartiction(int arr[],int low,int high,int *T_COMP);
void swap(int arr[],int i,int j);

void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void QSL(int arr[],int low,int high,int *T_COMP)
{
    if(low<high)
    {
        int pi=Lpartiction(arr,low,high,T_COMP);
        QSL(arr,low,pi-1,T_COMP);
        QSL(arr,pi+1,high,T_COMP);
    }
}
void QSH(int arr[],int low,int high,int *T_COMP)
{
    if(low<high)
    {
        int pi=Hpartiction(arr,low,high,T_COMP);
        QSH(arr,low,pi-1,T_COMP);
        QSH(arr,pi+1,high,T_COMP);
    }
}
void RQS(int arr[],int low,int high,int *T_COMP)
{
    if(low<high)
    {
        int r=(rand()%(high-low+1))+low;
        //follow Hpartiction
        swap(arr,r,low);
        int pi=Hpartiction(arr,low,high,T_COMP);
        RQS(arr,low,pi-1,T_COMP);
        RQS(arr,pi+1,high,T_COMP);
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

int Hpartiction(int arr[],int low,int high,int *T_COMP)
{
    int privo=arr[low];
    int i=low;
    int j=high+1;
    while(i<j)
    {
        do{i++; }while(arr[i]<=privo);
        do{j--;}while(arr[j]>privo);
        (*T_COMP)++;
        if(i<j)
        {
            swap(arr,i,j);
        }
    }
    swap(arr,low,j);
    return j;
}
int main()
{
    srand(time(0));

    // 🔹 Input size
    int n = rand()%20 + 1;
    printf("Total number of elements: %d\n\n", n);

    // 🔹 Arrays for comparison
    int arr1[n], arr2[n], arr3[n];

    // 🔹 Generate same random data
    for(int i = 0; i < n; i++)
    {
        int val = rand() % 100;
        arr1[i] = arr2[i] = arr3[i] = val;
    }

    // 🔹 Print original array
    printf("Original Array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    printf("\n\n");

    // 🔹 Comparison counters
    int compL = 0, compH = 0, compR = 0;

    // 🔹 Sorting
    QSL(arr1, 0, n-1, &compL);   // Lomuto
    QSH(arr2, 0, n-1, &compH);   // Hoare
    RQS(arr3, 0, n-1, &compR);   // Randomized + Hoare

    // 🔹 Output results
    printf("Sorted Arrays:\n");

    printf("Lomuto:            ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    printf("\n");

    printf("Hoare:             ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr2[i]);
    printf("\n");

    printf("Randomized Hoare:  ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr3[i]);
    printf("\n\n");

    // 🔹 Comparison results
    printf("Comparisons:\n");
    printf("Lomuto           : %d\n", compL);
    printf("Hoare            : %d\n", compH);
    printf("Randomized Hoare : %d\n\n", compR);

    // 🔹 Theoretical values
    double best = n * log2(n);
    int worst = (n * (n - 1)) / 2;

    printf("Theoretical Analysis:\n");
    printf("Best Case  (n log n)     : %.2lf\n", best);
    printf("Worst Case (n(n-1)/2)    : %d\n", worst);

    return 0;
}