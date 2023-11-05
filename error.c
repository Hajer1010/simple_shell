#include "shell.h"
/*
 * is_del - checks delimiter
 * @a: char
 * @d: delimter
 * Return: 1 0
 */
int is_del(char a, char *d)
{
	while (*d != '\0')
	{
		if (a == *d)
		{
			return (1);
		}
		d++;
	}
	return (0);
}
/*
 *
 */

