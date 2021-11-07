typedef struct twoDArray {
    int x_length;
    int y_length;
    int cell_size;
    void *array;
} twoDArray;

int tdarray_get_x_length(twoDArray *arr) {
    return arr->x_length;
}

int tdarray_get_y_length(twoDArray *arr) {
    return arr->y_length;
}

int tdarray_get_cell_size(twoDArray *arr) {
    return arr->cell_size;
}

void *tdarray_get_cell(twoDArray *arr, int x_index, int y_index) {
    void * arr_addr = (char *)arr->array + (x_index * arr->y_length * arr->cell_size);
    return (char *)arr_addr + (y_index * arr->cell_size);
}

