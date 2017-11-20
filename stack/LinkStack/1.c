#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct node{
    DataType data;
    struct node *next;
}LStackNode, *LinkStack;

void Coversion_10_to_2(int N){
    LStackNode *p;
    LStackNode *top = NULL;
    do{
	p = (LStackNode *)malloc(sizeof(LStackNode));
	p->data = N%2;
	p->next = top;
	top = p;
	N = N/2;
    }while(N != 0);
    while(top != NULL){
	p = top;
	printf("%d", p->data);
	top = top->next;
	free(p);
    }

    return;
}

int main(int argc, char **argv)
{
    int n;
    printf("请输入一个十进制数:\n");
    scanf("%d", &n);
    printf("转换后的二进制数:\n");
    Coversion_10_to_2(n);
    printf("\n");
}
