#include "stdio.h"

void cambiar(int *n1, int *n2)
{
    int aux = *n2;
    *n2 = *n1;
    *n1 = aux;
}

void bubbleSort(int vector_entrada[],int n)
{
    int i, j;
    for(i = 0; i < n-1 ; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if(vector_entrada[j]<vector_entrada[j+1])
            {
                cambiar(&vector_entrada[j], &vector_entrada[j+1]);
            }
        }
    }
}

int imprimir(int vector_entrada[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%d , ", vector_entrada[i]);
        
    }
    printf("\nFin del ordenamiento");
}

int main(int argc, char const *argv[])
{
    int vector_entrada[] = {100,25,33,47,68,9,12};
    int n = sizeof(vector_entrada)/sizeof(vector_entrada[0]);
    bubbleSort (vector_entrada,n);
    imprimir(vector_entrada, n);
    printf("\n");
    return 0;
}
