#include<stdio.h>
int main()
{
	float selling_price,cost_price,profit;
	printf("Enter the total selling price of the 15 items : ");
	scanf("%f",&selling_price);
	printf("Enter the total profit of 15 items : ");
	scanf("%f",&profit);
	cost_price = (selling_price-profit)/15;
	printf("Cost_price of each item is : %f",cost_price);
	return 0;
}
