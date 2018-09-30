#include<stdio.h>
int fact(int);
int main()
{
   int f=1,n;
   printf("Enter the no.\t");
   scanf("%d",&n);
   f=fact(n);
   printf("The factorial of %d is %d",n,f);
   return 0;	
}

int fact(int num)
{
	int i , fa=1;
	for(i=num;i>1;i--)
	{
		fa=fa*i;
	}
	return(fa);
}
