#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
struct VER{
    int key;
    int p;
};
bool bellmanford(struct VER sol[],int ver,int w[ver][ver],int r)
{
    // Initialization
    for(int i=0;i<ver;i++)
    {
        sol[i].key=INT_MAX;
        sol[i].p=-1;
    }
    sol[r].key=0;
    // Relax edges V-1 times
    for(int k=1;k<=ver-1;k++)
    {
        for(int u=0;u<ver;u++)
        {
            for(int v=0;v<ver;v++)
            {
                if(w[u][v]!=0 && sol[u].key != INT_MAX && sol[u].key+w[u][v]<sol[v].key)
                    {
                        sol[v].key=sol[u].key+w[u][v];
                        sol[v].p=u;
                    }
            }
        }
    }

    //checking negative weight cycle
    for(int u=0;u<ver;u++)
    {
        for(int v=0;v<ver;v++)
        {
            if(w[u][v]!=0 && sol[u].key != INT_MAX && sol[u].key+w[u][v]<sol[v].key)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    FILE *fp;
    fp=fopen("graph.txt","r");
    if(fp==NULL)
    {
        printf("Error");
        exit(1);
    }
    int ver;
    fscanf(fp,"%d",&ver);
    printf("%d\n",ver);
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
    struct VER sol[ver];
    fclose(fp);
    if(bellmanford(sol,ver,w, 0))
    {
        printf("\nShortest Paths:\n");

        for(int i = 0; i < ver; i++)
        {
            printf("Vertex %d -> Cost = %d Parent = %d\n",
                   i,
                   sol[i].key,
                   sol[i].p);
        }
    }
    else
    {
        printf("\nNegative Weight Cycle Detected\n");
    }

}