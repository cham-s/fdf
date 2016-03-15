#include "fdf.h"

void draw_sqrt(t_mlx_ret *ret)
{
	int x;
	int y;

	x = 50;
	y = 0;
	while(x  < 150)
	{
		y = 50;
		while (y < 150)
		{
			mlx_pixel_put(ret->mlx, ret->win, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
}

int		my_keyfunct(int keycode, void *param)
{
	draw_sqrt(param);
	ft_putstr("key event ");
	ft_putnbr(keycode);
	ft_putendl("");
	return 1;
}


int main()
{
	void *win;
	void *mlx;

	t_mlx_ret *ret;
	ret = (t_mlx_ret *)ft_memalloc(sizeof(*ret));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 600, "mlx 42");
	ret->mlx = mlx;
	ret->win = win;
	mlx_key_hook(win, my_keyfunct, ret);
	mlx_loop(mlx);
	free(ret);
}
