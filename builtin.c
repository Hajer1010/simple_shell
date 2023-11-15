#include "shell.h"
/**
 * _myexit - exits the shell
 * @in: Struct
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _myexit(inf_t *in)
{
	int exitcheck;

	if (in->argv[1])
	{
		exitcheck = e_atoi(in->argv[1]);
		if (exitcheck == -1)
		{
			in->status = 2;
			_perror(in, "Illegal number: ");
			_eputs(in->argv[1]);
			_eputchar('\n');
			return (1);
		}
		in->ern = e_atoi(in->argv[1]);
		return (-2);
	}
	in->ern = -1;
	return (-2);
}
/**
* _mycd - function
* @in: Structure
* Return: Always 0
*/
int _mycd(inf_t *in)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!in->argv[1])
	{
		dir = _getenv(in, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(in, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(in->argv[1], "-") == 0)
	{
		if (!_getenv(in, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(in, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((dir = _getenv(in, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(in->argv[1]);
	if (chdir_ret == -1)
	{
		_perror(in, "can't cd to ");
		_eputs(in->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(in, "OLDPWD", _getenv(in, "PWD="));
		_setenv(in, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * _myhelp - changes the current directory of the process
 * @in: Structure containing potential argument
 * Return: Always 0
 */
int _myhelp(inf_t *in)
{
	char **arg_array;

	arg_array = in->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}

