/* stack.h */

/* NODE */
struct stack_list
{
	int num;
	struct stack_list *next;
};
typedef struct stack_list SNODE;

/* HEAD */
typedef struct
{
	int numNodes;
	int maxSize;
	SNODE *next;
}SHEAD;
