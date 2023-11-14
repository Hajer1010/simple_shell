#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define USE_GETLINE 0
#define USE_STRTOK 0
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096
#define INF_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL,\
	0, 0, 0}
extern char **env;

/**
 * struct list - struct
 * @str: string
 * @num: number
 * @next: next node
 */
typedef struct list
{
	char *str;
	int num;
	struct list *next;
} list_t;
/**
 * struct inf - structure
 * @arg: str
 * @ac:arg count
 * @en:envrion
 * @fn:file name
 * @his:history
 * @en_mod:env chanched
 * @status:status
 * @env:copy of env
 * @ali:alias
 * @lcf:line count flag
 * @lc:error count
 * @ern:error num
 * @path:string path
 * @cbt:command buffer type
 * @rfd:read fd
 * @cb:command buf
 * @hc:histry line count
 * @argv:araay of string
 */
typedef struct inf
{
	char *arg;
	int ac;
	char *fn;
	list_t *en;
	list_t *his;
	int status;
	int en_mod;
	char **env;
	list_t *ali;
	int lcf;
	unsigned int lc;
	char path;
	char **argv;
	int ern;
	char cb;
	int cbt;
	int rfd;
	int hc;
} inf_t;
/**
 * struct builtin - struct
 * @t: char
 * @fun: function
 */
typedef struct builtin
{
	char *t;
	int (*fun)(inf_t *);
} builtin_t;

size_t list_len(const list_t *h);
size_t print_list(const list_t *h);
int bufree(void **p);
list_t *node_start_with(list_t *node, char *p, char c);
char *start_with(const char *h, const char *n);
int _putchar(char c);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _puts(char *s);
char *_memset(char *s, char b, unsigned int n);
int _myexit(inf_t *in);
int _mycd(inf_t *in);
int _myhelp(inf_t *in);
int _history(inf_t *in);
int _unset_alias(inf_t *in, char *s);
int set_ali(inf_t *in, char *s);
int print_ali(list_t *node);
int _alias(inf_t *in);
int _myenv(inf_t *in);
char *_getenv(inf_t *in, const char *na);
char **strok2(char *st, char del);
void free_info(inf_t *in, int f);
int _mysetenv(inf_t *in);
char **list_to_strings(list_t *h);
int _myunsetenv(inf_t *in);
int populate_env_list(inf_t *in);
void _eputs(char *str);
size_t print_list_str(const list_t *head);
int _eputchar(char c);
int _putfd(char c, int fd);
int _psfd(char *str, int fd);
void _perror(inf_t *in, char *es);
int print_dec(int n, int fd);
void rm_comments(char *b);
char *con_num(int b, long int n, int f);
int e_atoi(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
void _free(char **s);
char **get_environ(inf_t *in);
int _unsetenv(inf_t *in, char *var);
int _setenv(inf_t *in, char *var, char *value);
ssize_t input_buf(inf_t *in, char **buf, size_t *len);
ssize_t get_input(inf_t *in);
ssize_t read_buf(inf_t *in, char *buf, size_t *i);
int _getline(inf_t *in, char **ptr, size_t *length);
void sigintHandler(__attribute__((unused)) int sig_num);
char *get_hist_file(inf_t *in);
int w_history(inf_t *in);
int r_hist(inf_t *in);
int renum_hist(inf_t *in);
int build_hist_list(inf_t *in, char *b, int c);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int inter(inf_t *in);
void _clear(inf_t *in);
void _set(inf_t *in, char **av);
char **strok(char *st, char *del);
int _atoi(char *s);
int _isalpha(int c);
list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head);
int main(int ac, char **av);
int is_cmd(inf_t *in, char *p);
char *dup_chars(char *ps, int sa, int so);
char *find_path(inf_t *in, char *ps, char *cm);
int shell(inf_t *in, char **av);
int find_builtin(inf_t *in);
void find_cmd(inf_t *in);
int is_chain(inf_t *in, char *buf, size_t *p);
void check_chain(inf_t *in, char *buf, size_t *p, size_t i, size_t len);
int replace_alias(inf_t *in);
int replace_vars(inf_t *in);
int replace_string(char **old, char *new);
int loopshell(char **);
#endif
