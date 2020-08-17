#include "sort.h"

/**
 * merge_subroutine - merges smaller arrays while sorting
 *
 * @a: array of integers to sort
 * @b: copy of array
 * @begin: starting point
 * @mid: halfway point
 * @end: ending point
 */
void merge_subroutine(int *a, int *b, size_t begin, size_t mid, size_t end)
{
	size_t left = begin;
	size_t right = mid;
	size_t i;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(a + begin, mid - begin);
	printf("[right]: ");
	print_array(a + mid, end - mid);

	for (i = begin; i < end; i++)
	{
		if (left < mid && (right >= end || a[left] <= a[right]))
		{
			b[i] = a[left];
			left++;
		}
		else
		{
			b[i] = a[right];
			right++;
		}
	}
	printf("[Done]: ");
	print_array(b + begin, end - begin);
}


/**
 * split_subroutine - recursively splits arrays and sorts
 *
 * @a: pointer to array of integers to sort
 * @b: copy of array
 * @begin: left point in array
 * @end: right point in array
 */
void split_subroutine(int *a, int *b, size_t begin, size_t end)
{
	size_t mid = (begin + end) / 2;

	/* BASE CASE */
	if ((end - begin) < 2)
		return;

	split_subroutine(b, a, begin, mid);
	split_subroutine(b, a, mid, end);
	merge_subroutine(b, a, begin, mid, end);
}


/**
 * merge_sort - sorts an array of integers in ascending order using
 *	top-down merge sort algorithm
 *
 * @array: pointer to array of integers
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *array_copy = NULL;
	size_t i = 0;

	if (!array || size < 2)
		return;

	array_copy = malloc(sizeof(*array) * size);
	if (!array_copy)
		return;

	for (i = 0; i < size; i++)
		array_copy[i] = array[i];

	split_subroutine(array, array_copy, 0, size);
	free(array_copy);
}
