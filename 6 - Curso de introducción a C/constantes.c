#include <stdio.h>

#define PIZZACOST 1.5
const char NEWLINE = '\n';

int main ()
{
    float costoPizza;
    int numbreOfSlices = 3;

    costoPizza= PIZZACOST * numbreOfSlices;

    printf("El precio total es de: %C %.1f",NEWLINE, costoPizza);
    return 0;

}
