#include <limits.h>
#include "binary_trees.h"

int binary_tree_is_bst(const binary_tree_t *tree, int min, int max);
int binary_tree_balance(const binary_tree_t *tree);

int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    if (!binary_tree_is_bst(tree, INT_MIN, INT_MAX))
        return 0;

    if (binary_tree_balance(tree) < -1 || binary_tree_balance(tree) > 1)
        return 0;

    if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
        return 0;

    return 1;
}

int binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return 1;

    if (tree->n < min || tree->n > max)
        return 0;

    return binary_tree_is_bst(tree->left, min, tree->n - 1) &&
           binary_tree_is_bst(tree->right, tree->n + 1, max);
}

int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return binary_tree_height(tree->left) - binary_tree_height(tree->right);
}
