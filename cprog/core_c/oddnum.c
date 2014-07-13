/*C program to print odd numbers between 0 and 10 by seven different ways.*/

#include <stdio.h>

void odd1 () {
	int i;
	
	for (i = 0; i <= 10; ++i)
		if ((i % 2) == 1)
			printf ("%d\t", i);
	
	printf ("\n");
}

void odd2 () {
	int i = 0;
 
	while (i <= 10) {
		if ((i % 2) == 1)
			printf ("%d\t", i);
		++i;
	}
	
	printf ("\n");
}

void odd3 () {
	int i = 0;
	
	do {
		if((i % 2) == 1)
			printf ("%d\t", i);
	
		++i;
	} while (i <= 10);
	
	printf ("\n");
}

void odd4 () {
	int i = 0;

l1:	if ((i % 2) == 1)
		printf ("%d\t", i);
	
	++i;

	if (i <= 10)
		goto l1;
	
	printf ("\n");
}

void odd5 () {
	int i = 0;
	
	while (1) {
		if ((i % 2) == 1)
			printf ("%d\t", i);
		++i;
	
		if (i > 10)
			break;
	} 
	
	printf ("\n");
}

void odd6 () {
	int a, i = 0;
	
	while (i <= 10) {
		a = i % 2;

		switch (a){
			case 1: printf ("%d\t", i);
				break;
		}
		
		++i;
	}
	
	printf("\n");
}

void odd7 () {
	int a, i = 0;
	
	for ( ; ; ) {
		a = i % 2;
		
		if (a == 1)
			printf ("%d\t", i);
		
		++i;
		
		if (i > 10)
			break;
	}

	printf ("\n");
}

int main () {
	odd1 ();
	odd2 ();
	odd3 ();
	odd4 ();
	odd5 ();
	odd6 ();
	odd7 ();
	return 0;
}
