#include "palindrome.h"

/**
 * is_palindrome - checks if an unsigned int is a palindrome
 * @n: number to check
 *
 * Return: 1 if palindrome, otherwise 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long original = n;
	unsigned long reverse = 0;
	unsigned long remainder;

	while (n > 0)
	{
		remainder = n % 10;
		reverse = reverse * 10 + remainder;
		n = n / 10;
	}
	if (original == reverse)
		return (1);
	return (0);
}
