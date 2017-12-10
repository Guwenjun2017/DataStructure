#ifndef queue_h
#define queue_h
#define DataType int

typedef struct _node{
    DataType data;
    struct _node *next;
}Node, *Nodeptr;

typedef struct _LinkQueue{
    Node *head;
    Node *tail;
}LinkQueue;

void initQueue(LinkQueue *LQ);

int QueueEmpty(LinkQueue *LQ);

int EnQueue(LinkQueue *LQ, DataType e);

int DeQueue(LinkQueue *LQ, DataType *e);

int GetHead(LinkQueue *LQ, DataType *e);

void ClearQueue(LinkQueue *LQ);

#endif
