#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "keyboard.h"

# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define WHITE	0xFFFFFF
# define BLACK	0x000000
# define GREY	0x585957

# define WIDTH 1920
# define HEIGHT 1080

# define ORIGIN_X (WIDTH / 2)
# define ORIGIN_Y (HEIGHT / 3)

typedef	struct			s_bres
{
	int					dx;
	int					dy;
	int					e;
	int					x_incr;
	int					y_incr;
	int					c_dx;
	int					c_dy;
	int					ex;
	int					ey;
}						t_bres;

typedef struct			s_point
{
	int					x;
	int					y;
	int					h;
}						t_point;

typedef struct			s_coord
{
	int					x_point;
	int					y_point;
	int					total_points;
	t_point				**verteces;
}						t_coord;

typedef struct			s_image
{
	unsigned long		img_color;
	char				*data;
	int					sizeline;
	int					endian;
	int					bpp;
}						t_image;

typedef struct			s_context
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	t_image				*img;
	t_coord				*coord;
	int					gap;
	int					c_height;
	int					line_color;
	int					bg_color;
	int					*colors;
	int					div;
}						t_context;

void					init_context_img(t_context *c, t_image *im);
void					rot(t_coord *coord, int div, int gap, int c_height);
void					height(t_coord *coord, int n_y);
void					translate(t_coord *coord, int x_axis, int y_axis);
void					zoom(t_coord *coord, int gap, int c_height);
void					scale(t_coord *coord, float x_axis, float y_axis);
void					join_x(t_coord *coord, t_image *img);
void					join_y(t_coord *coord, t_image *img);
void					draw_x_or_y(int x1, int y1, int x2, int y2, t_image *img);
void					draw_verteces(t_coord *coord, t_image *img);
void					pixel_put_image(t_image *image, t_point *p);
void					draw_line(t_image *img, t_point p1, t_point p2);
void					second_case(t_bres *b, t_image *img, t_point *p1);
void					first_case(t_bres *b, t_image *img, t_point *p1);
void					count_line_in_file(char *file_name, t_coord *coord);
void					print_point(t_coord *coord, t_image *img);
int						check_args(int ac, char *av);
void					stock_coord(char *file_name, t_context *c);
void					init_coord(char *file_name, t_context *coord);
void					check_len_map(int x_len, t_coord *coord);
int						handler(int keycode, void *param);
void					count_coord(int *fd, t_coord *coord);
void					check_ret_gnl(int *fd, char *line);
void					menu(t_context *c);
void					pixel_put_image_color(t_image *img, t_point *p, int color);
void					pixel_put_image_color(t_image *img, t_point *p, int color);
void					set_background(int color, t_image *img);

#endif
