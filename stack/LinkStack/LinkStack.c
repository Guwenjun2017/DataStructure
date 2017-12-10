#include<stdio.h>
#include<stdlib.h>
#include "LinkStack.h"

void InitStack(LinkStack *LS){
    LS->head = NULL;
    LS->tail = NULL;

    return;
}

int StackEmpty(LinkStack *LS){
    if(LS->head == NULL){
	return 1;
    }else{
	return 0;
    }
}
//将元素e入栈
int PushStack(LinkStack *LS, DataType e){
    LStackNode *node=(LStackNode *)malloc(sizeof(LStackNode));
    if(node == NULL){
	printf("malloc error!\n");
	return 0;
    }
    node->data = e;
    node->next = LS->head;
    LS->head = node;

    return 1;
}
//将栈顶元素出栈
int PopStack(LinkStack *LS, DataType *e){
    LStackNode *node= LS->head;
    if(!node){
	printf("栈空!\n");
	return 0;
    }
    LS->head = node->next;
    *e = node->data;
    free(node);
    return 1;
}
//取栈顶元素
int GetHead(LinkStack *LS, DataType *e){
    LStackNode *node = LS->head;
    if(!node){
	printf("栈空!\n");
	return 0;
    }
    *e = node->data;
    return 1;
}
//取栈长
int GetLength_LinkStack(LinkStack *LS){
    LStackNode *node = LS->head;
    int count = 0;
    while(node->next != NULL){
	node = node->next;
	count++;
    }

    return count;
}
//清空栈
void Clear_LinkStack(LinkStack *LS){
    LStackNode *node = LS->head;
    LStackNode *free_node;
    while(!node){
	free_node = node;
	node = node->next;
	free(free_node);
    }

    return;
}
