/* queueDriver.c */
/* Driver program for queue */

#include<stdio.h>
#include"queueOps.h"

int main()
{
	QHEAD *qhead;
	qhead=createQueue(2);
	printQueue(qhead);
	if(isEmpty(qhead)==1) printf("Queue is Empty\n");	
	addQ(qhead, 20);
	printQueue(qhead);
	addQ(qhead, 30);
	printQueue(qhead);
	printf("The front value is %d\n",frontQ(qhead));
	printf("The deleteQ value is %d\n",deleteQ(qhead));
	printf("The front value is %d\n",frontQ(qhead));
	printQueue(qhead);
	printf("The deleteQ value is %d\n",deleteQ(qhead));
	printQueue(qhead);
	printf("The deleteQ value is %d\n",deleteQ(qhead));
	printf("The front value is %d\n",frontQ(qhead));

	return 0;
}
