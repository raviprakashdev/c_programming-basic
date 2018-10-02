#include<stdio.h>
int main()
{
	int i, p=1,b,e;
	printf("Enter the base and exponential");
	scanf("%d %d",&b,&e);
	for( i=1;i<=e;i++)
	{
		p=p*b;
	}
printf("answer is %d",p);
	return 0;
}
