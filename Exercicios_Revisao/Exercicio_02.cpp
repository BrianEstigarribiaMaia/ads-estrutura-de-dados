/* 2.Faça um algoritmo que leia o valor do salário de 35 funcionários e o valor do salário mínimo. 
  Calcule e mostre a quantidade de salários mínimos que cada funcionário ganha. */

#include <stdio.h>
#include <stdlib.h>

main()
{
   int i, qtde;
   float sal, sal_min, qtd;
   for (i=1; i<=35; i++) {
       printf("Digite o salario do funcionario\n");
       scanf("%f", &sal);
       printf("Digite o valor do salario minimo\n");
       scanf("%f", &sal_min);
       qtd = sal/sal_min;
       qtde = qtd;
       printf ("O funcionario recebe %d salario(s) minimo(s)\n", qtde);
       system ("pause");

       }   
      
}
