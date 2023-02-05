/* DLinkedListOps.c */

#include "DLinkedList.h"
#include<stdio.h>
#include<stdlib.h>

DHEAD *createList()
{
	DHEAD *dhead;
	dhead = (DHEAD *) malloc (sizeof(DHEAD));
	dhead->numNodes=0;
	dhead->next=NULL;
	return dhead;
}
void printList(DHEAD *dhead)
{
	DNODE *temp;
	temp = dhead->next;
	printf("\n");
	if(temp==NULL)
		printf("The List is Empty\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%d -->",temp->num);
			temp=temp->next;
		}
	}
}
void insertAtHead(DHEAD *dhead, int val)
{
	DNODE *temp;
	temp=(DNODE *)malloc(sizeof(DNODE));
	temp->num=val;
	temp->next=dhead->next;
	temp->prev=NULL;
	if(dhead->next!=NULL)
		dhead->next->prev=temp;
	dhead->next=temp;
	dhead->numNodes=dhead->numNodes+1;

}
void insertAtTail(DHEAD *dhead, int val)
{
	DNODE *temp, *dnode;
	dnode=(DNODE *)malloc(sizeof(DNODE));
	dnode->num=val;
	dnode->next=NULL;
	temp=dhead->next;
	if(temp==NULL)
	{
		dhead->next=dnode;
		dnode->prev=NULL;
	}
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=dnode;
		dnode->prev=temp;
	}
	dhead->numNodes=dhead->numNodes+1;
}

//??????????????????????????????????
void insertAtPos(DHEAD *dhead, int pos, int val)
{
	if(dhead->numNodes<pos)
		printf("wrong position\n");
	else if(pos==0)
		insertAtHead(dhead,val);
	else
	{	
		DNODE *dnode, *temp;
		dnode=(DNODE *)malloc(sizeof(DNODE));
		dnode->num=val;
		temp=dhead->next;
		for(int var1=0; var1<(pos-1); var1++)
			temp=temp->next;
		dnode->next=temp->next;
		temp->next->prev=dnode; 
		temp->next=dnode;
		dnode->prev=temp;
		dhead->numNodes=dhead->numNodes+1;
	}
}

//????????????????????????????????????
void insertAfterVal(DHEAD *dhead, int val, int newVal)
{
	DNODE *dnode, *temp;
	temp=dhead->next;
	while(temp!=NULL)
	{
		if(temp->num==val)
		{
			dnode=(DNODE *)malloc(sizeof(DNODE));
			dnode->num=newVal;
			dhead->numNodes=dhead->numNodes+1;
			dnode->next=temp->next;
			temp->next=dnode;
			dnode->prev=temp;
			break;
		}	
		temp=temp->next;
	}
	if(temp==NULL)
		printf("Could not find Element\n");
}


int deleteFromHead(DHEAD *dhead)
{
	DNODE *temp;
	int num;
	if(dhead->next==NULL)
	{
		printf("No Element to delete\n");
		return -1;
	}
	temp=dhead->next;
	dhead->next=dhead->next->next;
	if(dhead->next!=NULL)
		dhead->next->prev=NULL;
	dhead->numNodes=dhead->numNodes-1;
	num=temp->num;
	free(temp);
	return num;
}

int deleteFromTail(DHEAD *dhead)
{
	DNODE *temp;
	int num;
	if(dhead->next==NULL)
	{
		printf("No Element to delete\n");
		return -1;
	}
	if(dhead->numNodes==1)
	{
		num=dhead->next->num;
		free(dhead->next);
		dhead->next=NULL;
		dhead->numNodes=0;
	}
	else
	{
		temp=dhead->next;
		while(temp->next->next!=NULL)temp=temp->next;
		num=temp->next->num;
		free(temp->next);
		temp->next=NULL;
		dhead->numNodes=dhead->numNodes-1;
	}
	return num;
}

int deleteFromPos(DHEAD *dhead, int pos)
{
	DNODE *temp, *temp1;
	int i, num;
	if(dhead->next==NULL || dhead->numNodes < (pos+1))
	{
		printf("No Element to delete\n");
		return -1;
	}
	if(pos==0)
	{
		return deleteFromHead(dhead);
	}
	temp=dhead->next;
	for(i=0; i<(pos-1); i++)
		temp=temp->next;
	num=temp->next->num;
	if(temp->next->next!=NULL)
		temp->next->next->prev=temp;
	temp1=temp->next;
	temp->next=temp->next->next;
	free(temp1);
	dhead->numNodes=dhead->numNodes-1;
	return num;
}

int deleteVal(DHEAD *dhead, int val)
{
	DNODE *temp, *temp1;
	int i, num;
	if(dhead->next==NULL)
	{
		printf("No Element to delete\n");
		return -1;
	}
	if(dhead->next->num==val)
	{
		return deleteFromHead(dhead);
	}
	temp=dhead->next;
	while(temp->next!=NULL)
	{
		if(temp->next->num==val)
		{
			temp1=temp->next;
			temp->next=temp->next->next;
			if(temp->next!=NULL)
				temp->next->prev=temp;
			free(temp1);
			dhead->numNodes=dhead->numNodes-1;
			return val;
		}
		temp=temp->next;
	}
	printf("No element to delete\n");
	return -1;
}
