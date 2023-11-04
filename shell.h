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
#define BUFFER -1

int _putchar(char c);
int _puts(char *s);

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


#endif
