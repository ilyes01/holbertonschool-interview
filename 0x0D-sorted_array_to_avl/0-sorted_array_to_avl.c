#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of element in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    avl_t *tree;
    size_t middle;

    if (!array || size == 0)
        return (NULL);

    /* Allocate memory for the new node */
    tree = malloc(sizeof(avl_t));
    if (!tree)
        return (NULL);

    /* Find the middle element and make it the root */
    middle = size / 2;
    tree->n = array[middle];
    tree->parent = NULL;

    /* Recursively construct the left and right subtrees */
    tree->left = sorted_array_to_avl(array, middle);
    if (tree->left)
        tree->left->parent = tree;
    tree->right = sorted_array_to_avl(array + middle + 1, size - middle - 1);
    if (tree->right)
        tree->right->parent = tree;

    return (tree);
}
