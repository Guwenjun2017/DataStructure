#include<stdio.h>
#include "binTree.h"

int main(int argc, char **argv)
{
    BinTreeNode t = NULL;
    int count = 0;
    int count1;

    printf("请输入根节点:\n");
    createBinTree(&t);
    printf("\n先序遍历:");
    PreOrder(t, &count);
    printf("\n节点个数: %d", count);
    count1 = mycount(t);
    printf("\n叶结点个数: %d", count1);
    printf("\n二叉树深度: %d", Height(t));
    printf("\n中序遍历:");
    PostOrder(t);
    printf("\n后序遍历:");
    printf("\n先序遍历(非递归):");
    PreOrder_n(t);
    release(t);
    
    return 0;
}
