#pragma once

typedef struct {
    int *data;
    int length;    
    int capacity; 
} DynamicArray;

void initArray(DynamicArray *arr, int capacity);
void resizeArray(DynamicArray *arr);
void push(DynamicArray *arr, int value);
void pop(DynamicArray *arr);
int get(DynamicArray *arr, int index);
void set(DynamicArray *arr, int index, int value);
void freeArray(DynamicArray *arr);