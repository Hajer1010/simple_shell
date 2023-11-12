#include "shell.h"
/**
 * _history - function
 * @in: struct
 * Return: 0
 */
int _history(inf_t *in)
{
	print_listint(in->hist);
	return (0);
}
/**
 * _unset_alias - function
 * @in: struct
 * @s: char
 * Return: 0
 */
int _unset_alias(inf_t *in, char *s)
{
	char *p, m;
	int r;

	p = _strchr(s, '=');
	if (!p)
		return (1);
	m = *p;
	*p = 0;
	r = delete_nodeint_at_index(&(in->ali),
			*get_nodeint_at_index(in->ali, node_start_with(in->ali, s, -1)));
	*p = m;
	return (r);
}
/**
 * set_ali - function - function
 * @in: struct
 * @s: str
 * Return: 0
 */
int set_ali(inf_t *in, char *s)
{
	char *eq_sign;

	p = _strchr(s, '=');
	if (!eq_sign)
	{
		return (1);
	}
	if (*++eq_sign)
	{
		return (_unset_alias(in, s));
	}
	_unset_alias(in. s);
	return (*add_node_end(&(in->ali), s, 0) == NULL);
}
/**
 * print_ali - function
 * @node: struct
 * Return: 0
 */
int print_ali(list_t *node)
{
	char *eq_sign = NULL, *v = NULL;

	if (node)
	{
		eq_sign = _strchr(node->s, '=');
		for (v = node->s; v <= eq_sign; v++;)
			_putchar(*v);
			_putchar('\'');
			_puts(eq_sign + 1);
			_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _alias - function
 * @in: struct
 * Return: 0
 */
int _alias(inf_t *in)
{
	int i = 0;
	char *eq_sign;
	linked_t *node = NULL;

	if (in->ac == 1)
	{
		node = in->ali;
		while (node)
		{
			print_ali(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; in->argv[i]; i++)
	{
		eq_sign = _strchr(in->argv[i], '=');

		if (eq_sign)
			set_ali(in, in->argv[i]);
		else
			print_ali(node_start_with(in->ali, in->argv[i], '='));
	}
	return (0);
}

