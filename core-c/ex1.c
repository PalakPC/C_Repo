#include<stdio.h>
#include<math.h>

void tri(int x);

int c=0;

int main()
{
	int i=0;
	printf("The first hundred triangular numbers are:\n");
	while(c<100)
	{
		tri(i);
		i++;
	}
	return 0;
}

void tri(int x)
{
	int y=(8*x)+1;
	float z=sqrt(y);
	if(z-(int)z==0)
	{
		int a=(int)z;
		if(a%2!=0)
		{
			printf("%d\n", x);
			c++;
		}
	}
}
