#include<stdio.h>
#include "createList.h"
/*生成待排序序列*/
void createList(int list[], int *n){
    int i = 1;
    int a;
    printf("请输入待排序序列(长度小于50,以输入一个字符结束):\n");
    while(scanf("%d", &a) == 1){
	list[i] = a;
	i++;
    }

    *n = i - 1;
    getchar();

    return;
}
