/***********************************************************
4 - Qual o resultado da execução do programa abaixo?

ex: recursividade 
Brian Estigarribia
***********************************************************/

#include <stdlib.h>
#include <stdio.h>

int ff (int n)
{
	if (n == 1)
		return 1;
	if (n%2 == 0)
		return ff(n/2);
	
	return ff((n-1)/2) + ff((n+1)/2);
	//(7-1)/2 = 3 return 1;
	//(7+1)/2 = 4 return (4/2) = 2;
	//1+2 = 3
}

int main (void)
{
	printf("%d\n", ff (7));  //retorna 3
	system("pause");
}
