#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void MAX_MIN



int main() {
    int length;
    printf("Enter the lenght of the array:");
    scanf("%d",&length);
    int arr[length];
    int i;
    srand(time(0));
    for (i=0;i<=length;i++)
    {
        arr[i]=rand()%100;
    }
    for(i=0;i<=length;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");


    return 0;
}