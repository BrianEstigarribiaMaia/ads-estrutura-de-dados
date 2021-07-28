/*2. Implementar uma função que receba como parâmetro um vetor de números reais (vet) 
de tamanho n e retorne quantos números negativos estão armazenados nesse vetor. 
Essa função deve obedecer ao protótipo:

int negativos (int n, float *vet);
*/

#include <stdio.h>
#include <stdlib.h>

int negativos (int n, float* vet)
     {
     int i, neg=0;
     for (i=0; i< n; i++)
         {
          if (vet[i] < 0)
              neg++;     
          }
          return neg;

     }     

main()
  {       
  int n, i, neg;
  

  printf("Digite tamanho do vetor\n");
  scanf("%d",&n);
  float vet[n];
  for (i=0; i< n; i++)
      {
      printf("Digite um valor para o indice %d do vetor\n", i);
      scanf("%f",&vet[i]);
      }         

  neg = negativos(n, &vet[0]);

  printf("A quantidade de numeros negativos no vetor eh: %d\n", neg);
  system("pause");
  }
