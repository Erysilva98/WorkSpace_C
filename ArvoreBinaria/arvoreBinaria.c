/*
   -- Struct de Registro em Árvore de Buscar Binária 
   -- Métodos:
        Adiciona, remove  e  limpa. 
        Imprimir os Registros de Alunos.
        Imprimir os valores de forma ordenada (busca em profundidade).
        Imprimir os valores na ARVORE_BIN por nível (busca em largura).
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
 
typedef struct no   // Nó
{
    Registro_Aluno dados;
    struct no *direita, *esquerda; 
    int qtdElementos;
}ArvB; // Árvore Binária
 
ArvB *criarNo(Registro_Aluno dados)
{
    ArvB *no = malloc (sizeof(ArvB));
 
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


ArvB *adicionar(ArvB *raiz, Registro_Aluno dados)
{
    if (raiz == NULL)
    {
        printf("\n Sucesso! ");
        criarNo(dados);
    }
    else
    {
        if (dados.indentificador < raiz->dados.indentificador)
        {
            raiz->esquerda = adicionar(raiz->esquerda,dados);
        }
        if (dados.indentificador > raiz->dados.indentificador)
        {
            raiz->direita = adicionar(raiz->direita,dados);
        }
        return raiz;
    }
    return NULL;
}

ArvB* remover(ArvB *raiz, int ch) {
    if(raiz == NULL)
    {
        printf("\n\n\tChave Invalida!");
        return NULL;
    } 
    else 
    { 
        if(raiz->dados.indentificador == ch) 
        {
            // Remove Nó sem Filhos
            if(raiz->esquerda == NULL && raiz->direita == NULL) 
            {
                free(raiz);
                printf("\nRegistro removido: %d !",ch);
                return NULL;
            }
            // Quando houver filhos
            else
            {
                // Nó com 2 filhos
                if(raiz->esquerda != NULL && raiz->direita != NULL)
                {
                    ArvB *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                    {
                        aux = aux->direita;
                    }
                    raiz->dados.indentificador = aux->dados.indentificador;
                    aux->dados.indentificador = ch;
                    printf("\nRegistro Alterado: %d !", ch);
                    raiz->esquerda = remover(raiz->esquerda, ch);
                    return raiz;
                }
                else
                {
                    // Nó com apenas 1 Filho
                    ArvB *aux;
                    if(raiz->esquerda != NULL)
                    {
                        aux = raiz->esquerda;
                    }
                        
                    else
                    {
                        aux = raiz->direita;
                    }
                    free(raiz);
                    printf("\nRegistro com 1 filho removido: %d !", ch);
                    return aux;
                }
            }
        } 
        else 
        {
            if(ch < raiz->dados.indentificador)
            {
                raiz->esquerda = remover(raiz->esquerda, ch);
            }
            else
            {
                raiz->direita = remover(raiz->direita, ch);
            }
            return raiz;
        }
    }
}

void imprimirEmProfundidade(ArvB *raiz)
{
    if (raiz)
    {
        // Impressão de Forma Ordenada
        imprimirEmProfundidade(raiz->esquerda);
        printf("%2d - ",raiz->dados.indentificador);
        imprimirEmProfundidade(raiz->direita);
    }
}

void imprimirEmLargura(ArvB *raiz, int posicao)
{
    if (raiz)
    {
        imprimirEmLargura(raiz->esquerda, posicao + 1);
        printf("\nPosicao (%d) = %2d ",posicao,raiz->dados.indentificador);
        imprimirEmLargura(raiz->direita, posicao + 1);
    }
}

// Impressão para Testes
void testArvB(ArvB *raiz)
{
    if(raiz)
    {
        testArvB(raiz->esquerda);
        printf("%2d|",raiz->dados.indentificador);
        testArvB(raiz->direita);
    }
}

int tamanhoArvB(ArvB *raiz)
{
    if(raiz == NULL)
    {
        return 0;
    }
    {
        return 1 + tamanhoArvB(raiz->esquerda) + tamanhoArvB(raiz->direita);
    }
}

void *limpa(ArvB *raiz)
{
    if(raiz != NULL)
    {
        limpa(raiz->esquerda);
        limpa(raiz->direita);
        raiz = NULL;
        free(raiz);   
    }  
    return raiz;
}

void imprimir(ArvB *raiz)
{
    if (raiz)
    {
        imprimir(raiz->esquerda);
        printf("\n\n\t- Registro do Aluno - %2d\t\n", raiz->dados.indentificador);
        printf("\n Nome: %s", raiz->dados.nome);
        printf("\n Idade: %2d", raiz->dados.idade);
        printf("\n Matricula: %s", raiz->dados.matricula);
        printf("\n Curso: %2d", raiz->dados.curso);
        printf("\n Periodo: %2d", raiz->dados.periodo);
        imprimir(raiz->direita);
    }
}
 
int main()
{
    int ch; // Chave para o método remover 
    Registro_Aluno r1, r2, r3, r4, r5, r6, r7, r8, r9;
    ArvB *raiz = NULL;

    printf("\n\n\t------------- Adicionado Registros ------------- \n");
    r1.indentificador = 20; // Raiz
    r1.nome = "Erimilson";
    r1.idade = 23;
    r1.matricula = "AEB-2022";
    r1.periodo = 2;
    r1.curso = ENG_SOFTWARE;          
 
    r2.indentificador = 07;
    r2.nome = "Ana";
    r2.idade = 22;
    r2.matricula = "AEB-2022";
    r2.periodo = 2;
    r2.curso = INFORMATICA;
 
    r3.indentificador = 10;
    r3.nome = "Teste de Remover 2";
    r3.idade = 22;
    r3.matricula = "AEB-2022";
    r3.periodo = 2;
    r3.curso = AGROPECUARIA;
 
    r4.indentificador = 01;
    r4.nome = "Mary";
    r4.idade = 22;
    r4.matricula = "AEB-2022";
    r4.periodo = 2;
    r4.curso = ENFERMAGEM;

    r5.indentificador = 70;
    r5.nome = "Leticia";
    r5.idade = 01;
    r5.matricula = "AEB-2022";
    r5.periodo = 2;
    r5.curso = AGROPECUARIA;

    r6.indentificador = 35;
    r6.nome = "Teste de Remover 1";
    r6.idade = 01;
    r6.matricula = "AEB-2022";
    r6.periodo = 2;
    r6.curso = ENFERMAGEM;

    r7.indentificador = 25;
    r7.nome = "Mary";
    r7.idade = 01;
    r7.matricula = "AEB-2022";
    r7.periodo = 2;
    r7.curso = INFORMATICA;

    r8.indentificador = 05;
    r8.nome = "Melissa";
    r8.idade = 01;
    r8.matricula = "AEB-2022";
    r8.periodo = 2;
    r8.curso = ENFERMAGEM;

    r9.indentificador = 55;
    r9.nome = "Juliana";
    r9.idade = 01;
    r9.matricula = "AEB-2022";
    r9.periodo = 2;
    r9.curso = ENFERMAGEM;
 
    raiz = adicionar(raiz,r1);
    raiz = adicionar(raiz,r2);
    raiz = adicionar(raiz,r3); // Teste de Remover 2
    raiz = adicionar(raiz,r4);
    raiz = adicionar(raiz,r5); 
    raiz = adicionar(raiz,r6);  // Teste de Remover 1
    raiz = adicionar(raiz,r7); 
    raiz = adicionar(raiz,r8); 
    raiz = adicionar(raiz,r9); 
    testArvB(raiz);

    printf("\n\n\t------------- Registros ------------- \n");
    imprimir(raiz);

    printf("\n\n\t------------- Removendo Registro ------------- \n");
    printf("\n\tRegistro a ser Removida: %s \n",r6.nome);
    ch = 10;
    remover(raiz,ch);
    printf("\n");
    testArvB(raiz);

    printf("\n\n\tRegistro a ser Removida: %s \n",r3.nome);
    ch = 35;
    remover(raiz,ch);
    printf("\n");
    testArvB(raiz);

    printf("\n\n\t------------- Impressao por Buscar em Profundidadde ------------- \n");
    // Impressão apenas das Chaves, mas podem ser impresso todo o registro
    imprimirEmProfundidade(raiz);

    printf("\n\n\t------------- Impressao por Buscar em Largura ------------- \n");
    //Impressão apenas das Chaves e suas posições, mas podem ser impresso os registro
    imprimirEmLargura(raiz,0);

    raiz->qtdElementos = tamanhoArvB(raiz);
    printf("\n\n\t------------- A profundidade total da árvore ------------- \n");
    printf("\n- Profundidade Total da Arvore  é %2d \n",raiz->qtdElementos);

    printf("\n\t------------- Removendo todos os Registros -------------\n");
    raiz = limpa(raiz);
    
    if (raiz == NULL)
    {
        printf("\nRegistros Removidos! \n");
    }
    
    return 0;
}
 
