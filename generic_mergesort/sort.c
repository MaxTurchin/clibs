#include <stdlib.h>
#include <string.h>

#include "compare.h"
#include "dynamic_array.h"
#include "professor.h"
#include "student.h"
 

void merge(void *base, void *middle, void *end, size_t cell_size, int offset, int (*compare) (void *, void *)) {
    void *temp_array = malloc(end - base);
    void *temp_p = temp_array;

    void *current_p = base;
    void *current_p1 = middle;

    while (current_p < middle && current_p1 < end) {
        if (compare(current_p + offset, current_p1 + offset) < 0) {
            memcpy(temp_p, current_p, cell_size);
            current_p += cell_size;
        } else {
            memcpy(temp_p, current_p1, cell_size);
            current_p1 += cell_size;
        }
        temp_p += cell_size;
    }
    while (current_p < middle) {
        memcpy(temp_p, current_p, cell_size);
        current_p += cell_size;
        temp_p += cell_size;
    }
    while (current_p1 < middle) {
        memcpy(temp_p, current_p1, cell_size);
        current_p1 += cell_size;
        temp_p += cell_size;
    }
    memcpy(base, temp_array, (int)temp_p - (int)temp_array);
    free(temp_array);
}

void mergesort(void *base, int nof_items, size_t cell_size, int offset, int (*compare) (void *, void *)) {
    if(nof_items > 1) {
        void *middle = base + (cell_size *(nof_items / 2)), *end = base + (cell_size * nof_items);

        mergesort(base, nof_items/2, cell_size, offset, compare);
        mergesort(middle, nof_items/2 + nof_items%2, cell_size, offset, compare);

        merge(base, middle, end, cell_size, offset, compare);
    }
}

void merge_int(int *base, int *middle, int *end) {
    int *temp = malloc(end - base);
    int *temp_p = temp;

    int *p = base;
    int *p1 = middle;

    while (p < middle && p1 < end) {
        if (*p < *p1) {
            memcpy(temp_p, p, sizeof(int));
            p++;
        } else {
            memcpy(temp_p, p1,sizeof(int));
            p1++;
        }
        temp_p ++;
    }

    while (p < middle) {
        memcpy(temp_p, p, sizeof(int));
        temp_p ++;
        p ++;
    }
    while(p1 < end) {
        memcpy(temp_p, p1, sizeof(int));
        temp_p ++;
        p1 ++;
    }

    memcpy(base, temp, (int)temp_p - (int)temp);
    free(temp);
}

void mergesort_int(int array[], int *end) {
    if (array + 1< end) {
        int *mid = array + (end - array)/2;
        mergesort_int(array, mid);
        mergesort_int(mid, end);
        merge_int(array, mid, end);
    }
}

