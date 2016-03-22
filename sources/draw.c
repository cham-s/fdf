#include "fdf.h"

void	pixel_put_image(char *datam t_img *img, int x, int y)
{
	int z;

	z = 0xff0000;
	((int *) data)[SIZE_PARA_WIDTH * y + z] = z;
}
t_point	*3d_iso(t_env *e)
{
	while (e->map_iso)
	{
		e->map_iso->x -= e->const_x_iso * e->map_iso->x - e->const_y_iso * e->map_iso->y;
		e->map_iso->y -= e->map_iso->z + (e->const_x_iso / 2) * e->map_iso->x + e->const_y_iso / 2;
		e->map_iso = e->map_iso->next;
	}
	return (e->map_iso);
}

t_point	*3d_para(t_env *e)
{
	while (e->map_para)
	{
		e->map_para->x -= e->const_para * e->map_para->z;
		e->map_para->y -= (e->const_para / 2) * e->map_para->z;
		e->map_para = e->map_para->next;
	}
	return (e->map_para);
}

void	draw_iso(t_env *e, 0, 0)
{
	e->map_iso =  3d_iso(e);
	while (e->map_iso)
	{
		pixel_put_image(e->img_iso->data, e->img_iso->img, e->map_iso->x, e->map_iso->y);
		e->map_iso = e->map_iso->next;
	}
	mlx_put_image_window(e->mlx, e->win_iso, e-img_iso->img, 0, 0);
}

void	draw_para(t_env *e, 0, 0)
{
	e->map_para = 3d_para(e);
	while (e->map_para)
	{
		pixel_put_image(e->img_para->data, e->img_para->img, e->map_para->x, e->map_para->y);
		e->map_para = e->map_para->next;
	}
	mlx_put_image_window(e->mlx, e->win_para, e-img_para->img, 0, 0);
}
