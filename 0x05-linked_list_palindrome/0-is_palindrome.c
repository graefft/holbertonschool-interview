#include "lists.h"

/**
 * is_palindrome - checks if singly-linked list is a palindrome
 * @head: double pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = NULL;
	listint_t *fast = NULL;

	if (!head || !*head)
		return (1);

	slow = *head;
	fast = *head;

	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	slow = slow->next;

	reverse_list(&slow);

	while ((*head)->next && slow->next)
	{
		if ((*head)->n != slow->n)
			return (0);
		*head = (*head)->next;
		slow = slow->next;
	}
	if ((*head)->n != slow->n)
		return (0);
	return (1);
}

/**
 * reverse_list - reverses a singly-linked list
 * @head: head of list to reverse
 * Return: new head of list
 */
void reverse_list(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;
	listint_t *next;

	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}
