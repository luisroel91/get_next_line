/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiroel <luiroel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:53:08 by luiroel           #+#    #+#             */
/*   Updated: 2020/03/09 13:04:15 by luiroel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int		bytesread;
	char	buff[BUFF_SIZE + 1];
	char	*ptr;

	while ((bytesread = read(fd, buff, BUFF_SIZE)))
	{
		buff[bytesread] = '\0';
		ptr = *content;
		if (!(*content = ft_strjoin(*content, buff)))
		{
			return (-1);
		}
		free(ptr);
		if (ft_strchr(buff, EOL))
		{
			break ;
		}
	}
	return (bytesread);
}

int		dup_line(char **line, char *content, char c)
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
	size_t			lnlen;
	char			*ptr;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || !line || (read(fd, buff, 0)) < 0 ||
		(!(frame = get_line(fd, &list))))
		return (-1);
	ptr = frame->content;
	lnlen = read_line(fd, &ptr);
	frame->content = ptr;
	if (!lnlen && !*ptr)
		return (0);
	lnlen = dup_line(line, frame->content, EOL);
	ptr = frame->content;
	if (ptr[lnlen] != '\0')
	{
		frame->content = ft_strdup(&(((char *)(frame->content))[lnlen + 1]));
		free(ptr);
	}
	else
		ptr[0] = '\0';
	return (1);
}
