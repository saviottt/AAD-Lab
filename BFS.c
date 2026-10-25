
void bfs(int start)
{
    int front = 0, rear = 0;
    int i, v;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

