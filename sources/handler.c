#include "fdf.h"

void	launchfunc(int keycode, t_context *c)
{
	if (keycode == KEY_EQUAL)
		height(c->coord, 2);
	else if (keycode == KEY_MIN)
		height(c->coord, -2);
	else if (keycode == KEY_NUM_MINUS)
		zoom(c->coord, c->gap-=5, 10);
	else if (keycode == KEY_NUM_PLUS)
		zoom(c->coord, c->gap+=5, 10);
	else if (keycode == KEY_LEFT)
		translate(c->coord, -5, 0);
	else if (keycode == KEY_RIGHT)
		translate(c->coord, 5, 0);
	else if (keycode == KEY_UP)
		translate(c->coord, 0, -5);
	else if (keycode == KEY_DOWN)
		translate(c->coord, 0, 5);
}

void	redraw(t_context *c, int key)
{
	if (key != KEY_LEFT && key != KEY_RIGHT && key != KEY_UP && key != KEY_DOWN 
		&& key != KEY_MIN
	 	&& key != KEY_NUM_PLUS && key != KEY_NUM_MINUS && key != KEY_EQUAL)
		return ;
	c->img->img_color = mlx_get_color_value(c->mlx_ptr, BLACK);
	print_point(c->coord, c->img);
	mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img_ptr, 0, 0);
	c->img->img_color = mlx_get_color_value(c->mlx_ptr, RED);
	launchfunc(key, c);
	print_point(c->coord, c->img);
	mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img_ptr, 0, 0);
}

int		handler(int keycode, void *param)
{
	if (((t_context *)param)->gap == 0) 
		((t_context *)param)->gap = 1;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(((t_context *)param)->mlx_ptr, ((t_context *)param)->img_ptr);
		mlx_destroy_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 49)
		mlx_clear_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr);
	else
		redraw((t_context *)param, keycode);
	return (0);
}
