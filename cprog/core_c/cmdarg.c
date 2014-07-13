/*C program to print command-line arguments.*/

#include <stdio.h>

int main (int argc, char ** argv) {
	int i = 1; 
 l1:	printf ("%s\n", argv[i]);
	++i;

	if (i < argc)
		goto l1;
	
	return 0;
}
