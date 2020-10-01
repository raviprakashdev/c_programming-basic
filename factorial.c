//This program will tell the factorial of number input by the user
#include<stdio.h>
int main(){
int a;
    printf("Enter the number whose factorial is to be calculated: ");
    scanf("%d", &a);    
    printf("The value of factorial %d is %d", a, factorial(a));
    return 0;
}
int factorial(int x){
    printf("Calling factorial(%d)\n", x);
    if (x==1 || x==0){
        return 1;
    }
    else{
        return x * factorial(x-1);
    }
}
	
