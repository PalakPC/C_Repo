/*C program to print alphabets to a file using multiple threads.*/

#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>

void *doloop (void *data)
{
	int rc;
	FILE *ofile;
	ofile = fopen("test.txt", "a");
	char a = 65 + (*((int *)data));
	fputc(a, ofile);
	close(ofile);
     pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
	int i, a, b, c = 0;
	srand (time(NULL));
	char s = ' ';
	pthread_t pthread1[26];
	int thr_id[26];
//	while(c < 500)
//	{
//		a = rand()%6 + 4;
		/*printf ("%d", a);*/
		b = 0; i=0;
		for (i=0; i<26; ++i)
		{
//			b++;
			thr_id[i] = pthread_create (&pthread1[i], NULL, doloop, (void *)&i);
	//		if (b == a)
	//		{
	//			FILE *ofile2;
	//			ofile2 = fopen("test.txt", "a");
	//			fputc(s, ofile2);
	//			b=0;
	//			c++;
	//			close(ofile2);
				/*b=0;*/
	//			break;
	//		}

		}
		/*c++;
		FILE *ofile2;
		ofile2 = fopen("test.txt", "a");
		fputc(s, ofile2);
		close(ofile2);*/
//	}
	/*printf("%d %d", c, b);*/
	return 0;
}
