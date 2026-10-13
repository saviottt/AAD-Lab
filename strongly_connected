
#include <stdio.h>

int graph[10][10], transpose[10][10];
int stack[10], visited[10], top = -1, n;

void dfs1(int v)
{
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++)
        if (graph[v][i] == 1 && !visited[i])
            dfs1(i);

    stack[++top] = v;
}

void dfs2(int v)
{
    int i;
    visited[v] = 1;
    printf(" %d", v);

    for (i = 0; i < n; i++)
        if (transpose[v][i] == 1 && !visited[i])
            dfs2(i);
}

int main()
{
    int i, j, e, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter source and destination of edges:\n");

    for (i = 0; i < e; i++)
    {
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        transpose[v][u] = 1;
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    for (i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Strongly Connected Components:\n");

    while (top >= 0)
    {
        v = stack[top--];

        if (!visited[v])
        {
            dfs2(v);
            printf("\n");
        }
    }

    return 0;
}
