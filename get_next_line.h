/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiroel <luiroel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:48:40 by luiroel           #+#    #+#             */
/*   Updated: 2020/03/04 19:36:23 by luiroel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# define MAX_FD 4096
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_line
{
	char			*temp;
	int				fd_arr[MAX_FD];
	size_t			line_sz;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
