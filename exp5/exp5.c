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
void unionset(int root1,int root2)
{
	parent[root1]=root2;
}
int main()
{
	int ver,edg;
	int i,j;
	int count=0;
	int totalcost=0;
	int root1,root2;
	struct Edge edge[100],temp;
	printf("enter no.of vertices ");
	scanf("%d",&ver);
	printf("enter the no.of edges");
	scanf("%d",&edg);
	printf("enter the edge connection");
	for(i=0;i<edg;i++)
	{
		printf("\nedges %d:",i+1);
		scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].cost);
	}
	for(i=1;i<=ver;i++)
	{
		parent[i]=i;
	}
	for(i=0;i<edg;i++)
	{
		for(j=i+1;j<edg;j++)
		{
			if(edge[i].cost>edge[j].cost)
			{
				temp=edge[i];
				edge[i]=edge[j];
				edge[j]=temp;
			}
		}
	}
	printf("seleted edges\n");
	for(i=0;i<edg;i++)
	{
		root1=find(edge[i].u);
		root2=find(edge[i].v);
		if(root1!=root2)
		{
			printf("%d----%d: %d\n",edge[i].u,edge[i].v,edge[i].cost);
			totalcost=totalcost+edge[i].cost;
			unionset(root1,root2);
			count++;
			if(count==ver-1)
			{
				break;
			}
		}
	}
	if(count==ver-1)
	{
		printf("min cost =%d\n",totalcost);
	}
	else
	{
		printf("all houses connot be connected");
	}
	return 0;
}

