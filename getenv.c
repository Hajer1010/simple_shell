#include "shell.h"
/**
* get_environ - returns the string array copy of our environ
* @in: Structure containing potential arguments.
* Return: Always 0
*/
char **get_environ(inf_t *in)
{
	if (!in->env || in->en_mod)
	{
		in->env = list_to_strings(in->en);
		in->en_mod = 0;
	}
	return (in->env);
}
/**
* _unsetenv - Remove an environment variable
* @in: Structure containing argument
* Return: 1 on delete, 0 otherwise
* @var: the string env var property
*/
int _unsetenv(inf_t *in, char *var)
{
	list_t *node = in->en;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);
	while (node)
	{
		p = start_with(node->s, var);
		if (p && *p == '=')
		{
			in->en_mod = delete_node_at_index(&(in->en), i);
			i = 0;
			node = in->en;
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
	node = in->en;
	while (node)
	{
		p = start_with(node->s, var);
		if (p && *p == '=')
		{
			free(node->s);
			node->s = buf;
			in->en_mod = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(in->en), buf, 0);
	free(buf);
	in->en_mod = 1;
	return (0);
}
