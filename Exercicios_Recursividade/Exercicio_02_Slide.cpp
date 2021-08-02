/************************************************************
    Implemente de forma recursiva as funções
    abaixo:
        
    void toUp(int n) – imprime os primeiros n números
    em forma crescente, iniciando em 0.
    
    void toDown(int n) - imprime os primeiros n números
    em forma decrescente terminando em 0
    
************************************************************/
#include <stdlib.h>
#include <stdio.h>


void toDown(int n){
   if(n>=0){
        printf("%d\n", n );
        toDown(n-1);
    }
}
 

void toUp(int n){
	if(n>=0){
		toUp(n-1);
        printf("%d\n", n );
    }
}
    
int main(){
	
	printf("Ordem decrescente - termina em 0\n");	
    toDown(5);
    
    printf("Ordem crescente - inicia em 0\n");
    toUp(5);
    system("pause");
    return 0;
}
