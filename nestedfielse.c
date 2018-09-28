#include<stdio.h>
void main()
{
	char g;
	int yos , q , s;
	printf("Enter the gender , year of service and qualification(g=0,pg=1)");
	scanf("%c %d %d",&g,&yos,&q);
	if(g=='m'&&yos>=10&&q==1)
	{
		s=15000;
	}
	else if((g=='m'&&yos>=10&&q==0)||(g=='m'&&yos<10&&q==1))
	
	{
		s=10000;
	}
	else if(g=='m'&&yos<10&&q==0)
	{
		s=7000;
	}
	else if(g=='f'&&yos>=10&&q==1)
		{
		s=12000;
	}
	else if(g=='f'&&yos>=10&&q==0)
	{
		s=9000;
	}
	else if(g=='f'&&yos<10&&q==1)
	{
		s=10000;
	}
	else if(g=='f'&&yos<10&&q==0)
	{
		s=6000;
	}
	printf("\n Salary of Employee = %d", s);
	
	
	
	
}
