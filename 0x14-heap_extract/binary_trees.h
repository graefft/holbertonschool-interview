#ifndef __BINARY_TREES_H__
#define __BINARY_TREES_H__

#include <stdio.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

int heap_extract(heap_t **root);
size_t binary_tree_height(const binary_tree_t *tree);
int is_perfect_recursion(const binary_tree_t *tree, int depth, int level);
int binary_tree_is_perfect(const binary_tree_t *tree);
void full_heapify(heap_t *node);

#endif
