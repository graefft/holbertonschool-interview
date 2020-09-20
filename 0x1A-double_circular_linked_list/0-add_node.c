#include "list.h"

/**
 * add_node_begin - adds node to beginning of doubly-linked list
 *
 * @list: pointer to list to modify
 * @str: string to copy into new node
 * Return: address of new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;

	if (!list || !str)
		return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
	{
		perror("malloc");
		return (NULL);
	}
	new_node->str = strdup(str);

	if (*list)
	{
		new_node->prev = (*list)->prev;
		new_node->next = *list;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
		*list = new_node;
	}
	else
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
	}
	return (new_node);
}


/**
 * add_node_end - adds node to end of doubly-linked list
 *
 * @list: pointer to list to modify
 * @str: string to copy into new node
 * Return: address of new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *tmp;

	if (!list || !str)
		return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		perror("strdup");
		return (NULL);
	}
	new_node->next = new_node->prev = NULL;

	if (*list)
	{
		tmp = (*list)->prev;
		tmp->next = new_node;
		new_node->prev = tmp;
		new_node->next = *list;
		(*list)->prev = new_node;
	}
	else
	{
		*list = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	return (new_node);
}
