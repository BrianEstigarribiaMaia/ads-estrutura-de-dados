#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
  int info;
  struct nodo * esquerda;
  struct nodo * direita;
}nodo;
typedef struct No{
   struct nodo *raiz; 
   struct No *prox; 
} No;

nodo * cria_elemento_arv(char info){
  nodo * novo = malloc(sizeof(nodo));
  novo->info = info;
  novo->esquerda = NULL;
  novo->direita = NULL;
  return novo;
}

No * cria_elemento_lista(){
  No *novo;
  novo = (No *) malloc(sizeof(No));
  novo->raiz = NULL;
  novo->prox  = NULL;
  return novo;
}
No * insere_primeiro(No * lista, No * novo){
   novo->prox = lista;
   return novo;
}

void insere_folha(nodo ** arv, int info){
   if (*arv == NULL){
     *arv = cria_elemento_arv(info);
   }else{
     if(info < (*arv)->info){
        printf("Inserindo na Esquerda. \n");
        insere_folha(&(*arv)->esquerda, info);
     }else if (info > (*arv)->info){
        printf("Inserindo na Direita. \n");
        insere_folha(&(*arv)->direita, info);
     }
   }
}
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

void apresenta_lista(No * lista){
   if (lista != NULL){
     printf("|");
     while (lista != NULL){
       pre_ordem(lista->raiz);
       
       lista = lista->prox;
     }
     printf("\n");
   }
}

main()
{
	No* lista=NULL;
	nodo*raiz=NULL;
	int x,z;
	for (x=0;x<5;x++){
		No* n =cria_elemento_lista();
		lista=insere_primeiro(lista,n);
			z=rand()%10;
			insere_folha(&n->raiz,z);
	
		
		
	}

	apresenta_lista(lista);
	system("pause");
	return 0;
}
