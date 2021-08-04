#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cont=0;

typedef struct No{
	int num;
	struct No *prox;
}No;

No *Gera_Fila(int num);

typedef struct Descritor{
  struct No *ptr_inicio_fila;
  struct No *ptr_fim_fila;
}Descritor;

typedef struct nodo{
	No *fila;
  	struct nodo *esquerda;
  	struct nodo *direita;
}nodo;

Descritor *cria_Descritor(){
	Descritor *desc = (Descritor *) malloc(sizeof(Descritor));
  	desc->ptr_inicio_fila = NULL;
  	desc->ptr_fim_fila    = NULL;
  	return desc;
}

No *cria_elem(int num){
	No *novo;
	novo = (No *) malloc(sizeof(No));
	novo->num = num;
	novo->prox = NULL;
	return novo;
}

nodo *cria_elemento(No *fila){
  nodo *novo = malloc(sizeof(nodo));
  novo->esquerda = NULL;
  novo->direita = NULL;
  novo->fila = fila;
  return novo;
}

int empty(Descritor *desc){
  if (desc->ptr_inicio_fila == NULL){
    return 1;
  }else{
    return 0;
  }
}

void insere_folha(nodo **arv, int num){
   if (*arv == NULL){
   		No *teste = Gera_Fila(num);
     	*arv = cria_elemento(teste);
   }else{
     if(num % 2 == 0){
        printf("Inserindo na Esquerda. \n");
        insere_folha(&(*arv)->esquerda, num);
     }else if (num % 2 == 1){
        printf("Inserindo na Direita. \n");
        insere_folha(&(*arv)->direita, num);
     }
   }
}

void enqueue(Descritor *desc, No *novo){
  if (empty(desc) == 1){
     desc->ptr_inicio_fila = novo;
     desc->ptr_fim_fila = novo;
  }else{
      desc->ptr_fim_fila->prox = novo;
      desc->ptr_fim_fila = novo;
  }
}

No *Gera_Fila(int tam){
	Descritor *desc = NULL;
	No *fila = NULL;
	desc = cria_Descritor();
	int i;
	
	for(i=0;i<tam;i++){
		fila = cria_elem(rand() % 100);
		enqueue(desc,fila);
	}
	return desc->ptr_inicio_fila;
}

void mostrar_fila(No *fila){
    int cont=0;
	while(fila != NULL){
    	cont++;
		printf("A fila na posicao %i contem: %i\n", cont, fila->num);
		printf("---------------------\n");
       	fila = fila->prox;
    }
}

void pre_ordem(nodo *arv){
  	if (arv != NULL) {
  		cont++;
    	printf("Fila %i:\n", cont);
    	mostrar_fila(arv->fila);
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
     cont++;
    	printf("Fila %i:\n", cont);
    	mostrar_fila(arv->fila);
     if (arv->direita != NULL){
       printf("Nodo Direito. \n");
       em_ordem(arv->direita);
     }
  }
}

void pos_ordem(nodo *arv){
  if (arv != NULL){
    if (arv->esquerda != NULL){
       printf("Nodo Esquerdo. \n");
       pos_ordem(arv->esquerda);
    }
    if (arv->direita != NULL){
       printf("Nodo direito. \n");
       pos_ordem(arv->direita);
    }
    cont++;
    	printf("Fila %i:\n", cont);
    	mostrar_fila(arv->fila);
  }
}

main(){
	nodo *arv = NULL;
	int i, num;
	srand(time(NULL));
	
	for(i=0;i<5;i++){
		num = (rand() % 20) + 5;
		insere_folha(&arv,num);
	}
	cont = 0;
	printf("------------------Exibindo com caminhamento pre-fixado------------------\n");
	pre_ordem(arv);
	cont = 0;
	printf("------------------Exibindo com caminhamento central---------------------\n");
	em_ordem(arv);
	cont = 0;
	printf("------------------Exibindo com caminhamento pos-fixado------------------\n");
	pos_ordem(arv);
	
	system("pause");
	return 0;
}
