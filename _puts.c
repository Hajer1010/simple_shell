#include "shell.h"
/**
 * _puts - prints string
 * @s: string to print
 * Return: 0
 */
int _puts(char *s)
{
	int n = 0;

	while(!s)
		return (write(1, "null", 6));
	while(s)
		n += _putchar(*s++);
	return (n);
}
