#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"

int main(int argc, char **argv)
{
    SeqStack S;
    int i;
    DataType a[] = {
	'a', 'b', 'c', 'd', 'e', 'f'
    };
    DataType e;
    InitStack(&S);   //初始化栈
    for(i = 0; i < sizeof(a)/sizeof(a[0]); i++){
	if(PushStack(&S, a[i]) == 0){
	    printf("栈已满,不能进栈!\n");
	    return 0;
	}
    }
    printf("依次出栈的元素是:\n");
    if(PopStack(&S, &e) == 1){
	printf("%4c\n", e);
    }
    if(PopStack(&S, &e) == 1){
	printf("%4c\n", e);
    }
    printf("当前栈顶元素是:");
    if(GetTop(S, &e) == 0){
	printf("stack Empty!\n");
	return 0;
    }else{
	printf("%4c\n", e);
    }
    printf("将元素g h依次进栈:\n");
    if(PushStack(&S, 'g') == 0){
	printf("Stack Full!\n");
	return 0;
    }
    if(PushStack(&S, 'h') == 0){
	printf("Stack Full!\n");
	return 0;
    }
    printf("当前栈中元素个数是: %d\n", StackLength(S));
    printf("将栈中元素出栈,出栈的序列是:\n");
    while(!StackEmpty(S)){
	PopStack(&S, &e);
	printf("%4c\n", e);
    }
    printf("\n");
}
