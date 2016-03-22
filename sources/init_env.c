/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 03:15:05 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/22 05:14:05 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put_image(char *data, t_img *img,int  x,int  y)
{
	int z;
	z = 0xff0000;

	((int *)data)[SIZE_PARA_WIDTH * y + x] = z;
// 	data[y * SIZE_PARA_WIDTH + x * 4 + 2] = 255; 
// 	data[y * SIZE_PARA_WIDTH + x * 4 + 1] = 0;
// 	data[y * SIZE_PARA_WIDTH + x * 4 ] = 0;
 	(void)img;
}
void	drawsqrt(t_env *e)
{
	int x = 0;
	int y = 0;

	while (x < 400)
	{
		y = 0;
		while (y < 400)
		{
			pixel_put_image(e->img_para->data, e->img_para->img, x, y);
			//ft_putendl(e->img_para->data);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win_para, e->img_para->img, 0, 0);
}

void	draw(t_env *e)
{
	t_point	p1;
	t_point p2;

	p1.x = 100;
	p1.y = 200;

	p2.x = 400;
	p2.y = 900;

	int x;
	
	x = p1.x;
	while (x <= p2.x)
	{
		pixel_put_image(e->img_para->data, e->img_para->img, x, p1.y + (p2.y - p1.y) * (x - p1.x) / (p2.x - p1.x));
		x++;
	}
}
void	env(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return ;
	e->win_iso = mlx_new_window(e->mlx, SIZE_ISO_WIDTH, SIZE_ISO_WEIGHT, "iso");
	e->img_iso->img = mlx_new_image(e->mlx, 1440, 720);
	e->win_para = mlx_new_window(e->mlx, SIZE_PARA_WIDTH, SIZE_PARA_WEIGHT, "para");
//	ft_putendl(e->img_para->img);
	e->img_para->img = mlx_new_image(e->mlx, SIZE_PARA_WIDTH, SIZE_PARA_WEIGHT);
	e->img_iso->data = mlx_get_data_addr(e->img_iso->img, &e->img_iso->bpp,
		   	&e->img_iso->size_line, &e->img_iso->endian);
	e->img_para->data = mlx_get_data_addr(e->img_para->img, &e->img_para->bpp,
		  &e->img_para->size_line, &e->img_para->endian);
	e->zoom_z = 2.5;
	e->const_x_iso = 0.7;
	e->const_y_iso = e->const_x_iso + (e->const_x_iso / 2);
	e->const_para = 0.7;
	//e.zoom = 8;
	//e.decalx = 150;
	//e.decaly = 150;
	//e.r = 255;
	//e.g = 0;
	//e.b = 0;
	//init_t_key(&e.key);
	//draw(e);
	drawsqrt(e);
//	ft_putendl(e->img_para->img);
	//mlx_hook(e.win, 2, 1, key_press, &e);
	//mlx_hook(e.win, 3, 2, key_release, &e);
	//mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e->mlx);
}
