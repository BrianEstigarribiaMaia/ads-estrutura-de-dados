/***********************************************************
1 - Escreva uma função recursiva que recebe como parâmetros 
um número real X e um inteiro N e retorna o valor de XN.
Obs.:N não pode ser negativo.

ex: recursividade 
Brian Estigarribia
***********************************************************/

#include <stdio.h>
#include <stdlib.h>

float Potencia(float x, int n)
{
  if (n == 0){
  	return (1.0);
  }else{
  	return (x * Potencia(x, n - 1));
  }
  
}

int main(){
	float val;
	val = Potencia(2.0,2);
	
	printf("%.2f\n",val);
	
	system("pause");
	return 0;
}
