/*
    -- Struct de Registro em Lista Circular Duplamente Encadeda
    --Métodos:
        Método de Adicionar,
        Impressão Ordenada,
        Método de Remover,
        Método de Buscar,        
        Resetar Lista.
    -- Autor: Erimilson Silva
    -- 15/12/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0

//Cursos
#define INFORMATICA 0
#define AGROINDUSTRIA 1
#define AGROPECUARIA 2
#define ENG_SOFTWARE 3
#define ENFERMAGEM 4
#define MUSICA 5

typedef int Tipo_indentificador;

typedef struct // Registro
{
    Tipo_indentificador chave;
    char *nome;
    char *matricula;
    int idade;
    int periodo;
    int curso;
}Reg;

typedef struct Fila_dia
{
    Reg alunos;
    int dia;
    int mes;
    int ano;
    int qtd_alunos;
    struct Fila_dia *proximo;
    struct Fila_dia *anterior;
}No;

typedef struct // Lista Encadeada
{
    No filas;
    size_t qtd_filas;
    No *inicio;
    No *final;
}Ifpe;

No *criarNo(Reg cad, No fila_d)
{
    No *no = malloc (sizeof(No));

    no->dia = fila_d.dia;
    no->mes = fila_d.mes;
    no->ano = fila_d.ano;

    no->alunos.chave = cad.chave;
    no->alunos.nome = cad.nome;
    no->alunos.idade = cad.idade;
    no->alunos.matricula = cad.matricula;
    no->alunos.curso = cad.curso;
    no->alunos.periodo = cad.periodo;

    no->proximo = no;
    no->anterior = no;

    return no;
}

Ifpe *iniciar()
{
    Ifpe *refeit = malloc(sizeof(Ifpe));

    refeit->inicio = NULL;
    refeit->final = NULL;
    refeit->qtd_filas = 0;

    return refeit;
}

int isVazia(Ifpe *refeit)
{
    return (refeit->qtd_filas == 0);
}

void addLista(Ifpe *refeit, Reg cad, No fila_d)
{
    No *novo = criarNo(cad,fila_d);
    novo->proximo = refeit->inicio;

    if(isVazia(refeit))
    {
        refeit->inicio = novo;
        refeit->final = novo;
        printf("\n Sucesso!");
    }
    else
    {
        novo->proximo = refeit->inicio;
        refeit->inicio->anterior = novo;
        refeit->inicio = novo;
        // Lista Circular
        novo->anterior = refeit->final;
        refeit->final->proximo = novo;
        printf("\n Sucesso!");
    }
    refeit->qtd_filas++;
}

void imprimir(Ifpe *refeit)
{
    if(isVazia(refeit))
    {
        printf("\n\tA Lista está Vazia! \n");
    }
    else
    {
        No *novo = refeit->inicio;
        printf("\n\t*** Registros ***\n");

        do
        {
            printf("\n - DATAS - %2d / %2d / %2d ",novo->dia,novo->mes,novo->ano);
            printf("\n- Registro do Aluno - %2d \t\n",novo->alunos.chave);
            printf("\nNome: %s",novo->alunos.nome);
            printf("\nIdade: %d",novo->alunos.idade);
            printf("\nMatricula: %s",novo->alunos.matricula);
            printf("\nCurso: %d",novo->alunos.curso);
            printf("\nPeriodo: %2d",novo->alunos.periodo);
            
            printf("\n-----------------------------------------------------");
            
            novo  = novo->proximo;
        } while (novo != refeit->inicio);
        
    }
    printf("\n\nNumero de Registros: %lu\n\n",refeit->qtd_filas);
}

int removelista(Ifpe *refeit, int ch)
{
    if(isVazia(refeit))
    {
        printf("\n\tA Lista está Vazia! \n");
    }
    else
    {
        No *aux, *prox;

        if(refeit->inicio)
        {
            aux = refeit->inicio;
            prox = aux->proximo;

            while (prox != refeit->inicio)
            {
                if(prox->alunos.chave == ch)
                {
                    aux->proximo = prox->proximo;
                    free(prox);
                    refeit->qtd_filas--;
                    printf("\n Sucesso! \n");
                    return True;
                }
                else
                {
                    aux = prox;
                    prox = prox->proximo;
                }
            }
            if(prox->alunos.chave == ch)
            {
                if(aux == prox)
                {
                    refeit->inicio == NULL;
                }
                else
                {
                    aux->proximo = prox->proximo;
                    refeit->inicio = prox->proximo;
                }
                free(prox);
                refeit->qtd_filas--;
                printf("\n Sucesso! \n");
                return True;
            }
        }
    }
    printf("\nRegistro não Encontrado! \n");
    return False;
}

No *buscar(Ifpe *refeit, Reg cad)
{
    No *aux = refeit->inicio;

    if(aux)
    {
        do
        {
            if (aux->alunos.chave == cad.chave)
            {
                return aux;
            }
            aux = aux->proximo;
            
        } while (aux != refeit->inicio);
    }
    return NULL;
}

void resetaLista(Ifpe *refeit)
{
    if(isVazia(refeit))
    {
        printf("\n\tA Lista está Vazia! \n");
    }
    else
    {
        No *novo = refeit->inicio;

        do
        {
            novo->alunos.chave = -1;
        } while (novo != refeit->inicio);
        novo->anterior = NULL;
        novo->proximo = NULL;
        refeit->qtd_filas = 0; 
    }
    printf("\nSucesso Registros Deletados! ");
    printf("\nNumero de Registros: %lu\n\n",refeit->qtd_filas);
}

int main()
{
    int opc, ch;
    Reg pesqCh, r1, r2, r3, r4, r5;
    No fila_d12, fila_d13, fila_d14, fila_d15, fila_d16;
    No *pesquisar;
    Ifpe *refeit = iniciar();

    do
    {
        printf("\n\n\t-----MENU-----");
        printf("\n\t 0 - SAIR ");
        printf("\n\t 1 - ADICIONAR");
        printf("\n\t 2 - IMPRIMIR");
        printf("\n\t 3 - REMOVER");
        printf("\n\t 4 - BUSCAR");
        printf("\n\t 5 - LIMPAR");
        printf("\n\n\tOpcao: ");

        scanf("%d",&opc);

        switch (opc)
        {
            case 1:
                printf("\n\n\t------------- Adicionado Registros ------------- \n");

                /* ---------------- */
                fila_d12.dia = 12;
                fila_d12.mes = 12;
                fila_d12.ano = 2022;

                r1.chave = 10;
                r1.nome = "Erimilson Silva";
                r1.idade = 23;
                r1.matricula = "2022-AEB";
                r1.curso = ENG_SOFTWARE;
                r1.periodo = 2;
                
                /* ---------------- */
                fila_d13.dia = 13;
                fila_d13.mes = 12;
                fila_d13.ano = 2022;

                r2.chave = 20; 
                r2.nome = "Lídia Silva";
                r2.idade = 21;
                r2.matricula = "2022-AEB";
                r2.curso = AGROINDUSTRIA;
                r2.periodo = 4;              
                
                /* ---------------- */
                fila_d14.dia = 14;
                fila_d14.mes = 12;
                fila_d14.ano = 2022;

                r3.chave = 30;
                r3.nome = "Kelly Ferraz";
                r3.idade = 21;
                r3.matricula = "2022-AEB";
                r3.curso = AGROPECUARIA;
                r3.periodo = 3;
                
                /* ---------------- */
                fila_d15.dia = 15;
                fila_d15.mes = 12;
                fila_d15.ano = 2022;

                r4.chave = 40;
                r4.nome = "Milena Almeida";
                r4.idade = 25;
                r4.matricula = "2020-AEB";
                r4.curso = ENFERMAGEM;
                r4.periodo = 6;

                /* ---------------- */
                fila_d16.dia = 16;
                fila_d16.mes = 12;
                fila_d16.ano = 2022;

                r5.chave = 50;
                r5.nome = "Amanda Silva";
                r5.idade = 25;
                r5.matricula = "2020-AEB";
                r5.curso = MUSICA;
                r5.periodo = 3;
                
                /* --------------- */
                addLista(refeit,r1,fila_d12);
                addLista(refeit,r2,fila_d13);
                addLista(refeit,r3,fila_d14);
                addLista(refeit,r4,fila_d15);
                addLista(refeit,r5,fila_d16);
                
                break;

            case 2:
                printf("\n\n\t------------- Registros ------------- \n");
                imprimir(refeit);

                break;
            
            case 3:
                printf("\n\n\t------------- Registros ------------- \n");
                imprimir(refeit);

                printf("\n\n\t------------- Removendo Registro ------------- \n");
                printf("\n\tDigite a Chave do Registro a ser Removida: ");
                scanf("%d",&ch);

                removelista(refeit,ch);

                break;

            case 4:
                // Buscando código de Regsitros 
                printf("\n\n\t------------- Pesquisar por Registros na Lista ------------- \n");
                printf("\n\tDigite o Chave do Registro: ");
                scanf("%d",&pesqCh);

                pesquisar = buscar(refeit,pesqCh);

                if(pesquisar)
                {
                    printf("\n\t Resgitro Encontrado: %d",pesquisar->alunos.chave);
                    printf("\n------------- Informacoes do Registro ------------- \n");
                    printf("\nNome: %s",pesquisar->alunos.nome);
                    printf("\nIdade: %2d",pesquisar->alunos.idade);
                    printf("\nMatricula: %s",pesquisar->alunos.matricula);
                    printf("\nCurso: %2d",pesquisar->alunos.curso);
                    printf("\nPeriodo: %2d",pesquisar->alunos.periodo);  
                }
                else
                {
                    printf("\n\nNenhum Registro Encontrado! \n");
                }

                break;

            case 5:
                printf("\n\n\t------------- Deletando Registros ------------- \n");
                resetaLista(refeit);
                break;

            default:
                if (opc != 0)
                {
                    printf("\n\n\t------------- Opcao Invalida ------------- \n");
                }  
        }
        
    } while (opc != 0);
    

    return False;
}