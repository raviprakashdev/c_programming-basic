#include<stdio.h>
int factorial(int n);
int main()
{
	int fact=1,  n;
	printf("Enter the number ");
	scanf("%d",&n);
	fact=factorial(n);
	printf("The factorial of %d is %d",n,fact);
}
int factorial(int num)
{
	if(num==0||num==1)
	{
		return (1);
	}
	else
	{
		return (num*(factorial(num-1)));
	}
}
