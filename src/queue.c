#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Queue* queue_create() {
    Queue* q = malloc(sizeof(Queue));
    assert(q);
    q->list = sll_create();
    return q;
}

void queue_free(Queue* q) {
    sll_free(q->list);
    free(q);
}

int queue_is_empty(Queue* q) {
    return q->list->length == 0;
}

size_t queue_size(Queue* q) {
    return q->list->length;
}

int queue_peek(Queue* q) {
    if (queue_is_empty(q)) {
        fprintf(stderr, "Queue underflow on peek!\n");
        exit(1);
    }
    return sll_get(q->list, 0);  // front = head
}

void queue_enqueue(Queue* q, int val) {
    sll_add_tail(q->list, val);  // O(1) with tail
}

int queue_dequeue(Queue* q) {
    if (queue_is_empty(q)) {
        fprintf(stderr, "Queue underflow on dequeue!\n");
        exit(1);
    }
    int val = sll_get(q->list, 0);
    sll_delete_at_index(q->list, 0); // remove from head
    return val;
}
