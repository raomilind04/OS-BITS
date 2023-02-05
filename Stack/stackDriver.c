/* StackDriver.c */
/* Driver program for Stack */

#include<stdio.h>
#include"stackOps.h"

int main()
{
	SHEAD *shead;
	shead=createStack(2);
	printStack(shead);
	if(isEmpty(shead)==1) printf("Stack is Empty\n");	
	push(shead, 20);
	printStack(shead);
	push(shead, 30);
	printStack(shead);
	printf("The top value is %d\n",top(shead));
	printf("The poped value is %d\n",pop(shead));
	printf("The top value is %d\n",top(shead));
	printStack(shead);
	printf("The poped value is %d\n",pop(shead));
	printStack(shead);
	printf("The poped value is %d\n",pop(shead));
	printf("The top value is %d\n",top(shead));

	return 0;
}
