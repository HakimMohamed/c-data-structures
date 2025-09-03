#include"linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_create_list_and_node() {
    LinkedList* list = create_list();
    assert(list != NULL);
    assert(list->head == NULL);
    list_free(list);
}

void test_add_head() {
    LinkedList* list = create_list();
    list_add_head(list, 10);
    assert(list_get(list, 0) == 10);
    list_add_head(list, 20);
    assert(list_get(list, 0) == 20);
    assert(list_get(list, 1) == 10);
    assert(list_get(list, 2) == -1);
    list_free(list);
}

void test_add_tail() {
    LinkedList* list = create_list();
    list_add_tail(list, 10);
    assert(list_get(list, 0) == 10);
    list_add_tail(list, 20);
    assert(list_get(list, 1) == 20);
    list_add_head(list, 5);
    assert(list_get(list, 2) == 20);
    list_free(list);
}

void test_add_at_index() {
    LinkedList* list = create_list();
    list_add_tail(list, 10);
    list_add_tail(list, 20);
    list_add_at_index(list, 1, 15);
    assert(list_get(list, 0) == 10);
    assert(list_get(list, 1) == 15);
    assert(list_get(list, 2) == 20);
    list_add_at_index(list, 0, 5); 
    assert(list_get(list, 0) == 5);
    list_free(list);
}

void test_delete_at_index() {
    LinkedList* list = create_list();
    list_add_tail(list, 10);
    list_add_tail(list, 20);
    list_add_tail(list, 30);
    list_delete_at_index(list, 1);
    assert(list_get(list, 1) == 30);
    list_delete_at_index(list, 0);
    assert(list_get(list, 0) == 30);
    list_delete_at_index(list, 0);
    assert(list_get(list, 0) == -1);
    list_free(list);
}

void test_linked_list(){
    test_create_list_and_node();
    test_add_head();
    test_add_tail();
    test_add_at_index();
    test_delete_at_index();

    printf("All Linked List tests passed!\n\n\n");
}