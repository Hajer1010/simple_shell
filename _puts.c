#include "shell.h"
/**
 * _puts - prints string
 * @s: string to print
 * Return: 0
 */
void _puts(char *s)
{
	int n = 0;

	if (!s)
		return;
	while (s[n] != '\0')
	{
		_putchar(s[n]);
		n++;
	}
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
	unsigned int a;

	for (a = 0; a < n; a++)
	{
		s[a] = b;
	}
	return (s);
}
/**
 * _strcat - a function that concatenates two strings
 * @dest: pointer to dest
 * @src: pointer to src
 * Return: pointer to result
 */
char *_strcat(char *dest, char *src)
{
	int st1, st2;

	st1 = 0;
	while (dest[st1])
		st1++;
	for (st2 = 0; src[st2] ; st2++)
		dest[st1++] = src[st2];
	return (dest);
}
