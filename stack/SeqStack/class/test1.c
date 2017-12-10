#include<stdio.h>
#include<stdlib.h>
#include"SeqStack.h"

int main(int argc, char **argv)
{
    char a;
    SeqStack S;

    InitStack(&S);

    printf("GetTop: ");
    GetTop(S, &a);
    printf("%c", a);

    printf("PushStack: ");
    printf("[将'1' '2' '3' '4' '5'依次入栈.]\n");
    PushStack(&S, '1');
    PushStack(&S, '2');
    PushStack(&S, '3');
    PushStack(&S, '4');
    PushStack(&S, '5');
    
    printf("Now GetTop: ");
    GetTop(S, &a);
    printf("%c\n", a);

    printf("PopStack: ");
    printf("[依次出栈并输出.]\n");
    PopStack(&S, &a);
    printf("%c\n", a);
    PopStack(&S, &a);
    printf("%c\n", a);
    printf("将两个元素出栈后,栈此时的长度: ");
    printf("%d\n", StackLength(S));
    PopStack(&S, &a);
    printf("%c\n", a);
    PopStack(&S, &a);
    printf("%c\n", a);
    PopStack(&S, &a);
    printf("%c\n", a);
    printf("可以明显看出栈FILO的特性!\n");

    ClearStack(&S);
    printf("清空栈后,栈此时的长度: ");
    printf("%d\n", StackLength(S));
    

    return 0;
}
