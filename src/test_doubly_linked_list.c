#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void dll_test_create_list_and_node() {
    DLL* list = dll_create();
    assert(list != NULL);
    assert(list->head == NULL);
    assert(list->tail == NULL);
    assert(list->length == 0);

    dll_free(list);
}

void dll_test_add_head() {
    DLL* list = dll_create();
    dll_add_head(list, 10);
    assert(dll_get(list, 0) == 10);
    assert(list->head == list->tail);
    assert(list->length == 1);

    dll_add_head(list, 20);
    assert(dll_get(list, 0) == 20);
    assert(dll_get(list, 1) == 10);
    assert(list->head->value == 20);
    assert(list->tail->value == 10);
    assert(list->length == 2);

    // check back-links
    assert(list->head->next->prev == list->head);

    dll_free(list);
}

void dll_test_add_tail() {
    DLL* list = dll_create();
    dll_add_tail(list, 10);
    assert(dll_get(list, 0) == 10);
    assert(list->head == list->tail);
    assert(list->length == 1);

    dll_add_tail(list, 20);
    assert(dll_get(list, 1) == 20);
    assert(list->tail->value == 20);
    assert(list->head->next == list->tail);
    assert(list->tail->prev == list->head);
    assert(list->length == 2);

    dll_add_head(list, 5);
    assert(dll_get(list, 0) == 5);
    assert(dll_get(list, 2) == 20);
    assert(list->length == 3);

    dll_free(list);
}

void dll_test_add_at_index() {
    DLL* list = dll_create();
    dll_add_tail(list, 10);
    dll_add_tail(list, 20);
    dll_add_at_index(list, 1, 15);

    assert(dll_get(list, 0) == 10);
    assert(dll_get(list, 1) == 15);
    assert(dll_get(list, 2) == 20);
    assert(list->length == 3);

    dll_add_at_index(list, 0, 5);
    assert(dll_get(list, 0) == 5);
    assert(list->head->value == 5);
    assert(list->head->next->prev == list->head);
    assert(list->length == 4);

    dll_add_at_index(list, 4, 25); 
    assert(dll_get(list, 4) == 25);
    assert(list->tail->value == 25);
    assert(list->tail->prev->value == 20);
    assert(list->length == 5);

    dll_free(list);
}

void dll_test_delete_at_index() {
    DLL* list = dll_create();
    dll_add_tail(list, 10);
    dll_add_tail(list, 20);
    dll_add_tail(list, 30);

    dll_delete_at_index(list, 1); // remove 20
    assert(dll_get(list, 1) == 30);
    assert(list->head->next == list->tail);
    assert(list->tail->prev == list->head);
    assert(list->length == 2);

    dll_delete_at_index(list, 0); // remove 10
    assert(dll_get(list, 0) == 30);
    assert(list->head->value == 30);
    assert(list->tail->value == 30);
    assert(list->length == 1);

    dll_delete_at_index(list, 0); // remove 30
    assert(list->head == NULL);
    assert(list->tail == NULL);
    assert(list->length == 0);

    dll_free(list);
}

void test_doubly_linked_list() {
    dll_test_create_list_and_node();
    dll_test_add_head();
    dll_test_add_tail();
    dll_test_add_at_index();
    dll_test_delete_at_index();

    printf("All DLL tests passed!\n");
}
