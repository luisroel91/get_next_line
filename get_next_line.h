/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiroel <luiroel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:48:40 by luiroel           #+#    #+#             */
/*   Updated: 2020/03/04 16:08:39 by luiroel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1000
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_line
{
	char			*temp;
	size_t			line_sz;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
