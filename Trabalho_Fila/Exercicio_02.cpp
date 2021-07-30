/***********************************************************************
	“Os últimos serão os primeiros e os primeiros serão os últimos”.   *
	Crie uma função que muda o apontamento do último elemento          *
	da fila do exercício 1 para o primeiro elemento da fila (ou seja,  *
	troque o primeiro e o último de lugar). Assim que realizar a troca,*
	realizem uma operação dequeue até que não reste nenhum             *
	elemento."                                                         *
	                                                                   *
	Matéria: Estrutura de dados                                        *
	Aluno: Brian Estigarribia                                          *
                                                                       *
************************************************************************/

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

/* Função exercicio 2 */
void troca(descritor *desc){
	elemento* prim = desc->ptr_inicio_fila;
	elemento* ult = desc->ptr_fim_fila;
	elemento* ant = NULL;
	elemento* aux = desc->ptr_inicio_fila;
	
	while (aux != ult)
	{
		ant = aux;
		aux = aux->ptr_proximo;
	}
	
	ult->ptr_proximo = prim->ptr_proximo;
	desc->ptr_inicio_fila = ult;
	prim->ptr_proximo = NULL;
	desc->ptr_fim_fila = prim;
	
	if (ant != NULL){
		ant->ptr_proximo = prim;
	}
	
	desc->ptr_fim_fila = prim;
	
}

int main(){

  descritor *desc = (descritor *) malloc(sizeof(descritor));
  desc->ptr_inicio_fila = NULL;
  desc->ptr_fim_fila    = NULL;

  //elemento *excluido = NULL;
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
  
  printf(" EXERCICIO 2 \n\n\n");
  printf(" Troca do primeiro com o ultimo\n\n");
  troca(desc);
  mostrar_fila(desc->ptr_inicio_fila);
  
  system("pause");
  return 0;
}
