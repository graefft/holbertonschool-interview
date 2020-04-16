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
	int lo = 0, hi = 0, value = 0;

	if (!line | !size)
		return (0);

	if (direction == SLIDE_LEFT)
	{
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
	if (direction == SLIDE_RIGHT)
	{
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
	return (1);
}
