/***********************************************************
2 - Ler um número inteiro N (só aceitar valores positivos) 
e escrever todos os nºs pares de 0 a N. 

ex: recursividade 
Brian Estigarribia
***********************************************************/

#include <stdio.h>
#include <stdlib.h>

int par(int n){
	if(n>0){
		if(n%2 == 0){
			printf("%d\n",n);
			return par(n-2);
		}else{
			return par(n-1);
		}
	}
}

int main(){
	int num = 0;
	
	printf("Digite um numero: \n");
	scanf("%d",&num);
	
	printf("%d\n",par(num));
	
	system("pause");
	return 0;
}
