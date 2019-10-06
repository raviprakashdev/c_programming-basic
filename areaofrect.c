//programme to calculate the area and perimeter of a rectangle
#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter the length and breadth of the rectangle\n");
	scanf("%d%d",&a,&b);
	printf("area of the rectangle: %d\nperimeter of the rectangle: %d\n",a*b,(2*(a+b)));
	return 0;
}
