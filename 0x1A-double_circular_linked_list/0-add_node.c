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
	List *new_node = NULL;

	if (!list || !str)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
	{
		perror("malloc");
		return (NULL);
	}

	new_node->str = strdup(str);
	new_node->next = *list;
	new_node->prev = NULL;
	(*list)->prev = new_node;
	
	printf("string = %s\n", new_node->str);
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
	List *new_node = NULL, *tmp;

	if (!list || !*list)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	new_node->next = NULL;
	tmp = *list;

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new_node;
	new_node->prev = tmp;

	return (new_node);
}
