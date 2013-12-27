#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **allocate2D(int *rows, int *columns);

void (*quicksort)(int*, int*);

void quick(int*, int*);

char **s;

int *carr;

int main(int argc, char *argv[])
{
	FILE *ifile;
	char *str;
	int *count, *i, *j, *k, *rows, *col;
	rows=(int*)malloc(sizeof(int));
	col=(int*)malloc(sizeof(int));
	*rows=100;
	*col=30;
	ifile=fopen(argv[1], "r");
	s=allocate2D(rows, col);
	free(rows);
	free(col);
	count=(int*)malloc(sizeof(int));
	(*count)=0;
	while (fscanf(ifile, "%s", (s[*count]))!=EOF)
	{
		(*count)++;
	}
	i=(int*)malloc(sizeof(int));
	(*i)=0;
	j=(int*)malloc(sizeof(int));
	k=(int*)malloc(sizeof(int));
	str=(char*)malloc(30*sizeof(char));
	(*i)=0;
	carr=(int*)malloc(30*sizeof(int));
	while((*i)<(*count))
	{
		(*j)=(*i)+1;
		strcpy(str, s[*i]);
		*(carr+(*i))=1;
		while((*j)<(*count))
		{
			if(strcmp(str, s[*j])==0)
			{
				++(*(carr+(*i)));
				(*k)=(*j);
				while((*k)<(*count))
				{
					strcpy(s[*k], s[(*k)+1]);
					++(*k);
				}
				--(*j);
				--(*count);
			}
			++(*j);
		}
		++(*i);
	}
	free(j);
	free(k);
	free(str);
	int *low, *high;
	low=(int*)malloc(sizeof(int));
	high=(int*)malloc(sizeof(int));
	*low=0;
	*high=(*count)-1;
	quicksort=quick;
	(*quicksort)(low, high);
	free(low);
	free(high);
	(*i)=0;
	while((*i)<(*count))
	{
		printf("%s\t%d\n", s[*i], *(carr+(*i)));
		(*i)++;
	}
	free(i);
	free(count);
	free(carr);
	free(s);
	close(ifile);
}

char ** allocate2D(int *rows,int *cols)
{
	char **arr2D;
	int *i;
	i=(int *)malloc(sizeof(int));
	arr2D = (char**)malloc((*rows)*sizeof(char*));
	for((*i)=0;(*i)<(*rows);(*i)++)
	{
		arr2D[*i] = (char*)malloc((*cols)*sizeof(char));
	}
	return arr2D;
}

void (quick)(int *low, int *high)
{
	int *i, *j, *temp;
	i=(int*)malloc(sizeof(int));
	j=(int*)malloc(sizeof(int));
	*i=*low;
	*j=*high;
	int *pivot;
	pivot=(int*)malloc(sizeof(int));
	char *swap;
	swap=(char*)malloc(30*sizeof(char));
	*pivot=*(carr+((*low)+((*high)-(*low))/2));
	while((*i)<=(*j))
	{
		while(*(carr+(*i))<(*pivot))
		{
			++(*i);
		}
		while(*(carr+(*j))>(*pivot))
		{
			--(*j);
		}
		if((*i)<=(*j))
		{
			temp=(int *)malloc(sizeof(int));
			*temp=*(carr+(*i));
			strcpy(swap, s[*i]);
			*(carr+(*i))=*(carr+(*j));
			strcpy(s[*i], s[*j]);
			*(carr+(*j))=*temp;
			strcpy(s[*j], swap);
			free(temp);
			++(*i);
			--(*j);
		}
	}
	if((*low)<(*j))
	{
		(*quicksort)(low, j);
	}
	if((*i)<(*high))
	{
		(*quicksort)(i, high);
	}
	free(i);
	free(j);
	free(pivot);
	free(swap);
}
