#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: binary tree
 * Return: height of the @tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height;
	size_t r_height;

	if (tree == NULL)
		return (-1);

	if (tree->left)
		l_height = 1 + binary_tree_height(tree->left);
	else
		l_height = 0;

	if (tree->right)
		r_height = 1 + binary_tree_height(tree->right);
	else
		r_height = 0;

	return (l_height > r_height ? l_height : r_height);
}

/**
 * balance - function that measures the balance factor
 * of a binary tree
 * @tree: pointer to root node of the tree to measure balance
 * Return: balance factor
 */
int balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (1);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	return (abs(left - right) <= 1
		&& balance(tree->left)
		&& balance(tree->right));
}



/**
 * isBST - helper function
 * @node: binary tree
 * @min: min in the left subtree
 * @max: max in the right subtree
 * Return: 1 or 0
 */
int isBST(binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);
	if (node->n < min || node->n > max)
		return (0);
	return
		(isBST(node->left, min, node->n - 1) &&
		 isBST(node->right, node->n + 1, max));
}

/**
 * binary_tree_is_bst - function that checks if a binary tree is a
 * valid Binary Search Tree
 * @tree: binary tree
 * Return: 1 if @tree is BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (isBST((binary_tree_t *)tree, INT_MIN, INT_MAX));
}


/**
 * binary_tree_is_avl - function that checks if a
 * binary tree is a valid AVL Tree
 * @tree: binary tree
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int bst, blc;

	if (!tree)
		return (0);

	bst = binary_tree_is_bst(tree);
	blc = balance(tree);
	return (bst == 1 && blc == 1);
}
