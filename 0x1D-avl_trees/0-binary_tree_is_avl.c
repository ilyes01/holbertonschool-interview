#include "binary_trees.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree, or 0 if @tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: A pointer to the root node of the tree.
 * @min: The minimum value the node's value can be.
 * @max: The maximum value the node's value can be.
 *
 * Return: 1 if the tree is a valid BST, otherwise 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (binary_tree_is_bst(tree->left, min, tree->n - 1) &&
			binary_tree_is_bst(tree->right, tree->n + 1, max));
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
		return (0);

	if (!binary_tree_is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	if (abs(binary_tree_height(tree->left) - binary_tree_height(tree->right)) > 1)
		return (1);

	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}
