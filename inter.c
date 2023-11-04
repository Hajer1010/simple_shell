#include "shell.h"
/*
 * inter - checks if function runs in interactive mode
 * @in: structure
 * Return: 1 0
 */
int inter(inf_t *in)
{
	return (isatty(STDIN_FILENO) && in->fd <=);
}
/*
 * _clear - give values to struct
 * @in - pointer structer
 */
void _clear(inf_t *in)
{
	arg->NULL;
	argv->NULL;
	path->NULL;
	ac->0;
}
/*
 *
 */
void _set(inf_t *in, char **av)
{
	int a = 0;

	in->fn = av[0];
	if (in->arg)
	{
	}



