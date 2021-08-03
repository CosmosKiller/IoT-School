#include <stdio.h>
#include <stdlib.h>

int binaryNumber[12],n,i;

int main()
{
    system("clear");
    printf("Se convertirá un numero aleatoria a decimal:\n");
    n = rand();
    printf("%d\n",n);

    i=0;
    while (n > 0)
    {
        binaryNumber[i] = n%2;
        n = n/2;
        i++;
    }
    
    printf("El valor en binario es: \n");
    for (i = i-1; i >= 0; i--)
    {
        printf("%d",binaryNumber[i]);
    }
    printf("\n");
    return 0;
}