/*
   -- Implementação de um Lista Circular Duplamente Encadeada
    -- Métodos:
        Iniciar Lista, 
        Adicionar Registro, 
        Remover Registro, 
        Resetar Lista, 
        Imprimir Lista.
    -- Autor: Erimilson Silva
    -- 12/12/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0

typedef int Tip_Chave;

typedef struct // Registro
{
    Tip_Chave chave;
    char *nome;
    int idade;
    char *matricula;
    int curso;
    int periodo;

}Reg;

typedef struct no
{
    Reg cadastro;
    struct no *proximo; 
    struct no *anterior;   
}No;

typedef struct // Lista Circular
{
    No *inicio;
    No *final;
    size_t tam;    // Determinar o tamanho da Lista
}cLista;

No *criarNo(Reg cad)
{
    No *no = malloc (sizeof(No));

    no->cadastro.chave = cad.chave;
    no->cadastro.nome = cad.nome;
    no->cadastro.idade = cad.idade;
    no->cadastro.matricula = cad.matricula;
    no->cadastro.curso = cad.curso;
    no->cadastro.periodo = cad.periodo;
    
    no->proximo = no;
    no->anterior = no;

    return no;
}

cLista *initLista()
{
    cLista *lista = malloc(sizeof(cLista));

    lista->inicio = NULL;
    lista->final = NULL;
    lista->tam = 0;

    return lista;
}

int isVazia(cLista *lista)
{
    // Retorna True
    return (lista->tam == 0);   
}

void addLista(cLista *lista, Reg cad)
{
    No *novo = criarNo(cad);
    novo->proximo = lista->inicio;

    // Se a Lista está Vazia
    if(isVazia(lista))      
    {
        lista->inicio = novo;
        lista->final = novo;
        printf("\n Sucesso! \n");
    }
    else
    {
        novo->proximo = lista->inicio;
        lista->inicio->anterior = novo;
        lista->inicio = novo;
        // Lista Circula
        novo->anterior = lista->final;
        lista->final->proximo = novo;
        printf("\n Sucesso! \n");
    }
    lista->tam++;
}

void imprimir(cLista *lista)
{
    if(isVazia(lista))
    {
        printf("\n\tA Lista está Vazia! \n");
    }
    else
    {
        No *novo = lista->inicio;
        printf("\n\t*** REGISTROS ***\n");
        do
        {
            printf("\n\n\t- Registro do Aluno -\t\n");
            printf("\nChave: %2d",novo->cadastro.chave);
            printf("\nNome: %s",novo->cadastro.nome);
            printf("\nIdade: %2d",novo->cadastro.idade);
            printf("\nMatricula: %s",novo->cadastro.matricula);
            printf("\nCurso: %2d",novo->cadastro.curso);
            printf("\nPeriodo: %2d",novo->cadastro.periodo);          
            novo = novo->proximo;
        }
        while(novo != lista->inicio);
    }
    printf("\n\nNumero de Registros: %lu\n\n",lista->tam);
}

int removeLista(cLista *lista, int ch)
{
    if(isVazia(lista))
    {
        printf("\n\tA Lista está Vazia! \n");
    }
    else
    {
        No *aux, *prox;

        if(lista->inicio)
        {
            aux = lista->inicio;
            prox = aux->proximo;
            while (prox != lista->inicio)
            {
                if(prox->cadastro.chave == ch)
                {
                    aux->proximo = prox->proximo;
                    free(prox);
                    lista->tam--;
                    printf("\n Sucesso! \n");
                    return True;
                }
                else
                {
                    aux = prox;
                    prox = prox->proximo;
                }
            }
            if(prox->cadastro.chave == ch)
            {
                if(aux == prox)
                {
                    lista->inicio = NULL;
                }
                else
                {
                    aux->proximo = prox->proximo;
                    lista->inicio = prox->proximo;
                }
                free(prox);
                lista->tam--;
                printf("\n Sucesso! \n");
                return True;
            }                
        }
    }
    printf("\nRegistro não Encontrado! \n");
    return False;
}

void resetaLista(cLista *lista)
{
    if(isVazia(lista))
    {
        printf("\n\tA Lista está Vazia! \n");
    }
    else
    {
        No *novo = lista->inicio;
        do
        {
            novo->cadastro.chave = -1;
            novo->cadastro.nome = NULL;
            novo->cadastro.idade = -1;
            novo->cadastro.matricula = NULL;
            novo->cadastro.curso = -1;
            novo->cadastro.periodo = -1;
        }
        while(novo != lista->inicio);
        novo->anterior = NULL;
        novo->proximo = NULL;
        lista->tam = 0;
    }
    printf("\nSucesso Registros Deletados! ");
    printf("\nNumero de Registros: %lu\n\n",lista->tam);
    
}

int main()
{
    int opc, ch;
    Reg r1, r2, r3, r4, r5;
    cLista *lista = initLista();

    do
    {
        printf("\n\n\t-----MENU-----");
        printf("\n\t 0 - SAIR ");
        printf("\n\t 1 - ADICIONAR");
        printf("\n\t 2 - IMPRIMIR");
        printf("\n\t 3 - REMOVER");
        printf("\n\t 4 - LIMPAR");
        printf("\n\n\tOpcao: ");

        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            printf("\n\n\tAdicionando Registros no Inicio da Lista \n");
            r1.chave = 01;
            r1.nome = "Erimilson Silva";
            r1.idade = 23;
            r1.matricula = "2022-AEB";
            r1.curso = 3;
            r1.periodo = 2;

            r2.chave = 02;
            r2.nome = "Lídia Silva";
            r2.idade = 21;
            r2.matricula = "2022-AEB";
            r2.curso = 2;
            r2.periodo = 4;

            r3.chave = 03;
            r3.nome = "Kelly Ferraz";
            r3.idade = 21;
            r3.matricula = "2022-AEB";
            r3.curso = 1;
            r3.periodo = 3;

            r4.chave = 04;
            r4.nome = "Milena Almeida";
            r4.idade = 25;
            r4.matricula = "2020-AEB";
            r4.curso = 4;
            r4.periodo = 6;

            r5.chave = 05;
            r5.nome = "Amanda Silva";
            r5.idade = 25;
            r5.matricula = "2020-AEB";
            r5.curso = 5;
            r5.periodo = 3;

            addLista(lista,r4); // Teste de Remover
            addLista(lista,r1); // Esse será o Primeiro
            addLista(lista,r5); 
            addLista(lista,r2); // Esse será o Último
            addLista(lista,r3); // Teste de Remover
            
            break;

        case 2:
            // Imprimir Registro
            imprimir(lista);
            break;
        
        case 3:
            // Remover Registro da Lista
            printf("\n\nRegistro a ser Removido da Lista - %s\n",r3.nome);    
            ch = 3;
            removeLista(lista,ch); 
            printf("\n\nRegistro a ser Removido da Lista - %s\n",r4.nome);    
            ch = 4;
            removeLista(lista,ch);
            break;

        case 4:
            // Reiniciar Lista
            resetaLista(lista);
            break;

        default:
            if(opc != 0)
            {
                printf("\n\t Opcao Invalida! \n");
            }
        }
    }
    while (opc != 0);

    return False;
}