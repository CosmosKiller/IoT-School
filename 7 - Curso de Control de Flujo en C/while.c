#include <stdio.h>

int n;
int j=1;
int fact=1;

int main()
{
    printf("Ingrese un numero para calcular su factorial:\n");
    scanf("%i",&n);
    
    while (j <= n)
    {
        fact = j*fact;
        j = j+1;
    }
    printf("El factorial de %d es igual a %d\n",n,fact);
    return 0;
}