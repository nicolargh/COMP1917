// For the purposes of abstraction, we only put the typedef for the struct in
// the .h file. The actual contents of the struct goes in the .c to 'hide' it
// from the person who wants to use it.
typedef struct node_* Node;

// Creates a new node with whatever data the user pleases.
Node newNode(int number);

// Deletes a given Node and only that node. Deleting a single node may corrupt
// a list.
void deleteNode(Node node);

// Print out a single node, or 'X' if NULL is given.
void printNode(Node node);

// Join two nodes together. This is done by arranging pointers.
void join(Node first, Node second);

// Print out the entire list, starting from the node given.
void printList(Node start);

// Delete the list from the node given onwards.
void deleteList(Node start);
