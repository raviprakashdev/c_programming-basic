#include<stdio.h>
int main()
{
	int i,j,arr[20],temp,n;
	printf("Enter the length of an array");
	scanf("%d",&n);
	printf("Enter the element in array");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("sorted array");
	for(i=0;i<n;i++)
	{
		printf("%d",arr[i+1]);
	}
	return 0;
}
