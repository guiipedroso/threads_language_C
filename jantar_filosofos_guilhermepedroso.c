/*
  Dicente: Guilherme Pedroso
  Disciplina: Sistemas Operacionais
  Title: Jantar dos Filosofos 
 
*/

#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define QUANTIDD 5
#define PENSANDO 0
#define FAMINTO 1
#define COMENDO 2
#define LEFT (nfilosofo+4)%QUANTIDD
#define RIGHT (nfilosofo+1)%QUANTIDD


void *filosofo(void *num);
void pegaGarfos(int);
void deixaGarfos(int);
void comer(int);

sem_t mutex;
sem_t S[QUANTIDD]; 
int status[QUANTIDD];
int nfilosofo[QUANTIDD]={0,1,2,3,4};

void 
*filosofo(void *num)
  {
   while(!0)
     {
     int *i = num;
     sleep(3);
     pegaGarfos(*i);
     sleep(3);
     deixaGarfos(*i);
     }
  }

void
pegaGarfos(int nfilosofo)
  {
  sem_wait(&mutex);
  status[nfilosofo] = FAMINTO;
  printf("Filosofo %d esta faminto\n", nfilosofo+1);
  comer(nfilosofo);
  sem_post(&mutex);
  sem_wait(&S[nfilosofo]);
  sleep(3);
  }

void
deixaGarfos(int nfilosofo)
  {
  sem_wait(&mutex);
  status[nfilosofo]=PENSANDO;
  printf("Filosofo %d largou os garfos %d e %d.\n", nfilosofo+1, LEFT+1, nfilosofo+1);
  printf("Filosofo %d esta pensando\n", nfilosofo+1);
  comer(LEFT);
  comer(RIGHT);
  sem_post(&mutex);
  }

void
comer(int nfilosofo)
  {
  if(status[nfilosofo]==FAMINTO && status[LEFT]!=COMENDO && status[RIGHT]!=COMENDO)
   {
   status[nfilosofo]=COMENDO;
   sleep(3);
   printf("Filosofo %d pegou os garfos %d e %d.\n", nfilosofo+1, LEFT+1, nfilosofo+1);
   printf("Filosofo %d esta comendo\n", nfilosofo+1);
   sem_post(&S[nfilosofo]);
   }
  }

int
main()
  {
  int i;
  pthread_t thread_id[QUANTIDD];
  sem_init(&mutex,0,1);
  for(i=0;i<QUANTIDD;i++)
    {   
    sem_init(&S[i],0,0);
    }	    
  for(i=0;i<QUANTIDD;i++)
    {
    pthread_create(&thread_id[i], NULL, filosofo, &nfilosofo[i]);
    printf("Filosofo %d esta pensando\n",i+1);
    }
  for(i=0;i<QUANTIDD;i++)
    {
    pthread_join(thread_id[i],NULL); 
    }
   return(0);
}
