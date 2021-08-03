#include "stdio.h"

int fact = 0;

void factorial(int n)
{
    int p = 1;
    while (n != 0)
    {
        p = n * p;
        n = n-1;
    }

    fact = p;
}

int main(int argc, char const *argv[])
{
    factorial(5);
    printf("El factorial es: %d \n",fact);
    return 0;
}