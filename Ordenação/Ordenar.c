#include <stdio.h>
#include <stdlib.h>

void bublSort(int vetor[], int tam);

int main(void)
{
    int vetor[] = {8,46,20,1,87};

    int i, tam = 5;

    bublSort(vetor, tam);
    printf("\n");

    return 0;
}

void bublSort(int vetor[], int tam)
{
    int temp, troca;

    printf("Iniciando Função Bubble Sort \n");

    troca = 1;

    while(troca !=0)
    {
        troca = 0;
        for(int i=0; i<tam; i++)
        {
            if(vetor[i] > vetor[i+1])
            {
                troca =1;
                temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
            }
        }
        tam = tam -1;
    }

    printf("Lista Ordenada en Ordem Crescente : ");
    for(int i =0; i<=tam; i++)
    {
        printf("%d", vetor[i]);
    }
}