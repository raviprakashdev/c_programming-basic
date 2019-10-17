#include <stdio.h>
void main()
{
static int arr[100];
int length;
printf("enter the length of the array\n");
scanf("%d" , &length);
printf("enter the int elements in the array\n");
for(int i = 0 ; i<length ; i++)
{
scanf("%d" , &arr[i]);
}
printf(" successfully written \n");
sort(arr, length);

}

int sort( int arr[] , int length)
{
for(int i = 0 ; i<length-1 ; i++)
{
int min = i;
for(int j = i +1 ; j<length ; j++){ 
if(arr[min] > arr[i])
{min = j;
int temp = arr[i];
arr[i] = arr[min];
arr[min] = temp;
}}
}
for(int k=0 ; k<length ; k++)
{
printf("%d , " , arr[k]);
}
return 0;}
