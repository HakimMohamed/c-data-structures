#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct DLLNode* dll_create_node(int val) {
    struct DLLNode* newNode = malloc(sizeof(struct DLLNode));
    assert(newNode);
    newNode->value = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

DLL* dll_create() {
    DLL* obj = malloc(sizeof(DLL));
    assert(obj);
    obj->head = NULL;
    obj->tail = NULL;
    obj->length = 0;
    return obj;
}

int dll_get(DLL* obj, int index) {
    if (index < 0 || (size_t)index >= obj->length) {
        return -1; // Index out of bounds
    }

    struct DLLNode* current;
    // Optimization: choose direction based on index
    if ((size_t)index < obj->length / 2) {
        current = obj->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    } else {
        current = obj->tail;
        for (size_t i = obj->length - 1; i > (size_t)index; i--) {
            current = current->prev;
        }
    }
    return current->value;
}

void dll_add_head(DLL* obj, int val) {
    struct DLLNode* new_node = dll_create_node(val);
    new_node->next = obj->head;

    if (obj->head != NULL) {
        obj->head->prev = new_node;
    }
    obj->head = new_node;

    if (obj->tail == NULL) {
        obj->tail = new_node;
    }

    obj->length++;
}

void dll_add_tail(DLL* obj, int val) {
    struct DLLNode* new_node = dll_create_node(val);

    if (obj->tail == NULL) {
        obj->head = new_node;
        obj->tail = new_node;
    } else {
        obj->tail->next = new_node;
        new_node->prev = obj->tail;
        obj->tail = new_node;
    }

    obj->length++;
}

void dll_add_at_index(DLL* obj, size_t index, int val) {
    if (index > obj->length) {
        return; // Out of bounds
    }

    if (index == 0) {
        dll_add_head(obj, val);
        return;
    }

    if (index == obj->length) {
        dll_add_tail(obj, val);
        return;
    }

    struct DLLNode* current = obj->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    struct DLLNode* new_node = dll_create_node(val);
    new_node->next = current;
    new_node->prev = current->prev;

    if (current->prev) {
        current->prev->next = new_node;
    }
    current->prev = new_node;

    obj->length++;
}

void dll_delete_at_index(DLL* obj, size_t index) {
    if (index >= obj->length) {
        return; // Out of bounds
    }

    struct DLLNode* current;
    if (index == 0) {
        current = obj->head;
        obj->head = current->next;
        if (obj->head) {
            obj->head->prev = NULL;
        } else {
            obj->tail = NULL; // list became empty
        }
        free(current);
        obj->length--;
        return;
    }

    if (index == obj->length - 1) {
        current = obj->tail;
        obj->tail = current->prev;
        obj->tail->next = NULL;
        free(current);
        obj->length--;
        return;
    }

    current = obj->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);

    obj->length--;
}

void dll_free(DLL* obj) {
    struct DLLNode* current = obj->head;
    while (current != NULL) {
        struct DLLNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(obj);
}
