/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:11:26 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/14 18:22:29 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	launchfunc(int keycode, t_co *c)
{
	if (keycode == KEY_EQUAL)
		height(c->coord, 2);
	else if (keycode == KEY_MIN)
		height(c->coord, -2);
	else if (keycode == KEY_NUM_MINUS)
	{
		c->gap -= 5;
		if (c->gap == 0 || c->gap < 0)
			c->gap = 2;
		zoom(c->coord, c->gap, 10);
	}
	else if (keycode == KEY_NUM_PLUS)
		zoom(c->coord, c->gap += 5, 10);
	else if (keycode == KEY_LEFT)
		translate(c->coord, -5, 0);
	else if (keycode == KEY_RIGHT)
		translate(c->coord, 5, 0);
	else if (keycode == KEY_UP)
		translate(c->coord, 0, -5);
	else if (keycode == KEY_DOWN)
		translate(c->coord, 0, 5);
	else if (keycode == KEY_NUM_1)
		rot(c->coord, c->div += 1, c->gap, c->c_height);
	else if (keycode == KEY_NUM_2)
	{
		c->div--;
		if (c->div == 0)
			c->div = 1;
		rot(c->coord, c->div, c->gap, c->c_height);
	}
	else if (keycode == KEY_F)
		rot(c->coord, 1000, c->gap, c->c_height);
	else if (keycode == KEY_H)
		rot(c->coord, 1, c->gap, c->c_height);
}

void	redraw(t_co *c, int key)
{
	if (key != KEY_LEFT && key != KEY_RIGHT && key != KEY_UP && key != KEY_DOWN
		&& key != KEY_MIN
		&& key != KEY_NUM_PLUS && key != KEY_NUM_MINUS &&
		key != KEY_EQUAL && key != KEY_NUM_1 && key != KEY_NUM_2
		&& key != KEY_F && key != KEY_H)
		return ;
	set_background(c->bg_color, c->img);
	mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img_ptr, 0, 0);
	c->img->img_color = mlx_get_color_value(c->mlx_ptr, c->line_color);
	launchfunc(key, c);
	print_point(c->coord, c->img);
	mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img_ptr, 0, 0);
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

int		handler(int keycode, void *pa)
{
	if (((t_co *)pa)->gap == 0)
		((t_co *)pa)->gap = 1;
	if (keycode == KEY_ESC)
	{
		co_destroy(((t_co *)pa));
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_SPACE)
		mlx_clear_window(((t_co *)pa)->mlx_ptr, ((t_co *)pa)->win_ptr);
	else
		redraw((t_co *)pa, keycode);
	return (0);
}
