#include <stdio.h>
#define MAX 10

int knap[MAX][MAX];

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int knapsack(int items, int capacity, int profit[], int weight[])
{
    int i, j;

    for (i = 0; i <= items; i++)
    {
        for (j = 0; j <= capacity; j++)
        {
            knap[i][j] = 0;
        }
    }

    for (i = 1; i <= items; i++)
    {
        for (j = 1; j <= capacity; j++)
        {
            if (weight[i] <= j)
            {
                knap[i][j] = max(knap[i - 1][j], profit[i] + knap[i - 1][j - weight[i]]);
            }
            else
            {
                knap[i][j] = knap[i - 1][j];
            }
        }
    }
    return knap[items][capacity];
}

int main()
{
    int i, j, n, items, capacity, profit[MAX], weight[MAX], optimum_val;
    printf("Enter No. of objects: ");
    scanf("%d", &items);
    printf("Enter the Weights: ");
    for (i = 1; i <= items; i++)
        scanf("%d", &weight[i]);
    printf("Enter the Profits: ");
    for (i = 1; i <= items; i++)
        scanf("%d", &profit[i]);
    printf("Enter the Knapsack Capacity: ");
    scanf("%d", &capacity);
    optimum_val = knapsack(items, capacity, profit, weight);
    printf("Profit Table\n");
    for (i = 0; i <= items; i++)
    {
        for (j = 0; j <= capacity; j++)
        {
            printf("%d\t", knap[i][j]);
        }
        printf("\n");
    }
    printf("The Maximum Profit is: %d\n", optimum_val);
    return 0;
}
