#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 *
 * @line: pointer to array of integers
 * @size: number of integers in array
 * @direction: left or right that integers need to be merged into
 *
 * Return: 1 on success, or 0
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line | !size)
		return (0);

	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else if (direction == SLIDE_RIGHT)
		slide_right(line, size);
	return (1);
}

/**
 * slide_left - slides array to the left
 * @line: array of integers
 * @size: size of array
 * Return: void
 */
void slide_left(int *line, size_t size)
{
	int lo = 0;
	int hi;
	int prev = line[0];

	for (hi = 1; hi < (int)size; hi++)
	{
		if (line[hi])
		{
			if (!prev)
				prev = line[hi];
			else if (line[hi] == prev)
			{
				line[lo] = prev * 2;
				lo++;
				prev = 0;
			}
			else
			{
				line[lo] = prev;
				lo++;
				prev = line[hi];
			}
		}
	}
	if (prev)
		line[lo++] = prev;

	while (lo < (int)size)
	{
		line[lo] = 0;
		lo++;
	}
}

/**
 * slide_right - slides the array to the right
 *
 * @line: array of integers
 * @size: size of array
 * Return: void
 */
void slide_right(int *line, size_t size)
{
	int lo = size - 2;
	int hi = size - 1;
	int prev = line[hi];

	for (lo = size - 2; lo >= 0; lo--)
	{
		if (line[lo])
		{
			if (!prev)
				prev = line[lo];
			else if (prev == line[lo])
			{
				line[hi] = prev * 2;
				hi--;
				prev = 0;
			}
			else
			{
				line[hi] = prev;
				hi--;
			}
		}
	}
	if (prev)
		line[hi--] = prev;

	while (hi >= 0)
	{
		line[hi] = 0;
		hi--;
	}
}
