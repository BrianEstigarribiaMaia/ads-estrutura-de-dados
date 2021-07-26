/* 5.	Os funcionários de uma loja de motos recebem um salário fixo mais 4% de comissão 
sobre as vendas. Faça um algoritmo que leia o número de funcionários, o salário fixo e o valor 
das vendas de cada funcionário. Calcule e mostre o valor da comissão, o salário final de cada 
funcionário e o valor total da folha de pagamento da loja.
*/

#include <stdio.h>
#include <stdlib.h>

main()
{
   int num_func, i = 0;
   float sal_fixo, vl_venda, vl_comissao, sal_final, vl_folha = 0;
   
   printf("Digite o numero de funcionarios \n");
   scanf("%d", &num_func);
   
   while (i < num_func) {
       printf("Digite o salario fixo do funcionario\n");
       scanf("%f", &sal_fixo);
       printf("Digite o valor de venda do funcionario\n");
       scanf("%f", &vl_venda);
       vl_comissao = vl_venda * 0.04;
       sal_final = sal_fixo + vl_comissao;
       vl_folha = vl_folha + sal_final;
       
       printf("O valor da comissao eh: %.2f\n", vl_comissao);
       printf("O salario final eh: %.2f\n", sal_final);
       i++;
       }   
   printf("O valor da folha de pagamento eh: %.2f \n", vl_folha);
   system ("pause");
}
