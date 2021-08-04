#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
  float num;
  struct nodo *esquerda;
  struct nodo *direita;
  struct nodo *centro;
}nodo;

nodo *cria_elemento(float num){
  nodo *novo = malloc(sizeof(nodo));
  novo->num = num;
  novo->centro = NULL;
  novo->esquerda = NULL;
  novo->direita = NULL;
  return novo;
}

void insere_folha(nodo **arv, float num){
   if (*arv == NULL){
     *arv = cria_elemento(num);
   }else{
     if(num < 0){
        printf("Inserindo na Esquerda. \n");
        insere_folha(&(*arv)->esquerda, num);
     }else if (num < 100){
        printf("Inserindo no Centro. \n");
        insere_folha(&(*arv)->centro, num);
     }else{
     	printf("Inserindo na Direita. \n");
        insere_folha(&(*arv)->direita, num);
	 }
   }
}

void pre_ordem(nodo *arv, int op){
  if (arv != NULL) {
     printf("%.2f \n",arv->num);
     if (arv->esquerda != NULL && op == 1){
        printf("Nodo Esquerdo. \n");
        pre_ordem(arv->esquerda, op);
     }
     if (arv->centro != NULL && op == 2){
        printf("Nodo Centro. \n");
        pre_ordem(arv->centro, op);
     }
     if(arv->direita != NULL && op == 3){
        printf("Nodo Direito. \n");
        pre_ordem(arv->direita, op);
     }
  }
}

main(){
	nodo *arv = NULL;
	int op, opm;
	float num;
	
	do{
		printf("Digite a opcao: \n");
		printf("1- Inserir\n");
		printf("2- Mostrar\n");
		printf("0- Sair\n");
		scanf("%i", &op);
		switch (op){
			case 1:{
				printf("Digite um numero: ");
				scanf("%f", &num);
				insere_folha(&arv,num);
				break;
			}
			case 2:{
				printf("Digite a opcao para mostrar: \n");
				printf("1- Esquerda\n");
				printf("2- Centro\n");
				printf("3- Direita\n");
				scanf("%i", &opm);
				pre_ordem(arv,opm);
				break;
			}
		}
	}while(op != 0);
}
