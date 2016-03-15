#ifndef FDF_H
# define FDF_H
#include "libft.h"
#include "mlx.h"

typedef struct	s_point
{
	int x;
	int y;
	int z;
}				t_point;

typedef struct	s_mlx_ret
{
	void *mlx;
	void *win;
}				t_mlx_ret;

#endif
