#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

void initQueue(LinkQueue *LQ){
    LQ->head = LQ->tail = (Node *)malloc(sizeof(Node));
    if(LQ->head == NULL) 
	exit(-1);
    LQ->tail->next = NULL;

    return;
}

int QueueEmpty(LinkQueue *LQ){
    if(LQ->tail->next == NULL)
	return 1;
    else 
	return 0;
}

int EnQueue(LinkQueue *LQ, DataType iData){
    Node *node = (Node *)malloc(sizeof(node));
    if(!node)
	exit(-1);
    node->data = iData;
    node->next = NULL;

    LQ->tail->next = node;
    LQ->tail = node;

    return 1;
}

int DeQueue(LinkQueue *LQ, DataType *e){
    Node *node;
    if(LQ->head == LQ->tail)
	return 0;
    else{
	node = LQ->head->next;
	*e = node->data;
	LQ->head->next = node->next;
	if(LQ->tail == node)
	    LQ->tail = LQ->head;
	free(node);
	return 1;
    }
}

int GetHead(LinkQueue *LQ, DataType *e){
    Node *node;
    if(LQ->head == LQ->tail){
	printf("队列已空.\n");
	return 0;
    }
    else{
	node = LQ->head->next;
	*e = node->data;
	return 1;
    }
}

void ClearQueue(LinkQueue *LQ){
    while(LQ->head != NULL){
	LQ->tail = LQ->head->next;
	free(LQ->head);
	LQ->head = LQ->tail;
    }

    return;
}

