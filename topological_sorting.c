
#include <stdio.h>

int graph[10][10], visited[10], stack[10];
int n, top = -1;

void dfs(int v)
{
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }

    stack[++top] = v;
}

int main()
{
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            dfs(i);
    }

    printf("Topological Sorting: ");
    while (top != -1)
        printf("%d ", stack[top--]);

    return 0;
}
