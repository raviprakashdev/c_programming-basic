#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) 
{
	int a;
	
	printf("enter a number: ");
	scanf("%d",&a);

	if(a %5 == 0 && a %11 == 0)
	{
		printf("it is divisible to 5 and 11");
	}
	else
	{
		printf("it is NOT divisible to 5 and 11");
	}
	
	
	return 0;
}
