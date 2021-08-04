#include <stdio.h>
#include <stdlib.h>

//Inserir fila no criar elemento arvore.

typedef struct elemento{
  int  valor;
  struct elemento * ptr_proximo;
}elemento;


typedef struct descritor{
  struct elemento * ptr_inicio_fila;
  struct elemento * ptr_fim_fila;
}descritor;

typedef struct nodo{
  struct descritor * desc;
  struct nodo * esquerda;
  struct nodo * direita;
}nodo;

elemento * cria_elemento_fila(int valor){
  elemento *novo=malloc(sizeof(elemento));;
  novo->valor = valor;
  novo->ptr_proximo = NULL;
  return novo;
}
int empty(descritor * desc){
  if (desc->ptr_inicio_fila == NULL){
    return 1;
  }else{
    return 0;
  }
}

void enqueue(descritor * desc, elemento * novo){
  if (empty(desc) == 1){
     desc->ptr_inicio_fila = novo;
     desc->ptr_fim_fila = novo;
  }else{
      desc->ptr_fim_fila->ptr_proximo = novo;
      desc->ptr_fim_fila       = novo;
  }
}

nodo * cria_elemento_arv(int info){
  int x;
  descritor * desc = (descritor *) malloc(sizeof(descritor));
  nodo * novo_nodo = malloc(sizeof(nodo));
  novo_nodo->desc=malloc(sizeof(descritor));
  novo_nodo->desc->ptr_inicio_fila=NULL;
  novo_nodo->desc->ptr_fim_fila=NULL;
  novo_nodo->esquerda = NULL;
  novo_nodo->direita = NULL;
  elemento * novo_elemento =malloc(sizeof(elemento));
  
  for (x=0;x<info;x++){
  	novo_elemento = cria_elemento_fila(rand()%10);
	enqueue (novo_nodo->desc,novo_elemento); 
	
  }
  return novo_nodo;
  
}

void insere_folha(nodo ** arv, int info){
   if (*arv == NULL){
     *arv = cria_elemento_arv(info);
   }else{
     if(info%2==0){
        printf("Inserindo na Esquerda. \n");
        insere_folha(&(*arv)->esquerda, info);
     }else if(info%2!=0){
        printf("Inserindo na Direita. \n");
        insere_folha(&(*arv)->direita, info);
     }
   }
}

void mostrar_fila(elemento * fila){

    while(fila != NULL){
       printf(" |%d|", fila->valor);
       if (fila->ptr_proximo == NULL){
          printf("   ---\n");
       }
       fila = fila->ptr_proximo;
    }
}


void pre_ordem(nodo * arv){
  if (arv != NULL) {
     mostrar_fila(arv->desc->ptr_inicio_fila);
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
void em_ordem(nodo * arv){
  if (arv != NULL){
     if (arv->esquerda != NULL){
       printf("Nodo Esquerdo. \n");
       em_ordem(arv->esquerda);
     }
     mostrar_fila(arv->desc->ptr_inicio_fila);
     if (arv->direita != NULL){
       printf("Nodo Direito. \n");
       em_ordem(arv->direita);
     }
  }
}
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
    mostrar_fila(arv->desc->ptr_inicio_fila);
  }
}

main (){
	nodo * arv=NULL;
	int x,info;
	
	for (x=0;x<4;x++){
	info =rand()%25;
	if (info>4){
		printf ("%d",info);
		insere_folha(&arv,info);
	}
	else x--;
	}
	printf ("\n PRE-ORDEM\n");
	pre_ordem(arv);
	printf ("\n EM ORDEM \n");
	em_ordem(arv);
	printf ("\n POS-ORDEM \n");
	pos_ordem(arv);
	
	
}

 
