#include "stdio.h"
#define SIZE 5

int items [SIZE];
int front = -1;
int rear = -1;

void enQueue(int value)
{
    if(rear == SIZE-1)
        printf("El Queue está lleno \n");
    else
    {
        if(front == -1)
            front = 0;
        rear++;
        items[rear] = value;
        printf("Se insertó el valor %d al Queue \n", value);
    }    
}

void deQueue()
{
    if (front == -1)
    printf("El Queue está vacio \n");
    else
    {
        printf("Se elimino el valor %d \n", items[front]);
        if (rear > 0)
        {
            for (int i = 0; i < rear ; i++)
            {
                items[i]=items[i+1];
            }
        }
        rear = rear - 1;
        if (front > rear)
        front = rear = -1;
    }
}

int main(int argc, char const *argv[])
{
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(7);
    deQueue();
    deQueue();
    enQueue(12);
    printf("Los valores del queue son: \n");
    for(int loop = 0; loop <= rear; loop++)
      printf("%d \n", items[loop]);
    return 0;
}