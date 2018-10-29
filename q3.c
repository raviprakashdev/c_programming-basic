#include<stdio.h>
int main()
{
	int n,nn[1000],i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		nn[i]=i;
	
	}
	
	for( j=0;j<n;j++)
	{
		if(nn[j]%2!=0)
		{
		printf("%d",nn[j]);
	}
}
for( j=n-1;j>0;j--)
	{
	if(nn[j]%2==0)
	{
		
		printf("%d",nn[j]);
	}
}

	return 0;
}
