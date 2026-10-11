
#include <stdio.h>

int n, cost[10][10];
int visited[10] = {0};
int mincost = 9999;

void tsp(int city, int count, int total)
{
    int i;

    if (count == n)
    {
        if (cost[city][0] != 0 && total + cost[city][0] < mincost)
        {
            mincost = total + cost[city][0];
        }
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (!visited[i] && cost[city][i] != 0)
        {
            visited[i] = 1;

            tsp(i, count + 1, total + cost[city][i]);

            visited[i] = 0;
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    visited[0] = 1;

    tsp(0, 1, 0);

    if (mincost == 9999)
        printf("No possible tour\n");
    else
        printf("Minimum cost = %d\n", mincost);

    return 0;
}
