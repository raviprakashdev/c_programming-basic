#include <stdio.h>
#include <math.h>

int isPrime(int num)  //returns 1 if number is prime, else 0.
{
    int i, root = sqrt(num);
    for(i=2; i<=root; i++)
    {
        if( (double)(num % i) == 0)
            return 0;
    }
        return num > 1;
}

int main(void) {
  int input;
  while(input!=-1)
  {
  printf("Enter number(-1 to exit):");
  scanf("%d",&input);
  if(isPrime(input))
    printf("%d is Prime\n", input);
  else
    printf("%d is not Prime\n", input);
  }
  return 0;
}
