/* DLinkedListOps.h */

#include "DLinkedList.h"

extern DHEAD *createList();
extern void printList(DHEAD *dhead);
extern void insertAtHead(DHEAD *dhead, int val);
extern void insertAtTail(DHEAD *dhead, int val);
extern void insertAtPos(DHEAD *dhead, int pos, int val);
extern void insertAfterVal(DHEAD *dhead, int val, int newVal);
extern int deleteFromHead(DHEAD *dhead);
extern int deleteFromTail(DHEAD *dhead);
extern int deleteFromPos(DHEAD *dhead, int pos);
extern int deleteVal(DHEAD *dhead, int val);

