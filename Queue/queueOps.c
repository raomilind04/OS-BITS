/* queueOps.c */

#include "queue.h"
#include<stdio.h>
#include<stdlib.h>

QHEAD *createQueue(int maxSize)
{
	QHEAD *qhead;
	qhead=(QHEAD *)malloc(sizeof(QHEAD));
	qhead->numNodes=0;
	qhead->maxSize=maxSize;
	qhead->next=NULL;
	return qhead;
}
int isEmpty(QHEAD *qhead)
{
	if(qhead->next==NULL) return 1;
	else return 0;
}

int isFull(QHEAD *qhead)
{
	if(qhead->numNodes==qhead->maxSize) return 1;
	else return 0;
}
int frontQ(QHEAD *qhead)
{
	QNODE *temp;
	if(isEmpty(qhead))
		return -1;
	else
	{
		temp=qhead->next;
		while(temp->next!=NULL)
			temp=temp->next;
		return temp->num;		
	}
}
void addQ(QHEAD *qhead, int val)
{
	QNODE *qnode;
	if(isFull(qhead))
		printf("The Queue is Full\n");
	else
	{
		qnode=(QNODE *)malloc(sizeof(QNODE));
		qnode->num=val;
		qnode->next=qhead->next;
		qhead->next=qnode;
		qhead->numNodes=qhead->numNodes+1;
	}
}
int deleteQ(QHEAD *qhead)
{
	QNODE *temp;
	int num;
	if(isEmpty(qhead))
	{
		printf("No element to delete\n");
		return -1;
	}
	else if(qhead->next->next==NULL)
	{
		num=qhead->next->num;
		free(qhead->next);
		qhead->next=NULL;
		qhead->numNodes=0;
		return num;
	}
	else
	{
		temp=qhead->next;
		while(temp->next->next!=NULL)
			temp=temp->next;
		num=temp->next->num;
		free(temp->next);
		temp->next=NULL;
		return num;
	}
}	
void printQueue(QHEAD *qhead)
{
	QNODE *temp;
	temp=qhead->next;
	if(temp==NULL)
		printf("Queue is Empty\n");
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
