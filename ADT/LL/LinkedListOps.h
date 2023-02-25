/* LinkedListOps.h */

#include "LinkedList.h"

extern HEAD *createList();
extern void printList(HEAD *head);
extern void insertAtHead(HEAD *head, int val);
extern void insertAtTail(HEAD *head, int val);
extern void insertAtPos(HEAD *head, int pos, int val);
extern void insertAfterVal(HEAD *head, int val, int newVal);
extern int deleteFromHead(HEAD *head);
extern int deleteFromTail(HEAD *head);
extern int deleteFromPos(HEAD *head, int pos);
extern int deleteVal(HEAD *head, int val);

