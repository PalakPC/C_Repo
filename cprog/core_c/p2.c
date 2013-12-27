#include<stdio.h>

void amaze1()
{
	int i;
	for (i=0; i<=10; ++i)
		if((i%2)==1)
			printf("%d\t", i);
	printf("\n");
}

void amaze2()
{
	int i=0;
	while(i<=10)
	{
		if((i%2)==1)
			printf("%d\t", i);
		++i;
	}
	printf("\n");
}

void amaze3()
{
	int i=0;
	do
	{
		if((i%2)==1)
			printf("%d\t", i);
		++i;
	}while(i<=10);
	printf("\n");
}

void amaze4()
{
	int i=0;
l1:	if((i%2)==1)
		printf("%d\t", i);
	++i;
	if(i<=10)
		goto l1;
	printf("\n");
}

void amaze5()
{
	int i=0;
	while(1)
	{
		if((i%2)==1)
			printf("%d\t", i);
		++i;
		if(i>10)
			break;
	} 
	printf("\n");
}

void amaze6()
{
	int a, i=0;
	while(i<=10)
	{
		a=i%2;
		switch(a)
		{
			case 1: printf("%d\t", i);
				break;
		}
		++i;
	}
	printf("\n");
}

void amaze7()
{
	int a, i=0;
	for(;;)
	{
		a=i%2;
		if(a==1)
			printf("%d\t", i);
		++i;
		if(i>10)
			break;
	}
	printf("\n");
}

int main()
{
	amaze1();
	amaze2();
	amaze3();
	amaze4();
	amaze5();
	amaze6();
	amaze7();
	return 0;
}
