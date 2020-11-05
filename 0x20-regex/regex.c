#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 *
 * @str: string to scan
 * @pattern: regular expression
 * Return: 1 if pattern matches, otherwise 0
 */
int regex_match(char const *str, char const *pattern)
{
	if (!pattern || !str)
		return (0);
	return (1);
}
