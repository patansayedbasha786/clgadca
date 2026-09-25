#include<stdio.h>
int main()
{
	int a=0,b=1,c;
	printf("fibnacci series up to 100\n");
	while(a<=100)
	{
		printf("%d",a);
		c=a+b;
		a=b;
		b=c;
	}
	return 0;
}
