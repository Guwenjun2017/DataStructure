#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define INIT_SIZE 5
#define INCREAM 5
typedef int ElemType;
typedef struct _SeqList{
    ElemType *slist;  //存储空间的基地址
    int length;  //顺序表当前长度
    int listsize;  //当前分配的空间
}SeqList;

int InitList_sq(SeqList *L);
int CreateList_sq(SeqList *L, int n);
int ListInsert_sq(SeqList *L, int i, ElemType e);
int PrintList_sq(SeqList *L);
int ListDelete_sq(SeqList *L, int i);  //删除第i个元素
int ListLocate_sq(SeqList *L, ElemType e);

int main(int argc, char **argv)
{
    SeqList sl;
    int n, m, k;
    int elem;
    int index;
    printf("please input the number of element:");
    scanf("%d", &n);
    if(n > 0){
	printf("\n1-Create SeqList:\n");
	InitList_sq(&sl);
	CreateList_sq(&sl, n);
	printf("\n2-Print Seqlist:\n");
	PrintList_sq(&sl);
	printf("please input insert location and data:(location,data)\n");
	scanf("%d,%d", &m, &k);
	ListInsert_sq(&sl, m, k);
	printf("\n3-Print SeqList:\n");
	PrintList_sq(&sl);
	printf("\n4-Get the index of sured element,please input the element:");
	scanf("%d", &elem);
	printf("%d's index is %d.\n", elem, ListLocate_sq(&sl, elem));
	printf("\n5-Delete the element by it's index,please input a index:");
	scanf("%d", &index);
	ListDelete_sq(&sl, index);
	PrintList_sq(&sl);

    }
    else
	printf("ERROR\n");
    return 0;
}
int InitList_sq(SeqList *L){
    L->slist = (ElemType *)malloc(INIT_SIZE * sizeof(ElemType));
    if(!L->slist)
	return ERROR;
    L->length = 0;
    L->listsize = INIT_SIZE;

    return OK;
}

int CreateList_sq(SeqList *L, int n){
    ElemType e;
    int i;
    for(i = 0; i < n; i++){
	printf("input data %d:", i);
	scanf("%d", &e);
	if(!ListInsert_sq(L, i, e))
	    return ERROR;
    }

    return OK;
}
int ListInsert_sq(SeqList *L, int i, ElemType e){
    int k;
    if(i < 0 || i > L->length )
	return ERROR;
    if(L->length >= L->listsize){
	L->slist = (ElemType *)realloc(L->slist, (INIT_SIZE + INCREAM) * sizeof(ElemType));
	if(!L->slist)
	    return ERROR;
	L->listsize += INCREAM;
	}
	for(k = L->length-1; k >= i; k--){
	    L->slist[k + 1] = L->slist[k];
	}
	L->slist[i ] = e;
	L->length++;
	return OK;
}
int PrintList_sq(SeqList *L){
    int i;
    for(i = 0; i < L->length; i++){
	printf("%5d", L->slist[i]);
    }
    printf("\n");

    return OK;
}
int ListDelete_sq(SeqList *L, int i){  //删除第i个元素
    if(i < 0 || i > L->length) 
	return ERROR;
    else{
	if(i == L->length){
	    //free(&L->slist[i]);
	    L->length--; 
	}else{
	    //free(&L->slist[i]);
	    for(int j = i; j < L->length - 1; j++){
		L->slist[j] = L->slist[j + 1];
		L->length--; 
		//free(&L->slist[L->length]);
	    }
	}
    }

    return OK;
}
int ListLocate_sq(SeqList *L, ElemType e){
    for(int i = 0; i < L->length; i++){
	if(L->slist[i] == e)
	    return i;
    }

    printf("Not found.\n");
    return ERROR;
}
