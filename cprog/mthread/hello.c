#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 26

int a = 0, b = 0;

void *PrintHello (void *threadid) {
     char tid, s = ' ';
     tid = (int) threadid;
     tid = 65 + tid;
     FILE *ofile;
     ofile = fopen ("test.txt", "a");
     fputc (tid, ofile);
     a++;
     if (a == 2) {
        fputc (s, ofile);
        a = 0;
        b++;
     }
     if (b > 5) {
        exit (0);
     }
     close (ofile);
     pthread_exit (NULL);
}

int main (int argc, char *argv[]) {
     pthread_t threads[NUM_THREADS];
     int rc, t;
     for (t = 0; t < NUM_THREADS ; t++) {
        rc = pthread_create (&threads[t], NULL, PrintHello, (void *) t);
        if (rc) {
           printf ("ERROR; return code from pthread_create() is %d\n", rc);
           exit (-1);
        }
     }
     pthread_exit(NULL);
}
