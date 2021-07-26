/*   9. Crie um registro com nome, dia de aniversário e mês de aniversario. 
     Desenvolver um algoritmo que mostre em cada um dos meses do ano quem são 
     as pessoas que fazem aniversário, exibir também o dia. Considere um conjunto de 40 pessoas.
*/

#include <stdio.h>
#include <stdlib.h>


struct CAD_ANIVERSARIO {
			   char Nome[50];
			   int Dia;
			   int Mes;
			};

main()
{
	struct CAD_ANIVERSARIO aniver[40];
	int i, mes;

	
for (i=0; i<40; i++)
	{
		printf ("Digite o nome: ");
		scanf ("%s", &aniver[i].Nome);
		printf ("Digite o dia do aniver: ");
		scanf ("%d", &aniver[i].Dia);
		printf ("Digite o mes do aniver: ");
		scanf ("%d", &aniver[i].Mes);
	}
	
    system ("CLS");

	for (mes=1; mes<=12; mes++)
	{
     printf ("Aniversariantes do mes %d\n", mes);   
  	 for (i=0; i<40; i++)
	     {
         if (aniver[i].Mes == mes)
            {     
			printf ("Nome: %s \n", aniver[i].Nome);
			printf ("Dia: %d \n", aniver[i].Dia);
			printf ("Mes: %d \n", aniver[i].Mes);
		    }
      }  
	}
system ("pause");
}
