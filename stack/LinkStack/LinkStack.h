#ifndef LinkStack_h
#define LinkStack_h

typedef int DataType;
typedef struct node{
    DataType data;
    struct node *next;
}LStackNode;

typedef struct _LinkStack{
    LStackNode *head;
    LStackNode *tail;
    LStackNode *current;
}LinkStack;

void InitStack(LinkStack *);

int StackEmpty(LinkStack *);

int PushStack(LinkStack *, DataType);

int PopStack(LinkStack *, DataType *);

int GetHead(LinkStack *, DataType *);

int GetLength_LinkStack(LinkStack *);

void Clear_LinkStack(LinkStack *);

#endif
