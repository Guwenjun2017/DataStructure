#ifndef queue_h
#define queue_h
#define DataType int

//定义节点
typedef struct _node{
    DataType data;
    struct _node *next;
}Node;
//定义队列
typedef struct _Queue{
    Node *head;
    Node *tail;
}Queue;
//初始化队列
void initQueue(Queue *);
//添加元素
void enqueue(Queue *, DataType);
//删除元素
DataType *dequeue(Queue *);


#endif
