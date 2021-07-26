/*
	Exemplo de procedimento que mostra mensagens
*/
#include <stdio.h>
#include <stdlib.h>

//procedimento
void Mostra_mensagem(int numero1,int numero2){
	printf("Numero1:%d \n",numero1);	
	printf("Numero2:%d \n",numero2);
	
}

int main(){
	
	int valor1;
	
	printf("Digite o valor 1\n");
	scanf("%d",&valor1);
	
	//chama procedimento mostra mensagem
	Mostra_mensagem(valor1,30);
	Mostra_mensagem(44,80);

	return 0;
}
