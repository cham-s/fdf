#include "fdf.h"

int		is_alphanumeric(const char *s)
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
}

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
	/* t_mlx	ret_mlx; */
	/* t_img	img; */
	/* t_point p1; */
	/* t_point p2; */
	/* char	*data; */
    /*  */
	/* p1.x = 100; */
	/* p1.y = 100; */
    /*  */
	/* p2.x = 200; */
	/* p1.y = 200; */
    /*  */
	/* ret_mlx.mlx = mlx_init(); */
	/* ret_mlx.img = mlx_new_image(ret_mlx.mlx, 1000, 1000); */
	/* data = mlx_get_data_addr(ret_mlx.img , &(img.bpp), &(img.sizeline), &(img.endian)); */
	/* drawline(&p1, &p2, data, &img); */
	/* ret_mlx.win = mlx_new_window(ret_mlx.mlx, 1000, 1000, "Test" ); */
	/* mlx_put_image_to_window(ret_mlx.mlx, ret_mlx.win, ret_mlx.img, 0, 0); */
	/* mlx_loop(ret_mlx.mlx); */
}
