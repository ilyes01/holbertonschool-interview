#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* insert_node- inserts a number into a sorted singly linked list
*@head: pointer of the head of the list
* @number: var
* Return: new code
*/
listint_t *insert_node(listint_t **head, int number){

	listint_t *tmp, *in;
	listint_t *list;

	in = tmp = *head;
	if (head == NULL)
	return (NULL);
	list = malloc(sizeof(listint_t));
	if (list == NULL)
	return (NULL);
	list->next = NULL;
	list->n = number;
	if (!*head)
	{
		list->next = NULL;
		*head = list;
	return (list);
	}
	if ((*head)->n >= list->n)
	{
		list->next = *head;
		*head = list;
	return (list);
	}
	while (tmp && tmp->n < number)
	{
		in = tmp;
		tmp = tmp->next;

}
	list->next = tmp;
	in->next = list;
	return (list);
}
