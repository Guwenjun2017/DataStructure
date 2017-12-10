#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

void initQueue(Queue *queue){
    queue->head = NULL;
    queue->tail= NULL;

    return;
}

void enqueue(Queue *queue, DataType iData){
    Node *node = (Node *)malloc(sizeof(node));
    node->data = iData;

    if(queue->head = NULL){
	queue->tail = node;
	node->next = NULL;
    }else{
	node->next = queue->head;
    }

    queue->head = node;
    return;
}

//删除元素(使其出队)并将其返回
DataType *dequeue(Queue *queue){
    Node *tmp = queue->head;
    DataType *data = (DataType *)malloc(sizeof(DataType));

    if(queue->head == NULL){
	data = NULL;
    }else if(queue->head == queue->tail){
	queue->head = queue->tail = NULL;
	data = &tmp->data;
	free(tmp);
    }else{
	while(tmp->next != queue->tail){
	    tmp = tmp->next;
	}
	queue->tail = tmp;
	tmp = tmp->next;
	data = &tmp->data;
	queue->tail->next = NULL;
	free(tmp);
    }

    return data;
}
