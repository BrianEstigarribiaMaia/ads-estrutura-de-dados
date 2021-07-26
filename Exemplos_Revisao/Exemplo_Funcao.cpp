/*
	Exemplo de função de soma
*/

#include <stdio.h>
#include <stdlib.h>

int Soma(val1, val2){

	return val1+val2;
}
int main(){
	printf("Soma: %d \n", Soma(Soma(3,2), 5));
}
return 0;
