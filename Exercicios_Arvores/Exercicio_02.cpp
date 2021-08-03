/*****************************************************************************
Implemente uma árvore binária que em cada nodo possua um número inteiro (tipo int). 
Seu programa deve realizar as seguintes operações na árvore:

a) Quando o resto da divisão do inteiro contido no nodo dividido por 2 for 0, a árvore 
deve crescer para a esquerda;
b) Quando o resto da divisão do inteiro contido no nodo por 2 for 1, a árvore 
deve crescer para a direita;
c) O número inteiro contido em cada nodo deve ser sorteado entre 1 e 1000 ;
d) Insira 35 nodos na árvore;
e) Percorra a árvore com caminhamento Pré-fixado, Central
e Pós-fixado;
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Definicao da Arvore
typedef struct nodo{
  int info;
  struct nodo * esquerda;
  struct nodo * direita;
}nodo;


//Criacao de um nodo da arvore
nodo * cria_elemento(int info){
  nodo * novo = (nodo*)malloc(sizeof(nodo));
  novo->info = info;
  novo->esquerda = NULL;
  novo->direita = NULL;
  return novo;
}

//Inclusao de um nodo na Arvore
void insere_folha(nodo ** arv, int info){
   if (*arv == NULL){
     *arv = cria_elemento(info);
   }else
     if(info % 2 == 0){
        //printf("Inserindo na Esquerda. \n");
        insere_folha(&(*arv)->esquerda, info);
     }else{
        //printf("Inserindo na Direita. \n");
        insere_folha(&(*arv)->direita, info);
     }
   }

//Caminhamento pre-ordem
void pre_ordem(nodo * arv){
  if (arv != NULL) {
     printf("%d \n",arv->info);
     if (arv->esquerda != NULL){
        printf("Nodo Esquerdo. \n");
        pre_ordem(arv->esquerda);
     }
     if(arv->direita != NULL){
        printf("Nodo Direito. \n");
        pre_ordem(arv->direita);
     }
  }
}

//Caminhamento em-ordem
void em_ordem(nodo * arv){
  if (arv != NULL){
     if (arv->esquerda != NULL){
       printf("Nodo Esquerdo. \n");
       em_ordem(arv->esquerda);
     }
     printf("%d \n", arv->info);
     if (arv->direita != NULL){
       printf("Nodo Direito. \n");
       em_ordem(arv->direita);
     }
  }
}

//Caminhamento pos-ordem
void pos_ordem(nodo * arv){
  if (arv != NULL){
    if (arv->esquerda != NULL){
       printf("Nodo Esquerdo. \n");
       pos_ordem(arv->esquerda);
    }
    if (arv->direita != NULL){
       printf("Nodo direito. \n");
       pos_ordem(arv->direita);
    }
    printf("%d \n", arv->info);
  }
}


int main(){
	nodo * arv = NULL;
	
	for(int i = 0; i<= 34; i++){
		int num = 1 +(rand()% 1000);
		insere_folha(&arv, num);
	}
	
	printf("PRE-ORDEM\n\n");
    pre_ordem(arv);
    printf("-------------\n\n");
    printf("EM ORDEM\n\n");
    em_ordem(arv);
    printf("-------------\n\n");
    printf("POS-ORDEM\n\n");
    pos_ordem(arv);
    printf("-------------\n\n");

	system("pause");
	return 0;	
}
