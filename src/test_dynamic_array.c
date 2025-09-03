#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynamic_array.h"

void test_init_and_free() {
    DynamicArray arr;
    init_array(&arr, 2);
    assert(arr.length == 0);
    assert(arr.capacity == 2);
    free_array(&arr);
}

void test_push_and_resize() {
    DynamicArray arr;
    init_array(&arr, 2);
    
    push(&arr, 10);
    push(&arr, 20);
    push(&arr, 30); // Should trigger a resize
    
    assert(arr.length == 3);
    assert(arr.capacity == 4);
    assert(get(&arr, 0) == 10);
    assert(get(&arr, 1) == 20);
    assert(get(&arr, 2) == 30);
    
    free_array(&arr);
}

void test_set_and_get() {
    DynamicArray arr;
    init_array(&arr, 2);

    push(&arr, 1);
    push(&arr, 2);
    set(&arr, 1, 99);

    assert(get(&arr, 0) == 1);
    assert(get(&arr, 1) == 99);

    free_array(&arr);
}

void test_pop() {
    DynamicArray arr;
    init_array(&arr, 3);

    push(&arr, 5);
    push(&arr, 6);
    push(&arr, 7);
    
    pop(&arr);
    assert(arr.length == 2);
    assert(get(&arr, 0) == 5);
    assert(get(&arr, 1) == 6);

    pop(&arr);
    pop(&arr);
    assert(arr.length == 0);
    
    pop(&arr);
    assert(arr.length == 0);

    free_array(&arr);
}

void test_find_index() {
    DynamicArray arr;
    init_array(&arr, 5);

    push(&arr, 42);
    push(&arr, 7);
    push(&arr, 99);
    push(&arr, 15);
    
    assert(find_index(&arr, 42) == 0);
    assert(find_index(&arr, 7) == 1);
    assert(find_index(&arr, 99) == 2);
    assert(find_index(&arr, 15) == 3);
    assert(find_index(&arr, 100) == -1); // Not found

    free_array(&arr);
}

void test_get_index_sorted() {
    DynamicArray arr;
    init_array(&arr, 5);

    push(&arr, 5);
    push(&arr, 15);
    push(&arr, 25);
    push(&arr, 35);
    
    assert(get_index(&arr, 5) == 0);
    assert(get_index(&arr, 15) == 1);
    assert(get_index(&arr, 25) == 2);
    assert(get_index(&arr, 35) == 3);
    assert(get_index(&arr, 100) == -1); // Not found
    assert(get_index(&arr, 0) == -1); // Below minimum

    free_array(&arr);
}

void test_get_index_duplicates() {
    DynamicArray arr;
    init_array(&arr, 6);

    push(&arr, 2);
    push(&arr, 2);
    push(&arr, 2);
    push(&arr, 3);
    push(&arr, 3);
    push(&arr, 4);

    int idx2 = find_index(&arr, 2);
    assert(get_index(&arr, 2) == idx2);
    
    int idx3 = find_index(&arr, 3);
    assert(get_index(&arr, 3) == idx3);

    int idx4 = find_index(&arr, 4);
    assert(get_index(&arr, 4) == idx4);
    
    assert(get_index(&arr, 5) == -1);

    free_array(&arr);
}

void test_dynamic_array() {
    test_init_and_free();
    test_push_and_resize();
    test_set_and_get();
    test_pop();
    test_find_index();
    test_get_index_sorted();
    test_get_index_duplicates();
    
    printf("All DynamicArray tests passed!\n");
}