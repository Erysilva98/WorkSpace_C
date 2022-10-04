#include <stdio.h>

int main(){
    int i, n, t1 = 0, t2 = 1, proxTermo;

    printf("Informe a Quantidade de Termo: ");
    scanf("%i", &n);

    printf("\n Sequência de Fibonacci ");

    for (i =0; i <= n; i ++){
        
        printf("%i ", t1);
        proxTermo = t1 + t2;    // Soma dos primeiros termos = 1
        t1 = t2;                // t1 recebe o valor de t2 = 1
        t2 = proxTermo;         // t2 recebe a soma dos termos anterior = 1 
    }

    printf("\n");

}