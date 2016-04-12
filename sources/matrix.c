#include "fdf.h"

void matrix_mult(int mi[3][3], t_point *p)
{
	int i;
	int j;
	int newp[2];

	i = 0;
	j = 0;
	while (i < 2)
	{
		newp[i] = (mi[i][0] * p->x) + (mi[i][1] * p->y) + (mi[i][2] * 1);
		i++;
	}
	p->x = newp[0];
	p->y = newp[1];
}

void matrix_mult_scale(int mi[3][3], t_point *p, float x_axis, float y_axis)
{
	int		i;
	int		j;
	float	newp[2];
	t_point	tmp;

	i = 0;
	j = 0;
	tmp.x = (p->x + (-x_axis)) + x_axis;
	tmp.y = (p->y + (-y_axis)) + y_axis;
	while (i < 2)
	{
		newp[i] = (mi[i][0] * tmp.x) + (mi[i][1] * tmp.y) + (mi[i][2] * 1);
		i++;
	}
	p->x = (int )newp[0];
	p->y = (int )newp[1];
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
	while (v < coord->total_points)
	{
		matrix_mult(matrix, coord->verteces[v]);
		v++;
	}
}

void	scale(t_coord *coord, float x_axis, float y_axis)
{
	int matrix[3][3];
	int v;

	matrix[0][0] = x_axis; 
	matrix[0][1] = 0; 
	matrix[0][2] = 0; 
	matrix[1][0] = 0; 
	matrix[1][1] = y_axis; 
	matrix[1][2] = 0; 
	matrix[2][0] = 0; 
	matrix[2][1] = 0; 
	matrix[2][2] = 1; 
	v = 0;
	while (v < coord->total_points)
	{
		matrix_mult_scale(matrix, coord->verteces[v], x_axis, y_axis);
		v++;
	}
}

void	height(t_coord *coord, int n_y)
{
	int v;

	v = 0;
	while (v < coord->total_points)
	{
		coord->verteces[v]->y -= coord->verteces[v]->h * n_y;
		v++;
	}
}

void	zoom(t_coord *coord, int gap, int c_height)
{
	int v;
	int x;
	int y;

	v = 0;
	x = 0;
	y = 0;
	while (y < coord->y_point)
	{
		while (x < coord->x_point)
		{
			coord->verteces[v]->x = ((x * gap) - (y * gap)) + ORIGIN_X;
			coord->verteces[v]->y = ((x * gap) + (y * gap)) / 2 + ORIGIN_Y - (coord->verteces[v]->h * c_height);
			v++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	rotate(t_coord *coord, int angle)
{
	int matrix[3][3];
	int v;

	matrix[0][0] = cos(angle); 
	matrix[0][1] = -(sin(angle))+ 0.5; 
	matrix[0][2] = 0; 
	matrix[1][0] = sin(angle)+ 0.5; 
	matrix[1][1] = cos(angle)+ 0.5; 
	matrix[1][2] = 0; 
	matrix[2][0] = 0; 
	matrix[2][1] = 0; 
	matrix[2][2] = 1; 
	v = 0;
	while (v < coord->total_points)
	{
		matrix_mult(matrix, coord->verteces[v]);
		v++;
	}
}
