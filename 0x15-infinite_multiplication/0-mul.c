#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - returns the length of a string
 * @s: char to check
 * Return: length
 */

int _strlen(char *s)
{
	int count = 0;

	while (*s)
	{
		s++;
		count++;
	}
	return (count);
}

/**
 * multiply - multiply the strings
 * @s1: 1st string to multiply
 * @s2: 2nd string to multiply
 * Return: result
 */

char *multiply(char *s1, char *s2)
{
	char *result;
	int x, y, z, total_length, len_s1, len_s2;

	len_s1 = _strlen(s1);
	len_s2 = _strlen(s2);

	total_length = len_s1 + len_s2;
	result = malloc(len_s1 + len_s2);
	if (result == 0)
		printf("Error\n"), exit(98);

	while (total_length--)
		result[total_length] = 0;

	for (len_s1--; len_s1 >= 0; len_s1--)
	{
		if (!isdigit(s1[len_s1]))
		{
			free(result);
			printf("Error\n"), exit(98);
		}
		x = s1[len_s1] - '0';
		z = 0;
		for (len_s2 = _strlen(s2) - 1; len_s2 >= 0; len_s2--)
		{
			if (!isdigit(s2[len_s2]))
			{
				free(result);
				printf("Error\n"), exit(98);
			}
			y = s2[len_s2] - '0';
			z += result[len_s1 + len_s2 + 1] + (x * y);
			result[len_s1 + len_s2 + 1] = z % 10;
			z /= 10;
		}
		if (z)
			result[len_s1 + len_s2 + 1] += z;
	}
	return (result);
}

/**
 * main - multiplies two positive numbers
 * @argc: first number
 * @argv: second number
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i, x, length = 0;
	char *result;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	length = _strlen(argv[1]) + _strlen(argv[2]);
	result = multiply(argv[1], argv[2]);
	x = 0;
	for (i = 0; i < length; i++)
	{
		if (result[i])
			x = 1;
		if (x)
			_putchar(result[i] + '0');
	}
	if (x == 0)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
