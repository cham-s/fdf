#include "fdf.h"

void	pixel_put_image(t_image *img, t_point *p)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (img->img_color & 0xFF0000) >> 16;
	g = (img->img_color & 0xFF00) >> 8;
	b = (img->img_color & 0xFF);
	if (img->endian == 0)
	{
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 2] = r;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 1] = g;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 0] = b;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 3] = 0x00;
	}
	else
	{
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 2] = b;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 1] = g;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 0] = r;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 3] = 0x00;
	}
}

void	pixel_put_image_color(t_image *img, t_point *p, int color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = color & 0xFF0000 >> 16;
	g = color & 0xFF00 >> 8;
	b = color & 0xFF;
	if (img->endian == 0)
	{
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 2] = r;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 1] = g;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 0] = b;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 3] = 0x00;
	}
	else
	{
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 2] = b;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 1] = g;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 0] = r;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 3] = 0x00;
	}
}

void	join_x(t_coord *coord, t_image *img)
{
	int v;
	int x;
	int y;

	v = 0;
	x = 0;
	y = 0;
	while (y < coord->y_point - 1)
	{
		while (x < coord->x_point)
		{
			draw_line(img, *(coord->verteces[v]), *(coord->verteces[v + coord->x_point]));
			v++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	join_y(t_coord *coord, t_image *img)
{
	int v;
	int x;
	int y;

	v = 0;
	x = 0;
	y = 0;
	while (y < coord->y_point)
	{
		while (x < coord->x_point - 1)
		{
			draw_line(img, *(coord->verteces[v]), *(coord->verteces[v + 1]));
			v++;
			x++;
		}
		x = 0;
		y++;
		v++;
	}

}


void	print_point(t_coord *coord, t_image *img)
{
	join_x(coord, img);
	join_y(coord, img);
}

void	draw_verteces(t_coord *coord, t_image *img)
{
	int v;

	v = 0;
	while (v < coord->total_points)
	{
		pixel_put_image(img, coord->verteces[v]);
		v++;
	}
}
