/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:41:28 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/14 18:28:24 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot(t_coord *coord, int div, int gap, int c_height)
{
	int v;
	int x;
	int y;
	int orx;
	int ory;

	v = 0;
	x = 0;
	y = 0;
	orx = co->vert[v]->x;
	ory = co->vert[v]->y;
	while (y < co->y_point)
	{
		while (x < co->x_point)
		{
			co->vert[v]->x = ((x * gap) - (y * gap)) + orx;
			co->vert[v]->y = ((x * gap) + (y * gap)) / div + ory - (co->vert[v]->h * c_height);
			v++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	zoom(t_coord *coord, int gap, int c_height)
{
	int v;
	int x;
	int y;
	int orx;
	int ory;

	v = 0;
	x = 0;
	y = 0;
	orx = co->vert[v]->x;
	ory = co->vert[v]->y;
	while (y < co->y_point)
	{
		while (x < co->x_point)
		{
			co->vert[v]->x = ((x * gap) - (y * gap)) + orx;
			co->vert[v]->y = ((x * gap) + (y * gap)) / 2 + ory - (co->vert[v]->h * c_height);
			v++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	translate(t_coord *coord, int x_axis, int y_axis)
{
	int matrix[3][3];
	int v;

	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = x_axis;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = y_axis;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	v = 0;
	while (v < co->to_pts)
	{
		matrix_mult(matrix, co->vert[v]);
		v++;
	}
}
