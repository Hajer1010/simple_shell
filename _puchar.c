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
/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length of string
 */
int _strlen(char *s)
{
	int length;

	for (length = 0; *s != '\0'; s++)
		++length;
	return (length);

}
/**
 * _strcmp - a function that compares two strings
 * @s1: st1
 * @s2: st2
 * Return: result
 */
int _strcmp(char *s1, char *s2)
{
	int com = 0;

	while (*s1)
	{
		if (*s1 != *s2)
		{
			com = ((int)*s1 - 48) - ((int)*s2 - 48);
			break;
		}
		s1++;
		s2++;
	}
	return (com);
}
/**
 * *_strcpy -  copies the string pointed to by src
 * @dest: type string
 * @src: type string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');

	return (dest);
}
/**
 * _strdup-return ptr
 * @str: string
 * Return: ptr
 */
char *_strdup(const char *str)
{
	int i, z;
	char *ptr;

	if (str == NULL)
	{
		return (NULL);
	}

	for (z = 0; str[z] != '\0'; z++)
	;

	ptr = malloc(z * sizeof(*str) + 1);

	if (ptr == 0)
	{
		return (NULL);
	}
	else
	{
		for (i = 0; i < z; i++)
			ptr[i] = str[i];
	}
	return (ptr);
}
