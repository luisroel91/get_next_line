#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		retcount;
	char	*line;

	retcount = 0;
	//if (argc == 1)
	//{
	//	fd = 0;
	//}
	//if (argc == 1)
	//{
	fd = open("test_basic.txt", O_RDONLY);
	//}
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
		//retcount++;
		//printf("%d", retcount);
	}
	//if (argc == 1)
	//{
	close(fd);
	//}
}
