/*C program to demonstrate compilation pipeline.*/

#include <stdlib.h>
#include <string.h>

#include "reverse.h"
#include "fibonacci.h"

int main(int argc, char *argv[]) {	
	int i = 1;	

	#if(defined REVERSE) && (!defined FIBONACCI)		
		if(i < argc) {
			reverse(argv[i], strlen(argv[i]));
		}

	#elif(defined FIBONACCI) && (!defined REVERSE)		
		if(i < argc) {
			print_fib(atoi(argv[i]));
		}

	#else
		if(i < argc) {
			print_fib(atoi(argv[i]));
			++i;
		}		
	
		if(i < argc) {
			reverse(argv[i], strlen(argv[i]));
		}
	
	#endif

	return 0;
}
