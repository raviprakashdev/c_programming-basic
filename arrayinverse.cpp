#include<stdio.h>
int main ()
{
	int n=0 , i;
	int arr[100];
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	
		scanf("%d",&arr[i]);
	}
	for(int j=n-1;j>=0;j--)
	{
		printf("%d ",arr[j]);
	}
	return 0;
}
