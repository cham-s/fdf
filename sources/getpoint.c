#include "fdf.h"

void	init_coord(char *file_name, t_context *c)
{
	char	*line;
	int		i;
	int		fd;
	int		x_len;
	char	**split;

	i = 0;
	c->coord = (t_coord *)malloc(sizeof(t_coord));
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		if (i++ == 0)
			x_len = tab_len(split);
		c->coord->x_point = tab_len(split);
		tab_free(split);
		check_len_map(x_len, c->coord);
		free(line);
	}
	check_ret_gnl(&fd, line);
	c->coord->total_points = x_len * i;;
	c->coord->y_point = i;
	close(fd);
}

void	stock_coord(char *file_name, t_context *c)
{
	int		fd;
	char	*line;
	char	**split;
	int		x;
	int		y;
	int		v;

	x = 0;
	y = 0;
	v = 0;
	init_coord(file_name, c);
	fd = open(file_name, O_RDONLY);
	c->coord->verteces = (t_point **)malloc(sizeof(t_point *) * c->coord->total_points);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		while (x < c->coord->x_point)
		{
			c->coord->verteces[v] = (t_point *)malloc(sizeof(t_point));
			c->coord->verteces[v]->h = ft_atoi(split[x]);
			c->coord->verteces[v]->x = ((x * c->gap) - (y * c->gap)) + ORIGIN_X;
			c->coord->verteces[v]->y = ((x * c->gap) + (y * c->gap)) / 2 + ORIGIN_Y - (c->coord->verteces[v]->h * c->c_height);
			v++;
			x++;
		}
		tab_free(split);
		free(line);
		x = 0;
		y++;
	}
	close(fd);
}
