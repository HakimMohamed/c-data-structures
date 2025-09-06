#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_create_list_and_node() {
    SLL* list = sll_create();
    assert(list != NULL);
    assert(list->head == NULL);
    sll_free(list);
}

void test_add_head() {
    SLL* list = sll_create();
    sll_add_head(list, 10);
    assert(sll_get(list, 0) == 10);
    sll_add_head(list, 20);
    assert(sll_get(list, 0) == 20);
    assert(sll_get(list, 1) == 10);
    assert(sll_get(list, 2) == -1);
    sll_free(list);
}

void test_add_tail() {
    SLL* list = sll_create();
    sll_add_tail(list, 10);
    assert(sll_get(list, 0) == 10);
    sll_add_tail(list, 20);
    assert(sll_get(list, 1) == 20);
    sll_add_head(list, 5);
    assert(sll_get(list, 2) == 20);
    sll_free(list);
}

void test_add_at_index() {
    SLL* list = sll_create();
    sll_add_tail(list, 10);
    sll_add_tail(list, 20);
    sll_add_at_index(list, 1, 15);
    assert(sll_get(list, 0) == 10);
    assert(sll_get(list, 1) == 15);
    assert(sll_get(list, 2) == 20);
    sll_add_at_index(list, 0, 5); 
    assert(sll_get(list, 0) == 5);
    sll_free(list);
}

void test_delete_at_index() {
    SLL* list = sll_create();
    sll_add_tail(list, 10);
    sll_add_tail(list, 20);
    sll_add_tail(list, 30);
    sll_delete_at_index(list, 1);
    assert(sll_get(list, 1) == 30);
    sll_delete_at_index(list, 0);
    assert(sll_get(list, 0) == 30);
    sll_delete_at_index(list, 0);
    assert(sll_get(list, 0) == -1);
    sll_free(list);
}

void test_linked_list() {
    test_create_list_and_node();
    test_add_head();
    test_add_tail();
    test_add_at_index();
    test_delete_at_index();

    printf("All SLL tests passed!\n");
}
