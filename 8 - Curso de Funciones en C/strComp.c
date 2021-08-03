#include <stdio.h>
#include <string.h>

char string1[8];
char string2[8] = "Peru1843";

int main()
{
    

    printf("Ingrese su contraseña:\n");
    fgets(string1, 9,stdin);
    
    if (strcmp(string1, string2) == 0)
        printf("La contrseña ingresada es correcta\n");
    else
    {
        printf("La contraseña ingresada es incorrecta\n");
    }    
    
    
    return 0;
}