#include<stdio.h>


struct edge{
    int u;
    int v;
    int w;
};

int parent[100];

int find(int i)
{
    while(parent[i]!=i)
    {
        i=parent[i];
    }
    return i;
}
void unionn(int k,int l)
{
    int ROOTu=find(k);
    int ROOTv=find(l);
    parent[ROOTv]=ROOTu;
}



int main()
{
    int i,j,n,e;
    struct edge Edges[100],temp;
    int edgescount=0;
    int u,v;
    int total=0;
    printf("Enter the number vertices:");
    scanf("%d",&n);
    printf("Enter the number of edges:");
    scanf("%d",&e);
    printf("Enter the edges in the u-v format");
    for(i=0;i<e;i++)
    {
        scanf("%d%d%d",&Edges[i].u,&Edges[i].v,&Edges[i].w);
    }

    for(i=0;i<n;i++)
    {
        parent[i]=i;
    }

    for(i=0;i<e-1;i++)
    {
        for(j=i+1;j<e;j++)
        {
            if(Edges[i].w>Edges[j].w)
            {
                temp=Edges[i];
                Edges[i]=Edges[j];
                Edges[j]=temp;
            }
        }
    }

    for(i=0;i<e && edgescount<n-1;i++)
    {
        u=Edges[i].u;
        v=Edges[i].v;
        if(find(u)!=find(v))
        {
            edgecount++;
            unionn(u,v);
            printf("%d-%d:%d",u,v,Edges[i].w);
            total=total+Edges[i].w;
        }
    }
    printf("TGhe total cost is :%d",total);
    return 0;

}
