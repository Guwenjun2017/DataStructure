#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 5
typedef int ElemType;

typedef struct _SeqStack{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SeqStack;

int InitStack(SeqStack *S);
int Push(SeqStack *S, ElemType e);
int Pop(SeqStack *S, ElemType *e);
int CreateStack(SeqStack *S);
void PrintStack(SeqStack *S);

int main(int argc, char **argv)
{
    SeqStack s;
    printf("1-CreateStack\n");
    CreateStack(&s);
    printf("2-Pop&Print\n");
    PrintStack(&s);

    return 0;
}
int InitStack(SeqStack *S){
    S->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!S->base)
	return 0;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;

    return 1;
}

int Push(SeqStack *S, ElemType e){
    if(S->stacksize == 1){
	printf("栈满.\n");
	return 0;
    }
    if(S->stacksize == 10){
	*(S->base) = e;
	S->stacksize--;
    }
    else{
	*(S->top) = e;
	S->stacksize--;
    }
    
    return 1;
}
int Pop(SeqStack *S, ElemType *e){
    if(S->stacksize == 10){
	printf("栈空\n");
	return 0;
    }
    e = S->top;
    S->stacksize++;

    return 1;
}

int CreateStack(SeqStack *S){
    int e;
    if(InitStack(S))
	printf("Init Success.\n");
    else{
	printf("Init fail.\n");
	return 0;
    }
    printf("输入数字:(输入一个字符截止)\n");
    while(scanf("%d", &e)){
	Push(S, e);
    }
    
    return 1;
}

void PrintStack(SeqStack *S){
    ElemType e;
    while(Pop(S, &e))
	printf("%d\n", e);

    return;
}
