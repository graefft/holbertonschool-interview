#include "binary_trees.h"

/**
 * tree_height - function that measures the height of a binary tree
 * @tree: binary tree
 * Return: height of the @tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_height(tree->left) + tree_height(tree->right));
}

/**
 * is_perfect_recursion - recursive function to check if bt is perfect
 * @tree: root
 * @depth: depth
 * @level: checks level
 * Return: 1 if true, 0 if false
 */
int is_perfect_recursion(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursion(tree->left, depth, level + 1) &&
		is_perfect_recursion(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: binary tree
 * Return: 1 if @tree is perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth = 0;

	if (tree == NULL)
		return (0);

	while (tree)
	{
		depth++;
		tree = tree->left;
	}

	return (is_perfect_recursion(tree, depth, 0));
}

/**
 * full_heapify - heapifies full tree
 * @node: node of binary tree
 * Return: Nothing.
 */
void full_heapify(heap_t *node)
{
	int t;

	if (!node || (!node->left && !node->right))
		return;
	while (node)
	{
		if (node->left && node->right && node->n < node->right->n &&
		    node->n < node->left->n && node->left->n < node->right->n)
		{
			t = node->n, node->n = node->right->n, node->right->n = t;
			node = node->right;
		}
		else if (node->left && node->right && node->n < node->right->n
			 && node->n < node->left->n
			 && node->left->n > node->right->n)
		{
			t = node->n, node->n = node->left->n, node->left->n = t;
			node = node->left;
		}
		else if (node->left && node->left->n > node->n)
		{
			t = node->n, node->n = node->left->n, node->left->n = t;
			node = node->left;
		}
		else if (node->right && node->right->n > node->n)
		{
			t = node->n, node->n = node->right->n, node->right->n = t;
			node = node->right;
		}
		else
			return;
	}
}

/**
 * heap_extract - function that extracts the root node of a Max Binary Heap
 * @root: root of binary tree
 * Return: value of removed node on success, 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *curr = NULL;
	int r_full, l_full, r_height, l_height, temp;

	if (!root || !*root)
		return (0);
	curr = *root;
	while (curr)
	{
		if (!curr->left && !curr->right)
		{
			if (curr == *root)
			{
				temp = curr->n, free(curr), *root = NULL;
				return (temp);
			}

			temp = (*root)->n;
			(*root)->n = curr->n;
			curr->n = temp;
			if (curr->parent && curr->parent->left == curr)
				curr->parent->left = NULL;
			else if (curr->parent)
				curr->parent->right = NULL;
			free(curr);
			full_heapify(*root);
			return (temp);
		}
		r_full = binary_tree_is_perfect(curr->right);
		l_full = binary_tree_is_perfect(curr->left);
		r_height = tree_height(curr->right);
		l_height = tree_height(curr->left);
		if ((r_full && l_full && r_height < l_height)
		    || (r_full && !l_full && r_height != l_height)
		    || (!curr->right))
			curr = curr->left;
		else
			curr = curr->right;
	}
	return (0);
}
