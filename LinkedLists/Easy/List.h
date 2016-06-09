typedef struct _list * List;

/* Given functions */
List createList();
void freeList(List list);
List generateList(int n);

// print out a list
void showList (List list);

/* Open Learning questions */

// count the number of items in the list
int numItems (List l);

// find the value stored at position i
// i MUST be a valid position in the list
// dont call this on positions outside the list
int lookup (List l, int position);

// inset item at the front of the list
void frontInsert (List l, int item);

// insert at end of list
void append (List l, int value);


/* Challenge questions */

// delete node at position
void deleteAtPosition(List list, int position) ;

// reverse the linked list
void reverse(List list);

