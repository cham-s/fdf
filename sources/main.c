#include "fdf.h"

/* int		parse_file(fd, t_list *points) */
/* { */
/* 	line *line; */
/* 	char **split_points; */
/* 	int x; */
/* 	int y; */
/* 	int i; */

/* 	i = 0; */
/* 	x = 0; */
/* 	y = 0; */
/* 	while (get_next_line(fd, &line)) */
/* 	{ */
/* 		split_points = ft_strsplit(line, ' '); */
/* 		while () */
/* 	} */

/* } */

void    pixel_put_image(char *data, t_img *img, int x, int y)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	int				color;
	
	color = 0xf8f8ff;
	blue = (color & 0xFF00000) >> 24;
	green = (color & 0xFF00000) >> 16;
	red = (color & 0xFF00000) >> 8;
	data[y * img->sizeline + x * img->bpp / 8 ] = blue;
	data[y * img->sizeline + x * img->bpp / 8 + 1] = green;
	data[y * img->sizeline + x * img->bpp / 8 + 2] = red;
	data[y * img->sizeline + x * img->bpp / 8 + 3] = 0x1f;
}

int		ret_y(t_point *p1, t_point *p2, int x)
{
	return (p1->y + (p2->y - p1->y) * (x - p1->x)) / (p2->x - p1->x);
}

void	drawline(t_point *p1, t_point *p2, char *data, t_img *img)
{
	int x;

	x = p1->x;
	while (x <= p2->x)
	{
		pixel_put_image(data, img, x, ret_y(p1, p2, x));
		x++;
	}
}

void	drawsqrt(char *data, t_img *img)
{
	t_point	p;

	p.x = 100;
	p.y = 100;

	while (p.y < 300)
	{
		p.y = 100;
		while (p.x < 300)
		{
			pixel_put_image(data, img, p.x, p.y);
			p.x++;
		}
		p.y++;
	}
}

int main()
{
	t_mlx	ret_mlx;
	t_img	img;
	t_point p1;
	t_point p2;
	char	*data;

	p1.x = 100;
	p1.y = 100;

	p2.x = 200;
	p1.y = 200;

	ret_mlx.mlx = mlx_init();
	ret_mlx.img = mlx_new_image(ret_mlx.mlx, 900, 900);
	data = mlx_get_data_addr(ret_mlx.img , &(img.bpp), &(img.sizeline), &(img.endian));
	//drawline(&p1, &p2, data, &img);
	drawsqrt(data, ret_mlx.img);
	ret_mlx.win = mlx_new_window(ret_mlx.mlx, 1000, 1000, "Test" );
	mlx_put_image_to_window(ret_mlx.mlx, ret_mlx.win, ret_mlx.img, 0, 0);
	mlx_loop(ret_mlx.mlx);
}
