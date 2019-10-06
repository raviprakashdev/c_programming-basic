#include<stdio.h>
int main()
{
	long long int x,y,temp;
	printf("Enter the two numbers which you want to swap\n");
	scanf("%lld%lld",&x,&y);
	printf("x: %lld\ny: %lld\n",x,y);
	temp=x;
	x=y;
	y=temp;
	printf("****swapped values are****\n");
	printf("swapped x: %lld\nswapped y:%lld\n",x,y);
	return 0;
}

