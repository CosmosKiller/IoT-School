#include <stdio.h>
#include <math.h>

int x;
float result;

int main()
{
    printf("Ingrese el valor de x: ");
    scanf("%d",&x);
    result = cos(x);
    printf("El valor del cosenos de x es: %f\n",result);
    return 0;
}
