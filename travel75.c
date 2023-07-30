#include <stdio.h>
int c[100][100], s, ver, path[10];
float optimum = 999, sum;

int swap(int v[], int i, int j)
{
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void tsp(int v[], int n, int i)
{
    int sum1, j, k;
    if (i == n)
    {
        if (v[0] == s)
        {
            for (j = 0; j < n; j++)
                sum1 = 0;
            for (k = 0; k < n - 1; k++)
            {
                sum1 = sum1 + c[v[k]][v[k + 1]];
            }
            sum1 = sum1 + c[v[n - 1]][s];
            if (sum1 < optimum)
            {
                optimum = sum1;
                for (k = 0; k < n; k++)
                    path[k] = v[k];
            }
        }
    }
    else
    {
        for (j = i; j < n; j++)
        {
            swap(v, i, j);
            tsp(v, n, i + 1);
            swap(v, i, j);
        }
    }
}

void approx(int ver)
{
    int min, p, i, j, vis[20], from;
    for (i = 1; i <= ver; i++)
        vis[i] = 0;
    vis[s] = 1;
    from = s;
    printf("the approx.path is %d", s);
    sum = 0;
    for (j = 1; j < ver; j++)
    {
        min = 999;
        for (i = 1; i <= ver; i++)
            if (vis[i] != 1 && c[from][i] < min && c[from][i] != 0)
            {
                min = c[from][i];
                p = i;  
            }
        vis[p] = 1;
        from = p;
        printf("-->%d", p);
        sum = sum + min;
    }
    sum = sum + c[from][s];
    printf("-->%d\n", s);
}

int main()
{
    int v[100], ver, i, j;
    printf("Enter No. of vertices: ");
    scanf("%d", &ver);
    for (i = 0; i < ver; i++)
        v[i] = i + 1;
    printf("Enter the Cost matrix \n");
    for (i = 1; i <= ver; i++)
        for (j = 1; j <= ver; j++)
        {
            scanf("%d", &c[i][j]);
            if (c[i][j] == 0)
                c[i][j] = 999;
        }
    printf("Enter Source: ");
    scanf("%d", &s);
    tsp(v, ver, 0);
    printf("Shortest path for Optimal Solution: ");
    for (i = 0; i < ver; i++)
        printf("%d -> ", path[i]);
    printf("%d\n", path[0]);
    printf("\nOptimum solution is = %f\n", optimum);
    approx(ver);
    printf("Solution with Approximation Algorithm is = %f\n", sum);
    printf("The approximation value is = %.2f\n", ((sum / optimum) - 1) * 100);
    return 0;
}
