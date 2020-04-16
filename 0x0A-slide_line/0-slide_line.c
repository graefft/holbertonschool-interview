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
	int i = 0;
	int j = 0;
	int prev = line[0];

	for (j = 1; j < (int)size; j++)
	{
		if (line[j])
		{
			if (!prev)
				prev = line[j];
			else if (line[j] == prev)
			{
				line[i] = prev * 2;
				i++;
				prev = 0;
			}
			else
			{
				line[i] = prev;
				i++;
				prev = line[j];
			}
		}
	}
	if (prev)
		line[i++] = prev;

	while (i < (int)size)
	{
		line[i] = 0;
		i++;
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
	int i = 0;
	int j = size - 1;
	int prev = line[i];

	for (i = size - 2; i >= 0; i--)
	{
		if (line[i])
		{
			if (!prev)
				prev = line[i];
			else if (prev == line[i])
			{
				line[j] = prev * 2;
				j--;
				prev = 0;
			}
			else
			{
				line[j] = prev;
				j--;
				prev = line[i];
			}
		}
	}
	if (prev)
		line[j--] = prev;

	while (j >= 0)
	{
		line[j] = 0;
		j--;
	}
}
