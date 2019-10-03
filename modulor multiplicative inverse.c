
#include <stdio.h>

// A naive method to find modulor multiplicative inverse of
// 'a' under modulo 'm'

int main (int argc, char *argv[]) {

	 int a = 3, m = 17;

	 a = a%m;

	     for (int x=1; x<m; x++){
	    	      if ((a*x) % m == 1){
	        	     printf("The modulor multiplicative inverse of '%d' under modulo '%d' is: %d\n", a,m,x);
                   break;}
	           }
	 return 0;

}


