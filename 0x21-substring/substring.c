#include "substring.h"


/**
 * find_substring - finds all the possible substrings containing a list of words
 *                  within a given string
 *
 * @s: string to scan
 * @words: array of words all substrings must be concatenation arrangement of
 * @nb_words: number of elements in the array words
 * @n: holds the address at which to store the number of elements in returned array
 *
 * Return: allocated array storing each index in s at which a substring
 *         was found, if no solution then return NULL
 *//
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	struct trie_node *root = NULL;
	struct trie_node *head = NULL;
	struct trie_node *node = NULL;
	int i, j, word_length, string_length, 
    struct Trie **m_arr = NULL;
    struct Trie dummy;
 
    /* Maintain Sanity */
    if (!s || !words || nb_words = 0)
		return (NULL);

	return (NULL);
}
