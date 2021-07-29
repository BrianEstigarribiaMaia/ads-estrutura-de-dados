#include<stdlib.h>
#include<stdio.h>

//Define a estrutura da Lista Encadeada (Define como sera cada elemento/Nodo da lista)
typedef struct No{
   int idade; //Dados da lista
   struct No *prox; //Ponteiro para o proximo elemento da lista
} No;


//Funcao que cria um elemento
//Retorna um ponteiro para o elemento criado
No *cria_elemento(int idade){
  No *novo;
  novo = (No *)malloc(sizeof(No));
  novo->idade = idade;
  novo->prox  = NULL;
  return novo;
}

//Funcao para inserir um elemento na primeira posicao da lista
No *insere_primeiro(No *lista, No *novo){
   novo->prox = lista;
   return novo;
}

//Insere o novo elemento na ultima posicao da lista
No *insere_ultimo(No *lista, No *novo){
  if (lista != NULL) {
      No *aux = lista;
      while (aux->prox != NULL){
        aux = aux->prox;
      }
      aux->prox = novo;
      return lista;
  }else{
     return novo;
  }
}

No *remove_elemento(No *lista, int posicao){
 
  No *aux = lista;
  No *remove = NULL;
  int cont = 1;

  if (lista == NULL){ //se lista est? vazia
     return NULL;
  }

  while(aux->prox!= NULL && cont < (posicao-1)){
    aux = aux->prox;
    cont++;
  }
 
  // se eh a segunda posicao entao so deve atualizar o cont 
  if (posicao == 2)
  {
     cont++;
  }
  // Testa se a remo??o ? o primeiro da lista.
  // Neste caso, existem duas possibilidades: (a) ter mais de um na lista. 
  // Quando for mais de um, atualizar a lista para o novo primeiro ou
  //(b) ser o unico na lista
  
  if (cont == 1){ 
       if (aux->prox != NULL)
          lista = aux->prox; // atualiza o inicio.    
       else
          lista = NULL;     // caso s? exista na lista o proprio a ser removido
       free(aux);
       }
  else {     
        remove = aux->prox;
        aux->prox = remove->prox;
        free(remove);
        }
  return lista;
  }

void apresenta_lista(No *lista){
  //Percorrendo os elementos da lista
   int cont = 0;
   if (lista != NULL){
     printf("|");
     while (lista != NULL){
       printf("%d|", lista->idade);
       lista = lista->prox;
     }
     printf("\n");
   }
}

No *inserir_elemento_na_posicao(No *lista, No *novo, int posicao){

  No *aux = lista;
  int cont = 1;

  if (lista == NULL){
     return novo;
  }

  while(aux->prox!= NULL && cont < (posicao-1)){
    aux = aux->prox;
    cont++;
  }

  novo->prox = aux->prox;
  aux->prox = novo;

  if (posicao == 1){
      return novo;
  }else{
     return lista;
  }
}

 int main() {

   //No de referencia - Inicio da Lista
   No *lista = NULL;

   //Cria elementos para inserir na lista
   No *n = cria_elemento(35);
   No *n2 = cria_elemento(50);
   No *n3 = cria_elemento(30);
   No *n4 = cria_elemento(55);
   No *n5 = cria_elemento(3);

   printf("Inserindo na ultima posicao da lista os elementos n1 e n2 \n");
   lista = insere_ultimo(lista, n);
   lista = insere_ultimo(lista, n2);

   //Apresenta a lista com os dois elementos
   apresenta_lista(lista);

   system("PAUSE");

   printf("Inserindo n3 como primeiro elemento da lista \n");
   lista = insere_primeiro(lista, n3);

   printf("Inserindo n4 como ultimo elemento da lista \n");
   lista = insere_ultimo(lista, n4);

   // Apresenta a lista com o elemento n3 na primeira posicao
   apresenta_lista(lista);

   system("PAUSE");

   printf("Inserindo elemento n5 na posicao 3 \n");
   lista = inserir_elemento_na_posicao(lista, n5, 3);

   // Apresenta a lista
   apresenta_lista(lista);
   system("PAUSE");


   printf("Removendo o elemento da posição 1 da lista \n");
   lista = remove_elemento(lista, 1);

   // Apresenta a lista
   apresenta_lista(lista);
   system("PAUSE");

   printf("Removendo o elemento da posição 2 da lista \n");
   lista = remove_elemento(lista, 2);

   // Apresenta a lista
  apresenta_lista(lista);
  system ("pause");
 
   printf("Removendo o elemento da posição 3 da lista \n");
   lista = remove_elemento(lista, 3);

   // Apresenta a lista
  apresenta_lista(lista);
  system ("pause");

}
