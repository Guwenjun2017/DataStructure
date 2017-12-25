#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define maxSize 20
#define elemType char

typedef struct _node{
    elemType stack[maxSize];
    int top;
}stackNode;

void init(stackNode *s);
void push(stackNode *s, elemType e);
void pop(stackNode *s);

void init(stackNode *s){
    s->top = 0;
}

void Push(stackNode *s, elemType e){
    if(s->top == maxSize)
	printf("stack overflow!\n");
    else{
	s->top += 1;
	s->stack[s->top] = e;
    }

    return;
}

void Pop(stackNode *s){
    if(s->top > 0)
	s->top--;
    else
	printf("stack empty!\n");

    return;
}

int main(int argc, char **argv)
{
    char s[maxSize];
    int i;
    stackNode *p;
    printf("create a empty stack.\n");
    p = (stackNode *)malloc(sizeof(stackNode));
    init(p);
    printf("input a expression:\n");
    gets(s);
    for(i = 0; i < strlen(s); i++){
	if(s[i] == '(')
	    Push(p, s[i]);
	if(s[i] == ')')
	    Pop(p);
    }
    if(p->top == 0)
	printf(" '(' match ')' !\n");
    else
	printf(" '(' not match ')' !\n");

    return 0;
}
