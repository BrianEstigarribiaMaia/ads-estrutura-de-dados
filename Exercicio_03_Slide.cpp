/***************************************************************************************************
Criar um validador de escopos de expressões
matemáticas usando uma pilha.
O programa deve receber como entrada uma
expressão matemática do tipo
(a * b) + (b * c)
{[(a * b) + (b * c)] – (a * c)} * j
O programa deverá validar se os escopos estão
corretamente delimitados
se para cada “(“ ou “[” ou “{” existe um “)” ou “]” ou “}” na
ordem correta
****************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Definicao de cada elemento da pilha
typedef struct elemento{
  char  simbolo;
  struct elemento * anterior;
}elemento;

//Criacao de um elemento da pilha
elemento * cria_elemento(elemento * topo, char simbolo){
  elemento * novo = malloc(sizeof(elemento));
  novo->simbolo = simbolo;
  novo->anterior = NULL;
  return novo;
}


//Empilhar um elemento
elemento * push(elemento * topo, char simbolo){
  elemento * aux = topo;
  topo = cria_elemento(topo, simbolo);
  topo->anterior = aux;
  return topo;
}


//Verifica se a pilha est? vazia. 1 - Vazia  0 - N?o vazia  
int empty(elemento * topo){
  if (topo == NULL){
    return 1;
  }else{
    return 0;
  }
}

//Se a pilha est? vazia retorna \0, sen?o retorna o s?mbolo do topo
char top(elemento * topo){
  if (empty(topo) == 1){
     return '\0';
  }else{
    return topo->simbolo;
  }
}

//Desempilha os elementos
elemento * pop(elemento ** topo){
   //se pilha n?o est? vazia
   if (empty(*topo) == 0){
      elemento * aux = malloc(sizeof(elemento));
      aux  = *topo;
      *topo = (*topo)->anterior;
      aux->anterior = NULL;
      return aux;
   }else{
      return NULL;
   }
}

//Apresenta a pilha
void mostrar_pilha(elemento * topo){
  while(topo != NULL){
     printf("   ---\n");
     printf("   |%c|\n", topo->simbolo);
     if (topo->anterior == NULL){
        printf("   ---\n");
     }
     topo = topo->anterior;
  }
}

void monta_menu(){

   printf("//////////////////////////////////////////////////////////////// \n");
   printf("Validador de Expressoes \n");
   printf("Selecione a Opcao Desejada: \n");
   printf("   1 - Fornecer a expressao \n");
   printf("   2 - Validar a Expressao \n");
   printf("   0 - Sair \n");
   printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n \n");
   printf("Qual a sua opcao: ");
}

//Funcao com o objetivo de validar o par de delimitadores
int validaPar(char a, char b){
  switch (a){
    case '(':
       if (b == ')'){
         return 1;
       }
    case '[':
       if (b == ']'){
         return 1;
       }
    case '{':
       if (b == '}'){
         return 1;
       }
  }
  return 0;
}


void validar_expressao(elemento * topo, char * expressao){
  int i=0;
  char s;

  while (expressao[i] != '\0'){
     switch(expressao[i]){
        case '(':
        case '[':
        case '{' :
           topo = push(topo,expressao[i]);
           break;
        case ')':
        case ']':
        case '}':
              s = top(topo);
           //se s = \0 ? porque pilha est? vazia
           //se validaPar = 0, ? porque n?o encontrou a dupla de ( ou [ ou {
           if (s == '\0' || validaPar(s, expressao[i]) == 0){
              printf("A expressao informada esta incorreta %s ! \n", expressao);
              return;
           }else{
             //sen?o ?r porque encontrou a dupla e remove o elemento da pilha    
             elemento * excluido = pop(&topo);
             free(excluido);
           }
     }
     i++;
  }
  //se sobrou mais elementos na pilha e n?o tem o correspondente ), ] ou }
  if (empty(topo) != 1){
     printf("A expressao informada esta incorreta %s ! \n", expressao);
  }else{
     printf("A expressao informada %s esta correta!", expressao);
  }
}


int main(){
  int op = 1;
  char expressao[100];

  elemento * topo = NULL;
  elemento * excluido = NULL;

  do{
    monta_menu();
    scanf("%d", &op);
    system("cls");
    switch(op){
       case 1:
          printf("Informe expressao que desejas validar: ");
          //Le como um vetor de caracteres
          scanf("%*c");
          //Le ate encontrar um \n - enter
          scanf("%[^\n]", expressao);
          printf("Expressao lida: %s", expressao);
          break;
       case 2:
          printf("\n");
          validar_expressao(topo, expressao);
          break;
    }
  }while (op != 0);
}
