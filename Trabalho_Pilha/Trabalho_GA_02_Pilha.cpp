/*******************************************************************************************************
Você foi designado para implementar uma pilha com quantidade de elementos determinada pelo usuário.
A pilha deve conter as seguintes informações em cada elemento:
- id (tipo int);
- lista (tipo No).

A lista (que deve ser duplamente encadeada) deverá conter em cada nodo:
- registro (tipo int);
- valor (tipo float).

O Main() do programa deverá conter 3 operações básicas:
- Criação da pilha;
- Chamada de função para definir o escopo da pilha e das listas;
- Chamada de função para mostrar a estrutura da pilha e das listas contidas em cada elemento da pilha.

A função que define o escopo das pilhas e das listas deverá:
- Permitir que o usuário defina quantos elementos possui a pilha;
- Definir o ID de cada pilha (int);
- Definir a quantidade de nodos na lista dentro dos elementos da pilha;
- Definir o registro de cada nodo da lista (int);
- Definir o valor de cada nodo da lista (float);

A função que mostra a estrutura da pilha e das listas deverá:
- Mostrar o ID de cada elemento da pilha e qual é o do topo;
- Mostrar cada nodo da lista contida dentro dos elementos da pilha e suas variáveis (registro e valor);

Além disso, a sua implementação deve permitir que a
operação pop seja realizada na pilha. Realize-a e chame a função
de mostrar a pilha
***********************************************************************************************************/

#include<stdlib.h>
#include<stdio.h>

typedef struct No{
   int registro;
   float valor;
   struct No *proximo;
   struct No *anterior;
} No;

No * criar_elemento(int registro, float valor){
  printf("Novo nodo criado! \n");
  No *novo;
  novo = (No *) malloc(sizeof(No));
  novo->registro = registro;
  novo->valor = valor;
  novo->proximo  = NULL;
  novo->anterior = NULL;
  return novo;
}

No * insere_primeiro(No * lista, No * novo){
   if (lista != NULL){
     lista->anterior = novo;
     novo->proximo = lista;
   }
   return novo;
}

No * retorna_ultimo_da_lista(No * lista){
  while (lista->proximo != NULL){
    lista = lista->proximo;
  }
  return lista;
}

No * insere_ultimo(No * lista, No * novo){
  if (lista != NULL) {
    No * n = retorna_ultimo_da_lista(lista);
    n->proximo = novo;
    novo->anterior = n;
    return lista;
  }else{
    return novo;
  }
}

void apresenta_lista(No * lista){
  //Percorrendo os elementos da lista
   int cont = 1;
   while (lista != NULL){
      printf("\nElemento: %d Registro: %d Valor: %f", cont, lista->registro, lista->valor);
      cont++;
      lista = lista->proximo;
   }
}

void apresenta_lista_inversa(No * lista){
   int cont = 1;
   No * ultimo = retorna_ultimo_da_lista(lista);
   system("pause");
   while (ultimo != NULL){
      printf("\nElemento: %d Registro: %d Valor: %f", cont, ultimo->registro, ultimo->valor);
      cont++;
      ultimo = ultimo->anterior;
   }
}

No * remove_elemento(No * lista, int posicao){
  if (lista != NULL){
    No * aux = lista;
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

No * insere_na_lista(No * lista, No * novo, int posicao){
  No * aux = lista;
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

//Definicao de cada elemento da pilha
typedef struct elemento{
  int  valor;
  No *lista;
  struct elemento * anterior;
}elemento;

//Criacao de um elemento da pilha
elemento * criar_elemento(elemento * topo, int valor){
  elemento * novo = (elemento *)malloc(sizeof(elemento));
  novo->valor = valor;
  novo->anterior = NULL;
  return novo;
}

//Inserir elementos na pilha
elemento * push(elemento * topo, int valor){
  elemento * aux = topo;
  topo = criar_elemento(topo, valor);
  topo->anterior = aux;
  return topo;
}

//Verifica se a pilha esta vazia (retorna 1) ou tem elementos (Retorna 0)
int empty(elemento * topo){
  if (topo == NULL){
    return 1;
  }else{
    return 0;
  }
}

elemento * pop(elemento * topo){
   elemento * aux;
   if (empty(topo) == 0){ //se pilha n?o est? vazia
      aux  = topo;
      topo = topo->anterior;
      free(aux);
   }else{
      printf("A pilha esta vazia! \n");
      system("pause");
      
   }
   return topo;

}

/*void mostrar_pilha(elemento * topo){
  int first = 1;
  if (topo != NULL){
     while(topo != NULL){
        printf("   ---\n");
        if (first){
           printf("   |%d| <---- Topo \n", topo->valor);
           first = 0;
        }else{
           printf("   |%d|\n", topo->valor);
        }
        if (topo->anterior == NULL){
           printf("   ---\n");
        }
        topo = topo->anterior;
     }
  }else{

     printf("A pilha esta vazia! \n");
  }
}*/

void mostrar_pilha_lista(elemento * topo){
  int first = 1;
  if (topo != NULL){
     while(topo != NULL){
        printf("-----------------------------\n");
        if (first == 1)
        	printf("Pilha: |ID: %d| <--- TOPO\nLista %d", topo->valor, first); 
		else
		   printf("Pilha: |ID: %d| \nLista %d", topo->valor, first); 
		apresenta_lista(topo->lista);    
        if (topo->anterior == NULL){
           printf("\n-----------------------------");
        }
        
         
        printf("\n");
        topo = topo->anterior;	
		first++;	      
     }
  }else{

     printf("A pilha esta vazia! \n");
  }
}

No * DefineLista(No *lista){
	lista = NULL;
	int quantiaNodos = 0;
	printf("Digite a quantidade de nodos na lista dentro da pilha\n");
	scanf("%d", &quantiaNodos);
	
	No *n[quantiaNodos];
	
	int i = 0;	
	for(i = 0; i < quantiaNodos; i++){
		int registroTemp = 0;
		float valorTemp = 0;
		
		printf("Insira o registro do nodo na lista\n");
		scanf("%d", &registroTemp);
		
		printf("Insira o valor do nodo na lista\n");
		scanf("%f", &valorTemp);
		
		n[i] = criar_elemento(registroTemp, valorTemp);
		lista = insere_ultimo(lista, n[i]);
	}
	
	return lista;
}

elemento * DefinePilha(elemento * topo){
	int quantiaNodos = 0;
	printf("Digite a quantidade de nodos na pilha \n");
	scanf("%d", &quantiaNodos);
	
	int i;	
	for(i = 0; i < quantiaNodos; i++){	
		int idTemp = 0;
		printf("Digite a id do elemento da pilha \n");
		scanf("%d", &idTemp);
		
		topo = push(topo, idTemp);
		topo->lista = DefineLista(topo->lista);
	}
	
	return topo;
}

 int main() { 	
 	elemento * topo = NULL; 	
	topo = DefinePilha(topo);
	system("cls");
	mostrar_pilha_lista(topo);
   
    system("pause");  
}
