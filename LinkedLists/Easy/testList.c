#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "List.h"

void testFrontInsert();
void testNumItems();
void testAppend();
void testLookup();
void testDeleteAtPos();
void testReverse();

int main (void) {

    /* Open Learning questions */
    testNumItems();
    testLookup();
    testFrontInsert();
    testAppend();


    /* Challenge questions */
    testDeleteAtPos();
    testReverse();
    
    printf("All tests passed, you are awesome!\n");
    return EXIT_SUCCESS;
}

void testNumItems() {
    printf("Testing numItems: \n");
    List list1 = createList();
    printf("   Counting items in list of length 0:\n");
    printf("   List is: \n");
    showList(list1);
    assert(numItems(list1) == 0);
    printf("   0 elements counted!\n");
    freeList(list1);

    List list2 = generateList(0);
    printf("   Counting items in list of length 1:\n");
    printf("   List is: \n");
    showList(list2);
    assert(numItems(list2) == 1);
    printf("   1 elements counted!\n");
    freeList(list2);
   
    List list3 = generateList(1);
    printf("   Counting items in list of length 2:\n");
    printf("   List is: \n");
    showList(list2);
    assert(numItems(list3) == 2);
    printf("   2 elements counted!\n");
    freeList(list3);
    
    List list4 = generateList(9);
    printf("   Counting items in list of length 10:\n");
    printf("   List is: \n");
    showList(list4);
    assert(numItems(list4) == 10);
    printf("   10 elements counted!\n");
    freeList(list4);
    
    printf("Passed all frontInsert tests!\n\n");
    
}

void testLookup() {
    printf("Testing lookup: \n");
    List list1 = generateList(0);
    printf("   Looking up position 0 in list of length 1:\n");
    printf("   List is: \n");
    showList(list1);
    assert(lookup(list1, 0) == 0);
    printf("   0 found at position 0!\n");
    freeList(list1);
    
    List list2 = generateList(1);
    printf("   Looking up position 0 and 1 in list of length 2:\n");
    printf("   List is: \n");
    showList(list2);
    assert(lookup(list2, 0) == 0);
    printf("   0 found at position 0!\n");
    assert(lookup(list2, 1) == 1);
    printf("   1 found at position 1!\n");
    freeList(list2);
    
    List list3 = generateList(9);
    printf("   Looking up all positions in list of length 10:\n");
    printf("   List is: \n");
    showList(list3);
    int i;
    for (i = 0; i < 10; i++) {
        assert(lookup(list1, i) == i);
    }
    printf("   All lookups found!\n");
    freeList(list3);

    printf("Passed all lookup tests!\n\n");

}

void testFrontInsert() {
    printf("Testing front Insert: \n");
    List list1 = createList();
    printf("   List is now: \n");
    showList(list1);
    
    printf("   Inserting item at the front of empty list:\n");
    frontInsert(list1, 0);
    printf("   List is now: \n");
    showList(list1);
    assert(lookup(list1, 0) == 0);
    assert(numItems(list1) == 1);
    printf("   Inserted at the front of an empty list!\n");

    printf("   Inserting item at the front of list of length 1:\n");
    frontInsert(list1, 1);
    printf("   List is now: \n");
    showList(list1);
    assert(lookup(list1, 0) == 1);
    assert(lookup(list1, 1) == 0);
    assert(numItems(list1) == 2);
    printf("   Inserted at the front of a list of length 1!\n");

    printf("   Inserting 10 items at the front:\n");
    int i;
    for (i = 2; i < 12; i++) {
        frontInsert(list1, i);
    }
    printf("   List is now: \n");
    showList(list1);
    for (i = 0; i < 12; i++) {
        assert(lookup(list1, i) == 11-i);
    }
    assert(numItems(list1) == 12);
    printf("   Inserted 10 items at the front!\n");
    free(list1);

    printf("Passed all frontInsert tests!\n\n");

}

