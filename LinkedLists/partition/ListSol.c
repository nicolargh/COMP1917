// partition.c
// gcc -Wall -Werror -std=c99 -O -o testPartition testList.c list.c

//OR for gdb debugging use
// gcc -Wall -Werror -std=c99 -gdwarf-2 -o testPartition testList.c list.c
     
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
     
#include "List.h"
     
// given a list of integers and an integer key, write a function which 
// finds all the integers in the list that are smaller than the first element 
// and moves them to the beginning of the list. 

// So if the original list is        10->55->66->4->X, 
// the list should be modified to be  4->10->55->66->X

// If the original list is 10->4->1->X
// the list should be modified to be 4->1->10->X

// If the original list is    10->55->3->9->10->89->1->11->X, 
// the modified list would be 3->9->1->10->55->10->89->11->X

// If the original list is empty it should remain unmodified

// Constraints:
// don't delete any nodes (i.e. do not call free())
// don't create any new structs (i.e. do not call malloc())
// the nodes that are smaller and moved to the front should remain in their original relative order
// the nodes that are greater than or equal should remain in their original relative order
     
void partition (list sourceList) {
    if (sourceList == NULL || sourceList->head == NULL) {
        return;
    }
    int key = sourceList->head->value;
    link curr = sourceList->head->next;
    link prev = sourceList->head;
    link frontPrev = NULL;
    while (curr != NULL) {
        if (curr->value < key) {
            prev->next = curr->next;
            if (frontPrev == NULL) {
                curr->next = sourceList->head;
                sourceList->head = curr;
            } else {
                curr->next = frontPrev->next;
                frontPrev->next = curr;
            }
            frontPrev = curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}
