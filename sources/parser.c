int		is_numeric(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] < '0' && s[i] > '9' && s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int		is_space(char c)
{
	return (c == ' ');
}

int		linesize(char *l)
{
	size_t	i;
	int		s;

	i = 0;
	s = 0;
	while (l[i])
	{
		if (is_space(l[i]) && l[i + 1] && is_space(l[i + 1]))
			return (-1);
		if (!l[i + 1] && is_space(l[i]))
			return (-1);
		if (is_space(l[i]) && !is_space[i + 1])
			s++;
		i++;
	}
	return (s + 2);
}

int		check_line(char *line)
{
	int line_sz;

	line_sz = 0;
	if (!is_numeric(line))
		return (-1);
	if ((*line_sz = linesize(line)) == -1)
		return (-1);
	return (line_sz);
}

void	pushback(void **list, void *new)
{
	t_line *current;

	current = *list;
	if (!*list)
	{
		new->next = *list;
		*list = new;
	}
	while (current)
		current = current->next;
	current->next = new;
}

//penser a nettoyer line et son strdup a part
t_line	*linenew(char *line, int len)
{
	t_line *new;

	new = (t_line *)malloc(sizeof(t_line));
	if (!new)
		return (NULL);
	new->line = ft_strdup(line);
	new->len = len;
	return (new);
}

void	line_destroy(t_line *list)
{
	t_line *tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp->line);
		free(tmp);
	}
}

t_point		*pointnew(int x, int y, int z)
{
	t_point *new;

	if (!(new = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	new->x = x;
	new->x = y;
	new->x = z;

	return (new);
}

void	point_destroy(t_point *list)
{
	t_line *tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}

int		parse_map(int fd, t_env *env, t_line *lines, t_point *ptlist)
{
	int i;

	while (get_next_line(fd, &lines->line))
	{
		if (lines->linesize = check_line(line) == -1)
			return (-1);
		else 
			lstline
		i++;
	}
	if (lines->line)
}
