#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"
 
typedef struct _node {
    char value;
    Node next;
} node;
 
typedef struct _list {
    Node head;
} list;
 
 
//TODO
//Read List.h to help you look at the hints
//remove values which are uppercase
//
//given a list X
//(Empty List)
//then removeUpperCase(list);
//the list is still X
//
//given a list a->X
//then removeUpperCase(list);
//the list is a->X
//
//given a list A->X
//then removeUpperCase(list);
//the list is X
//
//given a list A->a->X
//then removeUpperCase(list);
//the list is a->X
//
//given a list C->a->A->D->X
//then removeUpperCase(list);
//the list is a->X
//
//given a list A->a->B->b->C->c->d->D->E->e->X
//then removeUpperCase(list);
//the list is a->b->c->d->e->X
void removeUpperCase(List l) {
   ////////////////////
   //TODO
}
 
//returns a new list of length 0
List newList() {
   List l = malloc(sizeof(list));
   assert ( l!=NULL );
   l->head = NULL;
   return l;
}
 
//frees everything malloced for the list
void destroy(List l) {
   Node curNode = l->head;
   Node prevNode = NULL;
 
   while (curNode != NULL) {
     prevNode = curNode;
     curNode = prevNode->next;
     free(prevNode);
   }
 
   free(l);
}
 
//appends a node of value to the end of the list
void append(List l, char value) {
   Node newNode = malloc(sizeof(node));
   newNode->value = value;
   newNode->next = NULL;
   Node curNode = l->head;
   if ( curNode==NULL ) {
      l->head = newNode;
   } else {
      while ( curNode->next!=NULL ) {
         curNode = curNode->next;
      }
      curNode->next = newNode;
   }
}
 
//returns the int value of the node at index
//assumes input index is within range of the list's length
char getValue(List l, int index) {
 
   Node curNode = l->head;
   assert (curNode!=NULL);
   int counter = 0;
   while (counter<index) {
      curNode = curNode->next;
      counter++;
   }
   return curNode->value;
}

