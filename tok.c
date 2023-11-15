#include "shell.h"
/**
 * strok - divide string to words
 * @st: string
 * @del: delimter
 * Return: ptr
 */
char **strok(char *st, char *del)
{
	int x, y, i, j, n = 0;
	char **str;

	if (st == NULL || st[0] == 0)
		return (NULL);
	if (!del)
		del = " ";
	for (i = 0; st[i] != '\0'; i++)
		if (!is_del(st[i], del) && (is_del(st[i + 1], del) || !st[i + 1]))
		n++;
	if (n == 0)
		return (NULL);
	str = malloc((1 + n) * sizeof(char *));
	if (!str)
		return (NULL);
	for (i = 0, j = 0; j < n; j++)
	{
		while (is_del(st[i], del))
			i++;
		x = 0;
		while (!is_del(st[i + x], del) && st[i + x])
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
/**
 * **strok2 - function
 * @st: input
 * @del: delimiter
 * Return: ptr
 */
char **strok2(char *st, char del)
{
	int x, y, i, j, n = 0;
	char **str;

	if (st == NULL || st[0] == 0)
		return (NULL);
	for (i = 0; st[i] != '\0'; i++)
		if ((st[i] != del && st[i + 1] == del) ||
			(st[i] != del && !st[i + 1]) || st[i + 1] == del)
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
