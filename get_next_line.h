/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiroel <luiroel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:48:40 by luiroel           #+#    #+#             */
/*   Updated: 2020/02/25 13:52:58 by luiroel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H
# define	BUFF_SIZE 32
# include	<unistd.h>
# include	"libft/includes/libft.h"

int			get_next_line(const int fd, char **line);

#endif
