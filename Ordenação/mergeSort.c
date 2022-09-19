#include <stdio.h>
#include <stdlib.h>

void Intercala(int vetor[], int inicio, int meio, int final);
void mergeSort(int vetor[], int inicio, int final);
void printArray(int vetor[], int tam);

int main()
{
    int vetor[] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};

    int i, pos = 0, tam = 10;

    printf("\n Vetor a ser Ordenado\n");
    printArray(vetor, tam);

    mergeSort(vetor, pos, tam);

    printf("\n Vetor Ordenado com Merge Sort \n");
    printArray(vetor, tam);

    printf("\n");

   return 0;
}

void Intercala(int vetor[], int inicio, int meio, int final)
{
    int i, j, k, *w;

    w = malloc ( (final-inicio) * sizeof (int) );

    i = inicio; j= meio; k = 0;

    while (i < meio && j < final)
    {
        if ( vetor[i] <= vetor[j])
        {
            w[k++] = vetor[i++];
        }
        else
        {
            w[k++] = vetor[j++];
        }
    }
    while (i < meio)
    {
        w[k++] = vetor[i++];
    }
    while (j < final)
    {
        w[k++] = vetor[j++];
    }

    for ( i=inicio; i < final; i++)
    {
        vetor[i] = w[i-inicio];
    }
    free (w);
}

void mergeSort(int vetor[], int inicio, int final)
{
    if (inicio < final -1 )
    {
        int meio = (inicio + final) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio, final);
        Intercala(vetor, inicio, meio, final);
    }
}

void printArray(int vetor[], int tam)
{
    int i;

    for( i=0; i < tam; i++)
    {
        printf(" %d", vetor[i]);

    }
    printf("\n");
}