/*   8. Escreva um algoritmo que leia dois vetores de 10 posições e faça a multiplicação 
dos elementos de mesmo índice, colocando o resultado em um terceiro vetor. 
Mostre o vetor resultante.
*/

#include <stdio.h>
#include <stdlib.h>

main()
{
   int vet1[10], vet2[10], vet_mult[10], i;
   
   for (i=0; i<=9; i++) {
       printf("Digite o numero do indice %d do primeiro vetor \n", i);
       scanf("%d", &vet1[i]);
       printf("Digite o numero do indice %d do segundo vetor \n", i);
       scanf("%d", &vet2[i]);
       vet_mult[i] = vet1[i]*vet2[i];
       }   
       
   for (i=0; i<=9; i++) {
       printf("O valor do indice %d do vetor de multiplicacao eh: %d\n", i, vet_mult[i]);
       }   
   system ("pause");
       
}
