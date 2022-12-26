/*
    -- Implementação de Árvore de Buscar Binária
    -- Métodos:
        Método de Inserção,
        Método de Buscar,
        Método de Remover,
        Altura da Árvore,
        Número de NOs,
        Número de Folhas,
        Impressão Ordenada.
    -- 14/12/2022
*/
#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef int Tip_Chave;

typedef struct // Registros 
{
    Tip_Chave chave;
    char *nome;
    int idade;
    char *matricula;
    int curso;
    int periodo;
}Reg;

typedef struct no  // Árvore Binária
{
    Reg cadastro;
    struct no *direita, *esquerda;    
}No;

No *criarNo(Reg cad)
{
    No *no = malloc (sizeof(No));

    no->cadastro.chave = cad.chave;
    no->cadastro.nome = cad.nome;
    no->cadastro.idade = cad.idade;
    no->cadastro.matricula = cad.matricula;
    no->cadastro.curso = cad.curso;
    no->cadastro.periodo = cad.periodo;

    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

No *inserir(No *raiz, Reg cad)
{
    if(raiz == NULL)
    {
        printf("\n  Sucesso");
        criarNo(cad);   
    }
    else
    {
        if(cad.chave < raiz->cadastro.chave)
        {
            raiz->esquerda = inserir(raiz->esquerda, cad);
        }
        if(cad.chave > raiz->cadastro.chave)
        {
            raiz->direita = inserir(raiz->direita, cad);
        }
        return raiz;
    }
}

No *buscar(No *raiz, Reg cad)
{
    if(raiz)
    {
        if(cad.chave == raiz->cadastro.chave)
        {
            return raiz;
        }
        else if (cad.chave < raiz->cadastro.chave)
        {
            return buscar(raiz->esquerda, cad);
        }
        else
        {
            return buscar(raiz->direita,cad);
        }
        return NULL;        
    }
}

No *remover(No *raiz, Reg cad)
{
    if(raiz == NULL)
    {
        printf("\nRegistro não Encontrado! ");
        return NULL;
    }
    // Procurar NO
    else 
    {
        if(raiz->cadastro.chave == cad.chave)
        {
            //Remove nós folhas (nós sem filhos
            if(raiz->esquerda == NULL && raiz->direita == NULL)
            {
                free(raiz);
                printf("\nElemento Folha Removido: %d !\n",cad.chave);
                return NULL;
            }
            else
            {
                // Remover Nós que possuem 2 filhos
                No *aux;
                if(raiz->esquerda != NULL && raiz->direita != NULL)
                {
                    // Subárvore á esquerda
                    No *aux = raiz->esquerda; 
                    while(aux->direita != NULL)
                    {
                        // Obtém o nó a direita
                        aux = aux->direita; 
                    }
                    raiz->cadastro.chave = aux->cadastro.chave;
                    aux->cadastro.chave = cad.chave;
                    printf("\nElemento trocado: %d !\n",cad.chave);
                    raiz->esquerda = remover(raiz->esquerda,cad);
                    return raiz;
                }
                else
                {
                    No *aux;
                    if(raiz->esquerda != NULL)
                    {
                        aux = raiz->esquerda;
                    }
                    else
                    {
                        aux = raiz->direita;
                    }
                    free(raiz);
                    printf("\nElemento com 1 Filho removido: %d !\n",cad.chave);
                    return aux;
                }
            }
        }
        else
        {
            if(cad.chave < raiz->cadastro.chave)
            {
                raiz->esquerda = remover(raiz->esquerda,cad);
            }
            else
            {
                raiz->direita = remover(raiz->direita,cad);
            }
            return raiz;
        }
    }
}

int alturaArv(No *raiz)
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

int numNos(No *raiz)
{
    if(raiz == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + numNos(raiz->esquerda) + numNos(raiz->direita);
    }
}

int numFolhas(No *raiz)
{
    if(raiz == NULL)
    {
        return 0;
    }
    else if (raiz->esquerda == NULL && raiz->direita == NULL)
    {
        return 1;
    }
    else
    {
        return numFolhas(raiz->esquerda) + numFolhas(raiz->direita);
    }
}

void imprimir(No *raiz)
{
    if(raiz)
    {
        imprimir(raiz->esquerda);
        printf("\n\n\t- Registro do Aluno - %2d\t\n",raiz->cadastro.chave);
        printf("\nNome: %s",raiz->cadastro.nome);
        printf("\nIdade: %2d",raiz->cadastro.idade);
        printf("\nMatricula: %s",raiz->cadastro.matricula);
        printf("\nCurso: %2d",raiz->cadastro.curso);
        printf("\nPeriodo: %2d",raiz->cadastro.periodo);  
        imprimir(raiz->direita);
    }
}

int main()
{
    int i, opc;
    Reg ch, r1, r2, r3, r4, r5, r6, r7;
    No *pesquisar, *arv = NULL;

    do
    {
        printf("\n\n\t-----MENU-----");
        printf("\n\t 0 - SAIR ");
        printf("\n\t 1 - ADICIONAR");
        printf("\n\t 2 - IMPRIMIR");
        printf("\n\t 3 - PESQUISAR");
        printf("\n\t 4 - ALTURA");
        printf("\n\t 5 - N° NOs");
        printf("\n\t 6 - N° FOLHAS");
        printf("\n\t 7 - REMOVER");
        printf("\n\n\tOpcao: ");

        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            printf("\n\n\t------------- Adicionado Registros na Lista ------------- \n");

            r1.chave = 50;
            r1.nome = "Erimilson Silva";
            r1.idade = 23;
            r1.matricula = "2022-AEB";
            r1.curso = 3;
            r1.periodo = 2;

            r2.chave = 20;
            r2.nome = "Lídia Silva";
            r2.idade = 21;
            r2.matricula = "2022-AEB";
            r2.curso = 2;
            r2.periodo = 4;

            r3.chave = 21;
            r3.nome = "Kelly Ferraz";
            r3.idade = 21;
            r3.matricula = "2022-AEB";
            r3.curso = 1;
            r3.periodo = 3;
            
            r4.chave = 18;
            r4.nome = "Milena Almeida";
            r4.idade = 25;
            r4.matricula = "2020-AEB";
            r4.curso = 4;
            r4.periodo = 6;
            
            r5.chave = 23;
            r5.nome = "Amanda Silva";
            r5.idade = 25;
            r5.matricula = "2020-AEB";
            r5.curso = 5;
            r5.periodo = 3;

            r6.chave = 12;
            r6.nome = "Nathalia Souza";
            r6.idade = 20;
            r6.matricula = "2020-AEB";
            r6.curso = 3;
            r6.periodo = 3;

            r7.chave = 07;
            r7.nome = "Amanda Silva";
            r7.idade = 18;
            r7.matricula = "2020-AEB";
            r7.curso = 2;
            r7.periodo = 2;

            arv = inserir(arv,r1);
            arv = inserir(arv,r2);
            arv = inserir(arv,r3);
            arv = inserir(arv,r4);
            arv = inserir(arv,r5);
            arv = inserir(arv,r6);
            arv = inserir(arv,r7);
                        
            break;

        case 2:
            printf("\n\n\t------------- Registros da Lista ------------- \n");
            imprimir(arv);
            break;
        
        case 3:
            // Buscando código de Regsitros 
            printf("\n\n\t------------- Pesquisar por Registros na Lista ------------- \n");
            printf("\n\tDigite o Chave do Registro: ");
            scanf("%d",&ch);

            pesquisar = buscar(arv,ch);

            if(pesquisar)
            {
                printf("\n\t Resgitro Encontrado: %d",pesquisar->cadastro.chave);
                printf("\n------------- Informacoes do Registro ------------- \n");
                printf("\nNome: %s",pesquisar->cadastro.nome);
                printf("\nIdade: %2d",pesquisar->cadastro.idade);
                printf("\nMatricula: %s",pesquisar->cadastro.matricula);
                printf("\nCurso: %2d",pesquisar->cadastro.curso);
                printf("\nPeriodo: %2d",pesquisar->cadastro.periodo);  
            }
            else
            {
                printf("\n\n\t------------- Nenhum Registro Encontrado ------------- \n");
            }
            break;
        
        case 4:
            printf("\n\n\t------------- Altura ------------- \n");
            printf("\nAltura da Arvore: %d\n", alturaArv(arv));
            break;

        case 5:
            printf("\n\n\t------------- Nos ------------- \n");
            printf("\nNúmero de NOs: %d\n",numNos(arv));
            break;
        
        case 6:
            printf("\n\n\t------------- Folhas ------------- \n");
            printf("\n\tNúmero de Folhas: %d\n",numFolhas(arv));
            break;    

        case 7:
            printf("\n\n\t------------- Removendo Registros ------------- \n");
            scanf("%d",&ch);

            arv = remover(arv,ch);
            break;    

        default:
            if(opc != 0)
            {
                printf("\n\n\t------------- Opcao Invalida ------------- \n");
            }
        }
    }
    while (opc != 0);

    return False;
}