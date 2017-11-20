#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct node{
    DataType data;
    struct node *next;
}LStackNode, *LinkStack;

void InitStack(LinkStack *top){
    *top = (LinkStack)malloc(sizeof(LStackNode));
    if(NULL == *top ){
	return;
    }
    (*top)->next = NULL;
}

int StackEmpty(LinkStack top){
    if(top->next == NULL){
	return 1;
    }else
	return 0;
}

int PushStack(LinkStack top, DataType e){
    LStackNode *p = (LStackNode *)malloc(sizeof(LStackNode));
    if(NULL == p){
	printf("内存分配失败!\n");
	return 0;
    }
    p->data = e;
    p->next = top->next;
    top->next = p;

    return 1;    
}

int PopStack(LinkStack top, DataType *e){
    LStackNode *p;
    p = top->next;
    if(!p){
	printf("栈已空!\n");
	return 0;
    }
    top->next = p->next;
    *e = p->data;

    free(p);
    return 1;
}

int GetTop(LinkStack top, DataType *e){
    LStackNode *p;
    p = top->next;
    if(!p){
	printf("栈已空!\n");
	return 0;
    }
    *e = p->data;

    return 1;
}

int StackLength(LinkStack top){
    LStackNode *p;
    int count;
    p = top;
    while(p->next != NULL){
	p = p->next;
	count++;
    }

    return count;
}

void DestoryStack(LinkStack top){
    LStackNode *p, *q;
    p = top;
    while(!p){
	q = p;
	p = p->next;
	free(q);
    }
}
