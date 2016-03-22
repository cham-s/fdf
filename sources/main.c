#include "fdf.h"

t_point		*mpointnew(int x, int y, int z)
{
	t_point *new;

	if (!(new = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	return (new);
}

void	mpushbackpoint(t_point **list, t_point *new)
{
	t_point *current;

	current = *list;
	if (!current)
		*list = new;
	else
	{
		while (current)
			current = current->next;
		current->next = new;
	}
}

int main(int ac, char **av)
{
	t_env *e;
	int fd;

	t_point *points;
	t_point *head;

	points = NULL;
	points = (t_point *)malloc(sizeof(t_point));
	head = points;
	points->x = 0;
	points->y = 0;
	points->z = 13;
	points->next = (t_point *)malloc(sizeof(t_point));
	points = points->next;
	points->x = 1;
	points->y = 0;
	points->z = 24;
	points->next = (t_point *)malloc(sizeof(t_point));
	points = points->next;
	points->x = 2;
	points->y = 0;
	points->z = 4;
	points->next = (t_point *)malloc(sizeof(t_point));
	points = points->next;
	points->x = 3;
	points->y = 0;
	points->z = 27;
	points->next = (t_point *)malloc(sizeof(t_point));
	points = points->next;
	points->x = 4;
	points->y = 0;
	points->z = 43;
	points->next = (t_point *)malloc(sizeof(t_point));
	points = points->next;
	points->x = 0;
	points->y = 1;
	points->z = 9;
	points->next = (t_point *)malloc(sizeof(t_point));
	points = points->next;
	points->x = 1;
	points->y = 1;
	points->z = 0;
	points->next = (t_point *)malloc(sizeof(t_point));
	points = points->next;
	points->x = 2;
	points->y = 1;
	points->z = 0;
	points->next = (t_point *)malloc(sizeof(t_point));
	points = points->next;
	points->x = 3;
	points->y = 1;
	points->z = 32;
	points->next = (t_point *)malloc(sizeof(t_point));
	points = points->next;
	points->x = 4;
	points->y = 1;
	points->z = 35;
	/* points->next = (t_point *)malloc(sizeof(t_point)); */
	/* points = points->next; */
	/* points->x = 0; */
	/* points->y = 0; */
	/* points->z = 45; */
	/* points->next = (t_point *)malloc(sizeof(t_point)); */
	/* points = points->next; */
	/* points->x = 0; */
	/* points->y = 0; */
	/* points->z = 0; */
	points->next = NULL;
	if (ac != 2)
	{
		ft_putendl("error");
		exit(4);
	}
	fd = open(av[1], O_RDONLY);
	e = (t_env *)malloc(sizeof(t_env));
	e->img_iso = (t_img *)malloc(sizeof(t_img));
	e->map_iso = (t_point *)malloc(sizeof(t_point));
	e->img_para = (t_img *)malloc(sizeof(t_img));
	e->map_para = (t_point *)malloc(sizeof(t_point));
	env(e);
//	parse(e, fd);
	return (0);
}
