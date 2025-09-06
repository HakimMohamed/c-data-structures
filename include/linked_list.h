#pragma once

struct SLLNode {
    int value;
    struct SLLNode* next;
};

typedef struct {
    struct SLLNode* head;
    struct SLLNode* tail;
} SLL;

// Functions
struct SLLNode* sll_create_node(int val);
SLL* sll_create();

// Queries
int sll_get(SLL* obj, int index);

// Mutations
void sll_add_head(SLL* obj, int val);
void sll_add_tail(SLL* obj, int val);
void sll_add_at_index(SLL* obj, int index, int val);
void sll_delete_at_index(SLL* obj, int index);

// Clean up
void sll_free(SLL* obj);
