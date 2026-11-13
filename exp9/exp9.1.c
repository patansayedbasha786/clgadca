#include <stdio.h>
#define MAX 15
#define INF 999999
int n;
int distance[MAX][MAX];
int dp[1 << MAX][MAX];
int TSP(int mask,int pos)
{
	int city;
    if(mask==(1<<n)-1)
    {
        return distance[pos][0];
    }
    if(dp[mask][pos]!=-1)
    {
        return dp[mask][pos];
    }
    int minCost=INF;
    for (city=0;city<n;city++)
    {
        if(!(mask&(1<<city)))
        {
            int newMask=mask | (1<<city);
            int cost=distance[pos][city]+TSP(newMask,city);
            if(cost<minCost)
            {
                minCost=cost;
            }
        }
    }
    dp[mask][pos]=minCost;
    return minCost;
}
void PRINT_PATH()
{
    int mask=1;
    int pos=0;
    int city;
    printf("\nOptimal Route: ");
    printf("1");
    while(mask!=(1<<n)-1)
    {
        int nextCity=-1;
        int minCost=INF;
        for(city=0;city<n;city++)
        {
            if(!(mask&(1<<city)))
            {
                int cost = distance[pos][city]+ TSP(mask | (1 << city), city);
                if (cost < minCost)
                {
                    minCost = cost;
                    nextCity = city;
                }
            }
        }
        pos = nextCity;
        mask = mask | (1 << pos);

        printf("%d ", pos + 1);
    }
    printf("1\n");
}
int main()
{
	int mask;
	int city;
	int i,j;
    printf("Enter number of hospitals: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX)
    {
        printf("Invalid number of hospitals!\n");
        return 1;
    }
    printf("Enter distance matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &distance[i][j]);
        }
    }
    for (mask = 0; mask < (1 << n); mask++)
    {
        for (city = 0; city < n; city++)
        {
            dp[mask][city] = -1;
        }
    }
    int minimumDistance = TSP(1, 0);
    printf("\nMinimum Travel Distance: %d\n",minimumDistance);
    PRINT_PATH();
    return 0;
}
