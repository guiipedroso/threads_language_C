  /* =======================================================
   
     Programming Threads in language C
   
     Autor: Guilherme Pedroso 
     Date: 04/11/2022
     Update: 04/26/2022  
   
   ==========================================================*/ 


  #include <stdio.h>
  #include <stdlib.h>
  #include <pthread.h>

  #define THREADS 4
  #define TAMANHO 40
  #define POSICOES 10 

  int j = 0;
  int vetor[TAMANHO];
  int num = 1;

  void
  *funcao(void *arg)
  { 
   printf("\nThread %d\n\n", num);
   for(int k = 0; k < POSICOES; k++)
     {
     scanf("%d", &vetor[j]);
     j++;
     }
     num++;
     pthread_exit ((void *) NULL);
  }

  void 
  imprime_vetor(int *vetor)
  {
    int cont = 0, t = 0;
    printf("\n\n\n-----PROCESSOS-----");
    for(int l = 0; l < TAMANHO; l++)
      {	       
      if(cont % POSICOES == 0)
      	{
         printf("\n");
	 t++;
         printf("\nThread %d\n", t);
         }
         
         printf("\n%d", vetor[l]);
	 cont++;
	}
	
  printf("\n");

  }

  int 
  main()
  { 
	pthread_t t[THREADS];

	printf("\n-----LEITURA-----\n");

	for(int i = 0; i < THREADS; i++)
	{
		
	pthread_create(&t[i], NULL, funcao, NULL);
	pthread_join(t[i], NULL);

	}
	
  imprime_vetor(vetor);

  printf("\n");
  return (0);
  }
