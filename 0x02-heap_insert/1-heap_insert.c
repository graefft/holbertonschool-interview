#include "binary_trees.h"

/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: binary tree
 * Return: the size of @tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}

/**
 * heapify - finds starting node for heap
 * @node: node to start traversing up tree
 * Return: pointer to root node
 */
heap_t *heapify(heap_t *node)
{
	int temp;

	if (!node || !node->parent)
		return (node);

	while (node->parent)
	{
		if (node->n < node->parent->n)
			return (node);
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 *
 * @root: double pointer to root node of Heap
 * @value: value stored in node to be inserted
 *
 * Return: pointer to inserted node or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int bitIndex = 0;
	int mask;
	ssize_t n = binary_tree_size(*root) + 1;
	heap_t *new_node = NULL;
	heap_t *node = *root;

	new_node = binary_tree_node(node, value);
	if (!new_node)
		return (NULL);
	if (!*root)
		return (*root = new_node);

	while (1)
	{
		if (1 << (bitIndex + 1) > n)
			break;
		bitIndex++;
	}

	bitIndex--;

	for (; bitIndex > 0; bitIndex--)
	{
		mask = (1 << bitIndex);
		if (n & mask)
			node = node->right;
		else
			node = node->left;
	}
	if (n & 1)
		node->right = new_node;
	else
		node->left = new_node;
	new_node->parent = node;
	return (heapify(new_node));
}
