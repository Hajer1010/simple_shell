#include "shell.h"
/**
 * get_hist_file - function get history file
 * @in: struct
 * Return: b
 */
char *get_hist_file(inf_t *in)
{
	char *b;
	char *r;

	r = _getenv(in, "HOME=");
	if (!r)
		return (NULL);
	b =  malloc(size(char) * (_strlen(r)) + _strlen((HIST_FILE) + 2));
	if (!b)
		return (NULL);
	b[0] = 0;
	_strcpy(b, r);
	_strcat(b, "/");
	_strcat(b, HIST_FILE);
	return (b);
}
/**
 * w_history - function that crear a file
 * @in: struct
 * Return: 1 -1
 */
int w_history(inf_t *in)
{
	list_t *node = NULL;
	ssize_t fd;
	char *f = get_hist_file(in);

	if (!f)
		return (-1);
	fd = open(f, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(f);
	if (fd == -1)
		return (-1);
	while (node)
	{
		for (node = in->his; node; node = node->next)
		{
			_psfd(node->str, fd);
			_putfd('\n', fd);
		}
		_putfd(BUF_FLUSH, fd);
		close(fd);
		return (1);
	}
}
/**
 * r_hist - function that read history
 * @in: struct
 * Return: 0
 */
int r_hist(inf_t *in)
{
	int x = 0, c = 0, la = 0;
	ssize_t fd, rd, fz = 0;
	struct stat st;
	char *b = NULL, *f = get_hist_file(in);

	if (!f)
		return (0);
	fd = open(f, O_RDONLY);
	free(f);

	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fz = st.st_size;
	if (fz < 2)
		return (0);
	b = malloc(sizeof(char) * (fz + 1));
	if (!b)
		return (0);
	rd = read(fd, b, fz);
	b[fz] = 0;
	if (rd <= 0)
		return (free(b), 0);
	close(fd);
	while (x < fz)
	{
		if (b[x] == '\n')
		{
			b[x] = '\0';
			build_hist_list(in, b + la, c++);
			la = x + 1; }
		x++; }
	if (la != i)
		build_hist_list(in, b + la, c++);
	free(b);
	in->hc = c;
	while (in->hc-- >= HIST_MAX)
		delete_nodeint_at_index(&(in->hist), 0);
	renum_hist(in);
	return (in->hc);
}
/**
 * renum_hist - function re number history
 * @in: struct
 * Return: new history
 */
int renum_hist(inf_t *in)
{
	list_t *node = in->hist;
	int i;

	for (i = 0; node; i++)
	{
		node->num = i;
		node = node->next;
	}
	return (in->hc = i);
}
/**
 * build_hist_list - function add to hist link list
 * @in: struct
 * @b: buffer
 * @c: linecount
 * Return: 0
 */
int build_hist_list(inf_t *in, char *b, int c)
{
	list_t *node = NULL;

	if (in->his)
	{
		node = in->his;
		add_node_end(&node, b, c);
	}
	if (!in->his)
		in->his = node;
	return (0);
}
