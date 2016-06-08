#include <stdio.h>
#include <stdlib.h>

#include "List.h"

int main(void) {
    // I can create a single node in the list with "21" as the data
    Node myNode = newNode(21);
    // I can only print out this node
    printNode(myNode);
    printf("\n");
    // I want another node, this time with "456" in it.
    Node node2 = newNode(456);
    // Join these two nodes together. We now have a linked list!
    join(myNode, node2);
    // I want to print the whole list this time, not just my node
    printList(myNode); 
    // I'm done with this list, so I should delete it.
    deleteList(myNode);

    // Let's showcase the power of linked lists!
    printf("Enter a number: ");
    int number;
    scanf("%d", &number);
    
    Node start = newNode(0);
    Node curr = start;
    int counter = 1;
    while (counter < number) {
        Node next = newNode(counter);
        join(curr, next);
        curr = next;
        counter++;
    }
    // You now have a list with that number of nodes!
    printList(start);

    return EXIT_SUCCESS;
}
