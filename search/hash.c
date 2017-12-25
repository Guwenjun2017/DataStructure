#include<stdio.h>
#include<malloc.h>
#define maxSize 50
#define P 13
#define OK 1
#define ERROR 0
#define DUPLICATE -1
#define TRUE 1
#define FLASE 0

typedef struct{
    int key;	    /*关键字值*/
    int flag;	    /*是否存放元素*/
}ElemType;

typedef struct _HashTable{
    ElemType data[maxSize];
    int count;	    /*元素个数*/
    int sizeindex; /*当前哈系表容量*/
}HashTable;

int d1[15] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14
};
int d2[15] = {
    0, 1, 2*2, -2*2, 3*3, -3*3, 4*4, -4*4, 5*5, -5*5, 6*6, -6*6, 7*7, -7*7
};
void dataset(int ds[], int *len);
int InsertHash(HashTable *H, int e, int d[]);
int CreateHash(HashTable *H, int ds[], int len, int d[]);
void InitHash(HashTable *H);
int SearchHash(HashTable *H, int e, int d[]);
void menu();

void dataset(int ds[], int *len){
    int n,m;
    n = 0;
    printf("查找表输入:\n");
    while(scanf("%d", &m) == 1){
	ds[n] = m;
	n++;
    }
    *len = n;
}
/*计算哈希地址,插入哈系表*/
int InsertHash(HashTable *H, int e, int d[]){
    int k, i = 1;
    k = e % P;
    while(H->data[k].flag == TRUE || k < 0){
	k = (e%P + d[i]) % maxSize;
	i++;
	if(i >= 15)
	    return ERROR;
    }
    H->data[k].key = e;
    H->data[k].flag = TRUE;
    H->count++;

    return OK;
}
/*构造哈希表*/
int CreateHash(HashTable *H, int ds[], int len, int d[]){
    int i;
    for(i = 0; i < len; i++){
	if(SearchHash(H, ds[i], d) != -1)
	    return DUPLICATE;
	InsertHash(H, ds[i], d);
	if(H->count >= maxSize)
	    return ERROR;
    }

    return OK;
}
/*初始化哈希表*/
void InitHash(HashTable *H){
    int i;
    for(i = 0; i < maxSize; i++){
	H->data[i].key = 0;
	H->data[i].flag = FLASE;
    }

    return;
}
/*在哈系表中查找*/
int SearchHash(HashTable *H, int e, int d[]){
    int k, i = 1;
    k = e % P;
    while(H->data[k].key != e){
	k = (e%P + d[i]) % maxSize;
	i++;
	if(i >= 15)
	    return -1;
    }

    return OK;
}
/*菜单*/
void menu(){
    int choice; int *p;
    HashTable h;
    h.count = 0;
    h.sizeindex = maxSize;
    int a[maxSize] = { 0 };
    int i, n, e;
    dataset(a, &n);  //建立查找表
    getchar();
    printf("\n");
    do{
	printf("\n-----哈希查找演示-----\n");
	printf("\n1. 线性探测构造哈希表\n");
	printf("\n2. 二分探测构造哈希表\n");
	printf("\n3. 退出\n");
	printf("\n输入选择>>>: ");
	scanf("%d", choice);
	if(choice == 1)
	    p = d1;
	else if(choice == 2)
	    p = d2;
	else
	    return;
	InitHash(&h);
	if(!(CreateHash(&h, a, n, p)))
	    printf("\n构造哈系表失败.\n");
	else if(i == DUPLICATE)
	    printf("\n哈希表有重复关键字.\n");
	else{
	    printf("哈系表:\n");
	    for(i = 0; i < h.sizeindex; i++)
		printf("%3d", h.data[i].key);
	    printf("\n\n哈希查找\n输入要查找的key值: ");
	    getchar();
	    scanf("%d", &e);
	    if((i = SearchHash(&h, e, p)) == -1)
		printf("\n%d 未找到\n.", e);
	    else
		printf("\n%d 在哈希表中下标为%d\n", e, i);
	}
	getchar();
    }while(1);

}

int main(int argc, char **argv)
{
    menu();

    return 0;
}
