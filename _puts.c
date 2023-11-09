#include "shell.h"
/**
 * _puts - prints string
 * @s: string to print
 * Return: 0
 */
int _puts(char *s)
{
	int n = 0;

	while (!s)
		return (write(1, "null", 6));
	while (s)
		n += _putchar(*s++);
	return (n);
}
/**
 *_memset - function that fills memory with a constant byte
 * @n: bytes
 * @b: const
 * @s: pointer to the memory area
 * Return: pointer
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a = 0;

	while (n > 0)
	{
		s[a] = b;
		a++, n--;
	}
	return (s);
}
/**
 * get_en - returns copy
 * @in: struct
 * Return: 0
 */
char **get_en(inf_t *in)
{
	if (!in->env || in->en_mod)
	{
		in->env = list_to_string(in->en);
		in->en_mod = 0;
	}
	return (in->env);
}
/**
 *
 */

