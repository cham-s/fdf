#include "libft.h"

void	tab_free(char **tab)
{
	int i;

	i = 0;

	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
