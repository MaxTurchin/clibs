#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 1

typedef struct DynamicArray {
    int current_length;
    int current_index;
    int cell_size;
    void *array;
} DynamicArray;

void darray_init(DynamicArray *arr, int cell_size) {
    arr->cell_size = cell_size;
    arr->array = malloc(INIT_SIZE*arr->cell_size);
    arr->current_length = INIT_SIZE;
    arr->current_index = 0;
}

int darray_get_length(DynamicArray *arr) {
    return arr->current_length;
}

int darray_get_current_index(DynamicArray *arr){
    return arr->current_index;
}

int darray_get_cell_size(DynamicArray *arr) {
    return arr->cell_size;
}

void *darray_get_cell(DynamicArray *arr, int index) {
    if (index >= arr->current_index) {
        return NULL;
    }
    void * res = (char *)arr->array + (index * arr->cell_size);
    return res;
}

void darray_append(DynamicArray *arr, void *item) {
    if(arr->current_index == arr->current_length) {
        arr->array = realloc(arr->array, arr->cell_size * arr->current_length * 2);
        arr->current_length *=2;
    }
    memcpy(arr->array + (arr->current_index * arr->cell_size), item, arr->cell_size);
    arr->current_index++;
}

void darray_remove_index(DynamicArray *arr, int index) {
    memcpy(arr->array + arr->cell_size * index, arr->array + arr->cell_size * (arr->current_index - 1), arr->cell_size);
    arr->current_index --;

    if(arr->current_index == arr->current_length/2){
        arr->array = realloc(arr->array, arr->cell_size * arr->current_length/2);
    }
}

void darray_print_addresses(DynamicArray *arr) {
    for (int i=0; i<darray_get_current_index(arr); i++) {
        printf("darray[%d]: %p\n", i, darray_get_cell(arr, i));
    }
}

void darray_print_properties(DynamicArray *arr) {
    printf("Current length [%p]: %d\n", &arr->current_length, arr->current_length);
    printf("Current index [%p]: %d\n", &arr->current_index, arr->current_index);
    printf("Cell size [%p]: %d\n", &arr->cell_size, arr->cell_size);
    printf("Array address: %p\n", arr->array);
}