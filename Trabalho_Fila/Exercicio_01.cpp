/*********************************************************************
	Implemente uma fila de pessoas que deverá possuir os             *
	atributos: RG, dinheiro, idade e cidade (local de nascimento).   *
	Devem ser inseridas 100 pessoas na fila e os atributos devem ser *
	preenchidos de forma aleatória (com limites dos valores          *
	coerentes). Crie 5 cidades diferentes para preenchimento         *
	aleatório. Após criar os nodos, apresente em funções distintas:  *
                                                                     *
	a) Média de idade das pessoas na fila;                           *
	b) Maior idade registrada na fila;                               *
	c) Menor idade registrada na fila;                               *
	d) Quantidade de crianças, jovens e adultos na fila (utilizar    *
	critério brasileiro);                                            *
	e) Média de dinheiro das pessoas da fila;                        *
	f) Soma de dinheiro das pessoas da fila;                         *
	g) Exibir todos os RGs das pessoas na fila separados por         *
	cidade.                                                          *
	                                                                 *
	Matéria: Estrutura de dados                                      *
	Aluno: Brian Estigarribia                                        *
                                                                     *
**********************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Definicao de cada elemento da fila
typedef struct elemento{
  int idade;
  int rg;
  float dinheiro;
  char cidade[50];
  struct elemento * ptr_proximo;
}elemento;


//Definicao do descritor. Ponteiros que armazezam o inicio e o final da fila
typedef struct descritor{
  struct elemento * ptr_inicio_fila;
  struct elemento * ptr_fim_fila;
}descritor;

/* Operações sobre a fila */
//Criacao de um elemento da fila
elemento * cria_elemento(int idade, int rg, float dinheiro, char cidade[50]){
  elemento *novo;
  novo = (elemento *) malloc(sizeof(elemento));

  novo->idade = idade;
  novo->rg = rg;
  novo->dinheiro = dinheiro;
  strcpy(novo->cidade, cidade);
  novo->ptr_proximo = NULL;
  return novo;
}

//Verifica se a fila esta vazia. Se fila vazia retorna 1, sen?o retorna 0
int empty(descritor *desc){
  if (desc->ptr_inicio_fila == NULL){
    return 1;
  }else{
    return 0;
  }
}

//Insere um elemento na fila seguindo o criterio FIFO
void enqueue(descritor *desc, elemento *novo){
  if (empty(desc) == 1){
     desc->ptr_inicio_fila = novo;
     desc->ptr_fim_fila = novo;
  }else{
      desc->ptr_fim_fila->ptr_proximo = novo;
      desc->ptr_fim_fila = novo;
  }
}


