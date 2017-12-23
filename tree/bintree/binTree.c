#include<stdio.h>
#include<stdlib.h>
#include "binTree.h"

void createBinTree(BinTreeNode *t){
    char s;
    BinTreeNode q;
    scanf("%c", &s);
    getchar();
    if(s == '#')
	*t = NULL;
    else{
	q = (BinTreeNode)malloc(sizeof(struct _BinTreeNode));
	if(q == NULL){
	    printf("malloc error!");
	    exit(-1);
	}
	q->data = s;
	*t = q;
	printf("请输入%c的左子节点: \n", s);
	createBinTree(&q->lchild);
	printf("请输入%c的右子节点: \n", s);
	createBinTree(&q->rchild);
    }

    return;
}

int Height(BinTreeNode t){
    if(t == NULL){
	return 0;
    }else{
	int i = Height(t->lchild);
	int j = Height(t->lchild);
	return (i > j)? i+1 : j+1;
    }
}
//void PreOrder(BinTreeNode p){
//    if(p != NULL){
//	printf("%c\t", p->data);
//	PreOrder(p->lchild);
//	PreOrder(p->rchild);
//    }
//}
void PreOrder(BinTreeNode p, int *count){
    if(p != NULL){
	(*count)++;
	printf("%c\t", p->data);
	PreOrder(p->lchild, count);
	PreOrder(p->rchild, count);
    }
}
void InOrder(BinTreeNode p){
    if(p != NULL){
	InOrder(p->lchild);
	printf("%c\t", p->data);
	InOrder(p->rchild);
    }
}
void PostOrder(BinTreeNode p){
    if(p != NULL){
	PostOrder(p->lchild);
	PostOrder(p->rchild);
	printf("%c\t", p->data);
    }
}

void PreOrder_n(BinTreeNode p){
    BinTreeNode stack[maxSize];
    BinTreeNode q;
    int top = 0, i;
    for(i = 0; i < maxSize; i++)
	stack[i] = NULL;
    q = p;
    while(q != NULL){
	printf("%c", q->data);
	if(q->rchild != NULL)
	    stack[top++] = q->rchild;
	if(q->lchild != NULL)
	    q = q->lchild;
	else
	    if(top > 0)
		q = stack[--top];
	    else
		q = NULL;
    }

    printf("\n");
    return;
}

void release(BinTreeNode t){
    if(t != NULL){
	release(t->lchild);
	release(t->rchild);
	free(t);
    }

    return;
}

