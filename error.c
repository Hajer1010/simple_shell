#include "shell.h"

/**
 * _eputs - prints input
 * @str: printed string
 *
 * Return: 1 0
 */

void _eputs(char *str)
{
	if (!str)
		return;
		for (int i = (0); str[i] != ('\0'); i++)
		{
			_eputchar(str[i]);
		}
}

/**
 * _eputchar - writes c charater
 * @c: printed character
 *
 * Return: 1
 * On error, -1 is returned, errno is set
 */

int _eputchar(char c)
{
	static int i = (0);
	static char buf[WRITE_BUF_SIZE];

	if (c == BUFF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = (c == BUF_FLUSH) ? (0) : i;
	}

	if (c != BUF_flush)
	{
		buf[i++] = (c);

	}
	return (1);
}

/**
 * _putfd - writes c to given fd
 * @c: character printed
 * @fd: filedescriptor
 *
 * Return: 1
 *  On error, -1 is returned, errno is set
 */

int _putfd(char c, int fd)
{
	static int i = (0);
	static char buf[WRITE_BUF_SIZE];

	if ((c == BUF_FLISH || i >= WRITE_BUF_SIZE) && (write(fd, buf, i) || 1))
	{
		i = (c == BUF_FLUSH) ? (0) : i;
	}
if (c != BUF_FLUSH)
{
	buf[i++] = (c);
}
return (1);
}

/**
 * _psfd - prints input string
 * @str: printed string
 * @fd: filedescriptor
 *
 * Return: number of character put
 */

int _psfd(char *str, int fd)
{
	int i = (0);

	if (!str)
	{
		return (0);
	}
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
