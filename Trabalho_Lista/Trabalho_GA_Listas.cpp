/************************************************************************************************************ 
Você foi designado para implementar um sistema bancário. Parte desta implementação é a criação de listas duplamente
encadeadas em C.
A primeira lista deve conter as seguintes informações em
cada nodo:
- dinheiro
- crédito
- dívida
Além destes atributos, a primeira lista conterá em cada nodo uma segunda lista. A segunda lista conterá as seguintes
informações:
- idade
- peso
- altura
A primeira lista conterá 4 nodos. Sabendo que dentro de cada nodo da primeira lista temos outra lista (chamada de
segunda lista), teremos ao total 5 listas.A segunda lista contida no primeiro nodo da primeira lista deverá ter 3 nodos.
A segunda lista contida no segundo nodo da primeira lista deverá ter 3 nodos.
A segunda lista contida no terceiro nodo da primeira lista deverá ter 2 nodos.
A segunda lista contida no quarto nodo da primeira lista deverá ter 5 nodos.
Após estruturar todas os elementos das listas você deve:
1) Apresentar a lista principal (primeira lista);
2) Apresentar as quatro listas secundárias (secunda lista);
3) Remover o elemento 2 da lista contida no nodo 4 dentro da lista principal;
4) Exibir a lista principal inversa;
5) Exibir as 4 listas secundárias inversas.
*************************************************************************************************************/
#include<stdlib.h>
#include<stdio.h>

typedef struct Valor{
	float dinheiro, credito, divida;
	struct Valor *prox;
	struct Valor *ant;
	struct Pessoa *pessoa;
}Valor;

typedef struct Pessoa{
	int idade;
	float peso, altura;
	struct Pessoa *prox;
	struct Pessoa *ant;
}Pessoa;

Valor *criar_elem_Valor(float dinheiro, float credito, float divida){
	Valor *novo;
	novo = (Valor *) malloc(sizeof(Valor));
	novo->credito = credito;
	novo->dinheiro = dinheiro;
	novo->divida = divida;
	novo->pessoa = NULL;
	novo->ant = NULL;
	novo->prox = NULL;
}

Pessoa *cria_elem_Pessoa(int idade, float peso, float altura){
	Pessoa *novo;
	novo = (Pessoa *) malloc(sizeof(Pessoa));
	novo->altura = altura;
	novo->idade = idade;
	novo->peso = peso;
	novo->ant = NULL;
	novo->prox = NULL;
}

Valor *insere_ultimo_Pessoa(Valor *lista, Pessoa *novo){
	Valor *valor = lista;
	while (valor->prox != NULL){
		valor = valor->prox;
	}
	Pessoa *pessoa = valor->pessoa;
	if(pessoa != NULL){
		while (pessoa->prox != NULL){
   			pessoa = pessoa->prox;
  		}
  		novo->ant = pessoa;
		pessoa->prox = novo;
  		return lista;
	}else{
		valor->pessoa = novo;
		return lista;
	}
}

Valor *insere_ultimo_Valor(Valor *valor, Valor *novo){
	Valor *lista = valor;
	
	if(lista != NULL){
		while(lista->prox != NULL){
   			lista = lista->prox;
  		}
  		lista->prox = novo;
  		novo->ant = lista;
  		return valor;
	}else{
		return novo;
	}
}

Valor *remover_Pessoa (Valor *listav, int posicaoV, int posicaoP){
	int cont = 1;
	Valor *valor = listav;
	
	while(listav != NULL && cont < posicaoV){
		listav = listav->prox;
		cont++;
	}
	Pessoa *lista = listav->pessoa;
	if (lista != NULL){
    	Pessoa *aux = lista;
    	if (posicaoP == 1){
      		lista = lista->prox;
      		if (lista != NULL){
         		lista->ant = NULL;
      		}
    	}else{
    		int cont2 = 1;
    		while (aux != NULL && cont2 < posicaoP) {
    			aux = aux->prox;
    			cont2++;
      		}
      		if (aux == NULL){
          		printf("A lista nao tem %d elementos \n", posicaoP);
          		return valor;
      		}
      		aux->ant->prox = aux->prox;
      		if (aux->prox != NULL){
        		aux->prox->ant = aux->ant;
	      	}
    	}
    free(aux);
  }else{
     printf("A lista esta vazia! \n");
  }
  return valor;
}

void apresenta_Valor(Valor *valor){
	int cont = 1;
	
	printf("\nPrimeira lista:\n");
	while (valor != NULL){
		printf("Elemento %i:\n", cont);
		printf("Dinheiro: %.2f\n",valor->dinheiro);
		printf("Credito: %.2f\n",valor->credito);
		printf("Divida: %.2f\n",valor->divida);
		valor = valor->prox;
		cont++;
	}
}

