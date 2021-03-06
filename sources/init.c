/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:11:17 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/15 22:42:35 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_co *c)
{
	int		s;
	char	*mx;
	char	*my;

	mx = ft_strjoin("origin x: ", ft_itoa(c->coord->vert[0]->x));
	my = ft_strjoin("origin y: ", ft_itoa(c->coord->vert[0]->y));
	s = WIDTH - 200;
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 10, WHITE, "Esc: Exit");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 25, WHITE, "+: Lvl +");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 40, WHITE, "-: Lvl -");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 100, WHITE, "Arrows: Move");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 115, WHITE, "F : Front View ");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 130, WHITE, "H : Top View");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 145, WHITE, "P Num 1: Rot Up");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 160, WHITE, "P Num 2: Rot Down");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 175, WHITE, "P Num +: Z In");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 190, WHITE, "P Num - : Z Out");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 10, WHITE, mx);
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 25, WHITE, my);
	free(mx);
	free(my);
}

void	init_co_img(t_co *c, t_image *im)
{
	c->bg_color.r = 125;
	c->bg_color.g = 25;
	c->bg_color.b = 53;
	c->bg_color.alpha = 0;
	c->line_color = WHITE;
	c->mlx_ptr = mlx_init();
	c->img_ptr = mlx_new_image(c->mlx_ptr, WIDTH, HEIGHT);
	im->data = mlx_get_data_addr(c->img_ptr, &im->bpp, &im->sizeline,
	&im->endian);
	im->img_color = mlx_get_color_value(c->mlx_ptr, c->line_color);
	c->img = im;
	c->win_ptr = mlx_new_window(c->mlx_ptr, WIDTH, HEIGHT, "FDF");
	set_background(&c->bg_color, c->img);
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
