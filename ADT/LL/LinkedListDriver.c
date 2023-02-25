/* LinkedListDriver.c */
/* Driver program for LinkedList */

#include<stdio.h>
#include"LinkedListOps.h"

int main()
{
	HEAD *head;
	head=createList();
	printList(head);
	insertAtHead(head, 20);
	printList(head);
	insertAtHead(head, 30);
	printList(head);
	insertAtTail(head, 25);
	printList(head);
	insertAtTail(head, 35);
	printList(head);
	insertAtPos(head, 2, 50);
	printList(head);
	insertAtPos(head, 6, 100);
	printList(head);
	insertAtPos(head, 5, 200);
	printList(head);
	insertAtPos(head, 0, 501);
	printList(head);
	insertAtPos(head, 0, 1001);
	printList(head);
	insertAfterVal(head, 50, 600);
	printList(head);
	deleteFromHead(head);
	printList(head);
	deleteFromTail(head);
	printList(head);
	deleteFromPos(head,2);
	printList(head);
	deleteFromPos(head,0);
	printList(head);
	deleteFromPos(head,10);
	printList(head);
	deleteVal(head,200);
	printList(head);
	deleteVal(head,30);
	printList(head);
	deleteVal(head,100);
	printList(head);
	return 0;
}
