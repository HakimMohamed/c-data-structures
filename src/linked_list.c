#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node* create_node(int val) {
    struct node* newNode = malloc(sizeof(struct node));
    assert(newNode);
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

LinkedList* create_list() {
    LinkedList* obj = malloc(sizeof(LinkedList));
    assert(obj);
    obj->head = NULL;
    return obj;
}

int list_get(LinkedList* obj, int index) {
    if (obj->head == NULL) {
        return -1;
    }
    struct node* current = obj->head;
    for (int i = 0; i < index; i++) {
        if (current->next == NULL) {
            return -1; // Index out of bounds
        }
        current = current->next;
    }
    return current->value;
}

void list_add_head(LinkedList* obj, int val) {
    struct node* new_node = create_node(val);
    new_node->next = obj->head;
    obj->head = new_node;
}

void list_add_tail(LinkedList* obj, int val) {
    struct node* new_node = create_node(val);
    if (obj->head == NULL) {
        obj->head = new_node;
        return;
    }
    struct node* current = obj->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void list_add_at_index(LinkedList* obj, int index, int val) {
    if (index < 0) return;
    if (index == 0) {
        list_add_head(obj, val);
        return;
    }
    struct node* current = obj->head;
    for (int i = 0; i < index - 1; i++) {
        if (current == NULL) return; // Index out of bounds
        current = current->next;
    }
    if (current == NULL) return; // Index out of bounds
    struct node* new_node = create_node(val);
    new_node->next = current->next;
    current->next = new_node;
}

void list_delete_at_index(LinkedList* obj, int index) {
    if (obj->head == NULL || index < 0) return;

    if (index == 0) {
        struct node* temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
        return;
    }

    struct node* current = obj->head;
    for (int i = 0; i < index - 1; i++) {
        if (current->next == NULL) return; // Index out of bounds
        current = current->next;
    }

    if (current->next == NULL) return; // Node to delete does not exist

    struct node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

void list_free(LinkedList* obj) {
    struct node* current = obj->head;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }
    free(obj);
}