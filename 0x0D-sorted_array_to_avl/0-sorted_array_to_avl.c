#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 *
 * @parent: parent of new node
 * @value: value to insert in node
 * Return: pointer to new node
 */
avl_t *binary_tree_node(avl_t *parent, size_t value)
{
	avl_t *new_node = NULL;

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * rec_array_to_avl - recursive function to put array into AVL tree
 *
 * @array: pointer to first element in section of array
 * @start: start of section
 * @end: end of section
 *
 * Return: pointer to AVL tree
 */
avl_t *rec_array_to_avl(int *array, int start, int end)
{
	avl_t *root = NULL;
	int mid;

	if (start > end)
		return (NULL);

	mid = start + (end - start) / 2;

	printf("mid = %d\n\n", mid);

	root = binary_tree_node(NULL, array[mid]);
	if (!root)
		return (NULL);

	root->left = rec_array_to_avl(array, start, mid - 1);
	if (root->left)
		root->left->parent = root;

	root->right = rec_array_to_avl(array, mid + 1, end);
	if (root->right)
		root->right->parent = root;

	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);

	return (rec_array_to_avl(array, 0, size - 1));
}
