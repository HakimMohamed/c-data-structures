#pragma once
#include <stddef.h>
typedef struct {
    int *data;
    size_t length;    
    size_t capacity; 
} DynamicArray;

void init_array(DynamicArray *arr, int capacity);
void resize_array(DynamicArray *arr);
void push(DynamicArray *arr, int value);
void pop(DynamicArray *arr);
int get(DynamicArray *arr, size_t index);
void set(DynamicArray *arr, size_t index, int value);
void free_array(DynamicArray *arr);
int find_index(DynamicArray *arr, int target); // works on unsorted arrays
int get_index(DynamicArray *arr, int target);  // binary search, requires sorted array