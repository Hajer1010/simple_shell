#include "shell.h"
/**
 * listint_len - function
 * @h: ptr
 * Return: length
 */
size_t listint_len(const listint_t *h)
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
 * print_listint - function
 * @h: ptr
 * Return: size
 */
size_t print_listint(const listint_t *h)
{
	size_t c = 0;

	while (h)
	{
		printf("%d\n", h->n);
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
