#include <stdlib.h>
#include <stdio.h>

#include "List.h"

struct node_ {
    int number;
    Node next;
};

Node newNode(int number) {
    Node node = malloc (sizeof(struct node_));
    node->number = number;
    node->next = NULL;
    return node;
}

void deleteNode(Node node) {
    free(node);
}

void printNode(Node node) {
    printf("[%d] ", node->number);
}

void join(Node first, Node second) {
    first->next = second;
}

void printList(Node start) {
    Node node = start;
    while (node != NULL) {
        printNode(node);
        printf("=> ");
        node = node->next;
    }
    printf("[X]\n");
}

void deleteList(Node start) {
    Node node = start;
    while (node != NULL) {
        Node next = node->next;
        deleteNode(node);
        node = next;
    }
}
