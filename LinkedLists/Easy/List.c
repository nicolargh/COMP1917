#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

typedef struct _node * Node;
struct _node {
	int data;
	Node next;
};

// a list is represented by a pointer to a struct which contains 
// a pointer to the first node of the list called the "head"
struct _list {
    Node head;
};     

/* Private funtions */
Node createNode(int data);

/* Questions */

// count the number of items in the list
int numItems (List l) {
    return 0;
}

// find the value stored at position i
// i MUST be a valid position in the list
// dont call this on positions outside the list
int lookup (List l, int position) {
    return 0;
}

// inset item at the front of the list
void frontInsert (List l, int item) {
}

// insert at end of list
void append (List l, int value) {
}

/* Challenge questions */

// delete node at position
void deleteAtPosition(List list, int position) {
}

// reverse the linked list
void reverse(List list) {
}


/* Given function */
List createList() {
    List l = malloc(sizeof(struct _list));
    l->head = NULL;
    return l;
}

void showList(List list) {
    assert(list != NULL);
    Node curr = list->head;
    while (curr != NULL) {
        printf("[%d]->", curr->data);
        curr = curr->next;
    }
    printf("[X]\n");
}

void freeList(List list) {
    assert(list != NULL);
    Node curr = list->head;
    while (curr != NULL) {
        Node temp = curr->next;
        free(curr);
        curr = temp;
    }
    free(list);
}

List generateList(int n) {
    List l = createList();
    if (n >= 0) {
        l->head = createNode(0);
        Node curr = l->head;
        int i = 1;
        while (i <= n) {
            curr->next = createNode(i);
            curr = curr->next;
            i++;
        }
    }
    return l;
}

/* Private functions */
Node createNode(int data) {
    Node n = malloc(sizeof(struct _node));
    n->data = data;
    n->next = NULL;
    return n;
}

