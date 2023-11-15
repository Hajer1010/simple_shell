#include "shell.h"
/**
 * _perror - func prints error message
 * @in: struct
 * @es: error string
 * Return: 0 -1
 */
void _perror(inf_t *in, char *es)
{
	_eputs(in->fn);
	_eputs(": ");
	print_dec(in->lc, STDERR_FILENO);
	_eputs(": ");
	_eputs(in->argv[0]);
	_eputs(": ");
	_eputs(es);
}
/**
 * print_dec - print decimals
 * @n:  inputs
 * @fd: filedescriptor
 * Return: numbers
 */
int print_dec(int n, int fd)
{
	int (*_putchars)(char) = _putchar;
	int x, c = 0;
	unsigned int ab, cu;

	if (fd == STDERR_FILENO)
	{
		_putchars = _eputchar;
	}
	if (n < 0)
	{
		ab = -n;
		_putchars('-');
		c++;
	}
	else
		ab = n;
	cu = ab;
	for (x = 1000000000; x > 1; x /= 10)
	{
		if (ab / x)
		{
			_putchars('0' + cu / x);
			c++;
		}
		cu %= x;
	}
	_putchars('0' + cu);
	c++;
	return (c);
}
/**
 * rm_comments - remove comments
 * @b: ptr
 * Return: 0
 */
void rm_comments(char *b)
{
	int i = 0;

	while (b[i] != '\0')
	{
		if (b[i] == '#' && (!i || b[i - 1] == ' '))
		{
			b[i] = '\0';
			break;
		}
		i++;
	}
}
/**
 * *con_num - convert numbers to string
 * @b: base
 * @n: number
 * @f: flag
 * Return: str
 */
char *con_num(long int n, int b, int f)
{
	static char buf[50];
	char *p;
	static char *a;
	char g = 0;
	unsigned long num = n;

	if (!(f & CONVERT_UNSIGNED) && n < 0)
	{
		num = -n;
		g = '-';
	}
	a = (f & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buf[49];
	*p = '\0';

	do {
		*--p = a[num % b];
		num /= b;
	} while (n != 0);
	if (g)
		*--p = g;
	return (p);
}
/**
 * e_atoi - convert str to int
 * @s: string
 * Return: r
 */
int e_atoi(char *s)
{
	int i = 0;
	unsigned long int r = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			r *= 10;
			r += (s[i] - '0');
			if (r > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (r);
}
