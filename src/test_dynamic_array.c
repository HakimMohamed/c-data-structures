#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynamic_array.h"

// Helper: compare for qsort (for binary search tests)
static int int_cmp(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

void test_dynamic_array() {
    DynamicArray arr;

    // --- init ---
    initArray(&arr, 2);
    assert(arr.length == 0);
    assert(arr.capacity == 2);
    freeArray(&arr);

    // --- push & resize ---
    initArray(&arr, 2);
    push(&arr, 10);
    push(&arr, 20);
    push(&arr, 30); // should resize
    assert(arr.length == 3);
    assert(arr.capacity >= 3);
    assert(get(&arr, 0) == 10);
    assert(get(&arr, 1) == 20);
    assert(get(&arr, 2) == 30);
    freeArray(&arr);

    // --- set & get ---
    initArray(&arr, 2);
    push(&arr, 1);
    push(&arr, 2);
    set(&arr, 1, 99);
    assert(get(&arr, 0) == 1);
    assert(get(&arr, 1) == 99);
    freeArray(&arr);

    // --- pop (normal + empty) ---
    initArray(&arr, 3);
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
    pop(&arr); // extra pop, should not crash
    assert(arr.length == 0);
    freeArray(&arr);

    // --- findIndex (unsorted) ---
    initArray(&arr, 5);
    push(&arr, 42);
    push(&arr, 7);
    push(&arr, 99);
    push(&arr, 15);
    assert(findIndex(&arr, 42) == 0);
    assert(findIndex(&arr, 7)  == 1);
    assert(findIndex(&arr, 99) == 2);
    assert(findIndex(&arr, 15) == 3);
    assert(findIndex(&arr, 100) == -1); // not found
    freeArray(&arr);

    // --- getIndex (sorted, unique elements) ---
    initArray(&arr, 5);
    push(&arr, 35);
    push(&arr, 15);
    push(&arr, 25);
    push(&arr, 5);
    qsort(arr.data, arr.length, sizeof(int), int_cmp); // sort: [5,15,25,35]
    assert(getIndex(&arr, 5) == 0);
    assert(getIndex(&arr, 15) == 1);
    assert(getIndex(&arr, 25) == 2);
    assert(getIndex(&arr, 35) == 3);
    assert(getIndex(&arr, 100) == -1); // not found
    assert(getIndex(&arr, 0)   == -1); // below minimum
    freeArray(&arr);

    // --- getIndex (duplicates) ---
    initArray(&arr, 6);
    push(&arr, 2);
    push(&arr, 2);
    push(&arr, 2);
    push(&arr, 3);
    push(&arr, 3);
    push(&arr, 4);
    // Already sorted
    int idx2 = getIndex(&arr, 2);
    assert(idx2 >= 0 && arr.data[idx2] == 2);
    int idx3 = getIndex(&arr, 3);
    assert(idx3 >= 0 && arr.data[idx3] == 3);
    int idx4 = getIndex(&arr, 4);
    assert(idx4 >= 0 && arr.data[idx4] == 4);
    assert(getIndex(&arr, 5) == -1);
    freeArray(&arr);

    // --- findIndex vs getIndex consistency ---
    initArray(&arr, 5);
    push(&arr, 10);
    push(&arr, 20);
    push(&arr, 30);
    push(&arr, 40);
    // findIndex works directly
    assert(findIndex(&arr, 20) == 1);

    // binary search
    assert(getIndex(&arr, 20) == 1);

    // --- Free array ---
    freeArray(&arr);

    printf("All DynamicArray tests passed!\n\n");
}
