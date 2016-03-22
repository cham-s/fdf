#ifndef FDF_H
# define FDF_H
#include "libft.h"
#include "mlx.h"

typedef struct	s_img
{
	int		bpp;
	int		sizeline;
	int		endian;
}				t_img;

typedef struct	s_point
{
	int x;
	int y;
	int z;
}				t_point;

typedef struct	s_mlx
{
	void *mlx;
	void *win;
	void *img;
}				t_mlx;

typedef struct	s_line
{
	char	*line;
	int		len;
	struct	s_line *prev;
	struct	s_line *next;
}				t_line;

#endif
