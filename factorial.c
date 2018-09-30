#include<stdio.h>
int main()
{
int i,f=1,n;
printf("Enter the no.\t");
scanf("%d",&n);
for(i=n;i>1;i--)
{
	f=f*i;
}
printf("The factorial of %d is %d",n,f);
return 0;
}
