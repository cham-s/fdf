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
	int		x;
	int		y;
	char	**split;
	int		v;
	int		gap;
	int		c_height;

	x = 0;
	y = 0;
	v = 0;
	gap = 20;
	c_height = 10;
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
			c->coord->verteces[v]->x = ((x * gap) - (y * gap)) + ORIGIN_X;
			c->coord->verteces[v]->y = ((x * gap) + (y * gap)) / 2 + ORIGIN_Y - (c->coord->verteces[v]->h * c_height);
			v++;
			x++;
		}
		tab_free(split);
		free(line);
		x = 0;
		y++;
	}
	/* v = 0; */
	/* int w = 1; */
	/* while (v < c->coord->total_points) */
	/* { */
	/* 	printf("%d, %d ", c->coord->verteces[v]->x, c->coord->verteces[v]->y); */
	/* 	if (w == c->coord->x_point) */
	/* 	{ */
	/* 		printf("\n"); */
	/* 		w = 0; */
	/* 	} */
	/* 	w++; */
	/* 	v++; */
	/* } */
	/* exit(4); */
	close(fd);
}
