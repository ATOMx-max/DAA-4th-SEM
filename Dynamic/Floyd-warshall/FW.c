#include<stdio.h>
#include<limits.h>
void floydwarshall(int ver,int w[ver][ver],int d[ver][ver],int p[ver][ver])
{
    for(int i=0;i<ver;i++)
    {
        for(int j=0;j<ver;j++)
        {
            d[i][j]=w[i][j];
            if(d[i][j]==0 || d[i][j]==99999)
            {
                p[i][j]=-1;
            }
            else
            {
                p[i][j]=i;
            }
        }
    }

    for(int k=0;k<ver;k++)
    {
        for(int i=0;i<ver;i++)
        {
            for(int j=0;j<ver;j++)
            {
                if(d[i][k]+d[k][j]<d[i][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=p[k][j];
                }
            }
        }
    }
}
int main()
{
    FILE *fp;
    int ver;
    fp=fopen("graph.txt","r");
    fscanf(fp,"%d",&ver);
    printf("VERTEXT:%d\n",ver);
    int w[ver][ver];
    for(int i=0;i<ver;i++)
    {
        for(int j=0;j<ver;j++)
        {
            fscanf(fp,"%d",&w[i][j]);
        }
    }
    for(int i=0;i<ver;i++)
    {
        for(int j=0;j<ver;j++)
        {
            printf("%d\t",w[i][j]);
        }
        printf("\n");
    }
    fclose(fp);
    int  D[ver][ver];
    int P[ver][ver];
    floydwarshall(ver,w,D,P);
    printf("\n");
    printf("D is:\n");
    for(int i=0;i<ver;i++)
    {
        for(int j=0;j<ver;j++)
        {
            printf("%d\t",D[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("D is:\n");
    for(int i=0;i<ver;i++)
    {
        for(int j=0;j<ver;j++)
        {
            printf("%d\t",P[i][j]);
        }
        printf("\n");
    }
    return 0;
}