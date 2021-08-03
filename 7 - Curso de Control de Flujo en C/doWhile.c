#include <stdio.h>

int n;

int main ()
{
    printf("Ingrese un numero para comprobar:\n");
    scanf("%i",&n);
    do
    {
        printf("n es igual a %d\n",n);
        n = n-1;
    } while (n > 10);
    printf("Hemos salido del bucle porque n es menor o igual a 10\n");
    return 0;
}