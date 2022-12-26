#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
    struct no *anterior;
}No;

// procedimento para inserir no início
void inserir_no_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        novo->anterior = NULL;
        
        if(*lista)
        {
            (*lista)->anterior = novo;
        }
        *lista = novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no fim
void inserir_no_fim(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro?
        if(*lista == NULL)
        {
            *lista = novo;
            novo->anterior = NULL;
        }
        else
        {
            aux = *lista;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no meio
void inserir_no_meio(No **lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        // é o primeiro?
        if(*lista == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->valor != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            if(aux->proximo)
            {
                aux->proximo->anterior = novo;
            }
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void inserir_ordenado(No **lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;

        if(*lista == NULL)
        {
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }
        else if (novo->valor < (*lista)->valor)
        {
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo && novo->valor > aux->proximo->valor)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;

            if(aux->proximo)
            {
                aux->proximo->anterior = novo;
            }
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }
    else
    {
        printf("Erro ao alocar Memoria! \n");
    }
}

No* remover(No **lista, int num)
{
    No *aux, *remover = NULL;

    if(*lista)
    {
        if((*lista)->valor == num)
        {
            remover = *lista;
            *lista = remover->proximo;
            if(*lista)
            {
                (*lista)->anterior = NULL;
            }
            else
            {
                aux = *lista;
                while (aux->proximo && aux->proximo->valor != num)
                {
                    aux = aux->proximo;
                }
                if(aux->proximo)
                {
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                    if(aux->proximo)
                    {
                        aux->proximo->anterior = aux;
                    }
                }
                
            }
        }
    }
    return remover;
}

No* buscar(No **lista, int num)
{
    No *aux, *no = NULL;

    aux = *lista;
    while (aux && aux->valor != num)
    {
        aux = aux->proximo;
    }
    if(aux)
    {
        no = aux;
    }
    return no;
}

void imprimir(No *no){
    printf("\n\tLista: ");
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

No* ultimo(No **lista)
{
    No *aux = *lista;
    while (aux->proximo)
    {
        aux = aux->proximo;
    }
    return aux;    
}

int main(){

    int opcao, valor, anterior;
    No *removido, *lista = NULL;

    do{
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - inserirF\n\t3 - InserirM\n\t4 - InserirO\n\t5 - Imprimir\n\t6 - Remover\n\t7 - Buscar\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Valor Add no Início da Lista");
            valor = 10;
            inserir_no_inicio(&lista, valor);
            valor = 90;
            inserir_no_inicio(&lista, valor);
            valor = 40;
            inserir_no_inicio(&lista, valor);

            break;
        case 2:
            printf("Valor Add no Final da Lista");
            valor = 100;
            inserir_no_fim(&lista, valor);
            break;
        case 3:
            printf("Valor Add no Meio da Lista");
            valor = 20;
            anterior = 40;
            inserir_no_meio(&lista, valor, anterior);
            break;    
        case 4:
            printf("Valor add na lista de forma Ordenada");
            valor = 12;
            inserir_ordenado(&lista, valor);
            break;
        case 5:
            imprimir(lista);
            break;
        
        case 6:
            printf("Valor a ser Removido = 10 ");
            valor = 10;
            removido = remover(&lista,valor);
            if(removido)
            {
                printf("Elemento a ser Removido: %d\n", removido->valor);
                free(removido);
            }
            else
                printf("Elemento nao existe! \n");
            break;
        case 7:
            printf("Informe o Valor a ser Procurado = 20 ");
            valor = 20;
            removido = buscar(&lista, valor);
            if(removido)
            {
                printf("Elemento a ser Encontrado: %d\n", removido->valor);
            }
            else
                printf("Elemento nao encontrado! \n");
            break;  
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}