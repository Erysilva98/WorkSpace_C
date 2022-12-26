#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	char nome[30];
	int valor;
	struct Node * prox;
	struct Node * ant;
};

typedef struct Node node;

struct lista{
	node * inicio;
	node * fim;
	int tamanho;
};

typedef struct lista LISTA;

LISTA * lista_inicia();
void lista_insere(LISTA * lista, const char * nome, int valor);
void lista_imprime(LISTA * l);
void brincadeira(LISTA * l);
void contar(LISTA * lista, int qnt);
void lista_remover(LISTA * l, const char * nome);
node * atPos(LISTA * l, int index);
void lista_libera(LISTA * l);


int main(){
	int n;
	int i;
	char nome[30];
	int valor;	

	LISTA * lista = lista_inicia();

	scanf("%d", &n);

	for(i=1;i<=n;i++){
		scanf(" %s %d", nome, &valor);
		lista_insere(lista, nome, valor);
	}
	contar(lista, lista->inicio->valor);
	lista_libera(lista);

	return 0;
}

LISTA * lista_inicia(){
	LISTA * new = (LISTA *)malloc(sizeof(LISTA));
	new->inicio = NULL;
	new->fim = NULL;
	new->tamanho = 0;
	return new;
}

void lista_insere(LISTA * l, const char * nome, int valor){
	node * new = (node*)malloc(sizeof(node));
	new->valor = valor;
	memcpy(new->nome, nome, strlen(nome));
	if(l->tamanho == 0){
		l->inicio = new;
		l->fim = new;
		l->tamanho++;
	}
	else if(l->tamanho == 1){
		l->inicio->prox = new;
		l->inicio->ant = new;
		l->fim = new;
		new->ant = l->inicio;
		new->prox = l->inicio;
		l->tamanho++;
	}else{
		l->inicio->ant = new;
		new->prox = l->inicio;
		new->ant = l->fim;
		l->fim->prox = new;
		l->fim = new;
		l->tamanho++;
	}
}

void lista_imprime(LISTA * l){
	node * percorre = l->inicio;
	printf("%s %d\n", percorre->nome, percorre->valor);
	percorre = percorre->prox;
	while(percorre!=l->inicio){
		printf("%s %d\n", percorre->nome, percorre->valor);
		percorre = percorre->prox;
	}
	//printf("\nInicio: %s\nFim: %s\n\n", l->inicio->nome, l->fim->nome);
}

void contar(LISTA * lista, int qnt){
	int temp;
	int i;
	node * percorre = lista->inicio;
	if(lista->tamanho == 1){
		printf("Vencedor(a) : %s\n", lista->inicio->nome);
		return;
	}
	if(qnt % 2 == 0){
		for(i=1;i<=qnt;i++){
			percorre = percorre->ant; //HORARIO
			//printf("Ciclo nº: %d\n%s %d\n",i, percorre->nome, percorre->valor);
		}
		int numero = percorre->valor;
		//printf("Parou no: %s\n", percorre->nome);
		lista_remover(lista, percorre->nome);
		//printf("Lista Atual: \n");
		//lista_imprime(lista);
		contar(lista,numero);
	}else if(qnt % 2 != 0){
		for(i=1;i<=qnt;i++){
			percorre = percorre->prox;	//ANTI-HORARIO
			//printf("Ciclo nº: %d\n%s %d\n",i, percorre->nome, percorre->valor);
		}
		int numero = percorre->valor;
		//printf("Parou no: %s %d\n", percorre->nome, numero);
		lista_remover(lista, percorre->nome);
		//printf("\nLista Atual: \n");
		//lista_imprime(lista);
		contar(lista, numero);
	}	
}

void lista_remover(LISTA * l, const char * nome){
	node * percorre =l->inicio, * aux;
	while(percorre->prox != l->inicio){
		if(strcmp(percorre->nome, nome)==0){
			//printf("caiu aqui\n");
			if(percorre == l->inicio){
				l->inicio = percorre->prox;
				l->fim->prox = l->inicio;
				l->inicio->ant = l->fim;
				l->tamanho--;
				free(percorre);
				return;
			}else {
				percorre->ant->prox = percorre->prox;
				percorre->prox->ant = percorre->ant;
				l->tamanho--;
				free(percorre);
				return;
			}
		}
		percorre=percorre->prox;
	}
	if((strcmp(percorre->nome, nome)==0)&&(percorre == l->fim)){
		l->inicio->ant = l->fim->ant;
		l->fim = l->inicio->ant;
		l->fim->prox = l->inicio;
		l->tamanho--;
		free(percorre);
		return;
	}
}

node * atPos(LISTA * l, int index){
	int i;
	node * percorre = l->inicio;
	for(i=1;i<index;i++) percorre=percorre->prox;
	return percorre;
}

void lista_libera(LISTA * l){
	node * percorre = l->inicio->prox;
	node * proximo;
	l->inicio = NULL;
	while(percorre->prox!=NULL){
		proximo=percorre->prox;
		free(percorre);
		proximo = percorre;
	}
	free(l);
}