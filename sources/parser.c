#include "fdf.h"

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
	while (is_space(l[i]))
		i++;
	while (l[i])
	{
		if (is_space(l[i]) && l[i + 1] && is_space(l[i + 1]))
			return (-1);
		if (!l[i + 1] && is_space(l[i]))
			return (-1);
		if (is_space(l[i]) && !is_space(l[i + 1]))
			s++;
		i++;
	}
	return (s + 1);
}

int		check_line(char *line)
{
	int line_sz;

	line_sz = 0;
	if (!is_numeric(line))
		return (-1);
	if ((line_sz = linesize(line)) == -1)
		return (-1);
	return (line_sz);
}

char	**tab_realloc(char **tab, char *line)
{
	char	**new;
	int		size_tab;
	int		i;

	i = 0;
	size_tab = ft_tablen(tab);
	new = (char **)malloc(sizeof(char *) * size_tab + 2);
	if (!new)
		return (NULL);
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = ft_strdup(line);
	i = 0;
	while (tab[i])
		free(tab[i]);
	free(tab);
	return (new);
}

void	get_points(char *line, char **tab)
{
	if (!line)
		return ;
	if (!tab)
		tab = (char **)ft_memalloc(sizeof(char *));
	tab = tab_realloc(tab, line);
}

void	parse_map(int fd, t_env *e)
{
	int		y;
	int		linesize;
	char	*line;
	char	**points;

	(void)e;
	y = 0;
	points = NULL;
	while (get_next_line(fd, &line))
	{
		linesize = check_line(line);
		get_points(line, points);
		free(line);
		y++;
	}
	while ()
}
