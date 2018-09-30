#include<stdio.h>
void swap(int* , int*);
int main()
{
	int a , b;
	printf("Enter value of a and b\n");
	scanf("%d %d",&a,&b);
	printf("The value of a and b is %d and %d\n",a,b);
	swap(&a,&b);
	printf("The value of a and b afetr func is %d and %d\n",a,b);
	return 0;
}
void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	printf("the value after swapping are a=%d and b=%d \n",*a,*b);
	
}
