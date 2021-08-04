#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
  float info;
  struct nodo * nodo1;
  struct nodo * nodo2;
  struct nodo * nodo3;
}nodo;

nodo * cria_elemento(float info){
  nodo * novo = malloc(sizeof(nodo));
  novo->info = info;
  novo->nodo2=NULL;
  novo->nodo1 = NULL;
  novo->nodo3 = NULL;
  return novo;
}

void insere_folha(nodo ** arv, float info){
   if (*arv == NULL){
     *arv = cria_elemento(info);
   }else{
     if(info < 0){
        printf("Inserindo na Esquerda. \n");
        insere_folha(&(*arv)->nodo1, info);
     } 
	 else if (info > 100){
        printf("Inserindo na Direita. \n");
        insere_folha(&(*arv)->nodo3, info);
     }
     else if (info>0&&info<100){
     	printf("Inserindo CENTRO. \n");
        insere_folha(&(*arv)->nodo2, info);
	 }
     
   }
}
	void pre_ordem(nodo * arv,int i){
  if (arv != NULL) {
     printf("%.2f \n",arv->info);
     if (i==1||i==4){
     if (arv->nodo1 != NULL){
        printf("Nodo Esquerdo. \n");
        pre_ordem(arv->nodo1,i);
     }
 }
 	if (i==2||i==4){
     if (arv->nodo2!=NULL){
     	printf ("Nodo Central.\n");
     	pre_ordem(arv->nodo2,i);
	 }
	}
	if (i==3||i==4){
     if(arv->nodo3 != NULL){
        printf("Nodo Direito. \n");
        pre_ordem(arv->nodo3,i);
     }
 }
     
  }
}
  



int main(int argc, char *argv[]) {
	nodo * arv=NULL;
	float x=800;
	int y=-1000; 
	while (x!=0){
		printf ("\n DIGITE O NUMERO A SER INSERIDO,0 PARA SAIR:");
		scanf ("%f",&x);
		insere_folha(&arv,x);
	}
	
	printf ("\n\n PARA VIZUALIZAR ARVORE=4 ,NODO ESQUERDO=1,NODO DIREITO=2,NODO CENTRAL=3,SAIR=0 ");
	while (y!=0){
	scanf ("%d",&y);
	pre_ordem(arv,y);
	}
	return 0;
}
