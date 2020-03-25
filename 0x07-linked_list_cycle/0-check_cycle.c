#include "lists.h"

/**
 * check_cycle - checks if linked list has a cycle
 * @list: pointer to head of list
 * Return: 1 if it is a cycle, otherwise 0
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = NULL;
	listint_t *fast = NULL;

	if (!list)
		return (0);

	slow = fast = list;

	while (fast&& fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
