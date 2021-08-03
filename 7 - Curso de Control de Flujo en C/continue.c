#include <stdio.h>

int n = 30;

int main()
{
    for (int i = 0; i < n+1; i++)
    {
        if (i==5 || i==7)
        {
            continue;
        }
        printf("El valor de n es %d\n",i);
    }
    return 0;
}