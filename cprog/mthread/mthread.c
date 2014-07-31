/*C program to print alphabets to a file using separate threads for each alphabet.*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 26

int a = 0, b = 1, len = 0;    /*Had to make b = 1 as otherwise it prints an extra word. I don't see why.*/

void *PrintHello (void *threadid) {
     char tid, s = ' ';
     tid = (int) threadid;
     tid = 65 + tid;
     FILE *ofile;
     ofile = fopen ("test.txt", "a");
     fputc (tid, ofile);
     a++;
     if (a >= len) {
        fputc (s, ofile);
        a = 0;
        len = rand () % 6 + 4;
        printf ("%d\n", len);
        b++;
     }
     if (b >= 50) {
        exit (0);
     }
     close (ofile);
     pthread_exit (NULL);
}

int main (int argc, char *argv[]) {
     srand (time (NULL));
     len = rand () % 6 + 4;
     printf ("%d\n", len);
     pthread_t threads[NUM_THREADS];
     int rc, t;
     void * status;
l1:  for (t = 0; t < NUM_THREADS ; t++) {
        rc = pthread_create (&threads[t], NULL, PrintHello, (void *) t);
        if (rc) {
           printf ("ERROR; return code from pthread_create() is %d\n", rc);
           exit (-1);
        }
        pthread_join (threads[t], &status);
     }
     if (b < 50)
        goto l1;
     pthread_exit(NULL);
}
