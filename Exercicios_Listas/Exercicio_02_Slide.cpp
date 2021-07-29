/*----------------------------EX_02------------------------------

* Criar um procedimento para remover nodo no fim da lista
No * remove_ultimo(No * lista)

* Criar um procedimento para remover nodo no início da lista
No * remove_primeiro(No * lista)

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*-----Crirar tipo abstrato de dadoo-----*/
typedef struct No{
   int num;
   struct No *prox;
} No;

/*-----Criar elemento para ser ultilizado na lista -----*/
No *criar_elemento(int num){
  No *novo;
  novo = (No *) malloc(sizeof(No));
  novo->num = num;
  novo->prox  = NULL;
  return novo;
}

/*-----Inserir elemento na primeira posição da lista-----*/
No *inserir_primeiro(No *lista, No *novo){
   novo->prox = lista;
   return novo;
}

/*-----Inserir elemento na ultima posição da lista-----*/
No *inserir_ultimo(No *lista, No *novo){
   novo->prox = lista;
   return novo;
}

/*-----Remover primeiro elemento da lista-----*/
No *remover_primeiro(No *lista, int pos){
 
  No * aux = lista;
  int cont = 1;

  if (lista == NULL){ 
     return NULL;
  }

  while(aux->prox!= NULL && cont < (pos-1)){
    aux = aux->prox;
    cont++;
  }
 
  if (pos == -1)
  {
     cont++;
  } 
  if (cont == 1){ 
       if (aux->prox != NULL)
          lista = aux->prox; 
       else
          lista = NULL;   
       free(aux);
       }
  return lista;
  }

/*-----Remover ultimo elemento da lista-----*/
No * remover_ultimo(No * lista, int pos){
 
  No * aux = lista;
  No * remove = NULL;
  int cont = 1;

  if (lista == NULL){ 
     return NULL;
  }

  while(aux->prox!= NULL && cont < (pos-1)){
    aux = aux->prox;
    cont++;
  }

    remove = aux->prox;
    aux->prox = remove->prox;
    free(remove);
    
  return lista;
}

/*-----Mostrar lista atualizada na tela-----*/  
void apresentar_lista(No * lista){

   int cont = 0;
   if (lista != NULL){
     while (lista != NULL){
       printf("|%d|", lista->num);
       lista = lista->prox;
     }
     printf("\n");
   }
}

/*-----Função principal -----*/
int main() {

   No * lista = NULL;
   
   No *n1 = criar_elemento(55);
   No *n2 = criar_elemento(60);
   No *n3 = criar_elemento(10);
   No *n4 = criar_elemento(120);
   
   printf("Mostrando os elemento da lista: \n");
   lista = inserir_primeiro(lista, n1);
   lista = inserir_primeiro(lista, n2);
   lista = inserir_ultimo(lista, n3);
   lista = inserir_ultimo(lista, n4);

   apresentar_lista(lista);
   
   printf("Removendo elemento do inicio da lista: \n");
   lista = remover_primeiro(lista, 0);

   apresentar_lista(lista);
   system("PAUSE");
   
   printf("Removendo elemento do fim da lista: \n");
   lista = remover_ultimo(lista, 3);

   apresentar_lista(lista);
   system("PAUSE");
   
   return 0;
}
