#include<stdio.h>
#include<stdlib.h>
#define maxSize 50

void createList(int list[], int *n);
void printList(int list[], int n);

void insertSort(int list[], int n);
void heapAdjust(int list[], int u, int v);
void heapSort(int list[], int n);
void shellSort(int list[], int length);
void quickSort(int list[], int left, int right, int *count);

int main(int argc, char **argv){
    int choice = 1; 
    int length;
    int count = 1;
    int slist[maxSize];
    while(choice != 0){
	printf("\n");
	printf("******内部排序算法演示******");
	printf("\n 1. 直接插入排序 \n");
	printf("\n 2. 堆排序 \n");
	printf("\n 3. 希尔排序 \n");
	printf("\n 4. 快速排序 \n");
	printf("\n 0. 退出 \n");
	printf("请选择: ");
	scanf("%d", &choice);
	getchar();
	switch(choice){
	    case 1:{
		       createList(slist, &length);
		       insertSort(slist, length);
		       break;
		   }
	    case 2:{
		       createList(slist, &length);
		       heapSort(slist, length);
		       break;
		   }
	    case 3:{
		       createList(slist, &length);
		       shellSort(slist, length);
		       break;
		   }
	    case 4:{
		       createList(slist, &length);
		       quickSort(slist, 0, length, &count);
		       printList(slist, length);
		       break;
		   }
	    default: choice = 0;
	}
	printf("\n");
    }

    return 0;
}
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
/*希尔排序*/
void shellSort(int list[], int length){
    int increment;
    int i;
    int j;
    int tmp;
    int count = 1;
    printf("对序列进行希尔排序:\n");
    printf("初始序列为:");
    printList(list, length);
    for(increment = length/2; increment > 0; increment /= 2){
	// i从第step开始排列,应为插入排序的第一个元素
	// 可以先不动,从第二个开始排序
	for(i = increment; i < length; i++){
	    tmp = list[i];
	    for(j = i - increment; j >= 0 && tmp < list[j]; j -= increment){
		list[j + increment] = list[j];
	    }
	    list[j + increment] = tmp;
	}
	printf("第%d次排序结果: ", count++);
	printList(list, length);
    }

    return;
}
/*快速排序(双向扫描)*/
void quickSort(int list[],int left, int right, int *count){
    int i, j, t, tmp;
    //int count = 1;
    if(left > right)
	return;
    tmp = list[left];
    i = left;
    j = right;
    while(i != j){
	while(list[j] >= tmp && i < j){
	    j--;
	}
	while(list[i] <= tmp && i < j){
	    i++;
	}
	if(i < j){
	    t = list[i];
	    list[i] = list[j];
	    list[j] = t;
	}
	printf("第%d次排序后的结果为:", (*count)++);
	printList(list,right);
	//printf("\n");
    }
    list[left] = list[i];
    list[i] = tmp;
    quickSort(list, left, i - 1, count);
    quickSort(list, i + 1, right, count);
}
/*堆排序*/
void heapAdjust(int list[], int u, int v){
    int i = u;
    int j = 2 * i;
    int tmp = list[i];
    while(j <= v){
	if(j < v && list[i] < list[j + 1])
	    j++;
	if(tmp < list[j]){
	    list[i] = list[j];
	    i = j;
	    j = 2 * i;
	}else
	    break;
    }
    list[i] = tmp;
}

void heapSort(int list[], int n){
    int i = 0;
    int tmp = 0;
    int count = 1;
    printf("对序列进行堆排序: \n");
    printf("初始序列为: ");
    printList(list, n);
    for(i = n / 2; i > 0; i--)
	heapAdjust(list, i, n);
    printf("建立的初始堆为: ");
    printList(list, n);
    for(i = n; i > 1; i--){
	//循环,完成堆排序
	tmp = list[1];
	list[1] = list[i];
	list[i] = tmp;  //将第一个元素同当前区间内最后一个元素对换
	heapAdjust(list, 1, i - 1);
	printf("第%d次排序结果: ", count++);
	printList(list, n);
    }

    return;
}
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
