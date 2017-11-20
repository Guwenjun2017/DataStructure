#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct node{
    DataType data;
    struct node *next;
}LStackNode, *LinkStack;

void Coversion_10_to_8(int N){
    LStackNode *p;
    LStackNode *top = NULL;
    do{
	p = (LStackNode *)malloc(sizeof(LStackNode));
	p->data = N%8;
	p->next = top;
	top = p;
	N = N/8;
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
    printf("转换后的八进制数:\n");
    Coversion(n);
    printf("\n");
}
