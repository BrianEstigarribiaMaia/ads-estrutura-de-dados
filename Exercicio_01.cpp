/*1.	Faça um algoritmo que leia 22 números inteiros positivos maiores 
que zero. A cada número informado calcule e mostre:
a.	O número digitado;
b.	A metade do número digitado;
c.	O dobro do número digitado;
d.	O número digitado ao cubo. */

#include <stdio.h>
#include <stdlib.h>

main()
{
   int i, num;
   for (i=1; i<=22; i++) {
       printf("Digite um numero inteiro\n");
       scanf("%d", &num);
       if (num >= 0) {
          printf("O numero eh %d\n", num);
          printf("A metade do numero eh %.2f\n", num/2.0);
          printf("O dobro do numero eh %d\n", num*2);
          printf("O numero ao cubo eh %d\n", num*num*num);
          }
       else {
            printf("Numero invalido");
            i--;
            }
 
       }   
      
      }
