/*--------------------------------EX_01-----------------------------------

* Criar o procedimento para inserir em uma posição específica da lista
void inserir_elemento_na_posicao(No * primeiro, No * novo, int posicao)

* Criar uma lista de alunos, contendo o nome,
número de matrícula e idade.

*Apresentar a média de idade dos alunos contidos na
lista.

------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//ESTRUTURA 
typedef struct Aluno{
	char nome[50];
	int matricula;
	int idade;
	struct Aluno *prox;
}Aluno; 

//PROCEDIMENTOS 

/*--criar elemento--*/ 
Aluno *cria_elemento(char nome[], int matricula, int idade){
  Aluno *novo;
  novo = (Aluno *) malloc(sizeof(Aluno));
  strcpy(novo->nome,nome);
  novo->matricula = matricula;
  novo->idade = idade;
  novo->prox  = NULL;
  return novo;
}

/*--inserir elementos--*/
Aluno * inserir_elemento_na_posicao(Aluno *lista, Aluno *novo, int posicao){
	Aluno *aux = lista;
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

/*--mostrar lista--*/

void mostrar_lista(Aluno *lista){
  //Percorrendo os elementos da lista
   int cont = 0;
   if (lista != NULL){
     while (lista != NULL){
       printf("Nome: %s\n", lista->nome);
       printf("Matricula: %d\n", lista->matricula);
       printf("Idade: %d\n", lista->idade);
       lista = lista->prox;
     }
     printf("\n");
   }
}

//FUNÇÃO MAIN
int main(){
	setlocale(LC_ALL,"");
	float media = 0.0;
	Aluno *lista = NULL;
	
	Aluno *aluno_1 = cria_elemento("Joao",1001,23);
    Aluno *aluno_2 = cria_elemento("Lucas",1002,25);
   
    media = (23+25)/2;
	   
	printf("Inserindo elemento aluno 1 na posicao 2 \n");
    lista = inserir_elemento_na_posicao(lista, aluno_1, 2);
    
    mostrar_lista(lista);
    
    printf("Inserindo elemento aluno 2 na posicao 1 \n");
    lista = inserir_elemento_na_posicao(lista, aluno_2, 1);
	
    mostrar_lista(lista);
    
	printf("Media de idades = %.2f\n",media);
	
	system("pause");
	return 0;
}


