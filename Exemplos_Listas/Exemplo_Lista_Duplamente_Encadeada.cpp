#include <stdlib.h>
#include <stdio.h>

//===========================================================
typedef struct No{
   int idade;             //informação
   struct No *proximo;    //pontteiro para proximo nó
   struct No *anterior;   //ponteiro para nó anterior 
} No;

//===========================================================
No *criar_elemento(int idade){
  No *novo;                            //ponteiro novo aponta para No
  novo = (No *) malloc(sizeof(No));    //alocando memória para nova informação
  novo->idade    = idade;              //pasando novo para informação
  novo->proximo  = NULL;               //atribuindo NULL como inicialização das variaveis 
  novo->anterior = NULL;
  return novo;
}

//===========================================================
//Funcao abaixo insere no inicio da lista
No *insere_primeiro(No *lista, No *novo){
   if (lista != NULL){            //se a lista não está vazia 
     lista->anterior = novo;      //nó que era primeiro aponta para novo
     novo->proximo   = lista;     //novo nó agora como primeiro aponta para próximo
   }
   return novo;                   //retorna resultado 
}

//===========================================================
No *retorna_ultimo_da_lista(No *lista){
  while (lista->proximo != NULL){  //enquanto proximo elemento for diferente de NULL ou percorrer até o ultimo elemento
    lista = lista->proximo;        //mostrar ultimo elemento
  }
  return lista;                    //retorna resultado 
}

//===========================================================
No *insere_ultimo(No *lista, No *novo){
  if (lista != NULL) {                        //se a lista não está vazia 
    No *n = retorna_ultimo_da_lista(lista);   //valor de n é igual a ultimo elemento 
    n->proximo     = novo;                    //n aponta para novo
    novo->anterior = n;                       //novo aponta para n
    return lista;                             //retorna atualização da lista
  }else{
    return novo;                              //se a lista estiver vazia retorna o valor do novo elemento
  }
}

//===========================================================
void apresenta_lista(No *lista){
  //Percorrendo os elementos da lista do primeiro ao ultimo elemento 
   int cont = 0;
   while (lista != NULL){
      printf("Idade do elemento %d, %d \n", cont, lista->idade);
      cont++;
      lista = lista->proximo;
   }
}
//===========================================================
void apresenta_lista_inversa(No *lista){
   int cont = 0;
   No *ultimo = retorna_ultimo_da_lista(lista);       //pega ultimo elemento encontrado e passa de parametro para "ultimo"
   system("pause");
   while (ultimo != NULL){                            //enquanto ultimo não apontar para null
      printf("Idade do elemento %d, %d \n", cont, ultimo->idade);
      cont++;
      ultimo = ultimo->anterior;                      //aponta para nó anterior 
   }
}

//===========================================================
No *remove_elemento(No *lista, int posicao){
  if (lista != NULL){
   //printf("Removendo NULL \n");
    No *aux = lista;
    //exclusao lista
    if (posicao == 1){
      lista = lista->proximo;
      //Se nao for o ultimo elemento da lista
      if (lista != NULL){
         lista->anterior = NULL;
      }
    }else{
      int cont = 1;
      while (aux != NULL && cont < posicao) {
        aux = aux->proximo;
        cont++;
      }

      if (aux == NULL){
          printf("A lista nao tem %d elementos \n", posicao);
          return lista;
      }

      aux->anterior->proximo = aux->proximo;

      //exclusão do último não necessita atualizar a referencia de um elemento posterior
      if (aux->proximo != NULL){
        aux->proximo->anterior = aux->anterior;
      }
    }
    free(aux);
  }else{
     printf("A lista esta vazia! \n");
  }
  return lista;
}

//===========================================================
No *insere_na_lista(No *lista, No *novo, int posicao){
  No *aux = lista;
  //Inclusão no inicio
  if (lista == NULL || posicao == 1){
     lista = insere_primeiro(lista, novo);
  }else{
    int cont = 1;
    while (aux->proximo != NULL && cont < posicao) {
      aux = aux->proximo;
      cont++;
    }
    //Inclusão no último
    if (aux->proximo == NULL){
       insere_ultimo(lista, novo);
    }else{
       //inclusão em outro ponto
       aux->anterior->proximo = novo;
       novo->proximo  = aux;
       novo->anterior = aux->anterior;
     
       aux->anterior  = novo;
    }
  }
  return lista;
}

//===========================================================
 int main() {
   // Criando referencia para a lista
   No *lista = NULL;

   // criar um lista apontada por n com o primerio elemento
   No *n  = criar_elemento(35);
   No *n2 = criar_elemento(50);
   No *n3 = criar_elemento(30);
   No *n4 = criar_elemento(55);
   No *n5 = criar_elemento(3);
   No *n6 = criar_elemento(1);

   printf("Inserindo na ultima posicao da lista os elementos n2, n3 e n4 \n");
   lista = insere_ultimo(lista, n2);
   lista = insere_ultimo(lista, n3);
   lista = insere_ultimo(lista, n4);
   apresenta_lista(lista);
   system("PAUSE");

   printf("Inserindo n5 como primeiro elemento da lista. \n");
   lista = insere_primeiro(lista, n5);
   apresenta_lista(lista);
   system("PAUSE");

   printf("Removendo o elemento da posicao 4 da lista. \n");
   lista = remove_elemento(lista, 4);
   apresenta_lista(lista);
   system("PAUSE");

   printf("Apresentado a lista em ordem inversa. \n");
   apresenta_lista_inversa(lista);
   system("PAUSE");


   printf("Inserindo n6 na posicao 2 da lista. \n");
   lista = insere_na_lista(lista, n6, 2);
   apresenta_lista(lista);
   system("PAUSE");

   printf("Apresentado a lista em ordem inversa. \n");
   apresenta_lista(lista);
   system("PAUSE");

   printf("Removendo 4 \n");
   lista = remove_elemento(lista, 4);
   apresenta_lista(lista);
   system("PAUSE");

   printf("Removendo 3 \n");
   lista = remove_elemento(lista, 3);
   apresenta_lista(lista);

   printf("Removendo 2 \n");
   lista = remove_elemento(lista, 2);
   apresenta_lista(lista);

   printf("Removendo 1 \n");
   lista = remove_elemento(lista, 1);
   apresenta_lista(lista);
   system("PAUSE");
}
