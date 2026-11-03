#include <stdio.h>
struct Edge
{
    int u,v,cost;
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
void unionSet(int root1,int root2)
{
    parent[root1]=root2;
}
int main()
{
    int V,E;
    int i,j;
    int count=0;
    int totalCost=0;
    struct Edge edge[100],temp;
    printf("Enter number of houses (vertices): ");
    scanf("%d",&V);
    printf("Enter number of pipe connections (edges): ");
    scanf("%d",&E);
    printf("\nEnter pipe connections (u v cost):\n");
    for(i=0;i<E;i++)
    {
        printf("Edge %d: ",i+1);
        scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].cost);
    }
    for(i=1;i<=V;i++)
    {
        parent[i]=i;
    }
    for(i=0;i<E-1;i++)
    {
        for(j=i+1;j<E;j++)
        {
            if(edge[i].cost>edge[j].cost)
            {
                temp=edge[i];
                edge[i]=edge[j];
                edge[j]=temp;
            }
        }
    }
    printf("\nSelected Edges:\n");
    for(i=0;i<E;i++)
    {
        int root1=find(edge[i].u);
        int root2=find(edge[i].v);
        if(root1!=root2)
        {
            printf("%d -- %d : %d\n",
                   edge[i].u,
                   edge[i].v,
                   edge[i].cost);
            totalCost=totalCost+edge[i].cost;
            unionSet(root1,root2);
            count++;
            if (count==V-1)
            {
                break;
            }
        }
    }
    if(count==V-1)
    {
        printf("\nMinimum Cost = %d\n", totalCost);
    }
    else
    {
        printf("\nAll houses canot be connected /n");
      }
      return 0;
  }
