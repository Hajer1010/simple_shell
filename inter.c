#include "shell.h"
/**
 * _clear - give values to struct
 * @in: pointer structer
 */
void _clear(inf_t *in)
{
	in->arg = NULL;
	in->argv = NULL;
	in->path = NULL;
	in->ac = 0;
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
		in->argv = strok(in->arg, " \t");
		if (!in->argv)
		{
			in->argv = malloc(sizeof(char *) * 2);
			if (in->argv)
			{
				in->argv[0] = _strdup(in->arg);
				in->argv[1] = NULL;
			}
		}

		for (a = 0; in->argv && in->argv[a]; a++)
			;
		in->ac = a;

		replace_alias(in);
		replace_vars(in);
	}
}
/**
 * free_info - function
 * @in: struct
 * @f: files
 */
void free_info(inf_t *in, int f)
{
	_free(in->argv);
	in->argv = NULL;
	in->path = NULL;
	if (f)
	{
		if (!in->cb)
			free(in->arg);
		if (in->env)
			free_list(&(in->env));
		if (in->his)
			free_list(&(in->his));
		if (in->ali)
			free_list(&(in->ali));
		_free(in->environ);
			in->environ = NULL;
		bufree((void **)in->cb);
		if (in->rfd > 2)
			close(in->rfd);
		_putchar(BUF_FLUSH);
	}
}
