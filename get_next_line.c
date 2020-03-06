/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiroel <luiroel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:53:08 by luiroel           #+#    #+#             */
/*   Updated: 2020/03/05 18:07:07 by luiroel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = ft_strnew(size)))
	{
		return (NULL);
	}
	while (s1[i] && i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

t_list	*get_line(int fd, t_list **list)
{
	t_list	*temp;

	if (!list)
	{
		return (NULL);
	}
	temp = *list;
	while (temp)
	{
		if ((int)temp->content_size == fd)
		{
			return (temp);
		}
		temp = temp->next;
	}
	temp = ft_lstnew("", fd);
	ft_lstadd(list, temp);
	return (temp);
}

int		read_line(const int fd, char **content)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*temp;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		temp = *content;
		if (!(*content = ft_strjoin(*content, buff)))
		{
			return (-1);
		}
		free(temp);
		if (ft_strchr(buff, EOL))
		{
			break ;
		}
	}
	return (ret);
}

int		copy_line(char **line, char *content, char c)
{
	int	counter;

	counter = 0;
	while (content[counter] && content[counter] != c)
	{
		counter++;
	}
	if (!(*line = ft_strndup(content, counter)))
	{
		return (0);
	}
	return (counter);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*frame;
	size_t			retcount;
	char			*temp;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || !line || (read(fd, buff, 0)) < 0 || (!(frame = get_line(fd, &list))))
	{
		return (-1);
	}
	temp = frame->content;
	retcount = read_line(fd, &temp);
	frame->content = temp;
	if (!retcount && !*temp)
	{
		return (0);
	}
	retcount = copy_line(line, frame->content, EOL);
	temp = frame->content;
	if (temp[retcount] != '\0')
	{
		frame->content = ft_strdup(&(((char *)(frame->content))[retcount + 1]));
		free(temp);
	}
	else
	{
		temp[0] = '\0';
	}
	return (1);
}
