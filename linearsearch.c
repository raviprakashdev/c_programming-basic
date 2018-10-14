#include<stdio.h>
void main()
{
	int arr[100],c,search,n;
	printf("enter the size of array");
	scanf("%d",&n);
	printf("enter the element in array");
	for(c=0;c<n;c++)
	{
		scanf("%d",&arr[c]);
	}
	printf("enter the element to be search");
	scanf("%d",&search);
	for(c=0;c<n;c++)
	{
		if (arr[c]==search)
		{
			printf("%d element found at position %d",search,c+1);
			break;
		}
		else
		{
		printf("\n Element not found");
	}
	}

}
