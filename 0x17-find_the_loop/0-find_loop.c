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

	if (!head || !head->next)
		return (NULL);

	slow = head->next;
	fast = head->next->next;

	while (fast && fast->next)
	{
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}
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
	return (NULL);
}
