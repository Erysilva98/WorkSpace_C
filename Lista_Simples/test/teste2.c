#include <stdio.h>
#include <stdlib.h>

typedef int chave;

typedef struct no
{
    int valor;
    struct no *prox;
}No;

void pushInicio (No **lista, int num)
{
    No *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;  // Preenhcer valor
        novo->prox = *lista; // O prox de novo nò aponta para o inicio da lista
        * lista = novo;     // o Inicio da lista passar a ser o novo nó
    }
    else
    {
        printf("Error ao Alocar memoria \n");
    }
}

void pushFim (No **lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;
        novo->prox = NULL;

        // è o primeiro?
        if(*lista == NULL)
        {
            *lista = novo;  // Primeiro nó da lista
        }
        else
        {
            aux = *lista;
            while (aux->prox)   // Caminha até o último nó da lista
            {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    } 
    else
    {
        printf("Erro ao Alocar Memoria! \n");
    }
}

void pushMeio (No **lista, int num, int ant)
{
    No *aux, *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;

        // é o primeiro?
        if(*lista == NULL)
        {
            novo->prox = NULL;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->valor != ant && aux->prox)
            {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memoria! \n");
    }
}

void imprimir(No *no)
{
    printf("\n\t Lista Encadeada Circular! \n");

    while (no)
    {
        printf("%d ", no->valor);
        no = no->prox;
    }
    printf("\n\n");
    
}

int main()
{
    int opc, valor, anterior;
    No *lista = NULL;

    do{
        printf("\n\t0 - Sair ");
        printf("\n\t1 - Inserir no Inicio ");
        printf("\n\t2 - Inserir no Final ");
        printf("\n\t3 - Inserir no Meio ");
        printf("\n\t4 - Imprimir ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
        {
            printf("Valor Add no Início da Lista");
            valor = 10;
            pushInicio(lista,valor);
            break;
        }    
        case 2:
        {
            printf("Valor Add no Final da Lista");
            valor = 50;
            pushFim(lista,valor);

            valor = 33;
            pushFim(lista,valor);
            break;
        }    
        case 3:
        {
            printf("Valor Add no Meio da Lista");
            valor = 22;
            anterior = 33;
            pushMeio(lista,valor,anterior);
            break;
        } 
        default:
        {
            if(opc != 0)
            {
                printf("Opcao Invalida !\n")
            }
            
            break;
        }
    }   
    while (opc != 0);
    
    return 0;
}