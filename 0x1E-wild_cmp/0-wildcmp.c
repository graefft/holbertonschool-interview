#include "holberton.h"

/**
 * wildcmp - compares two strings and has * as wildcard
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	if (!*s1 && *s2 == '*')
		return (wildcmp(s1, s2 + 1));
	if (!*s1 && *s2 != '*')
		return (!*s2);
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
