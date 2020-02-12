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

	if (!*head)
		return (NULL);

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->n = number;

	current = head;

	while (&(*current)->next && (*current)->n < new->n)
		current = &(*current)->next;

	new->next = *current;
	*current = new;
	return (*head);
}
