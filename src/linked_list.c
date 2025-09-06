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
    obj->tail = NULL;
    obj->length = 0;   // initialize length
    return obj;
}

int sll_get(SLL* obj, int index) {
    if (index < 0 || (size_t)index >= obj->length) {
        return -1; // Index out of bounds
    }

    struct SLLNode* current = obj->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}

void sll_add_head(SLL* obj, int val) {
    struct SLLNode* new_node = sll_create_node(val);
    new_node->next = obj->head;
    obj->head = new_node;

    if (obj->tail == NULL) {
        // If list was empty, head and tail are the same
        obj->tail = new_node;
    }

    obj->length++;
}

void sll_add_tail(SLL* obj, int val) {
    struct SLLNode* new_node = sll_create_node(val);

    if (obj->head == NULL) {
        obj->head = new_node;
        obj->tail = new_node;
    } else {
        obj->tail->next = new_node;
        obj->tail = new_node;
    }

    obj->length++;
}

void sll_add_at_index(SLL* obj, size_t index, int val) {
    if (index > obj->length) {
        // Out of bounds
        return;
    }

    if (index == 0) {
        sll_add_head(obj, val);
        return;
    }

    if (index == obj->length) {
        // Equivalent to adding at the tail
        sll_add_tail(obj, val);
        return;
    }

    struct SLLNode* current = obj->head;
    for (size_t i = 0; i < index - 1; i++) {
        current = current->next;
    }

    struct SLLNode* new_node = sll_create_node(val);
    new_node->next = current->next;
    current->next = new_node;

    obj->length++;
}

void sll_delete_at_index(SLL* obj, size_t index) {
    if (index >= obj->length) {
        // Index out of bounds
        return;
    }

    if (index == 0) {
        struct SLLNode* temp = obj->head;
        obj->head = obj->head->next;
        if (obj->head == NULL) {
            // List became empty
            obj->tail = NULL;
        }
        free(temp);
        obj->length--;
        return;
    }

    struct SLLNode* current = obj->head;
    for (size_t i = 0; i < index - 1; i++) {
        current = current->next;
    }

    struct SLLNode* temp = current->next;
    current->next = temp->next;

    if (temp == obj->tail) {
        // Deleted the last node → update tail
        obj->tail = current;
    }

    free(temp);
    obj->length--;
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
