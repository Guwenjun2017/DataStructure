#include<stdio.h>
#include<stdlib.h>
#include "SeqStack.h"
//
//初始化栈
void InitStack(SeqStack *S){
    S->top = 0;
}

//判断栈是否为空
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

int PushStack(SeqStack *S, DataType e){
    if(S->top >= StackSize){
	printf("栈已满!不能进栈!\n");
	return 0;
    }else{
	S->stack[S->top] = e;
	S->top++;
	return 1;
    }
}

int PopStack(SeqStack *S, DataType *e){
    if(S->top == 0){
	printf("栈已空!不能出栈!\n");
	return 0;
    }else{
	S->top--;
	*e = S->stack[S->top];
	return 1;
    }
}

int StackLength(SeqStack S){
    return S.top;
}

void ClearStack(SeqStack *S){
    S->top = 0;
}
