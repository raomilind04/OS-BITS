/* stackOps.c */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

SHEAD *createStack(int maxSize)
{
	SHEAD *shead;
	shead=(SHEAD *)malloc(sizeof(SHEAD));
	shead->numNodes=0;
	shead->maxSize=maxSize;
	shead->next=NULL;
	return shead;
}

int isEmpty(SHEAD *shead)
{
	if(shead->next==NULL)
		return 1;
	else
		return 0;
}

int isFull(SHEAD *shead)
{
	if(shead->numNodes==shead->maxSize)
		return 1;
	else
		return 0;
}

int top(SHEAD *shead)
{
	if(shead->next==NULL)
		return -1;
	else
		return shead->next->num;
}

void push(SHEAD *shead, int val)
{
	if(isFull(shead))
		printf("The Stack is Full. Can't add New nodes\n");
	else
	{
		SNODE *snode;
		snode=(SNODE *)malloc(sizeof(SNODE));
		snode->num=val;
		snode->next=shead->next;
		shead->next=snode;
		shead->numNodes=shead->numNodes+1;
	}
}

int pop(SHEAD *shead)
{
	SNODE *snode;
	int num;
	if(isEmpty(shead))
	{
		printf("No element to POP\n");
		return -1;
	}
	else
	{
		snode=shead->next;
		shead->next=shead->next->next;
		shead->numNodes=shead->numNodes-1;
		num=snode->num;
		free(snode);
		return num;
	}
}

void printStack(SHEAD *shead)
{
	SNODE *temp;
	temp=shead->next;
	if(temp==NULL)
		printf("Stack is Empty\n");
	else
	{
		printf("\n");
		while(temp!=NULL)
		{
			printf("%d --> ",temp->num);
			temp=temp->next;
		}
	}
}
