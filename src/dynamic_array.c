#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

void init_array(DynamicArray *arr, int capacity) {
    arr->data = malloc(sizeof(int) * capacity);
    if (!arr->data) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    arr->length = 0;
    arr->capacity = capacity;
}

void resize_array(DynamicArray *arr) {
    arr->capacity *= 2;
    arr->data = realloc(arr->data, sizeof(int) * arr->capacity);
    if (!arr->data) {
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(1);
    }
}

void push(DynamicArray *arr, int value) {
    if (arr->length >= arr->capacity) {
        resize_array(arr);
    }
    arr->data[arr->length++] = value;
}

void pop(DynamicArray *arr) {
    if (arr->length == 0) {
        return;
    }
    arr->length--; // last element ignored
}

int get(DynamicArray *arr, size_t index) {
    if (index >= arr->length) {
        fprintf(stderr, "Index out of bounds!\n");
        exit(1);
    }
    return arr->data[index];
}

void set(DynamicArray *arr, size_t index, int value) {
    if (index >= arr->length) {
        fprintf(stderr, "Index out of bounds!\n");
        exit(1);
    }
    arr->data[index] = value;
}

void free_array(DynamicArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->length = 0;
    arr->capacity = 0;
}

int get_index(DynamicArray *arr, int value) {
    int left = 0, right = arr->length - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr->data[mid] == value) {
            result = mid;
            right = mid - 1;
        } else if (arr->data[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}


int find_index(DynamicArray *arr, int target) {
    for (size_t i = 0; i < arr->length; i++) {
        if (arr->data[i] == target) {
            return i; // return first match
        }
    }
    return -1;
}
