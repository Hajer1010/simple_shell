#include "shell.h"
/**
 *_memset - function that fills memory with a constant byte
 * @n: bytes
 * @b: const
 * @s: pointer to the memory area
 * Return: pointer
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
	{
		s[a] = b;
	}
	return (s);
}
/**
 * _free - free string
 * @s: string
 */
void _free(char **s)
{
	char **m = s;

	if (!s)
		return;
	while (*s)
	{
		free(*s++);
	}
	free(m);
}
/**
 * *_realloc-entry point
 * @ptr: ptr
 * @old_size: int
 * @new_size: int
 * Return: nothing
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);
	new = malloc(new_size);
	if (!new)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		new[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (new);
}
