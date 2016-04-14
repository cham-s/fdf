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
	c->gap = 10;
	c->c_height = 10;
}

int	main(int ac, char **av)
{
	t_context			c;
	t_image				im;

	check_args(ac, av[1]);
	stock_coord(av[1], &c);
	init_context_img(&c, &im);
	set_background(c.bg_color, c.img);
	print_point(c.coord, &im);
	mlx_put_image_to_window(c.mlx_ptr, c.win_ptr, c.img_ptr, 0, 0);
	mlx_hook(c.win_ptr, 2, 3, &handler, (void*)&c);
	mlx_loop(c.mlx_ptr);
	return (0);
}
