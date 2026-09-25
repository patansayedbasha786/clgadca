#include <stdio.h>
int main()
{
	int a[100],n,key,i;
	printf("enter the array size");
	scanf("%d",&n);
	printf("enter the array elements ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the key values: ");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			printf("the position is matched: %d",i+1);
			return 0;
		}
	}
	printf("the position is not matched");
	return 0;
}
