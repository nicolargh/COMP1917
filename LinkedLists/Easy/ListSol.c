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
    assert(l != NULL);
    Node curr = l->head;
    int count = 0;
    while(curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

// find the value stored at position i
// i MUST be a valid position in the list
// dont call this on positions outside the list
int lookup (List l, int position) {
    assert(l != NULL);
    Node curr = l->head;
    int i = 0;
    while (i < position) {
        assert(curr != NULL);
        curr = curr->next;
        i++;
    }
    return curr->data;
}

// inset item at the front of the list
void frontInsert (List l, int item) {
    assert(l != NULL);
    Node n = createNode(item);
    n->next = l->head;
    l->head = n;
}

// insert at end of list
void append (List l, int value) {
    assert(l != NULL);
    Node n = createNode(value);
    Node curr = l->head;
    if (curr == NULL) {
        l->head = n;
    } else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = n;
    }
}

/* Challenge questions */

// delete node at position
void deleteAtPosition(List list, int position) {
    assert(list != NULL);
    int i = 0;
    Node curr = list->head;
    if (position == 0) {
        Node newHead = list->head->next;
        free(list->head);
        list->head = newHead;
    } else {
        while (i < position-1) {
            curr = curr->next;
            i++;
        }
        Node next = curr->next->next;
        free(curr->next);
        curr->next = next;
    }
}

// reverse the linked list
void reverse(List list) {
    assert(list != NULL);
    Node curr = list->head;
    Node prev = NULL;
    if (curr == NULL || curr->next == NULL) {
        return;
    }
    while (curr != NULL) {
        Node next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
  
    list->head = prev;

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

