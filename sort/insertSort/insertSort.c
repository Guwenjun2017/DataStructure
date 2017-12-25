#include<stdio.h>
#include "insertSort.h"
/*直接插入排序*/
void insertSort(int list[], int n){
    int i = 1;
    int j = 0;
    int node = 0;
    int count =1;
    printf("对序列进行直接插入排序:\n");
    printf("初始序列为:");
    printList(list, n);
    for(i = 2; i <= n; i++){
	node = list[i];
	j = i - 1;
	while(j >= 0 && node < list[j]){
	    list[j + 1] = list[j];
	    --j;
	}
	list[j + 1] = node;
	printf("第%d次排序结果: ", count++);
	printList(list, n);

    }
}
/*输出排序结果*/
void printList(int list[], int n){
    int i = 1;
    for(i; i <= n; i++){
	printf(" %d ", list[i]);
	if(i % 10 == 0 && i != 0)
	    printf("\n");
    }
    printf("\n");

    return;
}
