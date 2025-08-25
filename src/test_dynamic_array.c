#include <stdio.h>
#include "dynamic_array.h"

void test_dynamic_array() {
    printf("Running DynamicArray tests...\n");

    DynamicArray arr;
    initArray(&arr, 2);

    push(&arr, 10);
    push(&arr, 20);
    push(&arr, 30); // This should trigger a resize

    printf("Initial array: ");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", get(&arr, i));
    }
    printf("\n");

    set(&arr, 1, 99);
    printf("After set: ");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", get(&arr, i));
    }
    printf("\n");

    pop(&arr);
    printf("After pop: ");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", get(&arr, i));
    }
    printf("\n");

    freeArray(&arr);

    printf("DynamicArray tests finished.\n\n");
}
