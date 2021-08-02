#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int i = 0;

int FuncaoRecursiva(){
	i++;		
	printf("%d ", i);
	system("pause");
	
	//Criterio de scape
	if(i < 9){
		//Chama propria funcao de forma recursiva
		//Ao parar de chamar a funcao, loop termina
		FuncaoRecursiva();
	}
		
}

int main(int argc, char *argv[]) {
	FuncaoRecursiva();
	return 0;
}
