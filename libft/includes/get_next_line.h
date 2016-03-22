/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 02:25:31 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/22 04:03:38 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 25

# include <sys/types.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>
# include "./libft.h"
# include <sys/uio.h>

int				get_next_line(int const fd, char **line);

#endif
