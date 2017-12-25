#include<stdio.h>
#include<stdlib.h>
#include "LinkBinaryTree.h"

int main(int argc, char **argv)
{
    DataType a;
    BinTree *bt = (BinTree *)malloc(sizeof(BinTree));
    printf("Begin.\n");
    
    InitBinaryTree(bt);
    printf("请输入根节点:\n");
    CreateBinaryTree(bt);
    
    printf("先序遍历:\n");
    PreOrderBinTree(*bt);
    printf("\n");
    printf("中序遍历:\n");
    InOrderBinTree(*bt);
    printf("\n");
    printf("后序遍历:\n");
    PostOrderBinTree(*bt);
    printf("\n");
    PostOrderBinTree_else(*bt);
    printf("\n");

    return 0;
}
