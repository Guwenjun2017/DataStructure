#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
typedef int ElemType;
typedef struct _LNode{
    ElemType data;
    struct _LNode *next;
}LNode, *Linkedlist;

Linkedlist CreateList(int n);
void PrintList(Linkedlist L);
int GetElem(Linkedlist L, int i, ElemType *e);
void InsertList(Linkedlist, ElemType data);
void Delete(Linkedlist, ElemType data);

int main(int argc, char **argv)
{
    int n, i;
    ElemType e;
    Linkedlist L = NULL;
    printf("please the num of element: ");
    scanf("%d", &n);
    if(n > 0){
	printf("\n1-Create Linkedlist:\n");
	L = CreateList(n);
	printf("\n2-Print Linkedlist:\n");
	PrintList(L);
	printf("\n3-GetElem from Linkedlist:\n");
	printf("\ninput it's index:");
	scanf("%d", &i);
	if(GetElem(L, i, &e))
	    printf("index %d's element is %d\n", i, e);
	else
	    printf("Not exists.");
	printf("\n4-插入指定元素,输入该元素: ");
	scanf("%d", &e);
	InsertList(L, e);
	PrintList(L);
	printf("\n5-删除指定元素,输入该元素: ");
	scanf("%d", &e);
	Delete(L, e);
	PrintList(L);
    }else
	printf("ERROR.");

    return 0;
}
Linkedlist CreateList(int n){
    LNode *p, *q, *head;
    int i;
    head = (LNode *)malloc(sizeof(LNode));
    head->next = NULL;
    p = head;
    for(i = 0; i < n; i++){
	q = (Linkedlist)malloc(sizeof(LNode));
	printf("input data %d: ", i);
	scanf("%d", &q->data);
	q->next = NULL;
	p->next = q;
	p = q;
    }

    return head;
}

void PrintList(Linkedlist L){
    LNode *p;
    p = L->next;  /*p指向单链表的第一个元素*/
    while(p != NULL){
	printf("%5d",p->data);
	p = p->next;
    }
    printf("\n");

    return;
}
int GetElem(Linkedlist L, int i, ElemType *e){
    LNode *p;
    int j = 0;
    p = L->next;
    while(p && j < i){
	p = p->next;
	j++;
    }
    if(!p || j > i)
	return ERROR;
    *e = p->data;

    return OK;
}
void InsertList(Linkedlist L, ElemType data){
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    p->next = NULL;

    if(L->next == NULL){
	L->next = p;
    }else{
	LNode *q = L->next;
	while(q->next != NULL ){
	    q = q->next;
	}
	q->next = p;
    }

    return;
}
void Delete(Linkedlist L, ElemType data){
    LNode *del;
    if(L->next == NULL)
	return;
    else{
	LNode *tmp = L->next;
	while(tmp != NULL && tmp->next->data != data){
	    tmp = tmp->next;
	}
	if(tmp != NULL){
	    del = tmp->next;
	    tmp->next = tmp->next->next;
	}
    }
    free(del);

    return;
    
}
