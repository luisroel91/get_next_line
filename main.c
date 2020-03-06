/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiroel <luiroel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:52:29 by tvandivi          #+#    #+#             */
/*   Updated: 2020/03/06 11:03:34 by luiroel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

void	prompt(int a, char *line)
{
		ft_putstr(FT_WHITE);
		ft_putstr("\nget_next_line(0, &line) returned: ");
		ft_putstr(FT_GREEN);
	   	ft_putnbr(a);
		ft_putstr("\tstr: ");
		ft_putstr(line);
		ft_putstr(FT_WHITE);
		ft_putstr("\nget_next_line(42, &line) returned: ");
		ft_putstr(FT_GREEN);
		ft_putnbr(get_next_line(42, &line));
		ft_putstr(FT_WHITE);
		ft_putstr("\nget_next_line(-99, &line) returned: ");
		ft_putstr(FT_GREEN);
		ft_putnbr(get_next_line(-99, &line));
		ft_putstr(FT_LIGHTGRAY);
}

int	main(int ac, char **av)
{
	int			fd;
	int			fd1;
	int			fd2;
	int			fd3;
	int			fd4;
	char		*buf;
	char		*buf1;
	char		*buf2;
	char		*buf3;
	char		*buf4;
	char		a;
	int			i;

//	a = 1;
	i = 0;
	if (ac == 1)
	{
		char *line = "a simple test string\nb simple test string\nc simple test string\nd simple test string\n";
		ft_putstr("Enter a few words: ");
		a = get_next_line(0, &line);
		prompt(a, line);
	}
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((a = get_next_line(fd, &buf)) > 0)
		{
			i++;
			printf("\033[0;35m%s\n", buf);
		}
		close(fd);
	}
	else if (ac == 3)
	{
		if (ft_strcmp(av[1], "debug") == 0)
		{
			fd = open(av[2], O_RDONLY);
			while ((a = get_next_line(fd, &buf)) > 0)
			{
				i++;
				printf("\033[0;35m%s\n", buf);
			}
			printf("\n\033[0;32m\u0305 \u0305 \u0305 \u0305 \u0305 \u0305 \u0503e\u0499\u0299\u0216\u050d\u050d\u0671\u05deg  \u0305 \u0305 \u0305 \u0305 \u0305 \u0305\n\n");
			printf("Buffer Length:\t%d\n", BUFF_SIZE);
			printf("buf Length:\t%zu\n", ft_strlen(buf));
			printf("Line Count:\t%d\n", i);
			close(fd);
		}
		else
		{
			fd = open(av[1], O_RDONLY);
			fd1 = open(av[2], O_RDONLY);
			while ((a = get_next_line(fd, &buf)) > 0)
			{
				printf("\033[0;34m%s\n", buf);
				if ((a = get_next_line(fd1, &buf1)) > 0)
					printf("\033[0;32m%s\n", buf1);
			}
			close(fd);
			close(fd1);
		}
	}
	else if (ac == 4)
	{
		fd = open(av[1], O_RDONLY);
		fd1 = open(av[2], O_RDONLY);
		fd2 = open(av[3], O_RDONLY);
		while ((a = get_next_line(fd, &buf)) > 0)
		{
			printf("\033[0;34m%s\n", buf);
			if ((a = get_next_line(fd1, &buf1)) > 0)
				printf("\033[0;32m%s\n", buf1);
			if ((a = get_next_line(fd2, &buf2)) > 0)
				printf("\033[0;36m%s\n", buf1);
		}
		close(fd);
		close(fd1);
		close(fd2);
	}
	else if (ac == 5)
	{
		fd = open(av[1], O_RDONLY);
		fd1 = open(av[2], O_RDONLY);
		fd2 = open(av[3], O_RDONLY);
		fd3 = open(av[4], O_RDONLY);
		while ((a = get_next_line(fd, &buf)) > 0)
		{
			printf("\033[0;34m%s\n", buf);
			if ((a = get_next_line(fd1, &buf1)) > 0)
				printf("\033[0;32m%s\n", buf1);
			if ((a = get_next_line(fd2, &buf2)) > 0)
				printf("\033[0;36m%s\n", buf2);
			if ((a = get_next_line(fd3, &buf3)) > 0)
				printf("\033[0;33m%s\n", buf3);
		}
		close(fd);
		close(fd1);
		close(fd2);
		close(fd3);
	}
	else if (ac == 6)
	{
		fd = open(av[1], O_RDONLY);
		fd1 = open(av[2], O_RDONLY);
		fd2 = open(av[3], O_RDONLY);
		fd3 = open(av[4], O_RDONLY);
		fd4 = open(av[5], O_RDONLY);
		while ((a = get_next_line(fd, &buf)) > 0)
		{
			printf("\033[0;34m%s\n", buf);
			if ((a = get_next_line(fd1, &buf1)) > 0)
				printf("\033[0;32m%s\n", buf1);
			if ((a = get_next_line(fd2, &buf2)) > 0)
				printf("\033[0;36m%s\n", buf2);
			if ((a = get_next_line(fd3, &buf3)) > 0)
				printf("\033[0;33m%s\n", buf3);
			if ((a = get_next_line(fd4, &buf4)) > 0)
				printf("\033[0;31m%s\n", buf4);
		}
		close(fd);
		close(fd1);
		close(fd2);
		close(fd3);
		close(fd4);
	}
	return (0);
}
