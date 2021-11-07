#ifndef H_DARRAYS
#define H_DARRAYS

#include <stdio.h>

typedef struct DynamicArray {
    int current_length;
    int current_index;
    int cell_size;
    void *array;
} DynamicArray;

void darray_init(DynamicArray *arr, int cell_size);
int darray_get_length(DynamicArray *arr);
int darray_get_current_index(DynamicArray *arr);
int darray_get_cell_size(DynamicArray *arr);
void *darray_get_cell(DynamicArray *arr, int index);
void darray_append(DynamicArray *arr, void *item);
void darray_remove_index(DynamicArray *arr, int index);

void darray_print_addresses(DynamicArray *arr);
void darray_print_properties(DynamicArray *arr);


#endif