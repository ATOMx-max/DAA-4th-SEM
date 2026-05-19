#include<stdio.h>
#include<stdlib.h>
struct EG{
    int v1;
    int v2;
    int w;
};
int p[100];
struct EG soluction[100];
void m_s(struct EG arr[],int low,int high);
void mg(struct EG arr[],int low,int mid,int high);
void kruskal(struct EG arr[],int e,int ver);
void makeset(int ver);
int find(int v);
void unionset(int u,int v);


void makeset(int ver)
{
    for(int i=0;i<ver;i++)
    {
        p[i]=-1;
    }
}
int find(int v)
{
    while(p[v]!=-1)
    {
        v=p[v];
    }
    return v;
}
void unionset(int u,int v)//v-->u
{
    p[v]=u;
}
int k=0;//element in the soluction array
void kruskal(struct EG arr[],int e,int ver)
{
    makeset(ver);
    for(int i=0;i<e;i++)
    {
        int u=find(arr[i].v1);//parent node for v1
        int v=find(arr[i].v2);//parent node for v2
        if(u!=v)//check no cycle
        {
            soluction[k].v1=arr[i].v1;
            soluction[k].v2=arr[i].v2;
            soluction[k].w=arr[i].w;
            //unionset(arr[i].v1,arr[i].v2);
            unionset(u,v);
            k++;
        }
    }

}

void m_s(struct EG arr[],int low,int high)
{

    if(low<high)
    {
        int mid=(low+high)/2;
        m_s(arr,low,mid);
        m_s(arr,mid+1,high);
        mg(arr,low,mid,high);
    }
}
void mg(struct EG arr[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    struct EG temp[100];
    while(i<=mid && j<=high)
    {
        if(arr[i].w>arr[j].w)
        {
            temp[k].w=arr[j].w;
            temp[k].v1=arr[j].v1;
            temp[k].v2=arr[j].v2;
            j++;
        }
        else
        {
            temp[k].w=arr[i].w;
            temp[k].v1=arr[i].v1;
            temp[k].v2=arr[i].v2;
            i++;
        }
        k++;
    }
    while(i<=mid)
    {
        temp[k].w=arr[i].w;
        temp[k].v1=arr[i].v1;
        temp[k].v2=arr[i].v2;
        k++;
        i++;
    }
    while(j<=high)
    {
        temp[k].w=arr[j].w;
        temp[k].v1=arr[j].v1;
        temp[k].v2=arr[j].v2;
        j++;
        k++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i].w=temp[i].w;
        arr[i].v1=temp[i].v1;
        arr[i].v2=temp[i].v2;
    }
}


int main()
{
    FILE *fp;
    fp=fopen("graph.txt","r");
    if(fp==NULL)
    {
        printf("ERROR");
        exit(1);
    }
    int ver,eg;
    fscanf(fp,"%d",&ver);
    fscanf(fp,"%d",&eg);
    struct EG side[eg];
    printf("Vertex=%d\nEdges=%d\n",ver,eg);
    for(int i=0;i<eg;i++)
    {
        fscanf(fp,"%d%d%d",&side[i].v1,&side[i].v2,&side[i].w);
    }
    printf("V1 V2 W\n");
    for(int i=0;i<eg;i++)
    {
        printf("%d %d %d\n",side[i].v1,side[i].v2,side[i].w);
    }
    fclose(fp);
    m_s(side,0,eg-1);
    printf("\nV1 V2 W\n");
    for(int i=0;i<eg;i++)
    {
        printf("%d %d %d\n",side[i].v1,side[i].v2,side[i].w);
    }

    kruskal(side,eg,ver);
    int i=0;
    printf("SOLUCTION ARRAY:\n");
    for(int i=0;i<k;i++)
    {
        printf("%d %d %d\n",soluction[i].v1,soluction[i].v2,soluction[i].w);
    }
}