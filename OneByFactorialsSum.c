//program to write the result of 1/1!+ 1/2! + 1/3! + ....... +1/n!

#include<stdio.h>
int main()
{
    int n;
    float fact =1;
    float sum = 0;
    printf("\nEnter the value of n: ");
    scanf("%d",&n);
    for(int i=1;i<=n;++i)   //repeat for n numbers
    {
        for(int j=i;j>=1;--j)   //calculate factorial
        {   fact *= j;  }

        sum += (1/fact);
        fact = 1;       //reseting for next use
    }
    printf("\nThe sum of the inverse of the factorials upto %d is: %f \n",n,sum);
    return 0;
}
