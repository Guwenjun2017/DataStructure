#include<stdio.h>
#include "insertSort.h"
#include "createList.h"

int main(int argc, char **argv)
{
    int choice = 1, length;
    int slist[maxSize];
    createList(slist, &length);
    insertSort(slist, length);
    printf("\n");

    return 0;
}
