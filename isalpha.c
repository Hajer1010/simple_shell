#include "shell.h"
/**
 * _atoi - convert string to intger
 * @s: string
 * Return: integar
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int r = 0;
	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			r *= 10;
			r += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -r;
	else
		output = r;
	return (output);
}
/**
 * _isalpha- function that checks for character
 * @c: checks input of function
 * Return: returns 1 if 'c' is true otherwise 0
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * interactive - checks if function runs in interactive mode
 * @in: structure
 * Return: 1 0
 */
int interactive(inf_t *in)
{
	return (isatty(STDIN_FILENO) && in->rfd <= 2);
}

/**
 * is_del - function
 * @c: char
 * @d: delimter
 * Return: 1 0
 */
int is_del(char c, char *d)
{
	while (*d)
		if (*d++ == c)
			return (1);
	return (0);
}
