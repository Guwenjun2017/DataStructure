#ifndef LinkBinaryTree_h
#define LinkBinaryTree_h
#define DataType char
#define MaxSize 100

typedef struct _BinTreeNode{
    DataType data;
    struct _BinTreeNode *lchild;
    struct _BinTreeNode *rchild;
}*BinTree, BinNode;

//初始化二叉树;
void InitBinaryTree(BinTree *bt);
//清除二叉树
void ClearBinaryTree(BinTree *bt);
//创建二叉树
void CreateBinaryTree(BinTree *bt);
/* 数据插入
 * LR=0,则将子树c插入到T中,使c成为p的左子树,节点p原来的左子树成为c的右子树;
 * LR=1,则将子树c插入到T中,使c成为p的右子树,节点p原来的右子树成为c的右子树.)
 */
int InsertChild(BinTree p, int LR, BinTree c);
//返回二叉树e的左孩子节点元素值
DataType LeftChild(BinTree bt, DataType e);
//返回二叉树e的右孩子节点元素值
DataType RightChild(BinTree bt, DataType e);
//返回含指定数据的二叉树节点指针
BinTree GetNode(BinTree bt, DataType e);
//删除子树
int DeleteLeftChild(BinTree bt, int LR);
//先序遍历二叉树
void PreOrderBinTree(BinTree bt);
//中序遍历二叉树
void InOrderBinTree(BinTree bt);
//后序遍历二叉树
void PostOrderBinTree(BinTree bt);
void PostOrderBinTree_else(BinTree bt);

#endif
