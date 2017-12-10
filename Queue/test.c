#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

int main(int argc, char **argv)
{
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    initQueue(Q);

    printf("将1 2 3 4 5依次入队.\n");
    enqueue(Q, 1);
    enqueue(Q, 2);
    enqueue(Q, 3);
    enqueue(Q, 4);
    enqueue(Q, 5);
    
    printf("出队:\n");
    DataType *data = dequeue(Q);
    printf("%d\n", *data);

    data = dequeue(Q);
    printf("%d\n", *data);
    
    data = dequeue(Q);
    printf("%d\n", *data);

    data = dequeue(Q);
    printf("%d\n", *data);

    data = dequeue(Q);
    printf("%d\n", *data);
    return 0;
}
