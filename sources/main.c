#include "fdf.h"

int	main(int ac, char **av)
{
	t_context			c;
	t_image				im;

	check_args(ac, av[1]);
	c.gap = 10;
	c.c_height = 10;
	stock_coord(av[1], &c);
	init_context_img(&c, &im);
	mlx_put_image_to_window(c.mlx_ptr, c.win_ptr, c.img_ptr, 0, 0);
	mlx_hook(c.win_ptr, 2, 3, &handler, (void*)&c);
	mlx_loop(c.mlx_ptr);
	return (0);
}
