#include "shell.h"
/**
 * list_len - function
 * @h: ptr
 * Return: length
 */
size_t list_len(const list_t *h)
{
	size_t c = 0;

	while (h)
	{
		h = h->next;
		c++;
	}
	return (c);
}
/**
 * print_list - function
 * @h: ptr
 * Return: size
 */
size_t print_list(const list_t *h)
{
	size_t c = 0;

	while (h)
	{
		_puts(con_num(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		c++;
	}
	return (c);
}
/**
 * *node_start_with - function
 * @c: char
 * @pre: string
 * @node: struct
 * Return: node
 */
list_t *node_start_with(list_t *node, char *pre, char c)
{
	char *p = NULL;

	while (node)
	{
		p = start_with(node->str, pre);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
/**
 * get_node_index - function
 * @head: ptr
 * @node: ptr
 * Return: index -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t x = 0;

	while (head)
	{
		if (head == node)
			return (x);
		head = head->next;
		x++;
	}
	return (-1);
}
/**
 * **list_to_strings - function
 * @h: ptr
 * Return: str
 */
char **list_to_strings(list_t *h)
{
	list_t *node = h;
	size_t x = list_len(h), y;
	char **st;
	char *str;

	if (!h || !x)
		return (NULL);
	st = malloc(sizeof(char *) * (x + 1));
	if (!st)
		return (NULL);
	for (x = 0; node; node = node->next, x++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (y = 0; y < x; y++)
				free(st[y]);
			free(st);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		st[x] = str;
	}
	st[x] = NULL;
	return (st);
}
