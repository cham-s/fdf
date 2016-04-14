/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:28:59 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/14 18:22:33 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	join_x(t_coord *co, t_image *img)
{
	int v;
	int x;
	int y;

	v = 0;
	x = 0;
	y = 0;
	while (y < co->y_point - 1)
	{
		while (x < co->x_point)
		{
			draw_line(img, *(co->vert[v]), *(co->vert[v + co->x_point]));
			v++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	join_y(t_coord *co, t_image *img)
{
	int v;
	int x;
	int y;

	v = 0;
	x = 0;
	y = 0;
	while (y < co->y_point)
	{
		while (x < co->x_point - 1)
		{
			draw_line(img, *(co->vert[v]), *(co->vert[v + 1]));
			v++;
			x++;
		}
		x = 0;
		y++;
		v++;
	}
}

void	print_point(t_coord *co, t_image *img)
{
	join_x(co, img);
	join_y(co, img);
}
