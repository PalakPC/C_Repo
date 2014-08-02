/*
 * C program to print alphabets to a file using separate threads for each 
 * alphabet.
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 26

struct t_ioparams
{
  int id;
  FILE *ofile;
  int status;
  int first_run;
  int alph_len;
  int word_len;
  int current_len;
  pthread_mutex_t key;
}typedef ioparams;

void * print_hello (void *t_params)
{
  int t_id;
  ioparams *params = (ioparams *) t_params;

  srand(time(NULL));
  
  pthread_mutex_lock(&params->key);
  t_id = params->id;
  params->id++;
  pthread_mutex_unlock(&params->key);
  
  while(1)
  {
    pthread_mutex_lock(&params->key);

    if((params->word_len > 500) || params->status)
    {
      pthread_mutex_unlock(&params->key);
      pthread_exit(NULL);
    }

    if(params->current_len >= params->alph_len  || params->first_run)
    {
      if(!params->first_run)
        fprintf(params->ofile, " ");
      params->alph_len = rand() % 6 + 4;
      params->word_len++;
      params->first_run = 0;
      params->current_len = 0;
    }
    fprintf(params->ofile, "%c", 65 + t_id);
    params->current_len++;

    pthread_mutex_unlock(&params->key);
    usleep(5000);
  }
}

int main (int argc, char *argv[])
{
  pthread_t threads[NUM_THREADS];
  ioparams params;
  int i;
  
  params.id          = 0;
  params.status      = 0;
  params.first_run   = 1; 
  params.alph_len    = 0;
  params.word_len    = 0;
  params.current_len = 0;
  params.ofile     = fopen ("test.txt", "a");

  pthread_mutex_init(&params.key, NULL);
  
  for(i=0; i<=25; i++)
  {
    if(pthread_create(&threads[i], NULL, print_hello, &params))
    {
      printf ("ERROR in thread create.\n");
      return 1;
    }
  }

  for(i=0; i<=25; i++)
  {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&params.key);
  return 0;
}
