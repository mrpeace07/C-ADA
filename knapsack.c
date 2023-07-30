#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapSack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
            printf("%d ", dp[i][j]);
        printf("\n");
    }

    int i = n, j = W;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
        {
            printf("OBJECT %d = 0\n", i--);
        }
        else
        {
            printf("OBJECT %d = 1\n", i--);
            j = j - wt[i];
        }
    }
    printf("the total profit is %d\n", dp[n][W]);
}

int main()
{
    int val[10], wt[10], n, W;
    printf("Enter number of objects and cap:\t");
    scanf("%d %d", &n, &W);
    printf("Enter value and weight for each:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &val[i], &wt[i]);
    knapSack(W, wt, val, n);
    
    return 0;
}
