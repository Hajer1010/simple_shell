#include "shell.h"
/**
 * bufree - free ptr
 * @p: pointer
 * Return: 0 1
 */
int bufree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
