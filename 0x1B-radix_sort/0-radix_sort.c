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
 *
 * Return: void
 */
void counting_sort_radix(int *array, int size, int digit)
{
	int i, j, value;
	int *output;
	int count[BASE] = {0};

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	/* store count of each character */
	for (i = 0; i < size; i++)
	{
		value = ((array[i] / digit) % BASE);
		count[value]++;
	}
	/* change array to store actual position of character in output */
	for (i = 1; i < BASE; i++)
		count[i] += count[i - 1];

	/* build output character array */
	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / digit) % 10] - 1] = array[j];
		count[(array[j] / digit) % 10]--;
	}
	/* copy sorted output array to array */
	for (i = 0; i < size; i++)
		array[i] = output[i];
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
	int max, digit;

	if (!array || size <= 1)
		return;

	max = find_max(array, size);
	for (digit = 1; max / digit > 0; digit *= BASE)
	{
		counting_sort_radix(array, size, digit);
		print_array(array, size);
	}
}
