#include "sort.h"

/**
 * get_max - helper function to get max value
 *
 * @a: array of integers
 * @n: integer to check against
 * Return: max value
 */
int get_max(int *a, size_t n)
{
	int max = a[0];
	size_t i;

	for (i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
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
	int base[10][10], base_cnt[10];
	int j, k, r, NOP = 0, divisor = 1, lar, pass;
	size_t i;

	if (!array || size <= 1)
		return;
	lar = get_max(array, size);
	while (lar > 0)
	{
		NOP++;
		lar /= 10;
	}
	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < 10; i++)
			base_cnt[i] = 0;
		for (i = 0; i < size; i++)
		{
			r = (array[i] / divisor) % 10;
			base[r][base_cnt[r]] = array[i];
			base_cnt[r] += 1;
		}
		i = 0;
		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < base_cnt[k]; j++)
			{
				array[i] = base[k][j];
				i++;
			}
		}
		divisor *= 10;
		for (i = 0; i < size; i++)
		{
			printf("%d", array[i]);
			i < size - 1 ? printf(", ") : printf("\n");
		}
	}
}
