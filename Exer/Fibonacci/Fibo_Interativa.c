#include <stdio.h>
#include <stdlib.h>

int fibonacciI(int n){
    
    int t1 = 0, t2 = 1, proxTermo, i =2;

    if (n==1)
        return t1;
    else
    {
        if(n==2)
            return t2;
        else
        {
            while ( i < n)
            {
                proxTermo = t1 + t2;
                t1 = t2;
                t2 = proxTermo;
                i++;
            }
            return proxTermo;
        }
            
    }

    return 0;
}

int main(){

    int n;

    printf("\n Quantos Termos deseja somar: ");
    scanf("%d", &n);
    printf("\n A Sequẽncia Fibonacci Interativa %d é: %d\n", n, fibonacciI(n));
    printf("\n");
    
    return 0;

}