// List.h

#define TRUE 1
#define FALSE 0

// node struct and link typedef
// these are the nodes in our list 
typedef struct _node *link; 

typedef struct _node { 
    int value; 
    link next; 
} node;


typedef struct _list *list;

struct _list { 
    link first;
    int size;
} ;


//#########################################################################
//				YOUR TASK(S)
//#########################################################################

/*
	NOTE - you should not be simply copying values around, 
	these exercises should be completed using pointer manipulation
*/


// take a list and insert a new node, containing the value v, at position n
// note: the list is zero indexed. (first node is node 0, second node is node 1 and so on...)
// n will be >= 0, but n may not be < list length. in that case, the new node will be placed at the end of the list
void insert_at_n(list l, int n, int v);

