#include <stdio.h>
#include <stdlib.h>
int *x;
int count=0;
int n;
int place(int k,int col)
{
	int i;
	for(i=1;i<k;i++)
	{
		if(x[i]==col||abs(x[i]-col)==abs(i-k))
		{
			return 0;
		}
	}
	return 1;
}
void nQueens(int k)
{
	int i,col;
	for(col=1;col<=n;col++)
	{
		if(place(k,col)==1);
		{
			x[k]=col;
			if(k==n)
			{
				count++;
				printf("Solution %d: ",count);
				for(i=1;i<=n;i++)
				{
					printf("%d ",x[i]);
				}
			printf("\n");
			}
			else
			{
				nQueens(k+1);
			}
		}
	}
}
int main()
{
	printf("Enter the value of N: ");
	scanf("%d",&n);
	if(n<=0)
	{
		printf("Invalid input");
		return 0;
	}
	x=(int *)calloc(n+1,sizeof(int));
	if(x==NULL)
	{
		printf("Memory allocation failed");
		return 1;
	}
	count=0;
	nQueens(1);
	if(count==0)
	{
		printf("No solutions exist for N = %d",n);
	}
	else
	{
		printf("Total number of solutions: %d",count);
	}
	free(x);
	return 0;
}
