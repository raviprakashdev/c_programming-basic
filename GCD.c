#include<stdio.h>
int gcd(int , int);
int main()
{
	int n1 ,n2 , result;
	printf("Enter the two number");
	scanf("%d %d",&n1,&n2);
	result=gcd(n1,n2);
	printf("The result of gcd is %d",result);
    return 0;
}
int gcd(int n1 ,int n2)
{
	int rem;
	rem=n1%n2;
	if(rem==0)
	{
		return (n2);
	}
	else
	return (gcd(n2,rem));
}

