#include "shell.h"
/**
 * _putchar - writes char to stdout
 * @c: char to print
 * Return: 1 on success -1 on fail
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
