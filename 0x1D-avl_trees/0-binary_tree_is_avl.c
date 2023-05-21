#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree, or 0 if @tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_bst_util - Helper function to check if a binary tree is a valid BST.
 * @tree: A pointer to the root node of the tree.
 * @min: The minimum value the node's value can be.
 * @max: The maximum value the node's value can be.
 *
 * Return: 1 if the tree is a valid BST, otherwise 0.
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst_util(tree->left, min, tree->n - 1) &&
			is_bst_util(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a valid AVL tree, otherwise 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	if (!is_bst_util(tree, INT_MIN, INT_MAX))
		return (0);

	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}

