#include<stdio.h>
#include<stdlib.h>
void print(int ver,int g[ver+1][ver+1])
{
    printf("GRAPH is:\n");
    for(int i=1;i<=ver;i++)
    {
        for(int j=1;j<=ver;j++)
        {
            printf("%d",g[i][j]);
        }
        printf("\n");
    }
}
void nextvalue(int k,int m,int ver,int x[ver+1],int g[ver+1][ver+1])
{
    while(1)
    {
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)return;
        int j;
        for(j=1;j<=k-1;j++)
        {
            if(g[j][k]==1 && x[j]==x[k])
            {
                break;
            }
        }
        if(j==k)return;
    }
}
void m_coloring(int k,int m,int ver,int x[ver+1],int g[ver+1][ver+1])
{
    while(1)
    {
        nextvalue(k,m,ver,x,g);
        if(x[k]==0)return;
        if(k==ver)
        {
            printf("SOLUCTION:");
            for(int i=1;i<=ver;i++)
            {
                printf("%3d",x[i]);
            }
            printf("\n");
        }
        else
        {
            m_coloring(k+1,m,ver,x,g);
        }
    }

}
int main()
{
    FILE *fp;
    fp= fopen("graph.txt","r");
    if(fp==NULL)
    {
        exit(0);
    }
    int ver;
    fscanf(fp,"%d",&ver);
    int g[ver+1][ver+1];
    for(int i=1;i<=ver;i++)
    {
        for(int j=1;j<=ver;j++)
        {
            fscanf(fp,"%d",&g[i][j]);
        }
    }
    printf("vertex:=%d",ver);
    print(ver,g);
    int m;
    printf("Enter the total collor:");
    scanf("%d",&m);
    int x[ver+1];
    for(int i=0;i<=ver;i++)
    {
        x[i]=0;
    }
    m_coloring(1,m,ver,x,g);
}