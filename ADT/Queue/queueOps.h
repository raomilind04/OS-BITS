/* queueOps.h */

#include "queue.h"

extern QHEAD *createQueue(int maxSize);
extern int isEmpty(QHEAD *qhead);
extern int isFull(QHEAD *qhead);
extern int frontQ(QHEAD *qhead);
extern void addQ(QHEAD *qhead, int val);
extern int deleteQ(QHEAD *qhead);
extern void printQueue(QHEAD *qhead);
