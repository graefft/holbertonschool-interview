#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - swaps two values
 * @x: first value
 * @y: second value
 */
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
 * heapify - heapifies a subtree rooted with index in array
 * @array: array to sort
 * @heap_size: size of heap
 * @index: index of heap
 * @size: size of heap
 */
void heapify(int *array, size_t heap_size, int index, size_t size)
{
	size_t largest = index;
	size_t left = (2 * index + 1);
	size_t right = (2 * index + 2);

	/* If left child is larger than root */
	if (left < heap_size && array[left] > array[largest])
		largest = left;

	/* If right child is larger than root */
	if (right < heap_size && array[right] > array[largest])
		largest = right;

	/* If largest is not root, swap & heapify affected subtree */
	if ((int)largest != index)
	{
		swap(&array[index], &array[largest]);
		if (array[index] != array[largest])
			print_array(array, size);
		heapify(array, heap_size, largest, size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order - sift-down
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	/* move current root to end */
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
