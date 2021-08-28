#include <stdio.h>

typedef struct Array {
    int length;
    int cell_size;
    void *array;
} Array;

int array_get_length(Array *arr) {
    return arr->length;
}

int array_get_cell_size(Array *arr) {
    return arr->cell_size;
}

void *array_get_cell(Array *arr, int index) {
    void * res = (char *)arr->array + (index * arr->cell_size);
    return res;
}