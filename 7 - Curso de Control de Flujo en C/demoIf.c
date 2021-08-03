#include <stdio.h>
int n = 5;

int main()
{
     if (n > 10 && n < 20)
     printf("El numero es mayor a 10 pero menor a 20\n");
     else if (n == 10)
     printf("El numero es 10\n");
     else if (n > 20)
     printf("El numero es mayor a 20\n");
     else
     printf("El numero es menor a 10\n");
     return 0;
}