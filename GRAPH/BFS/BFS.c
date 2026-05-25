#include<stdio.h>
#include<stdlib.h>
void print(int n,int arr[][n])
{
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-1;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    FILE *fp;
    int n;
    fp=fopen("ex.txt","r");
    if(fp==NULL)
    {
        printf("ERROR");
        exit(1);
    }
    fscanf(fp,"%d",&n);
    int grp[n][n];
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-1;j++)
        {
            fscanf(fp,"%d",&grp[i][j]);
        }
    }
    print(n,grp);

}