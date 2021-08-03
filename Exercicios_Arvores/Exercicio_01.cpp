/***************************************************************************
Organize a hierarquia dos setores de uma empresa através
de uma árvore. Inicie o nodo raiz com o presidente e cria mais 5
níveis (diretor, gerente, vendedor, caixa e empacotador). Cada
nível deve possuir no mínimo 2 nodos.
/***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definicao da Arvore
typedef struct nodo{
  char info [50];
  struct nodo * esquerda;
  struct nodo * direita;
}nodo;


//Criacao de um nodo da arvore
nodo * cria_elemento(char info[]){
  nodo * novo = (nodo*)malloc(sizeof(nodo));
  strcpy(novo->info,info);
  novo->esquerda = NULL;
  novo->direita = NULL;
  return novo;
}

//Inclusao de um nodo na Arvore
void insere_folha(nodo ** arv, char info[]){
   if (*arv == NULL){
     *arv = cria_elemento(info);
   }else{
   //se a informa??o ? menor que a informacao da arvore, insere a esquerda
     if(info < (*arv)->info){
        //printf("Inserindo na Esquerda. \n");
        insere_folha(&(*arv)->esquerda, info);
     //se a informa??o ? maior que a informacao da arvore, insere a direita
     }else if (info > (*arv)->info){
        //printf("Inserindo na Direita. \n");
        insere_folha(&(*arv)->direita, info);
     }
   }
}

void pre_ordem(nodo * arv){
  if (arv != NULL) {
     printf("%s \n",arv->info);
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


int main(){
	nodo *arv = NULL;
	
	insere_folha(&arv, "presidente"); //raiz
	insere_folha(&arv, "diretor a"); //n1
	insere_folha(&arv, "diretor b");
	insere_folha(&arv, "gerente j"); //n2
	insere_folha(&arv, "gerente i");
	insere_folha(&arv, "vendedor o"); //n3
	insere_folha(&arv, "vendedor m");
	insere_folha(&arv, "caixa r"); //n4	
	insere_folha(&arv, "caixa s");
	insere_folha(&arv, "empacotador y"); //n5
	insere_folha(&arv, "empacotador x");				

	printf("HIERARQUIA (PRE-ORDEM)\n\n");
	pre_ordem(arv);
	printf("---------\n");

	system("pause");
	return 0;
}
