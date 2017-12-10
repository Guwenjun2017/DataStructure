#include<stdio.h>
#include<stdlib.h>
#include "LinkStack.h"

int main(int argc, char **argv)
{
   LinkStack *LS = (LinkStack *)malloc(sizeof(LinkStack));
   DataType head;

   InitStack(LS);

   printf("将1 2 3 4 5依次入栈:\n");
   PushStack(LS, 1);
   PushStack(LS, 2);
   PushStack(LS, 3);
   PushStack(LS, 4);
   PushStack(LS, 5);
   GetHead(LS, &head);
   printf("此时的栈顶元素是: %d\n", head);
   PopStack(LS, &head);
   printf("将栈顶元素出栈,它是: %d\n", head);
   GetHead(LS, &head);
   printf("此时的栈顶元素是: %d\n", head);

   printf("此时的栈长为: %d\n", GetLength_LinkStack(LS));
   Clear_LinkStack(LS);
   printf("此时的栈长为: %d\n", GetLength_LinkStack(LS));

}
