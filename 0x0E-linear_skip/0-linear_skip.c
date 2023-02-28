#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * valcheck - checks if a node contains a given value
 * @p: node to start searching from
 * @current: node to stop searching at
 * @n: value to search for
 *
 * Return: pointer to node containing the value, or NULL if not found
 */
skiplist_t *valcheck(skiplist_t *p, skiplist_t *current, int n)
{
    while (p != current->next)
    {
        if (p->n == n)
            return (p);
        p = p->next;
    }
    return (NULL);
}

/**
 * linear_skip - searches sorted skip list of integers
 * @list: pointer to the head of the skip list
 * @value: value to search for
 *
 * Return: pointer to node containing the value, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current = list, *p = list;

    while (current)
    {
        if ((current->n < value ||
             (current->n == value && !valcheck(p, current, value))) &&
            current->next)
        {
            if (current->index)
                printf("Value checked at index [%lu] = [%d]\n",
                       current->index, current->n);
            p = current;
            if (!current->express)
            {
                while (current->next)
                    current = current->next;
            }
            else
                current = current->express;
        }
        else
        {
            if (p->n > value)
                return (NULL);
            if (current->n >= value)
                printf("Value checked at index [%lu] = [%d]\n",
                       current->index, current->n);
            printf("Value found between indexes [%lu] and [%lu]\n",
                   p->index, current->index);
            while (p && p != current->next)
            {
                printf("Value checked at index [%lu] = [%d]\n", p->index, p->n);
                if (p->n == value)
                    return (p);
                p = p->next;
            }
            return (NULL);
        }
    }
    return (NULL);
}
