/* LinkedListOps.c */

#include "LinkedList.h"
#include<stdio.h>
#include<stdlib.h>

HEAD *createList()
{
	HEAD *head;
	head = (HEAD *) malloc (sizeof(HEAD));
//	head->numNodes=0;
	(*head).numNodes=0;	
	head->next=NULL;
	return head;
}
void printList(HEAD *head)
{
	NODE *temp;
	temp = head->next;
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
void insertAtHead(HEAD *head, int val)
{
	NODE *temp;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->num=val;
	temp->next=head->next;
	head->next=temp;
	head->numNodes=head->numNodes+1;
}
void insertAtTail(HEAD *head, int val)
{
	NODE *temp, *node;
	node=(NODE *)malloc(sizeof(NODE));
	node->num=val;
	node->next=NULL;
	temp=head->next;
	if(temp==NULL) head->next=node;
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=node;
	}
	head->numNodes=head->numNodes+1;
}

void insertAtPos(HEAD *head, int pos, int val)
{
	if(head->numNodes<pos)
		printf("wrong position\n");
	else if(pos==0)
		insertAtHead(head,val);
	else
	{	
		NODE *node, *temp;
		node=(NODE *)malloc(sizeof(NODE));
		node->num=val;
		temp=head->next;
		for(int var1=0; var1<(pos-1); var1++)
			temp=temp->next;
		node->next=temp->next;
		temp->next=node;
		head->numNodes=head->numNodes+1;
	}
}


void insertAfterVal(HEAD *head, int val, int newVal)
{
	NODE *node, *temp;
	temp=head->next;
	while(temp!=NULL)
	{
		if(temp->num==val)
		{
			node=(NODE *)malloc(sizeof(NODE));
			node->num=newVal;
			head->numNodes=head->numNodes+1;
			node->next=temp->next;
			temp->next=node;
			break;
		}	
		temp=temp->next;
	}
	if(temp==NULL)
		printf("Could not find Element\n");
}


int deleteFromHead(HEAD *head)
{
	NODE *temp;
	int num;
	if(head->next==NULL)
	{
		printf("No Element to delete\n");
		return -1;
	}
	temp=head->next;
	head->next=head->next->next;
	head->numNodes=head->numNodes-1;
	num=temp->num;
	free(temp);
	return num;
}

int deleteFromTail(HEAD *head)
{
	NODE *temp;
	int num;
	if(head->next==NULL)
	{
		printf("No Element to delete\n");
		return -1;
	}
	if(head->numNodes==1)
	{
		num=head->next->num;
		free(head->next);
		head->next=NULL;
		head->numNodes=0;
	}
	else
	{
		temp=head->next;
		while(temp->next->next!=NULL)temp=temp->next;
		num=temp->next->num;
		free(temp->next);
		temp->next=NULL;
		head->numNodes=head->numNodes-1;
	}
	return num;
}

int deleteFromPos(HEAD *head, int pos)
{
	NODE *temp, *temp1;
	int i, num;
	if(head->next==NULL || head->numNodes < (pos+1))
	{
		printf("No Element to delete\n");
		return -1;
	}
	if(pos==0)
	{
		return deleteFromHead(head);
	}
	temp=head->next;
	for(i=0; i<(pos-1); i++)
		temp=temp->next;
	num=temp->next->num;
	temp1=temp->next;
	temp->next=temp->next->next;
	free(temp1);
	head->numNodes=head->numNodes-1;
	return num;
}

int deleteVal(HEAD *head, int val)
{
	NODE *temp, *temp1;
	int i, num;
	if(head->next==NULL)
	{
		printf("No Element to delete\n");
		return -1;
	}
	if(head->next->num==val)
	{
		return deleteFromHead(head);
	}
	temp=head->next;
	while(temp->next!=NULL)
	{
		if(temp->next->num==val)
		{
			temp1=temp->next;
			temp->next=temp->next->next;
			free(temp1);
			head->numNodes=head->numNodes-1;
			return val;
		}
		temp=temp->next;
	}
	printf("No element to delete\n");
	return -1;

}
