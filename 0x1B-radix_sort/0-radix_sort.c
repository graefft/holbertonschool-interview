#include "sort.h"

#define BASE 10

/**
 * counting_sort_radix - sorts array using Counting Sort algorithm
 *
 * Description: sorts using keys, counts number with key value to
 * determine placement in output
 *
 * @array: pointer to array
 * @size: size of array
 * @digit: digit to sort
 * @sorted: array of sorted values
 *
 * Return: void
 */
void counting_sort_radix(int *array, size_t size, int digit)
{
	int value;
	int *output;
	int count[BASE] = {0};
	size_t i;

	if (!count)
		return;
	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	/* store count of each character */
	for (i = 0; i < size; i++)
	{
		value = (array[i] / digit % BASE);
		count[value]++;
	}
	/* change array to store actual position of character in output */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	/* build output character array */
	for (j = 0; j < size; j++)
	{
		output[count[array[i]] / digit % 10] = array[i];
		count[array[i]]--;
	}
	/* copy sorted output array to array */
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}

/**
 * find_max - finds max key in array
 * @array: array to be sorted
 * @size: size of array
 * Return: max value
 */
int find_max(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * radix_sort - sorts an array of integers in ascending order using radix
 * algorithm
 *
 * @array: array of integers >= 0 to sort
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max, digit, *sorted;
	unsigned int i = 1;

	if (!array || size <= 1)
		return;

	sorted = malloc(sizeof(*sorted) * size);
	if (!sorted)
		return;

	max = find_max(array, size);
	for (digit = 1; max / digit > 0; digit *= BASE)
	{
		counting_sort_radix(array, size, digit, sorted);
		print_array(array, size);
	}
	free(sorted);
}
