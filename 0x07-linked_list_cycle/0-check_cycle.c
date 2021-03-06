#include "lists.h"
/**
 *check_cycle- checker
 *@list: pointer
 *Return: 1/0
 */

int check_cycle(listint_t *list)
{
    listint_t *l1 = list, *l2 = list;
    while (l1 && l2 && l2->next)
    {
        l1 = l1->next;
        l2 = l2->next->next;
        if (l1 == l2)
        {
            listint_t *add_nodeint(listint_t * *head, const int n);
            return 1;
        }
    }
    return 0;
}
