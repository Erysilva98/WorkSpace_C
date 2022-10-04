#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetor[10] = {};

    for (int i = 0; i < 10; i++){
        
        vetor[i] = rand () % 100;
        printf("%d", vetor[i], "\n");
    }
}