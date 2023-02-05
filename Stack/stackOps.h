/* stackOps.h */

#include "stack.h"

extern SHEAD *createStack(int maxSize);
extern int isEmpty(SHEAD *shead);
extern int isFull(SHEAD *shead);
extern int top(SHEAD *shead);
extern void push(SHEAD *shead, int val);
extern int pop(SHEAD *shead);
extern void printStack(SHEAD *shead);
