#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 

{
	int a,b,c;
	
	printf("Enter 3 numbers: ");
	scanf("%d,%d,%d",&a,&b,&c);
	
	if(a>b && a>c)
	{
		printf("your first entry is MAX = %d");
	}
		if(b>a && b>c)
		{
			printf("your second entry is MAX = %d");
		}
			if(c>a && c>b)
			{
				printf("your third entry is MAX = %d");
			}
		
	return 0;
}
