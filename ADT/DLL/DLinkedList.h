/* DLinkedList.h */

/* DNODE */
struct dlinked_list
{
	struct dlinked_list *prev;
	int num;
	struct dlinked_list *next;
};
typedef struct dlinked_list DNODE;

/* DHEAD */
typedef struct
{
	int numNodes;
	DNODE *next;
}DHEAD;
