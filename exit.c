#include "shell.h"
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
 * *_strchr - function that locates a character in a string
 * @c: char
 * @s: string
 * Return: nothing
 */
char *_strchr(char *s, char c)
{
	unsigned int a;

	for (a = 0; s[a] >= '\0'; a++)
	{
		if (s[a] == c)
		{
			return (s + a);
		}
	}
	return ('\0');
}
