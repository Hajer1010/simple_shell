#include "shell.h"
/**
 * add_node - function
 * @head: ptr
 * @str: str
 * Return: length
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));

	if (!head || !new)
		return (NULL);
	if (str)
	{
		new->str = strdup(str);
		if (!new->str)
		{
			free(new);
			return (NULL);
		}
		new->len = strlen(new->str);
	}
	new->next = *head;
	*head = new;
	return (new);
}
/**
 * add_node_end - function
 * @head: ptr
 * @str: str
 * Return: length
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));
	list_t *node = *head;

	if (!head || !new)
		return (NULL);
	if (str)
	{
		new->str = strdup(str);
		if (!new->str)
		{
			free(new);
			return (NULL);
		}
		new->len = strlen(new->str);
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
	else
		*head = new;
	return (new);
}
/**
 * delete_nodeint_at_index - function
 * @head: ptr
 * @index: index
 * Return: 1, -1
 */
int delete_nodeint_at_index(list_t **head, unsigned int index)
{
	list_t *node, *pre_node;
	unsigned int c = 0;

	if (!head || !*head)
		return (-1);
	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (c == index)
		{
			pre_node->next = node->next;
			free(node);
			return (1);
		}
		c++;
		pre_node = node;
		node = node->next;
	}
	return (-1);
}
/**
 * free_list - FUNCTION
 * @head: ptr
 * Return: ptr
 */
void free_list(list_t **head)
{
	list_t *temp, *node;

	if (!head)
		return;
	node = *head;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	*head = NULL;
}
