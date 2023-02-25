/* LinkedList.h */

/* NODE */
struct linked_list
{
	int num;
	struct linked_list *next;
};
typedef struct linked_list NODE;

/* HEAD */
typedef struct
{
	int numNodes;
	NODE *next;
}HEAD;
