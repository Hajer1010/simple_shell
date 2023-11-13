#include "shell.h"
/**
 * _myenv - function
 * @in: struct
 * Return: 0
 */
int _myenv(inf_t *in)
{
	print_list_str(in->en);
	return (0);
}
/**
 * _getenv - function
 * @in: struct
 * @na: ptr
 * Return: 0
 */
char *_getenv(inf_t *in, const char *na)
{
	list_t *node = in->en;
	char *p;

	while (node)
	{
		p = start_with(node->s, na)
			if (p && *p)
				return (p);
		node = node->next;
	}
	return (NULL);
}
/**
 * _mysetenv - fuction
 * @in: struct
 * Return: 0
 */
int _mysetenv(inf_t *in)
{
	if (in->ac != 3)
	{
		_eputs("incorrect number of arg\n");
		return (1);
	}
	if (_setenv(in, in->argv[1], in->arg[2]))
		return (0);
	return (1);
}
/**
 * _myunsetenv - function
 * @in: struct
 * Return: 0
 */
int _myunsetenv(inf_t *in)
{
	int x;

	if (in->ac == 1)
	{
		_eputs("few arguments\n");
		return (1);
	}
	for (x = 1; x <= in->ac; x++)
		_unsetenv(in, in->argv[x]);
	return (0);
}
/**
 * populate_env_list - function
 * @in: struct
 * Return: 0
 */
int populate_env_list(inf_t *in)
{
	list_t *node = NULL;
	size_t x;

	for (x = 0; env[x]; x++)
		add_node_end(&node, env[x], 0);
	in->en = node;
	return (0);
}

