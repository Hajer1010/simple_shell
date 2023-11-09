#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/type.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CONVERT_LOWERCASE 	1
#define CONVERT_UNSIGNED 	2
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **env

/**
 * struct list - struct
 * @s: string
 * @n: number
 * @next: next node
 */
typedef struct list
{
	char *s;
	int n;
	struct list *next;
}list_t;

typedef struct inf
{
	char *arg;
	int ac;
	char *fn; //file name
	list_t *en;
	list_t *his;
	int st; //status
	int en_mod;
	char **env;
	list_t *ali;
	int lcf;
	unsigned int lc; //line count
	char path;
	char *argv;
	int ern; //error num
	char cb; //command buffer
	int cbt; //command buffer type
	int fd;
	int hc; //history counter
}inf_t

size_t listint_len(const listint_t *h);
size_t print_listint(const listint_t *h);
int bufree(void **p);
int _putchar(char c);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _puts(char *s);
char *_memset(char *s, char b, unsigned int n);
char **get_en(inf_t *in);
void _eputs(char *str);
int _eputchar(char c);
int _putfd(char c, int fd);
int _psfd(char *str, int fd);
void _perror(inf_t *in, char *es);
int print_dec(int n, int fd);
void rm_comments(char *b);
char *con_num(int b, long int n, int f);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
void _free(char **s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int inter(inf_t *in);
void _clear(inf_t *in);
void _set(inf_t *in, char **av);
char **strok(char *st, char *del);
int _atoi(char *s);
int _isalpha(int c);
list_t *add_node(list_t **head, const char *str);
ist_t *add_node_end(list_t **head, const char *str);
int delete_nodeint_at_index(listint_t **head, unsigned int index);
void free_listint2(listint_t **head);

#endif
