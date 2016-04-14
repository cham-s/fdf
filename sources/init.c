#include "fdf.h"

void	init_context_img(t_context *c, t_image *im)
{
	c->bg_color = GREY;
	c->line_color = WHITE;
	c->mlx_ptr = mlx_init();
	c->img_ptr = mlx_new_image(c->mlx_ptr, WIDTH, HEIGHT);
	im->data = mlx_get_data_addr(c->img_ptr, &im->bpp, &im->sizeline, &im->endian);
	im->img_color = mlx_get_color_value(c->mlx_ptr, c->line_color);
	c->img = im;
	c->win_ptr = mlx_new_window(c->mlx_ptr, WIDTH, HEIGHT, "FDF");
	set_background(c->bg_color, c->img);
	print_point(c->coord, im);
}
