#include<stdio.h>
int main()
{
	int n,rev=0,r,temp;
	printf("enter the number that chaeck that pelentrom or not :");
	scanf("%d",&n);
	temp=n;
	while(n>0)
	{
		r=n%10;
		rev=rev*10+r;
		n=n/10;
	}
	if(temp==rev)
	printf("the given number is palentrome ");
	else
	printf("the given is not a palentrome ");
	return 0;
}
