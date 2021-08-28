#ifndef H_ARRAYS
#define H_ARRAYS

#include <stdio.h>

typedef struct Array {
    int length;
    int cell_size;
    void *array;
} Array;

int array_get_length(Array *arr);
int array_get_cell_size(Array *arr);
void *array_get_cell(Array *arr, int index);

#endif