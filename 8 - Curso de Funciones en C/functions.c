#include <stdio.h>

int potencia(int x,int y)
{   
    int z=1;
    for (int i = 0; i < y; i++)
    {
        z=z*x;
    }
    return z;
}

int main ()
{
    int x,y;
    printf("Ingrese el numero base:\n");
    scanf("%i",&x);
    printf("Ingrese el exponente:\n");
    scanf("%i",&y);
    int z=potencia(x,y);
    printf("%d^%d=%d\n",x,y,z);
    return 0;
}