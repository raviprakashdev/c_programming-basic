#include<stdio.h>
int main()
{
	float km,m,cm,feet,inches;	//m = meter, km = kilometer, cm = centimeter
	printf("Enter the distance in kilometers : ");
	scanf("%f",&km);
	m = km*1000;
	cm = km*10e5;
	inches =  km*39370.0787;
	feet = km*3280.8399;
	printf("Distance in meters : %f \n",m);
	printf("Distance in centimeters : %f \n",cm);
	printf("Distance in feet : %f \n",feet);
	printf("Distance in inches : %f \n",inches);
}
