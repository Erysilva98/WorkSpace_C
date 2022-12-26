#include <stdio.h>
#include <stdlib.h>

#define True 1 
#define False 0

typedef int chave;

typedef struct tip_No
{
    chave info;
    struct tip_No *ant;
    struct tip_No *prox;   
}tpLista;

typedef struct No
{
    int cod;
    float preco;
    char *produto;
    struct No *topo;
    
}Produtos;

typedef struct tip_produto
{
    Produtos *info;
    struct tip_produto *prox;
    
}Mercado;

void listagem (Mercado *t)
{
    Mercado *p = t;

    if (t!= NULL)
        do{
            printf("Info: %d", p->info);
            p = p->prox;
        }
        while (p!=t);
    else
    {
        printf("Lista Circular Vazia!");
    }

}

int pushProduto (Mercado **t, chave ch)
{
    Mercado *novo;

    novo = alloca(sizeof(Mercado));

    if(novo == NULL)    // Sem espaço
    {
        return False;
    }
    else
    {
        novo->info = ch;
        if(*t == NULL)  // Primeiro
        {

            *t = novo;
        }
        else            // Não é o Primeiro
        {
            novo->prox = (*t)->prox;
        }
        (*t)->prox = novo;
        return True;
    }
}

int popProduto(tpLista **t, int valor)
{
    tpLista*p;

    p = listagem(*t);

    if ( p==NULL)
    {
        return False;   // Não achou o elemento
    }
    if (*t ==p)
    {
        *t=p->prox; // primeiro elemento
    }
    else
    {
        p->ant->prox = p->prox; // não é o primeiro
    }
    if (p->prox != NULL)        // Não é o último
    {
        p->prox->ant = p->ant;
    }
    free(p);
    return True;
}

Mercado* aloca(void)
{
    Mercado *p = (Mercado*) malloc(sizeof(Mercado));
    p->prox = NULL;

    return p;
}

int main()
{
    Mercado *p;

    p->info->preco = 1;
    p->info->preco = 10.5;
    p->info->produto = "Óleo";

    return False;
}