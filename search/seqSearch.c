#include<stdio.h>

int seqSearch(int *a, int length, int value, int *count);
int main(int argc, char **argv){
    int a[] = {
        12, 76, 29, 15, 62, 35, 33, 89, 48, 20,
    };
    int count = 0;
    int size = sizeof(a) / sizeof(int);
    int result = seqSearch(a, size, 35, &count);
    printf("在列表[12, 76, 29, 15, 62, 35, 33, 89, 48, 20]中查找元素'35':\n");
    printf("Index: %d\n", result);
    printf("Count:%d\n", count);
}

int seqSearch(int *a, int length, int value, int *count){
    for(int i = 0; i  < length; i++){
	(*count)++;
	if(value == a[i])
	    return i;
    }

    return -1;
}
