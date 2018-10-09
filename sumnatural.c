#include<stdio.h>
int main()
{
	int n=10,sum=0,nn[10] ,i,j;
	for(i=0;i<n;i++)
	{
		nn[i]=i;
	
	}
	for( j=0;j<n;j++)
	{
		sum=sum+nn[j];
	}
	printf("%d",sum);
	return 0;
}
