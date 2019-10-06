#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int arr[256]={0},len,i;
	printf("enter a string with less than or equal to hundred characters\n");
	scanf("%[^\n]s",str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		arr[str[i]]++;
	}
	for(i=0;i<256;i++)
	{
		if(arr[i]!=0)
			printf("%c occurs %d times\n",i,arr[i]);
	}
	printf("NOTE:if there is something like ' ',consider it as a simple whitespace,else ignore it\n");
	return 0;
}	
