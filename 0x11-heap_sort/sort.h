#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);
void heapify(int *array, size_t heap_size, int index, size_t size);
void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif /* __SORT_H__ */
