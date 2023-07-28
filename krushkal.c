#include <stdio.h>

void kruskal(int cost[10][10], int n)
{
    int parent[10], i, j, a, b, u, v, min, count = 1, sum = 0;
    for (i = 1; i <= n; i++)
        parent[i] = 0;
    while (count != n)
    {
        min = 999;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = a = i;
                    v = b = j;
                }
        while (parent[u] != 0)
            u = parent[u];
        while (parent[v] != 0)
            v = parent[v];
        if (u != v)
        {
            count++;
            sum = sum + cost[a][b];
            printf("\nEdge (%d,%d) : %d", a, b, cost[a][b]);
            parent[v] = u;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nWeight of minimum spanning tree = %d\n", sum);
}

int main()
{
    int cost[10][10], i, j, n;
    printf("\nEnter the number of vertices : ");
    scanf("%d", &n);
    printf("\nEnter the cost matrix : \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);
    kruskal(cost, n);
    return 0;
}
