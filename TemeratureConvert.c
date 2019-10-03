#include<stdio.h>
int main()
{
	float fahrenheit,centigrate;
	printf("Enter the temperature in degree Fahrenheit : ");
	scanf("%f",&fahrenheit);
	centigrate = 5*(fahrenheit-32)/9;
	printf("Temperature in degree centigrate : %f",centigrate);
	return 0;
}
