// List.c implementation 
// tue 18-brass/thur 15-kora

// NOTE: this is NOT an ADT in its current configuration

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"



// take a list and insert a new node, containing the value v, at position n
// note: the list is zero indexed. (first node is node 0, second node is node 1 and so on...)
// if n > length of list, insert in last position
void insert_at_n(list l, int n, int v)
{
    link insert = malloc(sizeof(struct _node));
    insert->value = v;
    
    if (n == 0) { // insert at front
        insert->next = l->first;
        l->first = insert;
    } else {
        link curr = l->first;
        link prev = NULL;
        int count = 0;
        while (curr != NULL && count < n) {
            prev = curr;
            curr = curr->next;
            count++;
        }
        // doesn't matter if the while loop ended because we reached the nth
        // position or the end of the list
        prev->next = insert;
        insert->next = curr;
    }
}

