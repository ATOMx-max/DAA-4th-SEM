#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void MAX_MIN(int arr[],int i,int j,int *T_comp,int *max,int *min)
{
    int max1,min1,mid;
    if(i==j)//single element
    {
        *max=arr[i];
        *min=arr[i];
    }
    else if (i==j-1)//2 element
    {
        (*T_comp)++;
        if(arr[i]>arr[j])
        {
            *max=arr[i];
            *min=arr[j];
        }
        else
        {
            *max=arr[j];
            *min=arr[i];
        }
    }
    else
    {
        mid=(i+j)/2;
        MAX_MIN(arr,i,mid,T_comp,max,min);//already pointers
        MAX_MIN(arr,mid+1,j,T_comp,&max1,&min1);
        (*T_comp)++; 
        if(max1>*max)
        {
            *max=max1;
        }
        (*T_comp)++; 
        if(min1<*min)
        {
            *min=min1;
        }
    }
}


int main() {
    int length;
    printf("Enter the lenght of the array:");
    scanf("%d",&length);
    int arr[length];
    int i;
    srand(time(0));
    for (i=0;i<length;i++)
    {
        arr[i]=rand()%100;
    }
    for(i=0;i<length;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    int max;
    int min;
    int T_comp=0;
    MAX_MIN(arr,0,length-1,&T_comp,&max,&min);
    printf("Max = %d\nMin = %d\n", max, min);
    printf("TOTAL COMP (((3*n/2))-1)=%d\n",((3*length/2)-2));
    printf("TOTAL COMP (PRACTICAL):%d\n",T_comp);
    printf("Conclusion\nThis  method splits recursively → loses one comparison efficiency when n is not power of 2");

    return 0;
}