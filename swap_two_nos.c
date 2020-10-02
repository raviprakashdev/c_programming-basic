#include<stdio.h>
int main()
{
	int x,y,temp;
	printf("Enter the two numbers which you want to swap\n");
	scanf("%d %d",&x,&y);
	printf("x: %d\n y: %d\n",x,y);
	temp=x;
	x=y;
	y=temp;
	printf("****swapped values are****\n");
	printf("swapped x: %d\n swapped y:%d\n",x,y);
	return 0;
}

