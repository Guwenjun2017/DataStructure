#include<stdio.h>
#include "queue.h"

int main(int argc, char **argv)
{
    LinkQueue *LQ;
    DataType a;

    initQueue(LQ);
    printf("入队:[1 2 3 4 5]\n");
    EnQueue(LQ, 1);
    EnQueue(LQ, 2);
    EnQueue(LQ, 3);
    EnQueue(LQ, 4);
    EnQueue(LQ, 5);
    printf("获取头元素: ");
    GetHead(LQ, &a);
    printf("%d\n", a);
    printf("出队:\n");
    DeQueue(LQ, &a);
    printf("%d\n", a);

    DeQueue(LQ, &a);
    printf("%d\n", a);

    DeQueue(LQ, &a);
    printf("%d\n", a);

    DeQueue(LQ, &a);
    printf("%d\n", a);

    DeQueue(LQ, &a);
    printf("%d\n", a);

    DataType b = 9;
    DeQueue(LQ, &b);
    printf("%d\n", b);

    ClearQueue(LQ);
    DataType c = 8;
    printf("获取头元素: ");
    GetHead(LQ, &c);
    printf("%d\n", c);

    return 0;
}
