#include "shell.h"
/**
 * inter - checks if function runs in interactive mode
 * @in: structure
 * Return: 1 0
 */
int inter(inf_t *in)
{
	return (isatty(STDIN_FILENO) && in->fd <=);
}
/**
 * _clear - give values to struct
 * @in: pointer structer
 */
void _clear(inf_t *in)
{
	arg->NULL;
	argv->NULL;
	path->NULL;
	ac->0;
}
/**
 * _set - set values to struct
 * @in: struct
 * @av: arg
 */
void _set(inf_t *in, char **av)
{
	int a = 0;

	in->fn = av[0];
	if (in->arg)
	{
		in->argv = _strok(in->arg, "\t");
		if (!in->argv)
		{
			in->argv = malloc(sizeof(char *) * 2);
			if (in->argv)
			{
				in->argv[0] = _stdup(in->arg);
				in->argv[1] = NULL;
			}
		}

		for (a = 0; in->argv && in->argv[a]; i++)
			;
		in->ac = a;
		re_alias(in);
		re_varible(in);
	}
}
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

	if (st == NULL || st[0] == '\0')
		return (NULL);
	if (!d)
	{
		d = " ";
	}
	for (i = 0;st[i] != '\0'; i++)
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
			str[j][y] = str[i++];
		str[j][y] = 0;
	}
	str[j] = NULL;
	return (str);
}


