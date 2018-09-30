#include<stdio.h>
int main()
{
	int i=1 ,a , t;
	printf("Enter the no. of which you want the table to print\t");
	scanf("%d",&a);
	while(i<=10)
	{
		t=a*i;
		printf("%d * %d = %d \n ",a,i,t);
		i++;
	}
	return 0;
}
	
