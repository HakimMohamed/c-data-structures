#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct SLLNode* sll_create_node(int val) {
    struct SLLNode* newNode = malloc(sizeof(struct SLLNode));
    assert(newNode);
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

SLL* sll_create() {
    SLL* obj = malloc(sizeof(SLL));
    assert(obj);
    obj->head = NULL;
    return obj;
}

int sll_get(SLL* obj, int index) {
    if (obj->head == NULL) {
        return -1;
    }
    struct SLLNode* current = obj->head;
    for (int i = 0; i < index; i++) {
        if (current->next == NULL) {
            return -1; // Index out of bounds
        }
        current = current->next;
    }
    return current->value;
}

void sll_add_head(SLL* obj, int val) {
    struct SLLNode* new_node = sll_create_node(val);
    new_node->next = obj->head;
    obj->head = new_node;
}

void sll_add_tail(SLL* obj, int val) {
    struct SLLNode* new_node = sll_create_node(val);
    if (obj->head == NULL) {
        obj->head = new_node;
        return;
    }
    struct SLLNode* current = obj->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void sll_add_at_index(SLL* obj, int index, int val) {
    if (index < 0) return;
    if (index == 0) {
        sll_add_head(obj, val);
        return;
    }
    struct SLLNode* current = obj->head;
    for (int i = 0; i < index - 1; i++) {
        if (current == NULL) return; // Index out of bounds
        current = current->next;
    }
    if (current == NULL) return; // Index out of bounds
    struct SLLNode* new_node = sll_create_node(val);
    new_node->next = current->next;
    current->next = new_node;
}

void sll_delete_at_index(SLL* obj, int index) {
    if (obj->head == NULL || index < 0) return;

    if (index == 0) {
        struct SLLNode* temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
        return;
    }

    struct SLLNode* current = obj->head;
    for (int i = 0; i < index - 1; i++) {
        if (current->next == NULL) return; // Index out of bounds
        current = current->next;
    }

    if (current->next == NULL) return; // Node to delete does not exist

    struct SLLNode* temp = current->next;
    current->next = temp->next;
    free(temp);
}

void sll_free(SLL* obj) {
    struct SLLNode* current = obj->head;
    while (current != NULL) {
        struct SLLNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(obj);
}
