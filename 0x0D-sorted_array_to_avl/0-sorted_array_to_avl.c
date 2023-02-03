#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


// Recursive function to create nodes for AVL tree
avl_t *create_node(int *array, avl_t *parent, int start, int end) {
    int mid = (start + end) / 2;
    avl_t *new_node = malloc(sizeof(avl_t));
    // Check if memory allocation was successful
    if (!new_node) return NULL;
    // Assign data and parent to the node
    new_node->n = array[mid];
    // Create left child node if there's a sub-array on the left
    new_node->left = start <= mid - 1 ? create_node(array, new_node, start, mid - 1) : NULL;
    // Create right child node if there's a sub-array on the right
    new_node->right = mid + 1 <= end ? create_node(array, new_node, mid + 1, end) : NULL;
    return new_node;
}

// Function to transform sorted array to AVL tree
avl_t *sorted_array_to_avl(int *array, size_t size) {
    int mid = size / 2;
    avl_t *head = malloc(sizeof(avl_t));
    // Check if memory allocation was successful
    if (!head) return NULL;
    // Assign data to the head node
    head->n = array[mid];
    // Create left child node if the array has at least two elements
    head->left = size >= 2 ? create_node(array, head, 0, mid - 1) : NULL;
    // Create right child node if the array has at least two elements
    head->right = size >= 2 ? create_node(array, head, mid + 1, size - 1) : NULL;
    return head;
}

