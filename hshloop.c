#include "shell.h"
/**
 * loophsh - loop prompt
 * @args: ptr
 * Return: 0 1
 */
int loophsh(char **args)
{
	int sta = system(*args);

	while (*args != NULL)
	{
		if (sta != 0)
		{
			printf("errer excuting command: %s\n", *args);
			return (1);
		}
		args++;
	}
	return (0);
}
