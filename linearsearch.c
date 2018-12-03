#include<stdio.h>
void main()
{
	int arr[100],c,search,n;
	printf("Enter the size of array");
	scanf("%d",&n);
	printf("Enter %d element in array",n);
	for(c=0;c<n;c++)
	{
		scanf("%d",&arr[c]);
	}
	printf("%Enter the element to be search");
	scanf("%d",&search);
	for(c=0;c<n;c++)
	{
		if(arr[c]==search)
		{
			printf("%d Element found at position %d-",search,c+1);
			break;
		}
	}
	if (c == n)
	printf("\n Element not found");
}
