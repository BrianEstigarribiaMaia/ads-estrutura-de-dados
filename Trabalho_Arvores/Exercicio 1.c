#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cont = 0;

typedef struct nodo{
  int num;
  struct nodo *esquerda;
  struct nodo *direita;
}nodo;

typedef struct No{
	nodo *arv;
	struct No *ant;
	struct No *prox;
}No;

nodo *cria_elemento(int num){
  nodo *novo = malloc(sizeof(nodo));
  novo->num = num;
  novo->esquerda = NULL;
  novo->direita = NULL;
  return novo;
}

No *cria_elem(){
	No *novo;
	novo = (No *) malloc(sizeof(No));
	novo->prox = NULL;
	novo->ant = NULL;
	novo->arv = NULL;
	return novo;
}

void insere_folha(nodo **arv, int num){
   if (*arv == NULL){
     *arv = cria_elemento(num);
     cont++;
   }else{
     if(num < (*arv)->num){
        printf("Inserindo na Esquerda. \n");
        insere_folha(&(*arv)->esquerda, num);
     }else if (num > (*arv)->num){
        printf("Inserindo na Direita. \n");
        insere_folha(&(*arv)->direita, num);
     }
   }
}

No *inserir_elemento_na_posicao(No *lista, No *novo, int posicao){
	No *aux = lista;
	No *aux2 = NULL;
	int cont = 1;
	
	if(lista == NULL){
		return novo;
	}
	if(posicao == 1){
		lista->ant = novo;
		novo->prox = lista;
		return novo;
	}	
	while(aux->prox != NULL && cont < (posicao-1)){
		aux = aux->prox;
		cont++;
	}
	novo->prox = aux->prox;
	aux->prox = novo;
	novo->ant = aux;
	if(novo->prox != NULL){
		aux->ant = aux->ant->prox;
	}
	return lista;
}

No *retorna_ultimo_da_lista(No * lista){
  while (lista->prox != NULL){
    lista = lista->prox;
  }
  return lista;
}

void Gera_arv(No *lista){
	cont = 0;
	int num,i;
	nodo *arv = NULL;
	
	while(lista->prox != NULL){
		lista = lista->prox;
	}
	do{
		num = (rand() % 9) + 1;
		insere_folha(&arv,num);	
	}while(cont < 5);
	lista->arv = arv;
}

void pre_ordem(nodo *arv){
  if (arv != NULL) {
     printf("%i \n",arv->num);
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

void em_ordem(nodo *arv){
  if (arv != NULL){
     if (arv->esquerda != NULL){
       printf("Nodo Esquerdo. \n");
       em_ordem(arv->esquerda);
     }
     printf("%d \n", arv->num);
     if (arv->direita != NULL){
       printf("Nodo Direito. \n");
       em_ordem(arv->direita);
     }
  }
}

void apresenta_lista_pre_ordem(No *lista){
	if(lista != NULL){
		printf("|");
		while(lista != NULL){
			pre_ordem(lista->arv);
			lista = lista->prox;
		}
		printf("\n");
	}
}

void apresenta_lista_em_ordem(No *lista){
	if(lista != NULL){
		printf("|");
		while(lista != NULL){
			em_ordem(lista->arv);
			lista = lista->prox;
		}
		printf("\n");
	}
}

main(){
	No *lista = NULL;
	int i;
	srand(time(NULL));
	
	for(i=0;i<2;i++){
		No *no = cria_elem();
		lista = inserir_elemento_na_posicao(lista,no,i+1);
		Gera_arv(lista);
	}
	printf("Pre-ordem\n\n");
	apresenta_lista_pre_ordem(lista);
	printf("EM-ordem\n\n");
	apresenta_lista_em_ordem(lista);
	
	system("pause");
}
