#include<stdio.h>

int main()
{
    int n,cost[10][10],visited[10]={0},mincost=0;
    int i,j;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the adjacency matirx:");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    i=0;
    visited[0]=1;
    int edges=0;
    int min=0;
    int u,v;
    while(edges<n-1)
    {
        min=999;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(visited[i]==1 && visited[j]==0)
                {
                    if(cost[i][j]!=0 && cost[i][j]<min)
                    {
                        u=i;
                        v=j;
                        min=cost[i][j];
                    }
                }
        if(min==999)
        {
            printf("Graph is disconnected");
            return 0;
        }
        edges++;
        mincost=mincost+min;
        visited[v]=1;
        printf("\n%d-%d :%d",u,v,min);
    }
    return 0;
}