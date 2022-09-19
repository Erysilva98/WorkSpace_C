#include <stdio.h>
#include <stdlib.h>

void mergeSort(int vetor[], int tam);
void mergeSortRecursivo( int vetor[], int inicio, int final);
void ordenarVetor(int vetor[], int inicio, int meio, int final);

int main()
{
    int vetor[] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};

    int i, tam = 10;

    printf("\n Vetor Ordenado com Merge Sort \n");

    mergeSort(vetor, tam);

    for( i=0; i < tam; i++)
    {
        printf("%d ", vetor[i]);

    }
    printf("\n");

    return 0;

}

void mergeSort(int vetor[], int tam)
{
    mergeSortRecursivo(vetor, 0, tam - 1);
}

void mergeSortRecursivo( int vetor[], int inicio, int final)
{
    if ( inicio < final)
    {
        int meio = inicio + (final - inicio ) / 2;

        mergeSortRecursivo(vetor, inicio, meio);
        mergeSortRecursivo(vetor, meio + 1, final);

        ordenarVetor(vetor, inicio, meio, final);
    }
}

void ordenarVetor(int vetor[], int inicio, int meio, int final)
{
    // Tamanho dos Vetor

    int tamInicio = meio - inicio + 1;
    int tamFinal = final - meio;

    // Variáveis Temporárias

    int temp_inicio[tamInicio];
    int temp_final[tamFinal];

    // Variáveis do FOR

    int i, j, k;

    for (i = 0; i < tamInicio; i++)
    {
        temp_inicio[i] = vetor[inicio + i];
    }

    for (i = 0; i < tamFinal; i++)
    {
        temp_final[i] = vetor[meio + 1 + i];
    }

    for (i =0, j= 0, k= inicio; k <= final; k++)
    {
        if (( i < tamInicio) && (j >= tamFinal) || temp_inicio[i] <= temp_final[j])
        {
            vetor[k] = temp_inicio[i];
            i++;
        }
        else
        {
            vetor[k] = temp_final[j];
            j++;
        }
    }
}

