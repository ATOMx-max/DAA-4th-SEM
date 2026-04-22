#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* create(int key)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=key;
    temp->next=NULL;
    return temp;
}
void insert_end(struct node **head,int key)
{
    struct node *new=create(key);
    if(*head==NULL)
    {
        *head=new;
        return;
    }
    struct node *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
}

int main()
{
    FILE *fp;
    fp=fopen("ex.txt","r");
    if(fp==NULL)
    {
        printf("ERROR");
        exit(1);
    }
    int n;
    fscanf(fp,"%d",&n);
    //store
    int grp[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            fscanf(fp,"%d",&grp[i][j]);
        }
    }
    fclose(fp);
    struct node *table[n];
    for(int i=0;i<n;i++)
    {
        table[i]=NULL;
        for(int j=0;j<n;j++)
        {
            if(grp[i][j]==1)//j is the adjacent vertex
            {
                insert_end(&table[i],j);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d -> ", i);

        struct node *temp = table[i];

        while(temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}