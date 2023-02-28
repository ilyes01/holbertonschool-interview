#include <stdio.h>
#include <stdlib.h>
#include "search.h"
/**
 * valcheck -  checker between prev and tmp
 * @p: node
 * @current: node
 * @n: what we searchnig for
 * Return: contains the value or NULL
 */
skiplist_t *valcheck(skiplist_t *p, skiplist_t *current, int n)
{
	for (; p != current->next; p = p->next)
	{
		if (p->n == n)
			return (p);
	}
	return (NULL);
}
/**
 * linear_skip - searches sorted skip list of integers
 * @list:  pointer
 * @value: the value we searching for
 * Return: a pointer
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list, *p = list;

	while (current)
	{
		if ((current->n < value
		|| ((current->n == value) && !(valcheck(p, current, value))))
		&& current->next)
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
				printf("Value checked at index [%lu] = [%d]\n", current->index,
				current->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
					p->index, current->index);
			for (; p && p != current->next; p = p->next)
			{
				printf("Value checked at index [%lu] = [%d]\n", p->index, p->n);
				if (p->n == value)
					return (p);
			}
			return (NULL);
		}
	}
	return (NULL);
}
