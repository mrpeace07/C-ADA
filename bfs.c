#include <stdio.h>

void BFS(int a[20][20], int source, int visited[20], int n)
{
    int queue[20], u, v;
    int f = 0;
    int r = -1;
    queue[++r] = source;
    while (f <= r)
    {
        u = queue[f++];
        for (v = 1; v <= n; v++)
        {
            if (a[u][v] == 1 && visited[v] == 0)
            {
                queue[++r] = v;
                visited[v] = 1;
            }
        }
    }
}

int main()
{
    int n, a[20][20], i, j, visited[20], source;
    printf("Enter the number of vertices:");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    printf("\nEnter the source node:");
    scanf("%d", &source);
    visited[source] = 1;
    BFS(a, source, visited, n);
    printf("\nNode Reachability Results:\n");
    for (i = 1; i <= n; i++)
    {
        if (visited[i] != 0)
            printf("\nNode %d is reachable", i);
        else
            printf("\nNode %d is not reachable", i);
    }

    return 0;
}
