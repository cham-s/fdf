#ifndef FDF_H
# define FDF_H
#include "libft.h"
#include "mlx.h"
#include <fcntl.h>

#define SIZE_ISO_WIDTH 2550
#define SIZE_ISO_WEIGHT 720

typedef struct		s_img
{
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	void			*img;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win_iso;
	t_img			*img_iso;
	int				**map;
}					t_env;

void	init_env(t_env *e);
void	getpoints(int fd, t_env *e);
#endif
