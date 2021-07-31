//Operacoees sobre pilhas
#include<stdio.h>
#include<stdlib.h>


//Definicao de cada elemento da pilha
typedef struct elemento{
  int  valor;
  struct elemento * anterior;
}elemento;

//Criacao de um elemento da pilha
elemento * cria_elemento(elemento * topo, int valor){
  elemento *novo;
   	
  novo = (elemento * )malloc(sizeof(elemento));
  novo->valor = valor;
  novo->anterior = NULL;
  return novo;
}

//Inserir elementos na pilha
elemento * push(elemento * topo, int valor){
  elemento * aux = topo;
  topo = cria_elemento(topo, valor);
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

void mostrar_pilha(elemento * topo){
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
}

void monta_menu(){
   system("cls");
   printf("############################################\n");
   printf("Operacoes sobre Pilhas \n");
   printf("Selecione a Opcao Desejada: \n");
   printf("   1 - Incluir \n");
   printf("   2 - Excluir \n");
   printf("   3 - Mostrar Pilha \n");
   printf("   0 - Sair \n");
   printf("############################################\n \n");
   printf("Qual a sua opcao: ");
}


int main(){
  int op = 1;
  int valor=0;

  elemento * topo = NULL;
 // elemento * excluido = NULL;

  do{
    monta_menu();
    scanf("%d", &op);

    switch(op){
       case 1:
          printf("Informe um valor para o novo elemento da pilha: ");
          scanf("%d", &valor);
          topo = push(topo, valor);
          break;
       case 2:
          topo = pop(topo);
          break;
       case 3:
          mostrar_pilha(topo);
          system("pause");
          break;
    }
  }while (op != 0);
}
