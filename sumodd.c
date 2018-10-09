#include<stdio.h>
int main()
{
	int n=10,sum=0,nn[10] ,i,j ,rem;
	for(i=0;i<n;i++)
	{
		nn[i]=i;
	
	}
	for( j=0;j<n;j++)
	{
		rem=nn[j]%2;
		if(rem!=0)
		{
	    sum=sum+nn[j];	
		}
	
	}
	printf("%d",sum);
	return 0;
}
