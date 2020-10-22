#ifndef __SUBSTRING_H__
#define __SUBSTRING_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_OFFSET(x) ((x) - 97)
#define TRIE_SIZE 26
#define SEGMENT_COUNT 256

/**
 * struct Trie - trie node
 *
 * @children: child nodes
 * @total: total number of instances of a word
 * @count: decremented during searching
 * @isWord: boolean 1 if end of word, 0 if not
 * @next: linked list node
 */
typedef struct Trie
{
	struct Trie *children[TRIE_SIZE];
	int total;
	int count;
	int isWord;
	struct tnode *next;
} Trie;

int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* __SUBSTRING_H__ */