//Remove um elemento da fila seguindo o critério FIFO
elemento * dequeue(descritor *desc){
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

//Mostra os elementos da fila
void mostrar_fila(elemento *fila){

    while(fila != NULL){
       printf("idade %d \n", fila->idade);
       printf("rg %d \n", fila->rg);
       printf("dinheiro %.2f \n", fila->dinheiro);
       printf("cidade %s \n", fila->cidade);
       printf("----------------------------------\n\n");
       fila = fila->ptr_proximo;
    }
}

/* Funções exercicio 1 */
//Função média de idade
void media_idade(descritor *desc)
{
	int soma = 0;
	int qtd = 0;
	float media = 0.0;
	elemento *aux = desc->ptr_inicio_fila;
	while (aux != NULL)
	{
		soma += aux->idade;
		aux = aux->ptr_proximo;
		qtd++;
	}
	media = soma / qtd;
	
	printf("Media: %.2f\n",media);
	printf("----------------------------------\n");
}

//Função maior idade
void maior_idade(descritor *desc)
{
	int maior = 0;
	elemento* aux = desc->ptr_inicio_fila;
	while (aux != NULL)
	{
		if (maior < aux->idade){
			maior = aux->idade;	
		}
		aux = aux->ptr_proximo;
	}
	printf("Maior %d\n", maior);
	printf("----------------------------------\n");
}

//Função menor idade
void menor_idade(descritor *desc)
{
	int menor;
	elemento* aux = desc->ptr_inicio_fila;
	while (aux != NULL)
	{
		if (menor > aux->idade){
			menor = aux->idade;
		}
	
		aux = aux->ptr_proximo;
	}
	printf("Menor: %d\n",menor);
	printf("----------------------------------\n");
}

//Função faixa etaria
void faixa_etaria(descritor *desc)
{
	int crianca = 0;
	int jovem = 0;
	int adulto = 0;
	elemento *aux = desc->ptr_inicio_fila;

	while (aux != NULL)
	{
		if (aux->idade < 13)
			crianca = crianca + 1;
		else if (aux->idade < 18)
			jovem = jovem + 1;
		else
			adulto = adulto + 1;
		aux = aux->ptr_proximo;
	}
	
	printf("Criancas: %d\n", crianca);
	printf("Jovens:   %d\n", jovem);
	printf("Aultos:   %d\n", adulto);
	printf("----------------------------------\n");
}

//Função media dinheiro
void media_dinheiro(descritor *desc)
{
	float soma = 0;
	float media = 0.0;
	int qtd = 0;
	elemento* aux = desc->ptr_inicio_fila;
	while (aux != NULL)
	{
		qtd++;
		soma += aux->dinheiro;
		aux = aux->ptr_proximo;
	}
	media = soma / qtd;
	
	printf("Media: %.2f\n", media);
	printf("----------------------------------\n");
}

//Função soma dinheiro
void soma_dinheiro(descritor *desc)
{
	float soma = 0;
	elemento* aux = desc->ptr_inicio_fila;
	while (aux != NULL)
	{
		soma += aux->dinheiro;
		aux = aux->ptr_proximo;
	}
	printf("Soma: %.2f\n", soma);
	printf("----------------------------------\n");
}

//Função rg por cidades
void rg_cidade(descritor *desc)
{
	elemento* aux = desc->ptr_inicio_fila;
	while (aux != NULL)
	{
		printf("Rg: %d    \n" ,aux->rg);
		printf("Cidade: %s \n" ,aux->cidade);
		printf("\n\n");
		aux = aux->ptr_proximo;
    }
    printf("----------------------------------\n");
}


int main(){

  descritor *desc = (descritor *) malloc(sizeof(descritor));
  desc->ptr_inicio_fila = NULL;
  desc->ptr_fim_fila    = NULL;

  elemento *excluido = NULL;
  //elemento *novo = NULL;
  
  elemento *n1  = cria_elemento (12, 1000001, 5000.00, "Sao Paulo");
  elemento *n2  = cria_elemento (20, 1000003, 4000.00, "Sao Paulo");
  elemento *n3  = cria_elemento (30, 1000002, 1500.00, "Porto Alegre"); 
  elemento *n4  = cria_elemento (15, 1000004, 2500.00, "Porto Alegre");
  elemento *n5  = cria_elemento (45, 1000006, 500.00 , "Curitiba");
  elemento *n6  = cria_elemento (40, 1000005, 700.00 , "Curitiba");
  elemento *n7  = cria_elemento (50, 1000008, 400.00 , "Rio de Janeiro");
  elemento *n8  = cria_elemento (55, 1000007, 600.00 , "Rio de Janeiro");
  elemento *n9  = cria_elemento (65, 1000009, 3600.00, "Brasilia");
  elemento *n10 = cria_elemento (60, 1000010, 6000.00, "Brasilia");
  // ...100
  
  enqueue(desc,n1);
  enqueue(desc,n2);
  enqueue(desc,n3);
  enqueue(desc,n4);
  enqueue(desc,n5);
  enqueue(desc,n6);
  enqueue(desc,n7);
  enqueue(desc,n8);
  enqueue(desc,n9);
  enqueue(desc,n10);
  // ...100
  
  printf("ELEMENTOS DA FILA \n\n\n");
  mostrar_fila(desc->ptr_inicio_fila);
  
  printf(" EXERCICIO 1 \n\n\n");
  printf("a) Media de idade das pessoas na fila\n");
  media_idade(desc);
  printf("b) Maior idade registrada na fila\n");
  maior_idade(desc);
  printf("c) Menor idade registrada na fila\n");
  menor_idade(desc);
  printf("d) Quantidade de criancas, jovens e adultos na fila\n");
  faixa_etaria(desc);
  printf("e) Media de dinheiro das pessoas da fila\n");
  media_dinheiro(desc);
  printf("f) Soma de dinheiro das pessoas da fila\n");
  soma_dinheiro(desc);
  printf("g) Exibir todos os RGs das pessoas na fila separados por cidade\n");
  rg_cidade(desc);
  
  system("pause");
  return 0;
}
