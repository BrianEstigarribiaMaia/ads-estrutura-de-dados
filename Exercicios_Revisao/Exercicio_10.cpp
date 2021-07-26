/*   10.	Uma empresa faz a folha mensal de pagamentos de seus  80 funcionários baseada no seguinte:
     existe uma tabela com os dados de cada funcionalidade: matrícula, nome e salário bruto.
     Escreva um programa que leia e processe a tabela e imprima para cada funcionário seu 
     contra-cheque, conforme segue:
     Matrícula:
     Nome:
     Salário bruto:
     Dedução INSS:
     Salário liquido: 
     (Observação: Dedução de INSS desconto de 12%, salário liquido é a diferença entre salário bruto e a redução do INSS).

*/

#include <stdio.h>
#include <stdlib.h>


struct CAD_FUNCIONARIO {
			   int Matricula;
               char Nome[50];
			   float Salario;
			};

main()
{
	struct CAD_FUNCIONARIO func[80];
	int i;
	float vl_INSS, vl_sal_liq;

	
for (i=0; i<80; i++)
	{
		printf ("A matricula do funcionario eh %d:\n ", func[i].Matricula);
		printf ("O nome do funcionario eh %s:\n ", func[i].Nome);
		printf ("O salario bruto do funcionario eh %.2f:\n ", func[i].Salario);
		vl_INSS = func[i].Salario * 0.12;
		vl_sal_liq = func[i].Salario - vl_INSS;
		printf ("O valor do desconto do INSS do funcionario eh %.2f:\n ", vl_INSS);
		printf ("O salario liquido do funcionario eh %.2f:\n ", vl_sal_liq);
        system ("pause");
	}
}
