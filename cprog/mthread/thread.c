#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t a_mutex = PTHREAD_MUTEX_INITIALIZER;

void *doloop (void *data)
{
	int rc;
	rc = pthread_mutex_lock(&a_mutex);
	FILE *ofile;
	ofile = fopen("test.txt", "a");
	char a = 65 + (*((int *)data));
	fputc(a, ofile);
	close(ofile);
	rc = pthread_mutex_unlock(&a_mutex);
}

int main (int argc, char *argv[])
{
	srand (time(NULL));
	int i, a, b, c = 0;
	char s = ' ';
	pthread_t pthread1[26];
	int thr_id[26];
	while(c < 500)
	{
		a = rand()%6 + 4;
//		printf ("%d", a);
		b = 0; i=0;
		for (i=0; i<26; ++i)
		{
			b++;
			thr_id[i] = pthread_create (&pthread1[i], NULL, doloop, (void *)&i);
			if (b == a)
			{
				FILE *ofile2;
				ofile2 = fopen("test.txt", "a");
				fputc(s, ofile2);
				b=0;
				c++;
				close(ofile2);
			//	b=0;
				break;
			}
		}
	//	c++;
/*		FILE *ofile2;
		ofile2 = fopen("test.txt", "a");
		fputc(s, ofile2);
		close(ofile2);*/
	}
//	printf("%d %d", c, b);
	return 0;
}
