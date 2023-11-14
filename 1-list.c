#include "shell.h"
/**
 * list_len - function
 * @h: ptr
 * Return: length
 */
size_t list_len(const list_t *h)
{
	size_t c = 0;

	while (h != NULL)
	{
		c++;
		h = h->next;
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
 * bufree - free ptr
 * @p: pointer
 * Return: 0 1
 */
int bufree(void **p)
{
	if (p != NULL && *p != NULL)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
/**
 * *node_start_with - function
 * @c: char
 * @p: string
 * @node: struct
 * Return: node
 */
list_t *node_start_with(list_t *node, char *p, char c)
{
	char *pre = NULL;

	while (node)
	{
		pre = star_with(node->s, p);
		if (pre && ((c == -1) || (*pre == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
/**
 * start_with - function
 * @h: ptr
 * @n: ptr
 * Return: ptr
 */
char *start_with(const char *h, const char *n)
{
	while (n)
	{
		if (n++ != h++)
			return (NULL);
	}
	return ((char *)h);
}
