#include<stdio.h>
int main()
{
	int arr[10] = {1 ,2,3,4,5,6,7,8,9,10};
	int n=10,sum=0 ,i,j;
	for( j=0;j<n;j++)
	{
		sum=sum+arr[j];
	}
	printf("%d",sum);
	return 0;
}
