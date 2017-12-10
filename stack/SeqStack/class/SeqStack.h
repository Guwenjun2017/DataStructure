#ifndef SeqStack_h
#define SeqStack_h
#define StackSize 100

typedef char DataType;
typedef struct seqStack{
    DataType stack[StackSize];
    int top;
}SeqStack;

//初始化栈
void InitStack(SeqStack *s);

//判断栈是否为空
int StackEmpty(SeqStack S);

int GetTop(SeqStack S, DataType *e);

int PushStack(SeqStack *S, DataType e);

int PopStack(SeqStack *S, DataType *e);

int StackLength(SeqStack S);

void ClearStack(SeqStack *S);

#endif
