#include "fdf.h"

static void	check_map(char *map)
{
	int fd;

	if ((fd = open(map, O_RDONLY)) == -1)
	{
		perror("Error ");
		exit(EXIT_FAILURE);
	}
}

int			check_args(int ac, char *map)
{
	if (ac != 2)
	{
		ft_putstr_fd("usage : ", 2);
		ft_putstr_fd(map, 2);
		ft_putendl_fd("./fdf <map>", 2);
		exit(EXIT_FAILURE);
	}
	check_map(map);
	return (EXIT_SUCCESS);
}

void		check_ret_gnl(int *fd, char *line)
{
	if (get_next_line(*fd, &line) < 0)
	{
		ft_putendl_fd("Not a valid file", 2);
		exit(EXIT_FAILURE);
	}
}

void		check_len_map(int x_len, t_coord *coord)
{
	if (x_len != coord->x_point)
	{
		ft_putendl_fd("Map not well formatted", 2);
		exit(EXIT_FAILURE);
	}
}
