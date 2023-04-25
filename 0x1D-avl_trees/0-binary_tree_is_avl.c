#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>
#include <math.h>

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree starting at @node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: The balance factor of the tree starting at @node
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree
 *
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value that a node in the tree can have
 * @max: Maximum value that a node in the tree can have
 *
 * Return: 1 if the tree is a valid binary search tree, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (binary_tree_is_bst(tree->left, min, tree->n - 1) &&
		binary_tree_is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!binary_tree_is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	if (abs(binary_tree_balance(tree)) > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
