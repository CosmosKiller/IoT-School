#include <stdio.h>
#include <string.h>

int main()
{
    char string1[60];
    printf("Escribe una frase: \n");
    fgets(string1, 60, stdin);

    printf("El string al reves es: %d\n", strlen(string1));
    return 0;
}