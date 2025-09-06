#pragma once
#include <stddef.h>

struct DLLNode {
    int value;
    struct DLLNode* prev;
    struct DLLNode* next;
};

typedef struct {
    struct DLLNode* head;
    struct DLLNode* tail;
    size_t length;
} DLL;

// Constructors
struct DLLNode* dll_create_node(int val);
DLL* dll_create();

// Queries
int dll_get(DLL* obj, int index);

// Mutations
void dll_add_head(DLL* obj, int val);
void dll_add_tail(DLL* obj, int val);
void dll_add_at_index(DLL* obj, size_t index, int val);
void dll_delete_at_index(DLL* obj, size_t index);

// Clean up
void dll_free(DLL* obj);
