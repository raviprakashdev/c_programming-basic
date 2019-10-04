#include <stdio.h>

int main()
{
int a,b;
printf("Enter two numbers\n");
scanf("%d%d",&a,&b);
if(a>b)
printf("Largest number is %d",a);
else
printf("Largest number is %d",b);
return 0;
}
