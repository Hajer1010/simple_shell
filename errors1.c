#include "shell.h"
/**
 * _perror - func prints error message
 * @in: struct
 * @es: error string
 * Return: 0 -1
 */
void _perror(inf_t *in, char *es)
{
	_eputs(in->fn));
	_eputs(":");
	print_dec(inf->lc, STDERR_FILENO);
	_eputs(":");
	_eputs(in->argv[0]);
	_eputs(":");
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
	int c = 0;
	int d = 1;
	int temp = n;
	int di = n / d;

	if (fd == STDERR_FILENO)
	{
		_putchars = _putchar;
	}
	if (n < 0)
	{
		_putchars("-");
		c++;
		n = -n;
	}
	if (n == 0)
	{
		_putchars('0');
		c++;
		return (c);
	}
	while (temp > 9)
	{
		d *= 10;
		temp /= 10;
	}
	while (d > 0)
	{
		_putchars('0' + di);
		c++;
		n %= d;
		d /= 10;
	}
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
		if (b[i] == '#' && (i == 0 || b[i - 1] == ' '))
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
char *con_num(int b, long int n, int f)
{
	static char buf[50];
	char *p = &buf[49];
	*p = '\0';
	unsigned long num = n;

	if (!(f & CONVERT_UNSIGNED) && n < 0)
	{
		num = -n;
		*--p = '-';
	}
	char *a = (f & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";

	while (n != 0)
	{
		*--p = a[num % b];
		num /= b;
	}
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
		if (isdigit(s[i]))
		{
			r = r * 10 + (s[i] - '0');
			if (r > INT_MAX)
				return (-1);
		}
		else
		{
			return (-1);
		}
	}
	return (r);
}