void testAppend() {
    printf("Testing append: \n");
    List list1 = createList();
    printf("   List is now: \n");
    showList(list1);
    
    printf("   Appending item to empty list:\n");
    append(list1, 0);
    printf("   List is now: \n");
    showList(list1);
    assert(lookup(list1, 0) == 0);
    assert(numItems(list1) == 1);
    printf("   Appended item to empty list!\n");

    printf("   Appending item to list of length 1:\n");
    append(list1, 1);
    printf("   List is now: \n");
    showList(list1);
    assert(lookup(list1, 0) == 0);
    assert(lookup(list1, 1) == 1);
    assert(numItems(list1) == 2);
    printf("   Appended item to list of length 1!\n");

    printf("   Appending 10 items:\n");
    int i;
    for (i = 2; i < 12; i++) {
        append(list1, i);
    }
    printf("   List is now: \n");
    showList(list1);
    for (i = 0; i < 12; i++) {
        assert(lookup(list1, i) == i);
    }
    assert(numItems(list1) == 12);
    printf("   Appended 10 items!\n");
    free(list1);

    printf("Passed all append tests!\n\n");

}

void testDeleteAtPos(){
    printf("Testing delete at position: \n");
    List list1 = generateList(10);
    int i;
    for(i = 0; i < 11; i++) {
        assert(lookup(list1, i) == i);
    }
    assert(numItems(list1) == 11);
    printf("   Set up complete. List is: \n");
    showList(list1);
    printf("   Deleting first element: \n");
    deleteAtPosition(list1, 0);
    printf("   List is now: \n");
    showList(list1);
    for(i = 0; i < 10; i++) {
        assert(lookup(list1, i) == i+1);
    }
    assert(numItems(list1) == 10);
    printf("   First element deleted!\n");

    printf("   Deleting last element: \n");
    deleteAtPosition(list1, 9);
    printf("   List is now: \n");
    showList(list1);
    for(i = 0; i < 9; i++) {
        assert(lookup(list1, i) == i+1);
    }
    assert(numItems(list1) == 9);
    printf("   Last element deleted!\n");

    printf("   Deleting middle element: \n");
    deleteAtPosition(list1, 4);
    printf("   List is now: \n");
    showList(list1);
    for(i = 0; i < 8; i++) {
        if (i<4){
            assert(lookup(list1, i) == i+1);
        } else {
            assert(lookup(list1, i) == i+2);
        } 
    }
    assert(numItems(list1) == 8);
    printf("   Middle element deleted!\n");
    
    
    printf("   Deleting until 1 element is left: \n");
    for(i = 0; i < 7; i++) {
        deleteAtPosition(list1, 1);
    }
    printf("   List is now: \n");
    showList(list1);
    assert(lookup(list1, 0) == 1);
    assert(numItems(list1) == 1);
    printf("   All elements but 1 element deleted!\n");

    printf("   Deleting last element: \n");
    deleteAtPosition(list1, 0);
    printf("   List is now: \n");
    showList(list1);
    assert(numItems(list1) ==  0);
    printf("   Last element deleted!\n");
    
    printf("Passed all deleteAtPosition tests!\n\n");
}

void testReverse() {
    printf("Testing reverse: \n");
    
    printf("   Reversing an empty list: \n");
    List list1 = generateList(-1);
    printf("   List before: \n");
    showList(list1);
    reverse(list1);
    printf("   List after: \n");
    showList(list1);
    assert(numItems(list1) ==  0);
    printf("   Reversed an empty list!\n");

    printf("   Reversing a list with one item: \n");
    List list2 = generateList(0);
    printf("   List before: \n");
    showList(list2);
    reverse(list2);
    printf("   List after: \n");
    showList(list2);
    assert(lookup(list2, 0) == 0);
    assert(numItems(list2) == 1);
    printf("   Reversed a list with 2!\n");
    free(list2);

    printf("   Reversing a list with two items: \n");
    List list3 = generateList(1);
    printf("   List before: \n");
    showList(list3);
    reverse(list3);
    printf("   List after: \n");
    showList(list3);
    int i;
    for(i=0; i<2; i++) {
        assert(lookup(list3, i) == 1-i);
    }
    assert(numItems(list3) == 2);
    printf("   Reversed a list with 2 items!\n");
    free(list3);

    printf("   Reversing a list with 100 items!! \n");
    List list4 = generateList(99);
    printf("   List before: \n");
    showList(list4);
    reverse(list4);
    printf("   List after: \n");
    showList(list4);
    for(i=0; i<100; i++) {
        assert(lookup(list4, i) == 99-i);
    }
    assert(numItems(list4) == 100);
    printf("   Reversed a list with 100 items!!\n\n");


    printf("Passed all reverse tests!\n\n");
}
    
