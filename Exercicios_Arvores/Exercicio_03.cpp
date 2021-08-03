/*************************************************************************
Desenhe uma árvore binária com 30 nodos. O critério de
crescimento deve ser definido por você. Cada nodo deve possuir
uma variável do tipo float.
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definicao da Arvore
typedef struct nodo{
  float info;
  struct nodo * esquerda;
  struct nodo * direita;
}nodo;

//Criacao de um nodo da arvore
nodo * cria_elemento(float info){
  nodo * novo = (nodo*)malloc(sizeof(nodo));
  novo->info = info;
  novo->esquerda = NULL;
  novo->direita = NULL;
  return novo;
}

//Inclusao de um nodo na Arvore
void insere_folha(nodo **arv, int info){
   if (*arv == NULL){
     *arv = cria_elemento(info);
   }else{
   //se a informa??o ? menor que a informacao da arvore, insere a esquerda
     if(info < (*arv)->info){
        printf("Inserindo na Esquerda. \n");
        insere_folha(&(*arv)->esquerda, info);
     //se a informa??o ? maior que a informacao da arvore, insere a direita
     }else if (info > (*arv)->info){
        printf("Inserindo na Direita. \n");
        insere_folha(&(*arv)->direita, info);
     }
   }
}
//Caminhamento pre-ordem
void pre_ordem(nodo * arv){
  if (arv != NULL) {
     printf("%.2f \n",arv->info);
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
     printf("%.2f \n", arv->info);
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
    printf("%.2f \n", arv->info);
  }
}


int main(){
	nodo * arv = NULL;
	
	for(float i = 1.0; i <= 30.0; i++){
		insere_folha(&arv, i);
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
