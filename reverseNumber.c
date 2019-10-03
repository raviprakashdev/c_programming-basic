#include <stdio.h>

void main()
{
	int n;
	
	printf("Enter the number to reverse: ");
	scanf("%d", &n);
	
	int ans = 0;
	
	while(n != 0)
	{
		int digit = n%10;
		
		ans = ans*10 + digit;
		
		n = n/10;
	}
	
	printf("The reversed number is: %d \n", ans);
}
