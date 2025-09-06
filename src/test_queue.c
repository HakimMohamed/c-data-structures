#include "queue.h"
#include <assert.h>
#include <stdio.h>

void test_queue_create() {
    Queue* q = queue_create();
    assert(queue_is_empty(q));
    assert(queue_size(q) == 0);
    queue_free(q);
}

void test_queue_enqueue_dequeue() {
    Queue* q = queue_create();
    queue_enqueue(q, 10);
    queue_enqueue(q, 20);
    queue_enqueue(q, 30);

    assert(queue_size(q) == 3);
    assert(queue_peek(q) == 10);

    int v1 = queue_dequeue(q);
    assert(v1 == 10);
    assert(queue_peek(q) == 20);
    assert(queue_size(q) == 2);

    int v2 = queue_dequeue(q);
    assert(v2 == 20);
    int v3 = queue_dequeue(q);
    assert(v3 == 30);

    assert(queue_is_empty(q));
    queue_free(q);
}

void test_queue_peek() {
    Queue* q = queue_create();
    queue_enqueue(q, 42);
    assert(queue_peek(q) == 42);
    assert(queue_size(q) == 1);
    queue_free(q);
}

void test_queue_stress() {
    Queue* q = queue_create();

    for (int i = 0; i < 100; i++) {
        queue_enqueue(q, i);
    }
    assert(queue_size(q) == 100);

    for (int i = 0; i < 100; i++) {
        assert(queue_dequeue(q) == i);
    }
    assert(queue_is_empty(q));

    queue_free(q);
}

void test_queue() {
    test_queue_create();
    test_queue_enqueue_dequeue();
    test_queue_peek();
    test_queue_stress();

    printf("All Queue tests passed!\n");
}
