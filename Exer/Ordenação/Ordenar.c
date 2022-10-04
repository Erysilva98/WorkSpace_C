#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // para clock()

int bubbleSort(int vetor[], int tam)
{
    clock_t tempo;
    int i, j, temp, troca;

    printf("Iniciando Função Bubble Sort. \n");

    tempo = clock(); // Tempo Inicial

    for (i = 0; i < tam - 1; i++) 
    {
        for (j = 0; j < tam - i - 1; j++) 
        {
            if (vetor[j] > vetor[j + 1]) 
            {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    tempo = clock() - tempo; // Tempo Final

    printf("Vetor Ordenado com Bubble sort: \n");
    for (i = 0; i < tam; i++) 
    {
        printf("%d  ", vetor[i]);
    }
    printf("\n  Tempo de Execução: %lf ",((double)tempo)/((CLOCKS_PER_SEC/1000)));
    printf("\n");
    return 0;

}

int insertionSort(int vetor[], int tam)
{
    clock_t tempo;
    int i, j, troca;

    tempo = clock(); // Tempo Inicial

    printf("\nIniciando Função Bubble Sort. \n");

    for(i =1; i < tam; i++){
        troca = vetor[i];
        j = i -1;

        while ( j>=0 && vetor[j] > troca )
        {
            vetor[j+1] = vetor[j];
            // Elemento da lista Ordenado
            j = j -1;
        }
        vetor[j+1] = troca;
    }

    tempo = clock() - tempo; // Tempo Final

    printf("Vetor Ordenado com Insert Sort: \n");
    for (i = 0; i < tam; i++) 
    {
        printf("%d  ", vetor[i]);
    }
    printf("\n  Tempo de Execução: %lf ",((double)tempo)/((CLOCKS_PER_SEC/1000)));
    printf("\n");
    return 0;
}

int selectionSort(int *vetor, int tam)
{
    clock_t tempo;
    int i, j, ultimo, temp;

    printf("\nIniciando Função Selection Sort. \n");

    tempo = clock(); // Tempo Inicial

    for(i=0; i<(tam-1); i++)
    {
        ultimo = i;

        for(j= (i+1); j < tam; j++)
        {
            if(vetor[j] < vetor[ultimo])
            ultimo = j;
        }
        if (vetor[i] != vetor[ultimo] )
        {
            temp = vetor[i];
            vetor[i] = vetor[ultimo];
            vetor[ultimo] = temp;
        }
    }

    tempo = clock() - tempo; // Tempo Final

    printf("Vetor Ordenado com Selection Sort: \n");
    for (i = 0; i < tam; i++) 
    {
        printf("%d  ", vetor[i]);
    }
    printf("\n  Tempo de Execução: %lf ",((double)tempo)/((CLOCKS_PER_SEC/1000)));
    printf("\n");
    return 0;
}

int main()
{
    int vetor[] = {8,6,2,1,7,9,5,3,10,4,23,99,45,67,21,76,57,71,49,20};

    int i, tam = 20;

    printf("Vetor á ser Ordenado: \n");
    for (i = 0; i < tam; i++) 
    {
        printf("%d  ", vetor[i]);
    }
    printf("\n \n");

    bubbleSort(vetor, tam);
    insertionSort(vetor, tam);
    selectionSort(vetor, tam);

    return 0;
}