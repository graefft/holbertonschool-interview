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
 *
 * @line: array of integers
 * @size: size of array
 * Return: void
 */
void slide_left(int *line, size_t size)
{
	int lo = 0;
	int hi = 0;
	int value = 0;

	for (hi = 1; hi < (int)size; hi++)
	{
		if (line[hi])
		{
			if (!value)
				value = line[hi];
			if (value == line[hi])
			{
				line[lo] = value * 2;
				printf("LO = [%d]\n", line[lo]);
				value = 0;
			}
			else
			{
				line[lo] = value;
				value = line[hi];
			}
		lo++;
		}
	}
	if (value)
		line[lo] = value;
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
	int lo = 0;
	int hi = 0;
	int value = 0;

	hi = size - 1;
	value = line[hi];
	for (lo = size - 2; lo >= 0; lo--)
	{
		if (value == line[lo])
		{
			line[hi] = value * 2;
			value = 0;
		}
		else
		{
			line[hi] = value;
			value = line[lo];
		}
	}
	if (value)
		line[hi] = value;
}
