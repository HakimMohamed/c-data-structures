#pragma once
#include "linked_list.h"

typedef struct {
    SLL* list;
} Queue;

// Constructors
Queue* queue_create();
void queue_free(Queue* q);

// Queries
int queue_is_empty(Queue* q);
size_t queue_size(Queue* q);
int queue_peek(Queue* q);

// Mutations
void queue_enqueue(Queue* q, int val); // add to rear
int queue_dequeue(Queue* q);           // remove from front
