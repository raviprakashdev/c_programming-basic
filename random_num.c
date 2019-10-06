#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int n,num,i;
	srand(time(0));
	printf("Enter number of random numbers:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		num=rand();
		printf("%d\n",num);
	}
	return 0;
}
