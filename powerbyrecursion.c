#include<stdio.h>
int power(int b,int e);
int main()
{
	int i, p=1,b,e;
	printf("Enter the base and exponential");
	scanf("%d %d",&b,&e);
    p=power(b,e);
printf("answer is %d",p);
	return 0;
}
int power(int b, int e)
{
	if(e!=0)
	{
		return(b*power(b,e-1));
	}
	else
	return(1);
}
