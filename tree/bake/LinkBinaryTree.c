#include<stdio.h>
#include<stdlib.h>
#include "LinkBinaryTree.h"

//初始化二叉树;
void InitBinaryTree(BinTree *bt){
    *bt = NULL;

    return;
}
//清除二叉树
void ClearBinaryTree(BinTree *bt){
    if(*bt){
	if((*bt)->lchild)
	    ClearBinaryTree(&((*bt)->lchild));
	if((*bt)->rchild)
	    ClearBinaryTree(&((*bt)->rchild));
	free(*bt);
	*bt = NULL;
    }

    return;
}
//创建二叉树
void CreateBinaryTree(BinTree *bt){
    DataType ch;
    DataType tmp;
    scanf("%c", &ch);
    tmp = getchar();
    if(ch == '#')
	*bt = NULL;
    else{
	*bt = (BinTree)malloc(sizeof(BinNode));
	if(!(*bt))
	    exit(-1);
	(*bt)->data = ch;
	printf("请输入%c的左子节点: \n", ch);
	CreateBinaryTree(&((*bt)->lchild));
	printf("请输入%c的右子节点: \n", ch);
	CreateBinaryTree(&((*bt)->rchild));
    }

    return;
}
/* 数据插入
 * LR=0,则将子树c插入到T中,使c成为p的左子树,节点p原来的左子树成为c的右子树;
 * LR=1,则将子树c插入到T中,使c成为p的右子树,节点p原来的右子树成为c的右子树.)
 */
int InsertChild(BinTree p, int LR, BinTree c){
    if(p){
	if(LR == 0){
	    c->rchild = p->lchild;
	    p->lchild = c;
	}else if(LR == 1){
	    c->rchild = p->rchild;
	    p->rchild = c;
	}
	return 1;
    }

    return 0;
}
//返回二叉树e的左孩子节点元素值
DataType LeftChild(BinTree bt, DataType e){
    BinTree p;
    if(bt){
	p = GetNode(bt, e);
	if(p && p->lchild)
	    return p->lchild->data;
    }

}
//返回二叉树e的右孩子节点元素值
DataType RightChild(BinTree bt, DataType e){
    BinTree p;
    if(bt){
	p = GetNode(bt, e);
	if(p && p->rchild)
	    return p->rchild->data;
    }
}
//返回含指定数据的二叉树节点指针
BinTree GetNode(BinTree bt, DataType e){
    BinTree Q[MaxSize];
    int front = 0, rear = 0;
    BinNode *p;
    if(bt){
	Q[rear] = bt;
	rear++;

	while(front != rear){
	    p=Q[front];
	    front++;
	    if(p->data == e){
		return p;
	    }
	    if(p->lchild){
		Q[rear]=p->lchild;
		rear++;
	    }
	    if(p->rchild){
		Q[rear]=p->rchild;
		rear++;
	    }
	}
    }

    return NULL;
}
//删除子树
int DeleteLeftChild(BinTree p, int LR){
    if(p){
	if(LR == 0){
	    ClearBinaryTree(&(p->lchild));
	}else if(LR == 1){
	    ClearBinaryTree(&(p->rchild));
	}
	return 1;
    }

    return 0;
}
//先序遍历二叉树
void PreOrderBinTree(BinTree bt){
    if(bt == NULL)
	return;
    printf("%c\t", bt->data);
    PreOrderBinTree(bt->lchild);
    PreOrderBinTree(bt->rchild);
}
//中序遍历二叉树
void InOrderBinTree(BinTree bt){
    if(bt == NULL)
	return;
    InOrderBinTree(bt->lchild);
    printf("%c\t", bt->data);
    InOrderBinTree(bt->rchild);
}
//后序遍历二叉树
void PostOrderBinTree(BinTree bt){
    if(bt == NULL)
	return;
    PostOrderBinTree(bt->lchild);
    PostOrderBinTree(bt->rchild);
    printf("%c\t", bt->data);
}
void PostOrderBinTree_else(BinTree bt){
    BinTree stack[MaxSize];
    int top;
    BinNode *p, *q;
    top = 0;
    p = bt, q = NULL;
    while(p != NULL || top > 0){
	while(p != NULL){
	    stack[top++] = p;
	    p = p->lchild;
	}
	if(top > 0){
	    p = stack[top - 1];
	    if(p->rchild == NULL || p->rchild == q){
		printf("%c\t", p->data);
		q = p;
		p = NULL;
		top--;
	    }
	    else
		p = p->rchild;
	}
    }

}
