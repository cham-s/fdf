/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:11:17 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/14 18:23:30 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_co *c)
{
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 10, WHITE, "Esc = Exit");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 25, WHITE, "+   = Zoom in");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 40, WHITE, "-   = Zoom out");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 55, WHITE, "R   = Reset");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 70, WHITE, "P   = Level +");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 85, WHITE, "O   = Level -");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 100, WHITE, ">   = Move Right");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 115, WHITE, "<   = Move Left");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 130, WHITE, "^   = Move Up");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 145, WHITE, "v   = Move Down");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 160, WHITE, "T  = Rotate Up");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 175, WHITE, "G  = Rotate Down");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 190, WHITE, "1  = Front view");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 205, WHITE, "2  = Top view");
}

void	init_co_img(t_co *c, t_image *im)
{
	c->bg_color = SPEBLUE;
	c->line_color = WHITE;
	c->mlx_ptr = mlx_init();
	c->img_ptr = mlx_new_image(c->mlx_ptr, WIDTH, HEIGHT);
	im->data = mlx_get_data_addr(c->img_ptr, &im->bpp, &im->sizeline,
	&im->endian);
	im->img_color = mlx_get_color_value(c->mlx_ptr, c->line_color);
	c->img = im;
	c->win_ptr = mlx_new_window(c->mlx_ptr, WIDTH, HEIGHT, "FDF");
	set_background(c->bg_color, c->img);
	print_point(c->coord, im);
}

void	coord_destroy(t_coord *co)
{
	int v;

	v = 0;
	while (v < co->to_pts)
	{
		free(co->vert[v]);
		v++;
	}
	free(co->vert);
}

void	co_destroy(t_co *c)
{
	coord_destroy(c->coord);
	mlx_destroy_image(c->mlx_ptr, c->img_ptr);
	mlx_destroy_window(c->mlx_ptr, c->win_ptr);
}
