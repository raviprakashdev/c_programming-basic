#include<stdio.h>
#include<math.h>
void main()

{
	typedef struct point
	{
		int x,y;
	}point;
	point p1,p2;
	float distance;
	printf("/nEnter the coordinate of first pt");
	scanf("%d %d",&p1.x,&p1.y);
	printf("/nEnter the coordinate of second pt");
	scanf("%d %d",&p2.x,&p2.y);
	distance=sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2));
	printf("The distance between p1 &p2 = %f",distance);
}
