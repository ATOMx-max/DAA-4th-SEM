#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>
void matrix_chain_mul(int n,int M[n][n],int S[n][n],int p[n])
{
    int mat=n-1;
    for(int i=1;i<=mat;i++)
    {
        M[i][i]=0;
    }
    for(int len=2;len<=mat;len++)
    {
        for(int i=1;i<=mat-len+1;i++)
        {
            int j=i+len-1;
            M[i][j]=INT_MAX;
            int cost =0;
            for(int k=i;k<=j-1;k++)
            {
                cost=M[i][k]+M[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(cost<M[i][j])
                {
                    M[i][j]=cost;
                    S[i][j]=k;
                }
            }
        }
    }

}
int main()
{
    int no_mat;
    printf("Enter the total number of matrix:");
    scanf("%d",&no_mat);
    int p[no_mat+1];
    srand(time(NULL));
    p[0]=(rand()%10)+1;
    for(int i=1;i<=no_mat;i++)
    {
        p[i]=(rand()%10)+1;
    }
    printf("\nMatrix Orders:\n");
    for(int i = 1; i <= no_mat; i++)
    {
        printf("A%d = %d x %d\n", i, p[i-1], p[i]);
    }
    int M[no_mat+1][no_mat+1],S[no_mat+1][no_mat+1];
    matrix_chain_mul(no_mat+1, M, S, p);
    printf("\nM Table:\n");

for(int i=1;i<=no_mat;i++)
{
    for(int j=1;j<=no_mat;j++)
    {
        if(i>j)
            printf("-\t");
        else
            printf("%d\t",M[i][j]);
    }
    printf("\n");
}
printf("\nS Table:\n");

for(int i=1;i<=no_mat;i++)
{
    for(int j=1;j<=no_mat;j++)
    {
        if(i>=j)
            printf("-\t");
        else
            printf("%d\t",S[i][j]);
    }
    printf("\n");
}
    return 0;
}