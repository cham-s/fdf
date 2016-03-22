#ifndef FDF_H
# define FDF_H
#include "libft.h"
#include "mlx.h"

typedef struct	s_img
{
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	void		*img;
}				t_img;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	void		*next;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win_iso;
	t_img		*img_iso;
	t_point		*map_iso;
	double		const_x_iso;
	double		const_y_iso;
	void		*win_para;
	t_img		*img_para;
	t_point		*map_para;
	double		const_para;
	double		zoom_z;
	//t_key		key;
}				t_env;

typedef struct	s_line
{
	char		*line;
	int			len;
	void		*prev;
	void		*next;
}				t_line;

void	env(t_env *e);
#endif
