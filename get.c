#include "shell.h"
/**
 * _free - free string
 * @s: string
 */
void _free(char **s)
{
	char **m = s;

	if (s == NULL)
		return ;
	while (s)
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
	void *new;
	unsigned int i;

	if (new_size == old_size)
	{
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		new = malloc(new_size);
		if (new == NULL)
		{
			return (NULL);
		}
		return (new);
	}
	if (new_size > old_size)
	{
		new = malloc(new_size);
		if (new == NULL)
		{
			return (NULL);
		}
		for (i = 0; i < old_size && i < new_size; i++)
			*((char *)new + i) = *((char *)ptr + i);
		free(ptr);
	}
	return (new);
}
