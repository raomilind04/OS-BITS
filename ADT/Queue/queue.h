/* queue.h */

/* NODE */
struct queue_list
{
	int num;
	struct queue_list *next;
};
typedef struct queue_list QNODE;

/* HEAD */
typedef struct
{
	int numNodes;
	int maxSize;
	QNODE *next;
}QHEAD;
