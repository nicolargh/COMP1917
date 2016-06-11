#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


#include "List.h"

static void print_list(list l);

void test_insert_at_n(void);

int main(int argc, char* argv[])
{

    printf("Testing lists...\n------------------------------------------------\n");

    test_insert_at_n();
    //test_odd_and_even();

    printf("------------------------------------------------\n>>> All tests PASSED!\n");
    return EXIT_SUCCESS;
}


void test_insert_at_n(void)
{
    printf("Testing insert_at_n()...");
    //printf("Testing insertion into an empty list...\n");

    // create list(s) and node(s) for test(s).
    list l1 = malloc(sizeof(struct _list));
    assert(l1 != NULL);
    l1->first = NULL;
    l1->size = -1;

    insert_at_n(l1, 0, 1);
    assert(l1->first->value == 1);
    insert_at_n(l1, 1, 3);
    assert(l1->first->next->value == 3);
    insert_at_n(l1, 10, 42);
    assert(l1->first->next->next->value == 42);
    insert_at_n(l1, 0, -1);
    assert(l1->first->value == -1);
    insert_at_n(l1, 1, -2);
    assert(l1->first->next->value == -2);
    insert_at_n(l1, 3, -10);
    assert(l1->first->next->next->next->value == -10);


    // cleaning up - keep australia beautiful~~~
    link del_cur = l1->first;
    l1->first = NULL;
    link del_prev;
    while(del_cur != NULL){
        del_prev = del_cur;
        del_cur = del_cur->next;
        del_prev->next = NULL;
        free(del_prev);
    }

    free(l1);

    printf("PASSED.\n");

}

static void print_list(list l)
{
    assert(l != NULL);

    link curr = l->first;

    while(curr != NULL){
        printf("[%d]->", curr->value);
        curr = curr->next;
    }
    printf("[X]\n");
}
