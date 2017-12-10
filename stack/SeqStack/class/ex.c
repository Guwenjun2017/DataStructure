#include<stdio.h>
#include<stdlib.h>
#include "SeqStack.h"

void InitStack(SeqStack *S){
    S->top = 0;

    return;
}

int StackEmpty(SeqStack S){
    if(S.top == 0)
	return 1;
    else
	return 0;
}

int GetTop(SeqStack S, DataType *e){
    if(S.top <= 0){
	printf("栈已空!\n");
	return 0;
    }else{
	*e = S.stack[S.top - 1];
	return 1;
    }
}
//入栈
int PushStack(SeqStack *S, DataType e){
    if(S->top >= StackSize){
	printf("栈已经满了,不能进栈!\n");
	return 0;
    }else{
	S->stack[S->top] = e;
	S->top++;
	return 1;
    }
}
//出栈
int PopStack(SeqStack *S, DataType *e){
    if(S->top == 0){
	printf("栈已经空了,不能出栈!\n");
	return 0;
    }else{
	S->top--;
	*e = S->stack[S->top];
	return 1;
    }
}
//获取栈的长度
int StackLength(SeqStack S){
    return S.top;
}
//清空栈
void ClearStack(SeqStack *S){
    S->top = 0;

    return;
}
