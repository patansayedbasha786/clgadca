
#include <stdio.h>

int main()
{
    int n, i,j, capacity;
    float weight[20], profit[20], ratio[20];
    float x[20], totalProfit = 0, remainingCapacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%f %f", &weight[i], &profit[i]);

        ratio[i] = profit[i] / weight[i];
        x[i] = 0;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1;j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                float temp;

                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    remainingCapacity = capacity;

    for(i = 0; i < n; i++)
    {
        if(weight[i] <= remainingCapacity)
        {
            x[i] = 1.0;
            remainingCapacity -= weight[i];
            totalProfit += profit[i];
        }
        else if(remainingCapacity > 0)
        {
            x[i] = remainingCapacity / weight[i];
            totalProfit += profit[i] * x[i];
            remainingCapacity = 0;
        }
    }

    printf("\\nSolution Vector:\\n");
    for(i = 0; i < n; i++)
    {
        printf("x[%d] = %.2f\\n", i + 1, x[i]);
    }

    printf("\\nMaximum Total Profit = %.2f\\n", totalProfit);

    return 0;
}
