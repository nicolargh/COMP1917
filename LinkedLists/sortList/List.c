// partition.c
// gcc -Wall -Werror -std=c99 -O -o testPartition testPartition.c partition.c

//OR for gdb debugging use
// gcc -Wall -Werror -std=c99 -gdwarf-2 -o testPartition testPartition.c partition.c
     
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
     
#include "List.h"
     
// given a list of integers, sort the list in ascending order.

// The easiest way to implement this is to compare two nodes, and if
// the left is bigger than the right, swap the two of them.

// So if the original list is        5->4->3->2->X, 
// the list should be modified to be  2->3->4->5->X

// If the original list is 1->2->3->X
// the list should remain unmodified

// If the original list is 1->X
// the list should should remain unmodified

// If the original list is empty it should remain unmodified

// Constraints:
// don't delete any nodes (i.e. do not call free())
// don't create any new structs (i.e. do not call malloc())
     
void sortList (list l) {

}
