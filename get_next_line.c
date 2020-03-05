/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiroel <luiroel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:53:08 by luiroel           #+#    #+#             */
/*   Updated: 2020/03/04 21:52:30 by luiroel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_strndup(const char *s, size_t size)
{
	char *newstr;

	if (!(newstr = ft_strnew(size)))
	{
		return (NULL);
	}
	ft_strncpy(newstr, s, size);
	return (newstr);
}

static char	*get_line(const int fd, char *line)
{
	char	buff[BUFF_SIZE + 1];
	int		i;

	if (fd < 0 || read(fd, buff, 0) < 0 || BUFF_SIZE < 1)
		return (0);
	line = (line == NULL) ? ft_strnew(1) : line;
	while (!(ft_strchr(line, '\n')))
	{
		if ((i = read(fd, buff, BUFF_SIZE)) < 0)
		{
			return (0);
		}
		buff[i] = '\0';
		line = ft_strjoin(line, buff);
		if (line[0] == '\0' || i == 0)
			break ;
	}
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	static char		*newline;
	t_line			lnstruct;

	if (!(newline = get_line(fd, (char *)line)) || !line)
		return (-1);
	if ((lnstruct.temp = ft_strchr((char *)line, '\n')) > 0)
	{
		lnstruct.line_sz = lnstruct.temp - newline;
		if (!(*line = ft_strndup(newline, lnstruct.line_sz)))
		{
			return (-1);
		}
		newline = ft_strdup(lnstruct.temp + 1);
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(newline)))
			return (-1);
		if (*line[0] == '\0')
			return (0);
		return (1);
	}
}
