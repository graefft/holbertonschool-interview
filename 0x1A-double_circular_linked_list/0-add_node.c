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
	List *new_node, *tmp;

	if (!list || !str)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
	{
		perror("malloc");
		return (NULL);
	}
	new_node->str = strdup(str);

	if (*list)
	{
		tmp = *list;
		while (tmp->next && tmp->next != *list)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
		new_node->next = *list;
		(*list)->prev = new_node;
		*list = new_node;
	}
	else
	{
		new_node->prev = NULL;
		new_node->next = NULL;
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

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);

	if (*list)
	{
		tmp = *list;
		while (tmp->next && tmp->next != *list)
			tmp = tmp->next;
		tmp->next = new_node;
		(*list)->prev = new_node;
		new_node->prev = tmp;
		new_node->next = *list;
	}
	else
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		*list = new_node;
	}
	return (new_node);
}
