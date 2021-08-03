//Operacoes sobre Arvore de busca binaria
#include <stdio.h>
#include <stdlib.h>


//Definicao da Arvore
typedef struct nodo{
  char info;
  struct nodo * esquerda;
  struct nodo * direita;
}nodo;


//Criacao de um nodo da arvore
nodo * cria_elemento(char info){
  nodo * novo = (nodo*)malloc(sizeof(nodo));
  novo->info = info;
  novo->esquerda = NULL;
  novo->direita = NULL;
  return novo;
}

//Inclusao de um nodo na Arvore
void insere_folha(nodo ** arv, char info){
   if (*arv == NULL){
     *arv = cria_elemento(info);
   }else{
   //se a informa??o ? menor que a informacao da arvore, insere a esquerda
     if(info < (*arv)->info){
        printf("Inserindo na Esquerda. \n");
        insere_folha(&(*arv)->esquerda, info);
     //se a informa??o ? maior que a informacao da arvore, insere a direita
     }else if (info > (*arv)->info){
        printf("Inserindo na Direita. \n");
        insere_folha(&(*arv)->direita, info);
     }
   }
}

//Caminhamento pre-ordem
void pre_ordem(nodo * arv){
  if (arv != NULL) {
     printf("%c \n",arv->info);
     if (arv->esquerda != NULL){
        printf("Nodo Esquerdo. \n");
        pre_ordem(arv->esquerda);
     }
     if(arv->direita != NULL){
        printf("Nodo Direito. \n");
        pre_ordem(arv->direita);
     }
  }
}

//Caminhamento em-ordem
void em_ordem(nodo * arv){
  if (arv != NULL){
     if (arv->esquerda != NULL){
       printf("Nodo Esquerdo. \n");
       em_ordem(arv->esquerda);
     }
     printf("%c \n", arv->info);
     if (arv->direita != NULL){
       printf("Nodo Direito. \n");
       em_ordem(arv->direita);
     }
  }
}

//Caminhamento pos-ordem
void pos_ordem(nodo * arv){
  if (arv != NULL){
    if (arv->esquerda != NULL){
       printf("Nodo Esquerdo. \n");
       pos_ordem(arv->esquerda);
    }
    if (arv->direita != NULL){
       printf("Nodo direito. \n");
       pos_ordem(arv->direita);
    }
    printf("%c \n", arv->info);
  }
}

//Pesquisar um nodo
void pesquisar_nodo(nodo * arv, char pesq){
  if (arv != NULL){
     if (arv->info == pesq){
        printf("Nodo encontrado %c. \n", arv->info);
     }else{
       if (pesq > arv->info){
          printf("Pesquisando a direita. \n");
          pesquisar_nodo(arv->direita, pesq);
       }else{
          printf("Pesquisando a esquerda. \n");
          pesquisar_nodo(arv->esquerda, pesq);
       }
     }
  }else{
        printf("Nodo nao encontrado\n");
  }
}

//Monta o menu do programa
void monta_menu(){

   printf("//////////////////////////////////////////////////////////////// \n");
   printf("Operacoes sobre Arvores \n");
   printf("Selecione a Opcao Desejada: \n");
   printf("   1 - Incluir Folha\n");
   printf("   2 - Caminhar Em Pre-Ordem \n");
   printf("   3 - Caminhar Em Ordem \n");
   printf("   4 - Caminhar Em Pos-Ordem \n");
   printf("   5 - Pesquisar nodos na Arvore \n");
   printf("   0 - Sair \n");
   printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n \n");
   printf("Qual a sua opcao: ");
}


int main(){
  int op = 1;
  char info ;

  nodo * arv = NULL;

  do{
    monta_menu();
    scanf("%d", &op);
    system("cls");
    switch(op){
       case 1:
          info = '\0';
          while (info != '@'){
            printf("Informe a letra a inserir na arvore (ou @ para sair): \n");
            scanf(" %c", &info);
            if (info != '@'){
              insere_folha(&arv, info);
            }
          }
          break;
       case 2:
          pre_ordem(arv);
          break;
       case 3:
          em_ordem(arv);
          break;
        case 4:
          pos_ordem(arv);
          break;
        case 5:
          printf("Informe a letra a ser pesquisada na Arvore: \n");
          scanf(" %c", &info);
          pesquisar_nodo(arv, info);
          break;

    }
  }while (op != 0);
}
