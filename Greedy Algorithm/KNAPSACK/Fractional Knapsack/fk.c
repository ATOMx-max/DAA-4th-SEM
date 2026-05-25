#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Item
{
    int profit;
    int weight;
    float ppw;
};
void FK(struct Item arr[],float sol[],int m,int n)
{
    int u=m;
    int i;
    for(i=0;i<n;i++)
    {
        sol[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(arr[i].weight>u)
        {
            sol[i]=(float)u/arr[i].weight;
            break;
        }
        sol[i]=1;
        u=u-arr[i].weight;
    }
}

void profit(struct Item arr[],float sol[],int n)
{
    float profit=0;
    for(int i=0;i<n;i++)
    {
        profit=profit+(sol[i]*arr[i].profit);
    }
    printf("Profit is:%0.2f",profit);
}






//shorting logic 
void mg(struct Item arr[], int low, int mid, int high);
void m_s(struct Item arr[], int low, int high);

void m_s(struct Item arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        m_s(arr, low, mid);
        m_s(arr, mid + 1, high);

        mg(arr, low, mid, high);
    }
}

void mg(struct Item arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    struct Item temp[high + 1];

    while(i <= mid && j <= high)
    {
        if(arr[i].ppw < arr[j].ppw)
        {
            temp[k] = arr[j];
            j++;
        }
        else
        {
            temp[k] = arr[i];
            i++;
        }

        k++;
    }

    while(i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}



int main()
{
    int n, i;

    printf("Enter number of items: ");
    scanf("%d", &n);
    int m;
    printf("Enter Capacity:");
    scanf("%d",&m);
    struct Item array[n];
    // Random seed
    srand(time(0));
    // Generate random profit and weight
    for(i = 0; i < n; i++)
    {
        array[i].profit = rand() % 100 + 1;   // 1 to 100
        array[i].weight = rand() % 20 + 1;    // 1 to 20
        array[i].ppw = (float)array[i].profit / array[i].weight;
    }

    // Display array
    printf("\nProfit\tWeight\tP/W\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%.2f\n",array[i].profit,array[i].weight,array[i].ppw);
    }
    m_s(array,0,n-1);
    printf("\nProfit\tWeight\tP/W\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%.2f\n",array[i].profit,array[i].weight,array[i].ppw);
    }

    float sol[n];
    FK(array,sol,m,n);
    printf("\nSelected Fractions:\n");

    for(i = 0; i < n; i++)
    {
        printf("Item %d -> %.2f\n", i + 1, sol[i]);
    }
    profit(array,sol,n);
    return 0;
}