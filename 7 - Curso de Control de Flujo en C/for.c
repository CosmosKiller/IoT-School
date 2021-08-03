#include <stdio.h>

int n;
int fact=1;

int main()
{
    printf("Ingrese un numero para calcular su factorial:\n");
    scanf("%i",&n);
    for (int i = 1; i < n+1; i++)
    {
        fact = i*fact;
    }
    printf("El factorial de %d es igual a %d\n",n,fact);
    return 0;    
}