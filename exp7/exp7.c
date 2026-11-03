#include <stdio.h>
#define INF 99999
#define MAX 100
int main()
{
    int n,i,j,k;
    int dist[MAX][MAX],next[MAX][MAX];
    printf("Enter number of locations: ");
    scanf("%d",&n);
    printf("Enter the distance matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&dist[i][j]);
            if(i==j)
                dist[i][j]=0;
            else if(dist[i][j]==0)
                dist[i][j]=INF;
            if(i!=j && dist[i][j]!=INF)
                next[i][j]=j;
            else
                next[i][j]=-1;
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dist[i][k]!=INF &&
                   dist[k][j]!=INF &&
                   dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    next[i][j]=next[i][k];
                }
            }
        }
    }
    printf("\nShortest Distance Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(dist[i][j]==INF)
                printf("INF ");
            else
                printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
    printf("\nShortest path from location:\n");
    for(j=1;j<n;j++)
    {
        if(next[0][j]==-1)
        {
            printf("Location %d: No path",j+1);
        }
        else
        {
            int current=0;
            printf("\nLocation %d\n",j+1);
            printf("Minimum distance: %d\n",dist[0][j]);
            printf("Shortest path: ");
            printf("%d",current+1);
            while(current!=j)
            {
                current=next[current][j];
                printf(" -> %d",current+1);
            }
        }
        printf("\n");
    }
    return 0;
}
