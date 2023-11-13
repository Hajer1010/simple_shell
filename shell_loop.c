#include "shell.h"
/**
 * shell- entry point
 * @in: struct
 * @av: arguments
 * Return: 0
 */
int shell(inf_t *in, char **av)
{
	ssize_t x = 0;
	int bul = 0;

	while (x != -1 && bul != -2)
	{
		_clear(in);
		if (inter(in))
			_puts("$");
		_eputchar(BUF_FLUSH);
		x = get_input(in);
		if (x != -1)
		{
			_set(in, av);
			bul = find_builtin(in);
			if (bul == -1)
				find_cmd(in);
		}
		else if (inter(in))
		_putchar('\n');
		free_info(in, 0);
	}
	w_hist(in);
	free_info(in, 1);
	if (!inter(in) && in->status)
		exit(in->status);
	if (bul == -2)
	{
		if (in->ern == -1)
			exit(in->status);
		exit(in->ern);
	}
	return (bul);
}
/**
 * find_builin - function
 * @in: struct
 * Return: -1 0 1 2
 */
int find_builin(inf_t *in)
{
	int x, builtin_r = -1;
	builtin_table builtint = {
		{"env", _myenv},
		{"exit", _myexit},
		{"help", _myhelp},
		{"history", _history},
		{"cd", _mycd},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"alias", _alias},
		{NULL, NULL}
	};
	for (x = 0; builtint[x].t; x++)
		if (_strcmp(in->argv[0], builtint[x].t) == 0)
		{
			in->lc++;
			builtin_r = builtint[x].fun(inf);
			break;
		}
	return (builtin_r);
}
/**
 *
 */
void find_cmd(inf_t *in)
{
	char *path = NULL;
	int x, y;

	in->path = in->argv[0];
	if (in->lcf == 1)
	{
		in->lc++;
		in->lcf = 0;
	}
	for (x = 0, y = 0; in->arg[x]; x++)
		if (!is_del(in->arg[x], "\t\n"))
			y++;
	if (!y)
		return ;
	path = find_path(in, _getenv(in, "PATH="),
			in->argv[0]);
	if (path)
	{
		in->path = path;
		fork_cmd(in);
	}
	else
	{
		if ((inter(in) || _getenv(in, "PATH=")
					|| in->argv[0][0] == '/')
				&& is_cmd(in->argv[0]))
			fork_cmd(in);
		else if (*(in->arg) != '\n')
		{
			in->status = 127;
			_perror(in, "not found\n");
		}
	}
}
