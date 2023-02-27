#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * linear_skip - performs linear skip search on a sorted linked list
 *
 * @list: head of the sorted list
 * @value: the value to search for
 *
 * Return: pointer to the node containing the searched value or NULL on failure
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	/* Initialize two pointers to the head of the list */
	skiplist_t *explore = list, *current = list;

	/* Check if the list is empty */
	if (!list)
		return (NULL);

	/* Traverse the list in jumps until reaching the value or end of the list */
	for (; explore->express != NULL; explore = explore->express)
	{
		current = explore;

		/* Print the checked value at each index during the traversal */
		printf("Value checked at index [%ld] = [%d]\n", explore->index, explore->n);

		/* If the current value is greater or equal to the search value or
		 * we've reached the end of the list, perform linear search on the
		 * sublist between the current and previous pointers */
		if (explore->n >= value)
		{
			/* Print the index range of the sublist we're performing linear search on */
			printf("Value found between indexes [%ld] and [%ld]\n", current->index, explore->index);

			/* Perform linear search on the sublist and return the node containing
			 * the searched value or NULL if the value is not found */
			for (; current != explore->next; current = current->next)
			{
				printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
				if (current->n == value)
					return (current);
			}

			return (NULL);
		}
	}

	/* If we've reached the end of the list and the current value
	 * is less than the search value, move the explore pointer to the
	 * last node in the list */
	if (explore->n < value)
	{
		current = explore;
		for (; explore->next != NULL; explore = explore->next)
			continue;
	}

	/* Print the index range of the sublist we're performing linear search on */
	printf("Value found between indexes [%ld] and [%ld]\n", current->index, explore->index);

	/* Perform linear search on the sublist and return the node containing
	 * the searched value or NULL if the value is not found */
	for (; current != explore->next; current = current->next)
	{
		printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
		if (current->n == value)
			return (current);
	}

	/* If we reach the end of the list without finding the value, return NULL */
	return (NULL);
}
