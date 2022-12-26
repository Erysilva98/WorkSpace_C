#include <stdio.h>
#include <stdlib.h>
 
int fibonacciR(int n)
{ 
   if (n ==1)
       return 0;
   else
   {
       if (n==2)
           return 1;
       else
          return fibonacciR(n-1) + fibonacciR(n-2);
   }
}
 
int main()
{
   int n;
 
   printf("\n Quantos Termos deseja somar: ");
   scanf("%d", &n);  
   printf("\n A Sequẽncia Fibonacci Recursiva %d é: %d\n", n, fibonacciR(n));
   printf("\n");
 
   return 0;
}
