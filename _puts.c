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
 * _strcat - a function that concatenates two strings
 * @dest: pointer to dest
 * @src: pointer to src
 * Return: pointer to result
 */
char *_strcat(char *dest, char *src)
{
	char *r = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src;
	*dest = *src;
	return (r);

}
/**
 * start_with - function
 * @h: ptr
 * @n: ptr
 * Return: ptr
 */
char *start_with(const char *h, const char *n)
{
	while (n)
		if (n++ != h++)
			return (NULL);
	return ((char *)h);
}
