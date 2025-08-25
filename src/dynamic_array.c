#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

/*
 * Dynamic Array Implementation
 *
 * This dynamic array provides a resizable array abstraction in C.
 * It automatically grows when needed and allows random access to elements.
 *
 * In this project, the dynamic array is also used like a stack:
 *   - push() adds an element to the end
 *   - pop() removes the last element
 *
 * So it can be treated both as a general-purpose array and as a stack.
*/

void initArray(DynamicArray *arr, int capacity) {
    arr->data = (int*)malloc(sizeof(int) * capacity);
    if (!arr->data) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    arr->length = 0;
    arr->capacity = capacity;
}

void resizeArray(DynamicArray *arr) {
    arr->capacity *= 2;
    arr->data = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
    if (!arr->data) {
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(1);
    }
}

void push(DynamicArray *arr, int value) {
    if (arr->length >= arr->capacity) {
        resizeArray(arr);
    }
    arr->data[arr->length++] = value;
}

void pop(DynamicArray *arr) {
    if (arr->length == 0) {
        printf("Array is empty!\n");
        return;
    }
    arr->length--; // last element ignored
}

int get(DynamicArray *arr, int index) {
    if (index < 0 || index >= arr->length) {
        fprintf(stderr, "Index out of bounds!\n");
        exit(1);
    }
    return arr->data[index];
}

void set(DynamicArray *arr, int index, int value) {
    if (index < 0 || index >= arr->length) {
        fprintf(stderr, "Index out of bounds!\n");
        exit(1);
    }
    arr->data[index] = value;
}

void freeArray(DynamicArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->length = 0;
    arr->capacity = 0;
}