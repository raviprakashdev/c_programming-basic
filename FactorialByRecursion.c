//Program to calculate factorial of a number using recursion concept
#include <stdio.h>
long factorial(int);

int main(void) {
	long num;
  printf("\nEnter the number: ");
	scanf("%ld",&num);
	printf("\nThe factorial of %ld is %ld \n\n",num,factorial(num));
	return 0;
}

long factorial(int n)
{
	if(n==1)
		return 1;
	return n*factorial(n-1);
}
