// This program works with parallel processing using Forks.
// It can work with up to four functions working simultaneously
// Create four generic functions that print a sentence.
// These functions can be changed to any other function, and then run in parallel.
// The code was implemented in linux thus might libraries that are not compatible with Windows/Mac
// IMPORTANT: The code must be compiled using " gcc fork.c -o fork -lm "


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void funtion1(){
	printf("First function\n");
}

void funtion2(){
	printf("Second function\n");
}

void funtion3(){
	printf("Third function\n");
}

void funtion4(){
	printf("Fourth function\n");
}


int main(int argc, char *argv[]) {
int pid = fork();

	 if (pid < 0) { //An error ocurred on the execution of the Fork
	      fprintf(stderr, "fork failed\n");
	      exit(1);
	 }

	 else if (pid == 0) { /* Child Process */
	     int pidC = fork();
	     if (pidC < 0) { //An error ocurred on the execution of the Child Process
	        fprintf(stderr, "fork failed\n");
	        exit(1);
	     }
	     else if(pidC == 0){
	        // YOU FUNCTION GOES HERE
					funtion1();
	     }
	     else{
					// YOU FUNCTION GOES HERE
					funtion2();
	     }
	 }

	 else { /* Parent Process */
	     int pidP = fork();
	     if (pidP < 0) {//An error ocurred on the execution of the Parent Process
	     		fprintf(stderr, "fork failed\n");
	      	exit(1);
	     }
	     else if(pidP == 0) {
				 	// YOU FUNCTION GOES HERE
				 	funtion3();

	     }
	     else{
				 	// YOU FUNCTION GOES HERE
				 	funtion4();

	     }
	     wait(NULL); /* Parent wait for the child to finish */
	     if(pidP != 0){
	     }
	 }

	return 0;
}
