/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 03:15:05 by apellicc          #+#    #+#             */
/*   Updated: 2016/04/03 15:27:08 by cattouma         ###   ########.fr       */
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
void	int_env(t_env *e)
{
	return ;
}
