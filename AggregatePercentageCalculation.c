#include<stdio.h>
int main()
{
	float s1,s2,s3,s4,s5,aggregate,percentage;	//s1,s2,s3,s4,s5 are the marks of five subjects 
	printf("Enter the marks of five subjects : ");
	scanf("%f%f%f%f%f",&s1,&s2,&s3,&s4,&s5);
	aggregate = (s1+s2+s3+s4+s5)*100/500;
	percentage = (s1+s2+s3+s4+s5)*100/500;
	printf("Aggregate marks : %f \n",aggregate);
	printf("Percentage marks : %f",percentage);
	return 0;
}
