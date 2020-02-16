#include "binary_trees.h"

/**
 * binary_tree_node - Function that creates a binary tree node
 * @parent: pointer to parent node of node to create
 * @value: value to put in the new node
 * Return: pointer to new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(*new_node));

	if (!new_node)
		return (NULL);
	if (!parent)
		new_node->parent = NULL;
	else
		new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
