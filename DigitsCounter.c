// Objective: To find the number of digits in a number

#include<stdio.h>
int CountDigits(unsigned long long);
int main()
{
    unsigned long long num;
    printf("\nEnter the number: \n");
    scanf("%llu",&num);      //llu is unsigned long long
    int digits = CountDigits(num);
    printf("\nThe number of digits in %llu is : %d\n",num,digits);
    return 0;
}
int CountDigits(unsigned long long n)
{
    //let n = 153
    int counter = 0;
    while(n>0)
    {
        n = n/10; //1.n=15 2.n=1 3.n=0 then condition false
        counter++;
    }
    return counter;
}
