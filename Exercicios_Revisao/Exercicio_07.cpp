/* 7. Escreva um algoritmo que leia 2 vetores de 10 elementos inteiros. 
Crie um terceiro vetor que seja a união dos dois primeiros. 
Mostre o vetor resultante.
*/

#include <stdio.h>
#include <stdlib.h>

main()
{
   int vet1[10], vet2[10], vet_uni[20], i;
   
   for (i=0; i<=9; i++) {
       printf("Digite o numero do indice %d do primeiro vetor \n", i);
       scanf("%d", &vet1[i]);
       printf("Digite o numero do indice %d do segundo vetor \n", i);
       scanf("%d", &vet2[i]);
       vet_uni[i] = vet1[i];
       vet_uni[i+10] = vet2[i];
       }   
       
   for (i=0; i<=19; i++) {
       printf("O numero do indice %d do vetor final eh: %d\n", i, vet_uni[i]);
       }   
   system ("pause");
       
}
