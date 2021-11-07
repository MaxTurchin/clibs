#ifndef TWODARRAY_H
#define TWODARRAY_H

typedef struct twoDArray {
    int x_length;
    int y_length;
    int cell_size;
    void *array;
} twoDArray;

int tdarray_get_x_length(twoDArray *arr);
int tdarray_get_y_length(twoDArray *arr);
int tdarray_get_cell_size(twoDArray *arr);
void *tdarray_get_cell(twoDArray *arr, int x_index, int y_index);

#endif