/*
   -- Struct de Registro em Árvore de Buscar Binária 
   -- Métodos:
        Inicializar(estrutura) para a estrutura ARVORE_BIN;
        Adiciona, remove  e  limpa. 
        Imprimir os valores de forma ordenada (busca em profundidade).
        Imprimir os valores na ARVORE_BIN por nível (busca em largura),
        Profundidade total da árvore.
    -- Autor: Erimilson Silva
    -- 20/12/2022
*/

#include <stdio.h>
#include <stdlib.h>
 
#define True 1
#define False 0
 
//Cursos
#define INFORMATICA 0
#define AGROINDUSTRIA 1
#define AGROPECUARIA 2
#define ENG_SOFTWARE 3
#define ENFERMAGEM 4
#define MUSICA 5
 
typedef int Tip_indentificador;
 
typedef struct // Registros de Aluno
{
    Tip_indentificador indentificador;
    char *nome;
    int idade;
    char *matricula;
    int curso;
    int periodo;
}Registro_Aluno;
 
typedef struct no   // Árvore Binária
{
    Registro_Aluno dados;
    struct no *direita, *esquerda;  
}Pai;
 
Pai *criarNo(Registro_Aluno dados)
{
    Pai *no = malloc (sizeof(Pai));
 
    no->dados.indentificador = dados.indentificador;
    no->dados.nome = dados.nome;
    no->dados.idade = dados.idade;
    no->dados.matricula = dados.matricula;
    no->dados.curso = dados.curso;
    no->dados.periodo = dados.periodo;
 
    no->esquerda = NULL;
    no->direita = NULL;
 
    return no;
}
 
Pai *adicionar(Pai *raiz, Registro_Aluno dados)
{
 
    if(raiz == NULL)
    {
        printf("\n  Sucesso");
        criarNo(dados);  
    }
    else
    {
        if(dados.indentificador < raiz->dados.indentificador)
        {
            raiz->esquerda = adicionar(raiz->esquerda,dados);
        }
        if(dados.indentificador > raiz->dados.indentificador)
        {
            raiz->direita = adicionar(raiz->direita,dados);
        }
        return raiz;
    }
}
 
int alturaArv(Pai *raiz)
{
    if(raiz == NULL)
    {
        return -1;
    }
    else
    {
        int esq = alturaArv(raiz->esquerda);
        int dir = alturaArv(raiz->direita);
 
        if(esq > dir)
        {
            return esq + 1;
        }
        else
        {
            return dir + 1;
        }
    }
}
 
void imprimirOrdenado(Pai *raiz)
{
    if(raiz != NULL)
    {
        imprimirOrdenado(raiz->esquerda);
        printf("--------------------------------------");
        printf("\n- Indentificador: %2d \n",raiz->dados.indentificador);
        printf("\n- Nome: %s \n",raiz->dados.nome);
        printf("\n- Idade: %2d \n",raiz->dados.idade);
        printf("\n- Matricula: %s \n",raiz->dados.matricula);
        printf("\n- Curso: %2d \n",raiz->dados.curso);
        printf("\n- Perido: %2d \n",raiz->dados.periodo);
        printf("---------------------------------------");
        imprimirOrdenado(raiz->direita);
    }
}
 
 
Pai *remover(Pai *raiz, int chave)
{
    if(raiz == NULL)
    {
        printf("\nVazia! ");
        return NULL;
    }
    else
    {
        if(raiz->dados.indentificador == chave)
        {
           
            if(raiz->esquerda == NULL && raiz->direita == NULL)
            {
                free(raiz);
                printf("\nRemovido: %d !\n",chave);
                return NULL;
            }
            else
            {
               
                Pai *aux;
                if(raiz->esquerda != NULL && raiz->direita != NULL)
                {
                    Pai *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                    {
                        aux = aux->direita;
                    }
                    raiz->dados.indentificador= aux->dados.indentificador;
                    aux->dados.indentificador = chave;
                    printf("\nTroca: %d !\n",chave);
                    raiz->esquerda = remover(raiz->esquerda,chave);
                    return raiz;
                }
                else
                {
                    Pai *aux;
                    if(raiz->esquerda != NULL)
                    {
                        aux = raiz->esquerda;
                    }
                    else
                    {
                        aux = raiz->direita;
                    }
                    free(raiz);
                    printf("\nRemovido: %d !\n",chave);
                    return aux;
                }
            }
        }
        else
        {
            if(chave < raiz->dados.indentificador)
            {
                raiz->esquerda = remover(raiz->esquerda,chave);
            }
            else
            {
                raiz->direita = remover(raiz->direita,chave);
            }
            return raiz;
        }
    }
}
 
int main()
{
    int ch;
    Registro_Aluno r1, r2, r3, r4;
    Pai *raiz = NULL;
 
    
    printf("\n\n\t------------- Adicionado Registros ------------- \n");
    r1.indentificador = 10;
    r1.nome = "Erimilson";
    r1.idade = 23;
    r1.matricula = "AEB-2022";
    r1.periodo = 2;
    r1.curso = ENG_SOFTWARE;               
 
    r2.indentificador = 7;
    r2.nome = "Ana";
    r2.idade = 22;
    r2.matricula = "AEB-2022";
    r2.periodo = 2;
    r2.curso = INFORMATICA;
 
    r3.indentificador = 15;
    r3.nome = "Elo";
    r3.idade = 22;
    r3.matricula = "AEB-2022";
    r3.periodo = 2;
    r3.curso = AGROPECUARIA;
    r3.indentificador = 1;
 
    r4.indentificador = 20;
    r4.nome = "Mary";
    r4.idade = 22;
    r4.matricula = "AEB-2022";
    r4.periodo = 2;
    r4.curso = ENFERMAGEM;
 
    raiz = adicionar(raiz,r1);
    raiz = adicionar(raiz,r2);
    raiz = adicionar(raiz,r3);
    raiz = adicionar(raiz,r4);
    

    printf("\n\n\t------------- Removendo Registro ------------- \n");
    printf("\n\tDigite a Chave do Registro a ser Removida: ");
    scanf("%2d",&ch);
 
    raiz = remover(raiz,ch);

    printf("\n\n\t------------- Registros ------------- \n");
    imprimirOrdenado(raiz);


    printf("\n\t- Profundidade Total da Arvore - %2d \n",alturaArv(raiz));
 
    return 0;
}
 
