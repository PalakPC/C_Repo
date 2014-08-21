/*C program to calculate the first hundred triangular numbers.*/

#include <stdio.h>
#include <math.h>

void trinum(int x);

int main() {
	int i = 1;
	printf("The first hundred triangular numbers are:\n");

	while(i <= 100) {
		trinum(i);
		i++;
	}
	
	return 0;
}

void trinum(int x) {
	int n;
	n = (x * (x + 1)) / 2;	/*nth triangular number is (n (n + 1)) / 2.*/
	printf("%d\n", n);
}
