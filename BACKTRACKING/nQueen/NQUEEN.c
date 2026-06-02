#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
bool is_safe(int x[],int k,int pos)
{
    for(int j=1;j<=k-1;j++)
    {
        if(x[j]==pos ||abs((j-k))==abs((x[j]-pos)))return false;
    }
    return true;
}

void nqueen(int x[],int k,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(is_safe(x,k,i))
        {
            x[k]=i;
            if(k==n)
            {
                printf("SOLUCTION\n");
                for(int i=1;i<=n;i++)
                {
                    printf("Row=%d Col=%d\n",i,x[i]);
                }
                printf("\n");
            }
            else
            {
                nqueen(x,k+1,n);
            }
        }
    }
}
int main()
{
    int Q;
    printf("Enter Total number of Quene:");
    scanf("%d",&Q);
    int x[Q+1];
    nqueen(x,1,Q);
    return 0;
}