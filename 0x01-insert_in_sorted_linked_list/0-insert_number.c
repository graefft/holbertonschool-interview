#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly-linked list
 * @head: double pointer to head of list
 * @number: number to insert
 * Return: address of new node or NULL if failure
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t **current;
	listint_t *new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->n = number;
	new->next = NULL;

	current = head;

	if (!*head || new->n < (*head)->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	while (&(*current)->next && (*current)->next->n < new->n)
		current = &(*current)->next;

	new->next = (*current)->next;
	(*current)->next = new;

	return (*current);
}
