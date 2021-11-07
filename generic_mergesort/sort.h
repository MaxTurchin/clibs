#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void mergesort(void *base, int nof_items, size_t cell_size, void *first_item, int (*compare) (void *, void *));
void mergesort_int(int array[], int *end);

#endif