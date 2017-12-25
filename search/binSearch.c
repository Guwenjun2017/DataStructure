#include<stdio.h>

int binSearch(int *, int, int, int *);

int main(int argc, char **argv){
    int count = 0;
    int a[] = {
	8, 15, 19, 26, 33, 41, 47, 52, 64, 90,
    };
    int size = sizeof(a) / sizeof(int);
    int result = binSearch(a, size, 41, &count);
    printf("在列表[8, 15, 19, 26, 33, 41, 47, 52, 64, 90] 中查找元素'41':\n");
    //printf("在列表[12, 76, 29, 15, 62, 35, 33, 89, 48, 20]中查找元素'35':\n");
    printf("Index: %d\n", result);
    printf("Count: %d\n", count);
}

int binSearch(int *a, int length, int value, int *count){
    int low = 0;
    int high = length - 1;
    int mid = 0;
    int find = 0;
    while((low <= high) && (!find)){
	mid = (low + high) / 2;
	if(value == a[mid]){
	    find = 1;
	    break;
	}else{
	    if(value > a[mid]){
		low = mid + 1;
	    }else{
		high = mid - 1;
	    }
	}
	(*count)++;
    }

    if(find){
	return mid;
    }else{
	return -1;
    }
}
