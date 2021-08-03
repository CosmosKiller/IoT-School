#include "stdlib.h"
#include "stdio.h"
#include "string.h"

struct client
{
    char Name[50];
    char Id[10];
    float Credit;
    char Address[100];
};

int main(int argc, char const *argv[])
{
    struct client client1 = {0};
    strcpy(client1.Name,"Joselito Suarez");
    strcpy(client1.Id,"000000001");
    client1.Credit = 1000000;
    strcpy(client1.Address,"Calle 45 n° 811");

    printf("El nombre del cliente es : %s \n", client1.Name);
    printf("El ID del cliente es : %s \n", client1.Id);
    printf("El credito del cliente es : %f \n", client1.Credit);
    printf("La dirección del cliente es : %s \n", client1.Address);

    return 0;
}
