#ifndef binTree_h
#define binTree_h
#define maxSize 20

typedef struct _BinTreeNode{
    char data;
    struct _BinTreeNode *lchild;
    struct _BinTreeNode *rchild;
}*BinTreeNode;

void createBinTree(BinTreeNode *t);
int Height(BinTreeNode t);
int mycount(BinTreeNode t);

//void PreOrder(BinTreeNode p);
void PreOrder(BinTreeNode p, int *count);
void InOrder(BinTreeNode p);
void PostOrder(BinTreeNode p);

void PreOrder_n(BinTreeNode p);

void release(BinTreeNode t);

#endif
