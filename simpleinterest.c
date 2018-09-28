//THis is calculation of simple interest for 3 sets or p , n , r;

#include<stdio.h>
void main()
{
	int p , n , count;
	float r , si;
	for(count=1;count<=3;count=count+1)
	{
		printf("Enter the value of p , n ,r");
		scanf("%d %d %f",&p,&n,&r);
		si=(p*n*r)/100;
		printf("Simple interest = RS.%f\n ",si);
	}
	
}
