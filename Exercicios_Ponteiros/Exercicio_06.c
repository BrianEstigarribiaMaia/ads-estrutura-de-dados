/* 6.	Implementar uma função que calcule o aumento salarial de um funcionário. 
Essa função deve obedecer ao protótipo:

void aumento_salarial (float salario, int anos, float *aumento);

Tabela de Aumento
Anos					Percentual
menos de 2 anos				5%
de 2 a 3 anos				7%
de 4 a 6					9%
de 7 a 9					10%
mais de 10 anos				12%

*/

#include <stdio.h>
#include <stdlib.h>
 
void aumento_salarial(float salario,int anos,float* aumento)
     {
      if (anos < 2)
          *aumento = salario*0.05;
      else if (anos >= 2 && anos <= 3)
               *aumento = salario * 0.07;
           else if (anos >= 4 && anos <=6)
                    *aumento = salario * 0.09;
                else if (anos >= 7 && anos <=9)
                         *aumento = salario * 0.10;
                     else
                         *aumento = salario * 0.12;
     }


main()
  {       
  float salario;
  float aumento;
  int anos;
  
  printf("Informe o salario\n");
  scanf("%f",&salario);
  printf("Informe o numero de anos de servico\n");
  scanf("%d",&anos);
  
  aumento_salarial(salario, anos, &aumento); 
  printf("O aumento do salario eh = %f\n", aumento);
  system("pause");
}
    
