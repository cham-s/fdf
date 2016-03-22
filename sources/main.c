#include "fdf.h"

/*int		is_alphanumeric(const char *s)
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

int		parse_file(int fd, t_env *env, t_list *lines)
{
	while (get_next_line(fd, &line) > 0)
	{

		if (lines->linesize = check_line(line) == -1)
			return (-1);
		else 
			lst_linepushback(lines, lstline);
	}
	if (lines->line)
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
