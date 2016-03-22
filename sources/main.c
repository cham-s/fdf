#include "fdf.h"

/*int		is_alphanumeric(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (!ft_isalnum(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int		check_line(char *line)
{
	if (!is_alphanumeric(line))
		return (-1);
}

int		parse_file(int fd, int **map, t_list *lines)
{
	line	*line;
	size_t tab_size;
	size_t next_split;

	while (get_next_line(fd, &line))
	{
		wh
	}
}*/

/* void    pixel_put_image(char *data, t_img *img, int x, int y) */
/* { */
/* 	data[y * img->sizeline + x * img->bpp / 8 +2] = 255; */
/* 	data[y * img->sizeline + x * img->bpp / 8 + 1] = 255; */
/* 	data[y * img->sizeline + x * img->bpp / 8 ] = 255; */
/* } */
/*  */
/* int		ret_y(t_point *p1, t_point *p2, int x) */
/* { */
/* 	return (p1->y + (p2->y - p1->y) * (x - p1->x)) / (p2->x - p1->x); */
/* } */
/*  */
/* void	drawline(t_point *p1, t_point *p2, char *data, t_img *img) */
/* { */
/* 	int x; */
/*  */
/* 	x = p1->x; */
/* 	while (x <= p2->x) */
/* 	{ */
/* 		pixel_put_image(data, img, x, ret_y(p1, p2, x)); */
/* 		x++; */
/* 	} */
/* } */

int main()
{
	t_env *e;
	
	e = (t_env *)malloc(sizeof(t_env));
	e->img_iso = (t_img *)malloc(sizeof(t_img));
	e->map_iso = (t_point *)malloc(sizeof(t_point));
	e->img_para = (t_img *)malloc(sizeof(t_img));
	e->map_para = (t_point *)malloc(sizeof(t_point));
	env(e);
	return (0);
}