void apresenta_Pessoa(Valor *valor){
	int cont = 1, cont2;
	printf("\nSegunda lista:\n");
	while (valor != NULL){
		cont2=1;
		Pessoa *teste = valor->pessoa;
		while (teste != NULL){
			printf("Elemento %i: Nodo %i\n", cont, cont2);
			printf("Idade: %i\n", teste->idade);
			printf("Peso: %.2f\n", teste->peso);
			printf("Altura: %.2f\n", teste->altura);
			teste = teste->prox;
			cont2++;
		}
		printf("\n");
		cont++;
		valor = valor->prox;
	}
}

void apresenta_Valor_inverso(Valor *lista){
   	int cont = 1;
   	while(lista->prox != NULL){
   		lista = lista->prox;
   		cont++;
   	}
   	while (lista != NULL){
		printf("Elemento %i:\n", cont);
		printf("Dinheiro: %.2f\n",lista->dinheiro);
		printf("Credito: %.2f\n",lista->credito);
		printf("Divida: %.2f\n",lista->divida);
		lista = lista->ant;
		cont--;
	}
}

void apresenta_Pessoa_inverso(Valor *listav){
	int cont = 1, cont2 = 1;
	Pessoa *lista = NULL;
	
	while(listav->prox != NULL){
		listav = listav->prox;
		cont++;
	}
   	while(listav != NULL){
   		lista = listav->pessoa;
   		cont2=1;
   		while(lista->prox != NULL){
	   		lista = lista->prox;
   			cont2++;
   		}
		while (lista != NULL){
			printf("Elemento %i: Nodo %i\n", cont, cont2);
			printf("Idade: %i\n", lista->idade);
			printf("Peso: %.2f\n", lista->peso);
			printf("Altura: %.2f\n", lista->altura);
			lista = lista->ant;
			cont2--;
		}
		printf("\n");
		cont--;
		listav = listav->ant;
	}
}

main(){
	Valor *lista = NULL;
	Valor *v = criar_elem_Valor(1000,400,100);
	Valor *v1 = criar_elem_Valor(2000,500,200);
	Valor *v2 = criar_elem_Valor(3000,600,300);
	Valor *v3 = criar_elem_Valor(4000,700,400);
	Pessoa *p = cria_elem_Pessoa(18,80,1.80);
	Pessoa *p1 = cria_elem_Pessoa(19,80,1.80);
	Pessoa *p2 = cria_elem_Pessoa(20,80,1.80);
	Pessoa *p3 = cria_elem_Pessoa(21,80,1.80);
	Pessoa *p4 = cria_elem_Pessoa(22,80,1.80);
	Pessoa *p5 = cria_elem_Pessoa(23,80,1.80);
	Pessoa *p6 = cria_elem_Pessoa(24,80,1.80);
	Pessoa *p7 = cria_elem_Pessoa(25,80,1.80);
	Pessoa *p8 = cria_elem_Pessoa(26,80,1.80);
	Pessoa *p9 = cria_elem_Pessoa(27,80,1.80);
	Pessoa *p10 = cria_elem_Pessoa(28,80,1.80);
	Pessoa *p11 = cria_elem_Pessoa(29,80,1.80);
	Pessoa *p12 = cria_elem_Pessoa(30,80,1.80);

	lista = insere_ultimo_Valor(lista,v);
	lista = insere_ultimo_Pessoa(lista,p);
	lista = insere_ultimo_Pessoa(lista,p1);
	lista = insere_ultimo_Pessoa(lista,p2);
	
	lista = insere_ultimo_Valor(lista,v1);
	lista = insere_ultimo_Pessoa(lista,p3);
	lista = insere_ultimo_Pessoa(lista,p4);
	lista = insere_ultimo_Pessoa(lista,p5);
	
	lista = insere_ultimo_Valor(lista,v2);
	lista = insere_ultimo_Pessoa(lista,p6);
	lista = insere_ultimo_Pessoa(lista,p7);
	
	lista = insere_ultimo_Valor(lista,v3);
	lista = insere_ultimo_Pessoa(lista,p8);
	lista = insere_ultimo_Pessoa(lista,p9);
	lista = insere_ultimo_Pessoa(lista,p10);
	lista = insere_ultimo_Pessoa(lista,p11);
	lista = insere_ultimo_Pessoa(lista,p12);
	
	apresenta_Valor(lista);
	apresenta_Pessoa(lista);
	
	printf("\nRemove elemento 2 no nodo 4 da primeira lista\n");
	lista = remover_Pessoa(lista,4,2);
	apresenta_Valor(lista);
	apresenta_Pessoa(lista);
	
	printf("\nApresenta lista principal inversa\n");
	apresenta_Valor_inverso(lista);
	printf("\nApresenta lista secundaria inversa\n");
	apresenta_Pessoa_inverso(lista);
}
