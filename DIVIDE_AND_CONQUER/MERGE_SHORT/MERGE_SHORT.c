#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void MERGE(int arr[],int low,int mid,int high,int *T_comp)
{
    int i=low,j=mid+1,k=low;
    int ele=high+1;
    int temp[ele];
    while(i<=mid && j<=high)
    {
        (*T_comp)++;
        if(arr[i]<arr[j])
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
        else{
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(int p = low; p <= high; p++)
    {
        arr[p] = temp[p];
    }
}
void MS(int arr[],int low,int high,int *T_comp)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MS(arr,low,mid,T_comp);
        MS(arr,mid+1,high,T_comp);
        MERGE(arr,low,mid,high,T_comp);
    }
}

int main()
{
    int length;
    printf("Enter the length of the array:");
    scanf("%d",&length);
    int arr[length];
    srand(time(0));
    for(int i=0;i<length;i++)
    {
        arr[i]=rand()%100;
    }
    printf("BEFFORE:");
    for(int i=0;i<length;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    int T_comp;
    MS(arr,0,length-1,&T_comp);
    printf("AFTER:");
    for(int i=0;i<length;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nTotal Comparisons = %d\n", T_comp);
    double theoretical = length * log2(length) - length + 1;
    printf("Theoretical Comparisons(MAX COMP) ≈ %.0lf\n", theoretical);
    return 0;

}