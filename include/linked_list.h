#pragma once

struct node {
    int value;
    struct node* next;
};

typedef struct {
    struct node* head;
    struct node* tail; 
} LinkedList;

struct node* create_node(int val);
LinkedList* create_list();
int list_get(LinkedList* obj, int index);
void list_add_head(LinkedList* obj, int val);
void list_add_tail(LinkedList* obj, int val);
void list_add_at_index(LinkedList* obj, int index, int val);
void list_delete_at_index(LinkedList* obj, int index);
void list_free(LinkedList* obj);