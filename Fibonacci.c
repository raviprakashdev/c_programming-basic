#include<stdio.h> 
#include<math.h> 
int fib(int n) { 
  double phi = (1 + sqrt(5)) / 2; 
  return round(pow(phi, n) / sqrt(5)); 
} 
int main () 
{ 
  int n = 9; 
  printf("%d", fib(n)); 
  return 0; 
}
