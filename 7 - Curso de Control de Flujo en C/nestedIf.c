#include <stdio.h>

int opt1, opt2;


int main()
{
    printf("¡Bienvenido al centro de atencion al usuario!, ¿Como podemos ayudarle?\n");
    printf("1 - Problemas de Software\n");
    printf("2 - Problemas de Hardware\n");
    printf("3 - Problemas administrativos\n");
    printf("4 - Otros problemas\n");
    scanf("%i",&opt1);

    // Software
    if (opt1 == 1)
    {
        printf("Usted ha elegido la opción 1, por favor especifique su problema\n");
        printf("1 - Error en la lectura de datos\n");
        printf("2 - Error de conexión a un dispositivo\n");
        printf("3 - Error de ingreso al servidor\n");
        scanf("%i",&opt2);

        if (opt2 == 1)
        printf("Usted ha elegido la opción 1 'Error en la lectura de datos'\n");
        else if (opt2 == 2)
        printf("Usted ha elegido la opción 2 'Error de conexión a un dispositivo'\n");
        else if (opt2 == 3)
        printf("Usted ha elegido la opción 3 'Error de ingreso al servidor'\n");
        else
        printf("Usted ha elegido una opción incorrecta\n");
    }

    //Hardware
    else if (opt1 == 2)
    {
        printf("Usted ha elegido la opción 2, por favor especifique su problema\n");
        printf("1 - Dispositivo no enciende\n");
        printf("2 - Dispositivo se sobrecalienta\n");
        printf("3 - Se requiere cambio de sensor/actuador\n");
        scanf("%i",&opt2);

        if (opt2 == 1)
        printf("Usted ha elegido la opción 1 'Dispositivo no enciende'\n");
        else if (opt2 == 2)
        printf("Usted ha elegido la opción 2 'Dispositivo se sobrecalienta'\n");
        else if (opt2 == 3)
        printf("Usted ha elegido la opción 3 'Se requiere cambio de sensor/actuador'\n");
        else
        printf("Usted ha elegido una opción incorrecta\n");
    }

    //Administrativos
    else if (opt1 == 3)
    {
        printf("Usted ha elegido la opción 3, por favor especifique su problema\n");
        printf("1 - Problemas de facturación\n");
        printf("2 - Problemas de inicio de sesión\n");
        printf("3 - Solicitud de baja\n");
        scanf("%i",&opt2);

        if (opt2 == 1)
        printf("Usted ha elegido la opción 1 'Problemas de facturación'\n");
        else if (opt2 == 2)
        printf("Usted ha elegido la opción 2 'Problemas de inicio de sesión'\n");
        else if (opt2 == 3)
        printf("Usted ha elegido la opción 3 'Solicitud de baja'\n");
        else
        printf("Usted ha elegido una opción incorrecta\n");
    }

    //Otros
    else if (opt1 == 4)
    {
        printf("Usted ha elegido la opción 4, por favor especifique su problema\n");
        printf("1 - Comunicarse con un representante\n");
        printf("2 - Conocer la misión de la empresa\n");
        printf("3 - Consultar declaracion de privacidad y uso de datos\n");
        scanf("%i",&opt2);

        if (opt2 == 1)
        printf("Usted ha elegido la opción 1 'Comunicarse con un representante'\n");
        else if (opt2 == 2)
        printf("Usted ha elegido la opción 2 'Conocer la misión de la empresa\n");
        else if (opt2 == 3)
        printf("Usted ha elegido la opción 3 'Consultar declaracion de privacidad y uso de datos'\n");
        else
        printf("Usted ha elegido una opción incorrecta\n");
    }

    else
    printf("Usted ha elegido una opción incorrecta\n");

    return 0;
}