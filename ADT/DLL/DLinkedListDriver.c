/* DLinkedListDriver.c */
/* Driver program for DLinkedList */

#include<stdio.h>
#include"DLinkedListOps.h"

int main()
{
	DHEAD *dhead;
	dhead=createList();
	printList(dhead);
	insertAtHead(dhead, 20);
	printList(dhead);
	insertAtHead(dhead, 30);
	printList(dhead);
	insertAtTail(dhead, 25);
	printList(dhead);
	insertAtTail(dhead, 35);
	printList(dhead);
	insertAtPos(dhead, 3, 200);
	printList(dhead);
	printf("\n"); 
	DNODE* temp = dhead -> next ; 
	for(int i = 0 ; i < 3 ; i++){
		temp = temp -> next ; 
	}
	printf("curr element : %d \n" , temp->next->num); 
	printf("prev element : %d \n" , temp->next->prev->num); 
	insertAtPos(dhead, 0, 501);
	printList(dhead);
	insertAtPos(dhead, 0, 1001);
	printList(dhead);
	insertAfterVal(dhead, 50, 600);
	printList(dhead);
	deleteFromHead(dhead);
	printList(dhead);
	deleteFromTail(dhead);
	printList(dhead);
	deleteFromPos(dhead,2);
	printList(dhead);
	deleteFromPos(dhead,0);
	printList(dhead);
	deleteFromPos(dhead,10);
	printList(dhead);
	deleteVal(dhead,200);
	printList(dhead);
	deleteVal(dhead,30);
	printList(dhead);
	deleteVal(dhead,100);
	printList(dhead);
	return 0;
}
