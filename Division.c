#include <stdio.h>
#include <stdlib.h>


int main() 
{
	int a,b,c;
	
	printf("enter a number: ");
	scanf("%d",&a);
	
	printf("enter another number: ");
	scanf("%d",&b);
	
	printf("enter another number: ");
	scanf("%d",&c);
	

if (a / b == 0 || a / c == 0 )
    {
        printf("a is divesible by both a and b");
    }
else
    {
        printf("a is not divisible ");
    }
	return 0;
}
