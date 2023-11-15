#include "shell.h"
/**
 * get_environ - returns the string array copy of our environ
 * @in: Structure containing potential arguments.
 * Return: Always 0
 */
char **get_environ(inf_t *in)
{
	if (!in->environ || in->en_mod)
	{
		in->environ = list_to_strings(in->env);
		in->en_mod = 0;
	}
	return (in->environ);
}
/**
 * _unsetenv - Remove an environment variable
 * @in: Structure containing argument
 * Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(inf_t *in, char *var)
{
	list_t *node = in->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);
	while (node)
	{
		p = start_with(node->str, var);
		if (p && *p == '=')
		{
			in->en_mod = delete_node_at_index(&(in->env), i);
			i = 0;
			node = in->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (in->en_mod);
}
/**
 * _setenv - Initialize anew environment
 * @in: Structure
 * @var: the string env var property
 * @value: the string env var value
 *  Return: 0
 */
int _setenv(inf_t *in, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);
	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = in->env;
	while (node)
	{
		p = start_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			in->en_mod = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(in->env), buf, 0);
	free(buf);
	in->en_mod = 1;
	return (0);
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
