#include <stdio.h>

int power(int b, int e);

int main() 
{
    int base, exponente;
    base = 3;
    exponente = 4;
    
    printf("exponente = %d resultado de la potencia = %d\n", exponente, power(base,exponente));
    

    return 0;
}

int power(int b, int e)
{
    int p;
    for (p = 1; e > 0; e--)
    {
        p = p * b;
        printf("el valor temporal del exponente es %d\n", e);
    }

    return p;
}