#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cliente{
	int idade;
	int rg;
	char cidade[50];
	float dinheiro;
} cliente;

//Definicao de cada elemento da fila
typedef struct elemento{
  cliente*  valor;
  struct elemento * ptr_proximo;
}elemento;


//Definicao do descritor. Ponteiros que armazezam o inicio e o final da fila
typedef struct descritor{
  struct elemento * ptr_inicio_fila;
  struct elemento * ptr_fim_fila;
}descritor;

//Criacao de um elemento da fila
elemento * cria_elemento(cliente* valor){
  elemento *novo;
  novo = (elemento *) malloc(sizeof(elemento));

  novo->valor = valor;
  novo->ptr_proximo = NULL;
  return novo;
}

//Verifica se a fila esta vazia. Se fila vazia retorna 1, sen?o retorna 0
int empty(descritor * desc){
  if (desc->ptr_inicio_fila == NULL){
    return 1;
  }else{
    return 0;
  }
}

//Insere um elemento na fila seguindo o criterio FIFO
void enqueue(descritor * desc, elemento * novo){
  if (empty(desc) == 1){
     desc->ptr_inicio_fila = novo;
     desc->ptr_fim_fila = novo;
  }else{
      desc->ptr_fim_fila->ptr_proximo = novo;
      desc->ptr_fim_fila       = novo;
  }
}

//Remove um elemento da fila seguindo o critério FIFO
elemento * dequeue(descritor * desc){
   if (empty(desc) == 0){
      elemento * aux = desc->ptr_inicio_fila;
      desc->ptr_inicio_fila = aux->ptr_proximo;
      if(desc->ptr_inicio_fila == NULL){
         desc->ptr_fim_fila = NULL;
      }
      aux->ptr_proximo = NULL;
      return aux;
   }else{
     printf("A fila esta vazia! \n");
     return NULL;
   }
}

void imprimeFila(descritor* fila)
{
	elemento* aux = fila->ptr_inicio_fila;
	while (aux != NULL)
	{
		printf("Rg: %d\n", aux->valor->rg);
		printf("Cidade: %s\n",aux->valor->cidade);
		printf("Dinheiro: %.2f\n",aux->valor->dinheiro);
		printf("Idade: %d\n",aux->valor->idade);
		aux = aux->ptr_proximo;
		printf("-------------------------------------------------------------\n\n");
	}
}

descritor* copiaFila(descritor* fila)
{
	descritor* novo = (descritor*)malloc(sizeof(descritor));
	novo->ptr_fim_fila = NULL;
	novo->ptr_inicio_fila = NULL;
	elemento* aux = fila->ptr_inicio_fila;
	while (aux != NULL)
	{
		elemento* novoElemento = cria_elemento(aux->valor);
		enqueue(novo, novoElemento);
		aux = aux->ptr_proximo;
	}
	return novo;
}

elemento* removeDaFila(descritor* fila, elemento* elem)
{
	elemento* ant = NULL;
	elemento* aux = fila->ptr_inicio_fila;

	while (aux != elem && aux != NULL)
	{
		ant = aux;
		aux = aux->ptr_proximo;
	}

	if (aux == NULL)
		return NULL;
	if (ant != NULL)
		ant->ptr_proximo = aux->ptr_proximo;
	else
		fila->ptr_inicio_fila = aux->ptr_proximo;
	if (aux == fila->ptr_fim_fila)
		fila->ptr_fim_fila = ant;
	return aux;
}

cliente* criaCliente(int idade, int rg, float dinheiro,char cidade[50])
{
	cliente* c = (cliente*)malloc(sizeof(cliente));
	strcpy(c->cidade, cidade);
	c->rg = rg;
	c->idade = idade;
	c->dinheiro = dinheiro;

	return c;
}

void exercicio3(descritor* fila)
{
	descritor* cloneFila = copiaFila(fila);
	descritor* ordenado;
	ordenado->ptr_fim_fila = NULL;
	ordenado->ptr_inicio_fila = NULL;
	while (empty(cloneFila) != 1)
	{
		elemento* aux = cloneFila->ptr_inicio_fila->ptr_proximo;
		elemento* maior = cloneFila->ptr_inicio_fila;

		while (aux != NULL)
		{
			if (maior->valor->idade < aux->valor->idade)
				maior = aux;
			aux = aux->ptr_proximo;
		}
		removeDaFila(cloneFila, maior);
		elemento* novo = cria_elemento(maior->valor);
		
		enqueue(ordenado, novo);
	}

	imprimeFila(ordenado);

}

int main(){

	cliente *n1  = criaCliente (12, 1000001, 5000.00, "Sao Paulo");
    cliente *n2  = criaCliente (20, 1000003, 4000.00, "Sao Paulo");
    cliente *n3  = criaCliente (30, 1000002, 1500.00, "Porto Alegre"); 
    cliente *n4  = criaCliente (15, 1000004, 2500.00, "Porto Alegre");
    cliente *n5  = criaCliente (45, 1000006, 500.00 , "Curitiba");
    cliente *n6  = criaCliente (40, 1000005, 700.00 , "Curitiba");
    cliente *n7  = criaCliente (50, 1000008, 400.00 , "Rio de Janeiro");
    cliente *n8  = criaCliente (55, 1000007, 600.00 , "Rio de Janeiro");
    cliente *n9  = criaCliente (65, 1000009, 3600.00, "Brasilia");
    cliente *n10 = criaCliente (60, 1000010, 6000.00, "Brasilia");

	elemento* e1 = cria_elemento(n1);
	elemento* e2 = cria_elemento(n2);
	elemento* e3 = cria_elemento(n3);
	elemento* e4 = cria_elemento(n4);
	elemento* e5 = cria_elemento(n5);
	elemento* e6 = cria_elemento(n6);
	elemento* e7 = cria_elemento(n7);
	elemento* e8 = cria_elemento(n8);
	elemento* e9 = cria_elemento(n9);
	elemento* e10 = cria_elemento(n10);

	descritor* fila = (descritor*)malloc(sizeof(descritor));
	fila->ptr_fim_fila = NULL;
	fila->ptr_inicio_fila = NULL;
	
	enqueue(fila, e1);
	enqueue(fila, e2);
	enqueue(fila, e3);
	enqueue(fila, e4);
	enqueue(fila, e5);
	enqueue(fila, e6);
	enqueue(fila, e7);
	enqueue(fila, e8);
	enqueue(fila, e9);
	enqueue(fila, e10);

	printf("ELEMENTOS DA FILA\n\n");
	imprimeFila(fila);
	printf("********************************************\n\n\n\n");
	printf(" EXERCICIO 3 - Ordenar por idade\n\n\n\n");
	exercicio3(fila);
	
	system("pause");
	return 0;
}
