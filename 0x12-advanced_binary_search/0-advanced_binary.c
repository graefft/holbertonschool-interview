#include "search_algos.h"

/**
 * advanced_binary_recursion - recursive function for binary search
 * @array: pointer to first element in array to search
 * @value: value to search for
 * @lo: left index of split
 * @hi: right index of split
 * Return: index or -1 if value not present
 */
int advanced_binary_recursion(int *array, int value, int lo, int hi)
{
	int i = lo;
	int mid = lo + ((hi - lo) / 2);

	printf("Searching in array: ");
	while (i < hi)
	{
		printf("%d, ", array[i]);
		i++;
	}
	printf("%d\n", array[i]);

	if (array[mid] == value)
	{
		if (array[mid - 1] == value)
		{
			hi = mid;
			return (advanced_binary_recursion(array, value, lo, hi));
		}
		else
			return (mid);
	}
	if (lo == hi)
		return (-1);
	if (array[mid] < value)
		return (advanced_binary_recursion(array, value, mid + 1, hi));
	if (array[mid] > value)
		return (advanced_binary_recursion(array, value, lo, mid));
	return (mid);
}

/**
 * advanced_binary - searchs for a value in a sorted array of integers
 * @array: pointer to first element of array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || !size || !value)
		return (-1);

	return (advanced_binary_recursion(array, value, 0, size - 1));
}
