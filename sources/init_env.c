/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 03:15:05 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/22 04:13:50 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void	env(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return ;
	e->win_iso = mlx_new_window(e->mlx, 2560, 720, "iso");
	e->img_iso->img = mlx_new_image(e->mlx, 1440, 720);
	e->win_para = mlx_new_window(e->mlx, 2560, 720, "para");
	e->img_para->img = mlx_new_image(e->mlx, 2560, 720);
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
	//draw_grid(&e, NULL, 0, 0);
	//mlx_hook(e.win, 2, 1, key_press, &e);
	//mlx_hook(e.win, 3, 2, key_release, &e);
	//mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e->mlx);
}

