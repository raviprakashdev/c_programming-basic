#include<stdio.h>
int main()
{
	int arr[100] , search , i , first , last , n , middle;
	printf("Enter the length of array");
	scanf("%d",&n);
	printf("enter %d element in array",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter search element");
	scanf("%d",&search);
	first = 0;
	last = n-1;
	while(first<=last)
	{
		middle = (first + last)/2;
		if(arr[middle]<search)
		{
			first = middle+1;
		}
		else if(arr[middle]==search)
		{
			printf("element %d found at location %d ",search,middle+1);
			break;
		}
		else
		last = middle-1;
	}
	if(first>last)
	{
		printf("Element %d doesnot exist in list");
	}
return 0;
}
