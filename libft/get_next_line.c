/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:59:25 by cattouma          #+#    #+#             */
/*   Updated: 2016/03/22 00:02:19 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buff;
	char		*tmp;
	int			ret;

	tmp = NULL;
	buff = malloc(BUFF_SIZE + 1);
	!save ? (save = ft_strnew(0)) :
	(tmp = ft_strchr(save, '\n'));
	while (fd > -1 && line && !tmp && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(save, buff);
		free(save);
		save = tmp;
		tmp = ft_strchr(save, '\n');
	}
	free(buff);
	if (fd < 0 || ret < 0 || !line)
		return (-1);
	if (!tmp && save[0] == '\0')
		return (0);
	*line = (tmp ? ft_strsub(save, 0, tmp - save) :	ft_strdup(save));
	save = (tmp ? ft_strcpy(save, ++tmp) : ft_strdup("\0"));
	return (1);
}

