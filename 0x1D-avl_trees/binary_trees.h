#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/* Structure for a binary tree node */
typedef struct binary_tree_s binary_tree_t;

/* Binary tree node */
struct binary_tree_s
{
    int n;
    binary_tree_t *parent;
    binary_tree_t *left;
    binary_tree_t *right;
};

/* Function prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);

int binary_tree_is_avl(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
