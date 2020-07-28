#include "lists.h"

/**
 * find_listint_loop - finds a loop in a singly-linked list
 *
 * @head: head of list
 *
 * Return: node where cycle starts, or NULL if there is no cycle
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = NULL;
	listint_t *fast = NULL;

	if (!head)
		return (NULL);

	slow = head;
	fast = head;

	while (fast->next->next && fast)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (fast);
		}
	}
	return (NULL);
}
