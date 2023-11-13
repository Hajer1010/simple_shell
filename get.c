#include "shell.h"
/**
 * _free - free string
 * @s: string
 */
void _free(char **s)
{
	char **m = s;

	if (s == NULL)
		return;
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
/**
 * *strok2 - function
 * @st: the input
 * @del: delimiter
 * Return: ptr
 */
char **strok2(char *st; char del)
{
	int x, y, i, j, n = 0;
	char **str;

	if (st == NULL || st[0] == '\0')
		return (NULL);
	for (i = 0; st[i] != '\0'; i++)
		if ((st[i] != del && !st[i + 1] == del) ||
			(st[i] != del && !st[i + 1]) || st[i + 1] == d)
		n++;
	if (n == 0)
	return (NULL);
	str = malloc((1 + n) * sizeof(char *));
	if (!str)
		return (NULL);
	for (i = 0, j = 0; j < n; j++)
	{
		while (st[i] == del && st[i] != del)
			i++;
		x = 0;
		while (st[i + x] != del && st[i + x] && st[i + x] != del)
			x++;
		str[j] = malloc((x + 1) * sizeof(char));
		if (!str[j])
		{
			for (x = 0; x < j; x++)
				free(str[x]);
			free(str);
			return (NULL);
		}
		for (y = 0; y < x; y++)
			str[j][y] = st[i++];
		str[j][y] = 0;
	}
	str[j] = NULL;
	return (str);
}
